#include "parameters.h"
#include "satellite.h"
#include "devices.h"
#include <stdint.h>

#define OBC_BOOT_COUNTER_FRAM_ADDRESS 0x0000

struct parameters_memory_pool {

  uint16_t testing_2;
  uint32_t testing_4;
  uint32_t testing_4_rw;
  uint32_t sensor_loop;
  uint32_t command_loop;

}mem_pool;

void init_parameters() {

  mem_pool.testing_2 = 0xCAFE;
  mem_pool.testing_4 = 0xDEADBEEF;

  mem_pool.testing_4_rw = 0xDEADBEEF;

  mem_pool.sensor_loop = 100000;
  mem_pool.command_loop = 900000;

}

void get_parameter(param_id pid, void* value, uint8_t *buf, uint16_t *size) {

  if(pid == OBC_boot_counter_param_id) {

    uint8_t temp_fram_buffer[2];
    uint16_t temp_val;

    struct fram_device temp_fram = {
      .id = OBC_FRAM_DEV_ID,
      .address = OBC_BOOT_COUNTER_FRAM_ADDRESS,
      .buffer = temp_fram_buffer,
      .count = 2
    };

    read_device_parameters(OBC_FRAM_DEV_ID, &temp_fram);

    memcpy(buf, temp_fram_buffer, 2);

    cnv8_16LE(temp_fram_buffer, &temp_val);
    *((uint16_t*)value) = temp_val;
    *size = 2;

  } else if(pid == SBSYS_sensor_loop_param_id) {
    *((uint32_t*)value) = mem_pool.sensor_loop;
    cnv32_8(mem_pool.sensor_loop, buf);
    *size = 4;

  } else if(pid == Master_command_loop_param_id) {
    *((uint32_t*)value) = mem_pool.command_loop;
    cnv32_8(mem_pool.command_loop, buf);
    *size = 4;

  } else if(pid == testing_2_param_id) {
    *((uint16_t*)value) = mem_pool.testing_2;
    cnv16_8(mem_pool.testing_2, buf);
    *size = 2;
  } else if(pid == testing_4_param_id) {
    *((uint32_t*)value) = mem_pool.testing_4;
    cnv32_8(mem_pool.testing_4, buf);
    *size = 4;

  } else if(pid == obc_int_temp_param_id) {

    struct tmp_device tmp_dev;

    read_device_parameters(OBC_INT_TEMP_DEV_ID, &tmp_dev);

    *((uint16_t*)value) = tmp_dev.raw_temp;
    cnv16_8(tmp_dev.raw_temp, buf);
    *size = 2;

  } else if(pid == obc_sensor_status_param_id) {

    bool status[16];
    uint16_t size2;

    read_device_status(&status, &size2);

    buf[0] = 0;

    for(uint8_t i = 0; i < size2; i++) {
      buf[0] |= (status[i] << i);
    }

    *((uint8_t*)value) = buf[0];
    *size = 1;

  } else {
    *size = 0;
  }

}

bool set_parameter(param_id pid, void* value) {

  bool res = true;

  if(pid == OBC_boot_counter_param_id) {

    uint8_t temp_fram_buffer[2];

    cnv16_8((uint16_t)value, temp_fram_buffer);

    struct fram_device temp_fram = {
      .id = OBC_FRAM_DEV_ID,
      .address = OBC_BOOT_COUNTER_FRAM_ADDRESS,
      .buffer = temp_fram_buffer,
      .count = 2
    };

    write_device_parameters(OBC_FRAM_DEV_ID, &temp_fram);

  } else if(pid == SBSYS_sensor_loop_param_id) {
    uint8_t *buf;
    buf = (uint8_t*)value;
    cnv8_32LE(&buf[0], &mem_pool.sensor_loop );

  } else if(pid == Master_command_loop_param_id) {
    uint8_t *buf;
    buf = (uint8_t*)value;
    cnv8_32LE(&buf[0], &mem_pool.command_loop);

  } else if(pid == SBSYS_reset_clr_int_wdg_param_id) {

    struct int_wdg_device dev;
    read_device_parameters(INT_WDG_DEV_ID, &dev);
    dev.clr = true;
    write_device_parameters(INT_WDG_DEV_ID, &dev);

  } else if(pid == SBSYS_reset_cmd_int_wdg_param_id) {

    struct int_wdg_device dev;
    read_device_parameters(INT_WDG_DEV_ID, &dev);
    dev.cmd = true;
    write_device_parameters(INT_WDG_DEV_ID, &dev);

  } else {
    res = false;
  }
  return res;
}
