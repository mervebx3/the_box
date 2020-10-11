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
int Air = 4;
/*****************************************************/
      /*Begin Humidity Variables:*/
/*****************************************************/
// threshold values (Schwellenwerte)
const int dryA0 = 1023;
const int dryA1 = 1023;
const int wetA0 = 0;
const int wetA1 = 0;
// digaital Pin of the lamp
int blueA0 = 13; 
int greenA0 = 12; 
int redA0 = 11;
  
int blueA1 = 10; 
int greenA1 = 9; 
int redA1 = 8;
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
      /*DEVICES LOCATOR FUNCTION
         -> needed here: humidity()*/
/*****************************************************/
void locate(){
  // locate devices on the bus
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount);
  Serial.println(" devices.");
  Serial.println("");
}

/*****************************************************/
      /*MEASURING TEMPERATURE FUNCTION*/
/*****************************************************/
void measureTemp(){ 
  // Send command to all the sensors for temperature conversion
  sensors.requestTemperatures(); 
  // Display temperature from each sensor
  for (int i = 0;  i < deviceCount;  i++)
  {
   
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" : ");
    tempC = sensors.getTempCByIndex(i);
    Serial.print(tempC);
    Serial.println(" C ");
    int temp1= i+1;
      Serial.println(temp1);
    //sensor im Boden  
    if(temp1 == 1){

      if(tempC >= 19 && tempC <= 24){
        Serial.println("Temperature is Good - null-s1");
          digitalWrite(blueTemp, LOW);
          digitalWrite(redTemp, LOW);
      }else if (tempC >=24){
       Serial.print("Too Hot! - s1"); 
          digitalWrite(blueTemp, LOW);
          digitalWrite(redTemp, HIGH);
        }else if (tempC <= 19){
          Serial.print("Too Cold! - s1");
            digitalWrite(redTemp, LOW);
            digitalWrite(blueTemp, HIGH);
          }else{
            Serial.println("Fehler Temperatur - s1");
            }
      //sensor an der lampe 
      }else if (temp1 == 2){

        if(tempC >= 19 && tempC <= 30){
         digitalWrite(Air, LOW);
         digitalWrite(blueTemp, LOW);
         digitalWrite(redTemp, LOW);
      Serial.println("Temperature is Good - eins-s2");
      }else if (tempC >=31){
       Serial.println("Too Hot! - s2"); 
          digitalWrite(Air, HIGH);
          digitalWrite(blueTemp, LOW);
          digitalWrite(redTemp, HIGH);
          delay(1000);
          digitalWrite(redTemp, LOW);
          delay(1000);
          digitalWrite(redTemp, HIGH);
          delay(1000);
        }else if (tempC <= 19){
          Serial.println("Too Cold! -s2");
            digitalWrite(redTemp, LOW);
            digitalWrite(blueTemp, HIGH);
            delay(500); 
            digitalWrite(blueTemp, LOW);
            delay(1000);
            digitalWrite(blueTemp, HIGH);
          }else{
            Serial.println("Fehler Temperatur -s2");
            }
        
        }
  }
  delay(500); 
}

/*****************************************************/
      /*MEASURING TEMPERATURE FUNCTION*/
/*****************************************************/
void humidity() {
  // sensorVal -> to store the "Sensor Value"
  int sensorVal_A0 = (analogRead(A0));
  int sensorVal_A1 = (analogRead(A1));
  //the percentages
  int percentageScale_A0 = map(sensorVal_A0, wetA0, dryA0, 100, 0);
  int percentageScale_A1 = map(sensorVal_A1, wetA1, dryA1, 100, 0);

  Serial.print("A0:   ");
  Serial.print(sensorVal_A0);
  delay(100);
  Serial.print("  A0 Prozentuell:   ");
  Serial.print(percentageScale_A0);
  Serial.println("%");


  Serial.print("A1:   ");

  Serial.print(sensorVal_A1);
  delay(100);
  Serial.print("  A1 Prozentuell:   ");
  Serial.print(percentageScale_A1);// good to know digits
  Serial.println("%");

  delay(1000);

/*THE WATERING LIGHT SWITCH */
  if (sensorVal_A0 <= 340) {
    Serial.println("A0: blau, WET AF!! ");
    digitalWrite(blueA0, HIGH);
    digitalWrite(greenA0, LOW);
    digitalWrite(redA0, LOW);
    digitalWrite(pump, LOW);
  }
  else if ((sensorVal_A0 >= 341) && (sensorVal_A0 <= 681)) {
    Serial.println("A0: grün");
    digitalWrite(blueA0, LOW);
    digitalWrite(greenA0, HIGH);
    digitalWrite(redA0, LOW);
    digitalWrite(pump, LOW);
  }
  else if ((sensorVal_A0 >= 682) && (sensorVal_A0 <= 1023)) {
    Serial.println("A0: rot, DRY!!!");
    digitalWrite(pump, HIGH);
    delay(3000);
    digitalWrite(pump, LOW);
    digitalWrite(blueA0, LOW);
    digitalWrite(greenA0, LOW);
    digitalWrite(redA0, HIGH);
  }else {
    Serial.println("FEHLER");
    return;
  };
/*THE WATERING LIGHT SWITCH */
  if  (sensorVal_A1 <= 340) {
    Serial.println("A1: blau, WET!! ");
    digitalWrite(blueA1, HIGH);
    digitalWrite(greenA1, LOW);
    digitalWrite(redA1, LOW);
    digitalWrite(pump, LOW);
  }
  else if ((sensorVal_A1>= 341)&&(sensorVal_A1 <= 681)) {
    Serial.println("A1: grün");
    digitalWrite(pump, LOW);
    digitalWrite(blueA1, LOW);
    digitalWrite(greenA1, HIGH);
    digitalWrite(redA1, LOW);
  }
  else if ((sensorVal_A1>= 682)&&(sensorVal_A1 <= 1023)) {
    Serial.println("A1: rot, DRY!!!");
    digitalWrite(pump, HIGH);
    delay(3000);
    digitalWrite(pump, LOW);
    digitalWrite(blueA1, LOW);
    digitalWrite(greenA1, LOW);
    digitalWrite(redA1, HIGH);
  }else {
    Serial.println("FEHLER");
    return;
  };
}
