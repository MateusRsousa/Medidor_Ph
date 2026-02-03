#include "SensorPh.h"


SensorPh::SensorPh() : Ph(0) {}


float SensorPh::getValue() {

  int measure = 0 ;

  for(int i=0 ; i<10 ; i++){
  measure = measure + analogRead(34);
}
   
  float mediameasure = measure/10;
  double voltage = 3.3 / 4095 * mediameasure; //classic digital to voltage conversion
  double voltageDivisor = voltage *3/2;
  float offset = -0.9; // Ajuste para calibrar o pH 
  float Po = 7 + ((2.5 - voltageDivisor) / 0.18) + offset;
  Ph=Po;

  if(Ph<0){

    Ph= Ph*(-1);
  }
  
  return round(Ph * 10) / 10.0;
}

