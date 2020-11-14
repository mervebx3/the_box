/*****************************************************/
/*DEVICES LOCATOR FUNCTION
   -> needed here: humidity()*/
/*****************************************************/
void locate() {
  // locate devices on the bus
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount);
  Serial.println(" devices.");
  Serial.println("");
}
/*****************************************************/
/*MEASURING TEMPERATURE FUNCTION*/
/*****************************************************/
void measureTemp() {
  // Send command to all the sensors for temperature conversion
  sensors.requestTemperatures();
  // Display temperature from each sensor
  for (int i = 0;  i < deviceCount;  i++)
  {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" : ");
    tempC = sensors.getTempCByIndex(i);
    Serial.print(tempC);
    Serial.println(" C ");
    int temp1 = i + 1;

    //sensor oben
    if (temp1 == 1) {
      if (tempC >= 19 && tempC <= 31) {
        Serial.println("Temperature is Good - null-s1");
        digitalWrite(Air, LOW);
        digitalWrite(blueTemp, LOW);
        digitalWrite(redTemp, LOW);
      } else if (tempC >= 31) {
        Serial.println("Too Hot! - s1");
        digitalWrite(Air, HIGH);
        digitalWrite(blueTemp, LOW);
        digitalWrite(redTemp, HIGH);
      } else if (tempC <= 19) {
        Serial.println("Too Cold! - s1");
        digitalWrite(Air, LOW);
        digitalWrite(redTemp, LOW);
        digitalWrite(blueTemp, HIGH);
      } else {
        Serial.println("Fehler Temperatur - s1");
      }
      //sensor am boden
    } else if (temp1 == 2) {

      if (tempC >= 19 && tempC <= 24) {
        digitalWrite(blueTemp, LOW);
        digitalWrite(redTemp, LOW);
        Serial.println("Temperature is Good - eins-s2");
      } else if (tempC >= 24) {
        Serial.println("Too Hot! - s2");
        digitalWrite(blueTemp, LOW);
        digitalWrite(redTemp, HIGH);
        delay(1000);
        digitalWrite(redTemp, LOW);
        delay(1000);
        digitalWrite(redTemp, HIGH);
        delay(1000);
      } else if (tempC <= 19) {
        Serial.println("Too Cold! -s2");
        digitalWrite(redTemp, LOW);
        digitalWrite(blueTemp, HIGH);
        delay(500);
        digitalWrite(blueTemp, LOW);
        delay(1000);
        digitalWrite(blueTemp, HIGH);
        delay(1000);
      } else {
        Serial.println("Fehler Temperatur -s2");
      }
    }
  }
  delay(500);
}
