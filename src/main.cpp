#include <Arduino.h>

/* ===============================================================================

     Termômetro Animado com Display Nextion 7" e Arduino

=============================================================================== */
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
// ===============================================================================
// --- Biblioteca Auxiliar ---
#include "Nextion.h"      //biblioteca Nextion
SoftwareSerial HMISerial(3,4);
#include <EEPROM.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  
// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);
int deviceCount = 0;
float tempC;


// ===============================================================================
// --- Mapeamento de Hardware ---

 
 
// ===============================================================================
// --- Declaração de Objetos ---


// -- Objetos do Nextion --
                     //page id:0, id componente:1, nome do componente: "bt0"

NexNumber at1 = NexNumber(0, 45, "n7");
NexNumber at2 = NexNumber(0, 46, "n8");
NexNumber at3 = NexNumber(0, 47, "n9");
NexNumber at4 = NexNumber(0, 48, "n10");
NexNumber at5 = NexNumber(0, 49, "n11");
NexNumber at6 = NexNumber(0, 50, "n12");
NexNumber at7 = NexNumber(0, 51, "n13");

NexNumber nt1 = NexNumber(0, 37, "n0");
NexNumber nt2 = NexNumber(0, 39, "n1");
NexNumber nt3 = NexNumber(0, 40, "n2");
NexNumber nt4 = NexNumber(0, 41, "n3");
NexNumber nt5 = NexNumber(0, 42, "n4");
NexNumber nt6 = NexNumber(0, 43, "n5");
NexNumber nt7 = NexNumber(0, 44, "n6");

NexPicture p0 = NexPicture(0, 9, "p0");
NexPicture p1 = NexPicture(0, 10, "p1");
NexPicture p2 = NexPicture(0, 11, "p2");
NexPicture p3 = NexPicture(0, 12, "p3");
NexPicture p4 = NexPicture(0, 13, "p4");
NexPicture p5 = NexPicture(0, 14, "p5");
NexPicture p6 = NexPicture(0, 15, "p6");

uint32_t temp1;
uint32_t temp2;
uint32_t temp3;
uint32_t temp4;
uint32_t temp5;
uint32_t temp6;
uint32_t temp7;

float atemp1;
float atemp2;
float atemp3;
float atemp4;
float atemp5;
float atemp6;
float atemp7;

float etemp1;
float etemp2;
float etemp3;
float etemp4;
float etemp5;
float etemp6;
float etemp7;

//NexProgressBar j0 = NexProgressBar(0, 6, "j0");
/*NexText at1  = NexNumber(0, 8, "n1");
NexText txt_umid  = NexText(0, 4, "t2");
NexText txt_temp1  = NexText(1, 16, "t7");
NexText txt_umid1  = NexText(0, 4, "t2");

NexPage page0 = NexPage(0, 0, "page0");
NexPage page1 = NexPage(1, 0, "page1");

*/



// ===============================================================================
// --- Configurações Iniciais ---
void setup()
{
  
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
sensors.begin();  // Start up the library
nexInit();                           //inicializa Nextion lib
EEPROM.get(0, etemp1);
nt1.setValue(etemp1);
EEPROM.get(10, etemp2);
nt2.setValue(etemp2);
EEPROM.get(20, etemp3);
nt3.setValue(etemp3);
EEPROM.get(30, etemp4);
nt4.setValue(etemp4);
EEPROM.get(40, etemp5);
nt5.setValue(etemp5);
EEPROM.get(50, etemp6);
nt6.setValue(etemp6);
EEPROM.get(60, etemp7);
nt7.setValue(etemp7);
/*temp1=etemp1;
temp2=etemp2;
temp3=etemp3;
temp4=etemp4;
temp5=etemp5;
temp6=etemp6;
temp7=etemp7;
*/
dbSerialPrintln("setup done");
dbSerialPrintln(etemp1);
dbSerialPrintln(etemp2);
dbSerialPrintln(etemp3);
dbSerialPrintln(etemp4);
dbSerialPrintln(etemp5);
dbSerialPrintln(etemp6);
dbSerialPrintln(etemp7);

} //end setup
 

