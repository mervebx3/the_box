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

  /*THE WATERING LIGHT SWITCH A0*/
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
  } else {
    Serial.println("FEHLER");
    return;
  };
  /*THE WATERING LIGHT SWITCH A1*/
  if  (sensorVal_A1 <= 340) {
    Serial.println("A1: blau, WET!! ");
    digitalWrite(blueA1, HIGH);
    digitalWrite(greenA1, LOW);
    digitalWrite(redA1, LOW);
    digitalWrite(pump, LOW);
  }
  else if ((sensorVal_A1 >= 341) && (sensorVal_A1 <= 681)) {
    Serial.println("A1: grün");
    digitalWrite(pump, LOW);
    digitalWrite(blueA1, LOW);
    digitalWrite(greenA1, HIGH);
    digitalWrite(redA1, LOW);
  }
  else if ((sensorVal_A1 >= 682) && (sensorVal_A1 <= 1023)) {
    Serial.println("A1: rot, DRY!!!");
    digitalWrite(pump, HIGH);
    delay(3000);
    digitalWrite(pump, LOW);
    digitalWrite(blueA1, LOW);
    digitalWrite(greenA1, LOW);
    digitalWrite(redA1, HIGH);
  } else {
    Serial.println("FEHLER");
    return;
  };
}
