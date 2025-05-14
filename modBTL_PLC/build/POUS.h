#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM TRAFFIC
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(BOOL,PEDESTRIANBUTTON)
  __DECLARE_LOCATED(BOOL,SYSTEMBUTTON0)
  __DECLARE_LOCATED(BOOL,PR)
  __DECLARE_LOCATED(BOOL,PY)
  __DECLARE_LOCATED(BOOL,PG)
  __DECLARE_LOCATED(BOOL,CR)
  __DECLARE_LOCATED(BOOL,CY)
  __DECLARE_LOCATED(BOOL,CG)
  TOF TOF0;
  SR SR0;
  TOF TOF1;
  TOF TOF3;
  TOF TOF2;
  TOF TOF5;
  TOF TOF6;
  R_TRIG R_TRIG1;
  F_TRIG F_TRIG1;
  __DECLARE_VAR(BOOL,_TMP_OR48_OUT)
  F_TRIG F_TRIG2;
  F_TRIG F_TRIG3;
  R_TRIG R_TRIG2;
  F_TRIG F_TRIG4;
  R_TRIG R_TRIG3;
  __DECLARE_VAR(BOOL,_TMP_AND39_OUT)
  F_TRIG F_TRIG5;
  F_TRIG F_TRIG6;

} TRAFFIC;

void TRAFFIC_init__(TRAFFIC *data__, BOOL retain);
// Code part
void TRAFFIC_body__(TRAFFIC *data__);
#endif //__POUS_H