// ===============================================================================
// --- Loop Infinito ---
void loop()
{
  sensors.requestTemperatures(); 
//  txt_temp.setText("test");
delay(1000);
dbSerialPrintln("Temp");
delay(300);
atemp1 = sensors.getTempCByIndex(0);
dbSerialPrintln(atemp1);
delay(300);
atemp2 = sensors.getTempCByIndex(1);
dbSerialPrintln(atemp2);
delay(300);
atemp3 = sensors.getTempCByIndex(2);
dbSerialPrintln(atemp3);
delay(300);
atemp4 = sensors.getTempCByIndex(3);
dbSerialPrintln(atemp4);
delay(300);
atemp5 = sensors.getTempCByIndex(4);
dbSerialPrintln(atemp5);
delay(300);
atemp6 = sensors.getTempCByIndex(5);
dbSerialPrintln(atemp6);
delay(300);
atemp7 = sensors.getTempCByIndex(6);
dbSerialPrintln(atemp7);
delay(300);

      at1.setValue(atemp1);
     delay(30);
      at2.setValue(atemp2);
     delay(300);
      at3.setValue(atemp3);
     delay(300);
      at4.setValue(atemp4);
     delay(300);
      at5.setValue(atemp5);
     delay(300);
      at6.setValue(atemp6);
     delay(300);
      at7.setValue(atemp7);

delay(300);
     

if (temp1 != etemp1) {
  etemp1=temp1;
  EEPROM.put(0, etemp1);
}
if (temp2 != etemp2) {
  etemp2=temp2;
  EEPROM.put(10, etemp2);
}
if (temp3 != etemp3) {
  etemp3=temp3;
  EEPROM.put(20, etemp3);
}
if (temp4 != etemp4) {
  etemp4=temp4;
  EEPROM.put(30, etemp4);
}
if (temp5 != etemp5) {
  etemp5=temp5;
  EEPROM.put(40, etemp5);
}
if (temp6 != etemp6) {
etemp6=temp6;
  EEPROM.put(50, etemp6);
}
if (temp7 != etemp7) {
etemp7=temp7;
  EEPROM.put(60, etemp7);
}

nt1.getValue(&temp1);
     delay(500);
      nt2.getValue(&temp2);
     delay(500);
      nt3.getValue(&temp3);
     delay(500);
      nt4.getValue(&temp4);
     delay(500);
      nt5.getValue(&temp5);
     delay(500);
      nt6.getValue(&temp6);
     delay(500);
      nt7.getValue(&temp7);
     delay(500);
     
 //1 
     if ( atemp1 <= temp1)
     {
      digitalWrite(5, LOW);
      p0.setPic(9);
     }
     else
     {
      digitalWrite(5, HIGH);
      p0.setPic(8);
     }
//2
     if ( atemp2 <= temp2)
     {
      digitalWrite(6, LOW);
      p1.setPic(9);
     }
     else
     {
      digitalWrite(6, HIGH);
      p1.setPic(8);
     }
//3
     if (atemp3 <= temp3)
     {
      digitalWrite(7, LOW);
      p2.setPic(9);
     }
     else
     {
      digitalWrite(7, HIGH);
     p2.setPic(8);
     }
//4
     if (atemp4 <= temp4)
     {
      digitalWrite(8, LOW);
      p3.setPic(9);
     }
     else
     {
      digitalWrite(8, HIGH);
     p3.setPic(8);
     }
//5
     if (atemp5 <= temp5)
     {
      digitalWrite(9, LOW);
      p4.setPic(9);
     }
     else
     {
      digitalWrite(9, HIGH);
     p4.setPic(8);
     }
//6
     if (atemp6 <= temp6)
     {
      digitalWrite(10, LOW);
      p5.setPic(9);
     }
     else
     {
      digitalWrite(10, HIGH);
      p5.setPic(8);
     }
//7
     if (atemp7 <= temp7)
     {
      digitalWrite(11, LOW);
      p6.setPic(9);
     }
     else
     {
      digitalWrite(11, HIGH);
      p6.setPic(8); 
     }
  delay(500);
} //end loop

/*
void readTempHumi()
{
  
    //Atualização dos valores do Nextion
    j0.setValue(temp_bar);
    txt_temp.setText(txt1);
    txt_umid.setText(txt2);
    
    j1.setValue(temp_bar);
    txt_temp1.setText(txt3);
    txt_umid1.setText(txt4);
 
    //Lê parâmetros de temperatura e umidade relativa do ar no DHT11
    my_dht.read11(dht_pin);
    temperatura = my_dht.temperature;
    umidade     = my_dht.humidity;
 
    //Converte inteiros para string
    memset(txt1, 0, sizeof(txt1));
    itoa(temperatura, txt1, 10);
    memset(txt2, 0, sizeof(txt2));
    itoa(umidade, txt2, 10);

    memset(txt3, 0, sizeof(txt3));
    itoa(temperatura, txt3, 10);
    memset(txt4, 0, sizeof(txt4));
    itoa(umidade, txt4, 10);
 
    //Normaliza a barra animada de acordo com a temperatura
    temp_bar = map(temperatura, -30, 45, 0, 100);
  
  
} //end readTempHumi

*/


