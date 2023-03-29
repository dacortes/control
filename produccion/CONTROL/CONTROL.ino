#include "Nextion.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Sodaq_DS3231.h> 
//DateTime dt(2021, 7, 29,  19, 11, 30, 0);//Configurar :año- mes- dia- hora- minutos- segundo
#define ledAuto 12
//Bombas 
#define BLechugas 10
#define BTomate 11
#define Rele 8
#define Rele2 9
//Ventiladores
#define Vent1 2
#define Vent2 3
//Sensores
#define STemperatureD 7
#define STemperatureA A7
OneWire comuniacion(STemperatureD);
DallasTemperature ds18b20(&comuniacion);
unsigned long tiempoX=0;
int SENSOR;
bool Estado;
NexDSButton bAuto  = NexDSButton(0, 1, "bAuto"); 
NexDSButton Bomba1 = NexDSButton(0, 2, "Bomba1"); 
NexDSButton Bomba2 = NexDSButton(0, 3, "Bomba2");
//Sensores
NexNumber nArdu   = NexNumber (0, 12, "nArdu");
NexNumber nInver   = NexNumber (0, 12, "nInver");
//Bar temp
NexProgressBar tArdu  = NexProgressBar(0, 4, "tArdu");
NexProgressBar tInver = NexProgressBar(0, 5, "tInver");
//Fecha
NexNumber nday    = NexNumber (0, 14, "nday");
NexNumber nmonth  = NexNumber (0, 15, "nmonth");
NexNumber nYear   = NexNumber (0, 16, "nYear");
//Hora
NexNumber nHr   = NexNumber (0, 17, "nHr");
NexNumber nMn   = NexNumber (0, 18, "nMn");
NexNumber nSg   = NexNumber (0, 19, "nSg");
NexTouch *nex_listen_list[] =
{
  &bAuto,
  &Bomba1,
  &Bomba2,
  NULL
};
void setup() {
  rtc.begin();
  nexInit();
  Serial.begin(9600);
  //rtc.setDateTime(dt);
  ds18b20.begin();
  pinMode(BLechugas,OUTPUT);
  pinMode(BTomate,OUTPUT);
  pinMode(Rele,OUTPUT);
  pinMode(Rele2,OUTPUT);
  pinMode(Vent1,OUTPUT);
  pinMode(Vent2,OUTPUT);
  pinMode(ledAuto,OUTPUT);
  pinMode(STemperatureA,INPUT);
  pinMode(STemperatureD,INPUT);
  digitalWrite(Vent1,LOW);
  digitalWrite(Vent2,LOW);
  digitalWrite(BLechugas,HIGH);
  digitalWrite(BTomate,HIGH);
  digitalWrite(Rele,HIGH);
  digitalWrite(Rele2,HIGH);
  Bomba1.attachPop(LechugasOn_Off);
  Bomba2.attachPop(TomatesOn_Off);
  bAuto.attachPop(Automatico);
}
void loop() {
tiempoX= millis();
imprimeNextion ();
Fecha_Hora();
imprimeTemp_digital();
Automatico();
TomatesOn_Off();
LechugasOn_Off();
if(Estado == 1){
Riego();
}
if(tiempoX==1000){
nexLoop(nex_listen_list);
}
}
  
void imprimeNextion () {
  
 int temperatura = 0;
 int t = 0;
 temperatura = analogRead(STemperatureA);//ds18b20.getTempCByIndex(0); //obtener temperatura
 t=((temperatura*5000.0) ) / 1023/ 10;
 nArdu.setValue(t);
 tArdu.setValue(t);
 Serial.print(temperatura+"    la T");
 if(t>=26 && t<=70){
  digitalWrite(Vent1,HIGH);
  digitalWrite(Vent2,HIGH);
  }else{
  digitalWrite(Vent1,LOW);
  digitalWrite(Vent2,LOW);
  }
}
void imprimeTemp_digital(){
  int temperatura =0;
  ds18b20.requestTemperatures();
  temperatura = ds18b20.getTempCByIndex(0); //obtener temperatura
  nInver.setValue(temperatura);
  tInver.setValue(temperatura);
  }
  
