#ifndef __SATELLITE_H
#define __SATELLITE_H

#include "satellite_ids.h"
#include <stdbool.h>
#include <stddef.h>

//#define C_ASSERT(e)    ((e) ? (true) : (services_error_handler(__FILE_ID__, __LINE__, #e)))
#define C_ASSERT(e)    ((e) ? (true) : (services_error_handler(1, 1, #e)))


#define PKT_TIMEOUT 60000 /*in mseconds*/
#define PKT_NORMAL  198   /*MAX_PKT_DATA*/

#define POOL_PKT_SIZE    4

#define MAX_APP_ID      20
#define MAX_SERVICES    20
#define MAX_SUBTYPES    26

#define TC_FM_TYPE    1
#define TC_HK_TYPE    3
#define TC_PING_TYPE 17

#define TC_FM_SET_PARAMETER_SUBTYPE  1

#define TC_HK_REQ_SUBTYPE  1
#define TM_HK_RESP_SUBTYPE 2

#define TC_PING_REQ_SUBTYPE  1
#define TM_PING_RESP_SUBTYPE 2

typedef enum {
    EPS_APP_ID      = _EPS_APP_ID_,
    COMMS_APP_ID    = _COMMS_APP_ID_,
    OBC_APP_ID      = _OBC_APP_ID_,
    ADCS_APP_ID     = _ADCS_APP_ID_,
    ADB_APP_ID      = _ADB_APP_ID_,
    GND_APP_ID      = _GND_APP_ID_,
    DBG_APP_ID      = _DBG_APP_ID_,
    LAST_APP_ID     = _LAST_APP_ID_
}SBSYS_id;

typedef enum {
    EPS_DEV_ID              =  1,
    COMMS_DEV_ID            =  2,
    ADCS_DEV_ID             =  3,
    OBC_DEV_ID              =  4,
    ADB_DEV_ID              =  5,
    EPS_BUS_DEV_ID          =  6,
    ADB_BUS_DEV_ID          =  7,
    COMMS_BUS_DEV_ID        =  8,
    ADCS_BUS_DEV_ID         =  9,
    OBC_BUS_DEV_ID          = 10,
    EPS_DBG_DEV_ID          = 11,
    COMMS_DBG_DEV_ID        = 12,
    ADCS_DBG_DEV_ID         = 13,
    ADB_DBG_DEV_ID          = 14,
    OBC_DBG_DEV_ID          = 15,
    EPS_OBC_MON_DEV_ID      = 16,
    EPS_COMMS_MON_DEV_ID    = 17,
    EPS_ADCS_MON_DEV_ID     = 18,
    EPS_SU_MON_DEV_ID       = 19,
    EPS_DC_MON_DEV_ID       = 20,
    EPS_UR_MON_DEV_ID       = 21,
    SOL_YP_MON_DEV_ID       = 22,
    SOL_YM_MON_DEV_ID       = 23,
    SOL_XP_MON_DEV_ID       = 24,
    SOL_XM_MON_DEV_ID       = 25,
    SOL_YP_TEMP_DEV_ID      = 26,
    SOL_YM_TEMP_DEV_ID      = 27,
    SOL_XP_TEMP_DEV_ID      = 28,
    SOL_XM_TEMP_DEV_ID      = 29,
    BATT_CHARGE_DEV_ID      = 30,
    EPS_FRAM_DEV_ID         = 31,
    ADB_MON_DEV_ID          = 32,
    ADB_TEMP_DEV_ID         = 33,
    OBC_MON_DEV_ID          = 34,
    OBC_TEMP_DEV_ID         = 35,
    OBC_FRAM_DEV_ID         = 36,
    ADCS_1_MON_DEV_ID       = 37,
    ADCS_2_MON_DEV_ID       = 38,
    ADCS_3_MON_DEV_ID       = 39,
    ADCS_4_MON_DEV_ID       = 40,
    ADCS_TEMP_DEV_ID        = 41,
    ADCS_FRAM_DEV_ID        = 42,
    LAST_DEV_ID             = 43
}dev_id;

typedef enum {
    EPS_INA_OBC_CUR_PAR_ID             =  0,
    EPS_INA_OBC_CUR_ARR_PAR_ID         =  1,
    EPS_INA_OBC_VLT_PAR_ID             =  2,
    EPS_INA_OBC_CUR_MON_HL_PAR_ID      =  3,
    EPS_INA_OBC_CUR_MON_LL_PAR_ID      =  4,
    LAST_PAR_ID                        =  5
}par_id;

typedef enum {
    TEST_VAULT_ID           =  0,
    LAST_VAULT_ID           =  1
}vault_id;

typedef enum {
    TEST_MON_ID             =  0,
    LAST_MON_ID             =  1
}mon_id;

typedef enum {
    P_OFF       = 0,
    P_ON        = 1,
    SET_VAL     = 2,
    LAST_FUN_ID = 3
}FM_fun_id;

typedef enum {
    HEALTH_REP      = 1,
    LAST_STRUCT_ID  = 2
}HK_struct_id;

typedef enum {
    SATR_OK                    = 0,
    SATR_ERROR                 = 1,
    SATR_EOT                   = 2,
    SATR_PKT_INIT              = 3,

    /*LAST*/
    SATR_LAST                  = 3
}SAT_returnState;

#endif
