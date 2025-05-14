void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void TRAFFIC_init__(TRAFFIC *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_0,data__->PEDESTRIANBUTTON,retain)
  __INIT_LOCATED_VALUE(data__->PEDESTRIANBUTTON,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1,data__->SYSTEMBUTTON0,retain)
  __INIT_LOCATED_VALUE(data__->SYSTEMBUTTON0,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->PR,retain)
  __INIT_LOCATED_VALUE(data__->PR,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_3,data__->PY,retain)
  __INIT_LOCATED_VALUE(data__->PY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->PG,retain)
  __INIT_LOCATED_VALUE(data__->PG,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_7,data__->CR,retain)
  __INIT_LOCATED_VALUE(data__->CR,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_6,data__->CY,retain)
  __INIT_LOCATED_VALUE(data__->CY,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_5,data__->CG,retain)
  __INIT_LOCATED_VALUE(data__->CG,__BOOL_LITERAL(FALSE))
  TOF_init__(&data__->TOF0,retain);
  SR_init__(&data__->SR0,retain);
  TOF_init__(&data__->TOF1,retain);
  TOF_init__(&data__->TOF3,retain);
  TOF_init__(&data__->TOF2,retain);
  TOF_init__(&data__->TOF5,retain);
  TOF_init__(&data__->TOF6,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  __INIT_VAR(data__->_TMP_OR48_OUT,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG2,retain);
  F_TRIG_init__(&data__->F_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  F_TRIG_init__(&data__->F_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->_TMP_AND39_OUT,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG5,retain);
  F_TRIG_init__(&data__->F_TRIG6,retain);
}

// Code part
void TRAFFIC_body__(TRAFFIC *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_LOCATED(data__->SYSTEMBUTTON0,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_LOCATED(data__->CR,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->,_TMP_OR48_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,),
    (BOOL)__GET_VAR(data__->F_TRIG1.Q,)));
  __SET_VAR(data__->TOF2.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TOF2.,IN,,__GET_VAR(data__->_TMP_OR48_OUT,));
  __SET_VAR(data__->TOF2.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TOF_body__(&data__->TOF2);
  __SET_LOCATED(data__->,CG,,__GET_VAR(data__->TOF2.Q,));
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_LOCATED(data__->CG,));
  F_TRIG_body__(&data__->F_TRIG2);
  __SET_VAR(data__->TOF5.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TOF5.,IN,,__GET_VAR(data__->F_TRIG2.Q,));
  __SET_VAR(data__->TOF5.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF5);
  __SET_LOCATED(data__->,CY,,__GET_VAR(data__->TOF5.Q,));
  __SET_VAR(data__->F_TRIG3.,CLK,,__GET_LOCATED(data__->CY,));
  F_TRIG_body__(&data__->F_TRIG3);
  __SET_VAR(data__->TOF6.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TOF6.,IN,,__GET_VAR(data__->F_TRIG3.Q,));
  __SET_VAR(data__->TOF6.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TOF_body__(&data__->TOF6);
  __SET_LOCATED(data__->,CR,,__GET_VAR(data__->TOF6.Q,));
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_LOCATED(data__->PEDESTRIANBUTTON,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->F_TRIG4.,CLK,,__GET_LOCATED(data__->PR,));
  F_TRIG_body__(&data__->F_TRIG4);
  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->F_TRIG4.Q,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_LOCATED(data__->CR,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->,_TMP_AND39_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR0.Q1,),
    (BOOL)__GET_VAR(data__->R_TRIG3.Q,)));
  __SET_VAR(data__->TOF0.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->_TMP_AND39_OUT,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_LOCATED(data__->,PG,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->F_TRIG5.,CLK,,__GET_LOCATED(data__->PG,));
  F_TRIG_body__(&data__->F_TRIG5);
  __SET_VAR(data__->TOF1.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TOF1.,IN,,__GET_VAR(data__->F_TRIG5.Q,));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_LOCATED(data__->,PY,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->F_TRIG6.,CLK,,__GET_LOCATED(data__->PY,));
  F_TRIG_body__(&data__->F_TRIG6);
  __SET_VAR(data__->TOF3.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TOF3.,IN,,__GET_VAR(data__->F_TRIG6.Q,));
  __SET_VAR(data__->TOF3.,PT,,__time_to_timespec(1, 0, 4, 0, 0, 0));
  TOF_body__(&data__->TOF3);
  __SET_LOCATED(data__->,PR,,__GET_VAR(data__->TOF3.Q,));

  goto __end;

__end:
  return;
} // TRAFFIC_body__() 