void Fecha_Hora(){
  DateTime now = rtc.now();
  int dia     =now.date();
  int mes     =now.month();
  int Year    =now.year();
  int hora    =now.hour();
  int minuto  =now.minute();
  int segundo = now.second();
  nday.setValue(dia);
  nmonth.setValue(mes);
  nYear.setValue(Year);
  nHr.setValue(hora);
  nMn.setValue(minuto);
  nSg.setValue(segundo);
  }
void Automatico(){
  uint32_t Auto;
  bAuto.getValue(&Auto);
  switch(Auto){
  case HIGH:
   digitalWrite(ledAuto,HIGH);
  Estado = 1;
  break;
  case LOW:
  digitalWrite(ledAuto,LOW);
  Estado = 0;
  break;
    }   
}
void Riego(){
  DateTime now = rtc.now();
  int hora    =now.hour();
  int minuto  =now.minute();
  int segundo = now.second();

    switch(hora){
  //Rele 1 para lechugas y Rele2 para tomates
  case 6:
  if(minuto>=0 && minuto<=10){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);}
  if(minuto>=15 && minuto<=22){
  digitalWrite(BTomate,LOW);
  }
  else{
  digitalWrite(BTomate,HIGH);
  }
  break;
  case 8:
  if(minuto>=0 && minuto<=10){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  case 9:
  if(minuto>=0 && minuto<=10){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  case 10:
  if(minuto>=0 && minuto<=10){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
 //Evento doble encendido de bomba lechugas
  case 11:
  if(minuto>=0 && minuto<=5){
  digitalWrite(BLechugas,LOW);
  }else if(minuto>=30 && minuto<=35){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
 //Evento doble encendido de bomba lechugas y prendido de bomba tomate
  case 12:
  if(minuto>=0 && minuto<=8){
    digitalWrite(BLechugas,LOW);
    digitalWrite(BTomate,LOW);
  }else if (minuto>=30 && minuto<=35){
    digitalWrite(BLechugas,LOW);
    }
 
  else{
  digitalWrite(BLechugas,HIGH);
  digitalWrite(BTomate,HIGH);
  }
  break;
  case 13:
  if(minuto>=0 && minuto<11){
  digitalWrite(BLechugas,LOW);
  }else if(minuto>=30 && minuto<41){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  case 14:
  if(minuto>=0 && minuto<11){
  digitalWrite(BLechugas,LOW);
  }else if(minuto>=30 && minuto<41){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  case 15:
  if(minuto>=0 && minuto<11){
  digitalWrite(BLechugas,LOW);
  }else if(minuto>=30 && minuto<41){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  case 16:
  if(minuto>=0 && minuto<=10){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  case 17:
  if(minuto>=0 && minuto<=10){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  //Bomba de tomates on ultimo riego 
  case 18:
  if(minuto>=0 && minuto<8){
  digitalWrite(BTomate,LOW);}
  else{
  digitalWrite(BTomate,HIGH);
  }
  break;
  case 20:
  if(minuto>=0 && minuto<=10){
  digitalWrite(BLechugas,LOW);
  }
  else{
  digitalWrite(BLechugas,HIGH);
  }
  break;
  default:
   digitalWrite(BTomate,HIGH);
   digitalWrite(BLechugas,HIGH);
 }
}

void LechugasOn_Off(){
  uint32_t estadoBlechuga;
  Bomba1.getValue(&estadoBlechuga);
  if (estadoBlechuga == HIGH){
    digitalWrite(BLechugas,LOW);
    }else{
    digitalWrite(BLechugas,HIGH);
      }
      }
void TomatesOn_Off(){
  uint32_t estadoBtomates;
  Bomba2.getValue(&estadoBtomates);
  if (estadoBtomates == HIGH){
    digitalWrite(BTomate,LOW);
    }else{
    digitalWrite(BTomate,HIGH);
      }
      }
