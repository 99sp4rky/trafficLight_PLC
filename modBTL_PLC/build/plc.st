TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM traffic
  VAR
    pedestrianButton AT %IX0.0 : BOOL;
    systemButton0 AT %IX0.1 : BOOL;
    pR AT %QX0.4 : BOOL;
    pY AT %QX0.3 : BOOL;
    pG AT %QX0.2 : BOOL;
    cR AT %QX0.7 : BOOL;
    cY AT %QX0.6 : BOOL;
    cG AT %QX0.5 : BOOL;
  END_VAR
  VAR
    TOF0 : TOF;
    SR0 : SR;
    TOF1 : TOF;
    TOF3 : TOF;
    TOF2 : TOF;
    TOF5 : TOF;
    TOF6 : TOF;
    R_TRIG1 : R_TRIG;
    F_TRIG1 : F_TRIG;
    _TMP_OR48_OUT : BOOL;
    F_TRIG2 : F_TRIG;
    F_TRIG3 : F_TRIG;
    R_TRIG2 : R_TRIG;
    F_TRIG4 : F_TRIG;
    R_TRIG3 : R_TRIG;
    _TMP_AND39_OUT : BOOL;
    F_TRIG5 : F_TRIG;
    F_TRIG6 : F_TRIG;
  END_VAR

  R_TRIG1(CLK := systemButton0);
  F_TRIG1(CLK := cR);
  _TMP_OR48_OUT := OR(R_TRIG1.Q, F_TRIG1.Q);
  TOF2(EN := TRUE, IN := _TMP_OR48_OUT, PT := T#3s);
  cG := TOF2.Q;
  F_TRIG2(CLK := cG);
  TOF5(EN := TRUE, IN := F_TRIG2.Q, PT := T#1s);
  cY := TOF5.Q;
  F_TRIG3(CLK := cY);
  TOF6(EN := TRUE, IN := F_TRIG3.Q, PT := T#5s);
  cR := TOF6.Q;
  R_TRIG2(CLK := pedestrianButton);
  F_TRIG4(CLK := pR);
  SR0(S1 := R_TRIG2.Q, R := F_TRIG4.Q);
  R_TRIG3(CLK := cR);
  _TMP_AND39_OUT := AND(SR0.Q1, R_TRIG3.Q);
  TOF0(EN := TRUE, IN := _TMP_AND39_OUT, PT := T#3s);
  pG := TOF0.Q;
  F_TRIG5(CLK := pG);
  TOF1(EN := TRUE, IN := F_TRIG5.Q, PT := T#2s);
  pY := TOF1.Q;
  F_TRIG6(CLK := pY);
  TOF3(EN := TRUE, IN := F_TRIG6.Q, PT := T#4s);
  pR := TOF3.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : traffic;
  END_RESOURCE
END_CONFIGURATION
