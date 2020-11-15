/*****************************************************/
/*Begib of Tempereature Variables:*/
/*****************************************************/

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int deviceCount = 0;
float tempC;
int blueTemp = 6;
int redTemp = 5;
//digital pin of the air fan
int Air = 4;
/*****************************************************/
/*Begin Humidity Variables:*/
/*****************************************************/
// threshold values (Schwellenwerte)
const int dryA0 = 1023;
const int dryA1 = 1023;
const int dryA2 = 1023;
const int wetA0 = 0;
const int wetA1 = 0;
const int wetA2 = 0;
// digaital Pin of the lamp
int blueA0 = 13;
int greenA0 = 12;
int redA0 = 11;

int blueA1 = 10;
int greenA1 = 9;
int redA1 = 8;

int blueA2 = A3;
int greenA2 = A4;
int redA2 = A5;


//digital pin of the pump
int pump = 3;
/*****************************************************/
/*SETUP FUNCTION*/
/*****************************************************/
void setup() {
  sensors.begin();
  Serial.begin(9600);
  locate();
  pinMode(blueTemp, OUTPUT);
  pinMode(redTemp, OUTPUT);
  pinMode(Air, OUTPUT);

  pinMode(blueA0, OUTPUT);
  pinMode(greenA0, OUTPUT);
  pinMode(redA0, OUTPUT);

  pinMode(blueA1, OUTPUT);
  pinMode(greenA1, OUTPUT);
  pinMode(redA1, OUTPUT);

  pinMode(blueA2, OUTPUT);
  pinMode(greenA2, OUTPUT);
  pinMode(redA2, OUTPUT);

  pinMode(pump, OUTPUT);
}

/*****************************************************/
/*LOOP FUNCTION*/
/*****************************************************/
void loop() {
  Serial.println("TEMPERATUR");
  measureTemp();
  Serial.println("--------------");

  Serial.println("HUMIDITY");
  humidity();

  delay(1500);
}


/*****************************************************/
/*MEASURING TEMPERATURE FUNCTION*/
/*****************************************************/
