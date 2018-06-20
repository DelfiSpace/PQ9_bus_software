#ifndef __DEVICES_H
#define __DEVICES_H

#include "satellite.h"
#include "stdint.h"

struct ina_device {
  dev_id id;
  float current;
  float voltage;
  float power;
  uint16_t voltage_raw;
  uint16_t current_raw;
  uint16_t power_raw;
  float shunt;
  float iMaxExpected;
  float currentLSB;
  float powerLSB;
};

struct tmp_device {
  dev_id id;
  float temp;
  int16_t raw_temp;
};

struct ltc_device {
  dev_id id;
  uint16_t R_sense;
  uint8_t M;
  uint16_t Q;
  uint16_t R;
  uint16_t I;
  int16_t temp;
};

struct fram_device {
  dev_id id;
  uint16_t address;
  uint8_t *buffer;
  size_t count;
};

void device_init();

void update_device(dev_id id);

void read_device_parameters(dev_id id, void * data);

void write_device_parameters(dev_id id, void * data);

void get_device_parameters(dev_id id, void * data);

bool ina_averaging(struct ina_average *ina_av,
                   int16_t current,
                   int16_t *new_value);

#endif
