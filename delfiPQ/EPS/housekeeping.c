#include "housekeeping.h"

#include "devices.h"
#include "osal.h"
#include "packet_utilities.h"


SAT_returnState hk_parameters_report(SBSYS_id app_id, HK_struct_id sid, uint8_t *data, uint8_t len) {
   return SATR_ERROR;
}

SAT_returnState hk_report_parameters(HK_struct_id sid, pq9_pkt *pkt) {


    pkt->data[0] = (HK_struct_id)sid;

    if(sid == HEALTH_REP) {

        uint16_t size = 1;

        cnv32_8( OSAL_sys_GetTick(), &pkt->data[1]);
        size += 4;

        struct ina_device ina_dev;

        //sol temp and inas
        //ltc

        //SOL_XM_MON_DEV_ID
        for(uint8_t i=EPS_OBC_MON_DEV_ID; i <= EPS_UR_MON_DEV_ID; i++) {

            read_device_parameters(i, &ina_dev);

            cnv16_8(ina_dev.current_raw,&pkt->data[size]);
            size += 2;
            cnv16_8(ina_dev.voltage_raw,&pkt->data[size]);
            size += 2;
            cnv16_8(ina_dev.power_raw,&pkt->data[size]);
            size += 2;
        }

        pkt->len = size;
    }

    return SATR_OK;
}
