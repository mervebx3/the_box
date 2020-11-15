/*****************************************************/
/*MEASURING TEMPERATURE FUNCTION*/
/*****************************************************/
void humidity() {
  // sensorVal -> to store the "Sensor Value"
  int sensorVal_A0 = (analogRead(A0));
  int sensorVal_A1 = (analogRead(A1));
  int sensorVal_A2 = (analogRead(A2));
  //the percentages
  int percentageScale_A0 = map(sensorVal_A0, wetA0, dryA0, 100, 0);
  int percentageScale_A1 = map(sensorVal_A1, wetA1, dryA1, 100, 0);
  int percentageScale_A2 = map(sensorVal_A2, wetA2, dryA2, 100, 0);


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

  Serial.print("A2:   ");
  Serial.print(sensorVal_A2);
  delay(100);
  Serial.print("  A2 Prozentuell:   ");
  Serial.print(percentageScale_A2);// good to know digits
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
  
  /*THE WATERING LIGHT SWITCH A2*/
  if (sensorVal_A2 <= 340) {
    Serial.println("A2: blau, WET AF!! ");
    digitalWrite(blueA2, HIGH);
    digitalWrite(greenA2, LOW);
    digitalWrite(redA2, LOW);
    digitalWrite(pump, LOW);
  }
  else if ((sensorVal_A2 >= 341) && (sensorVal_A2 <= 681)) {
    Serial.println("A2: grün");
    digitalWrite(blueA2, LOW);
    digitalWrite(greenA2, HIGH);
    digitalWrite(redA2, LOW);
    digitalWrite(pump, LOW);
  }
  else if ((sensorVal_A2 >= 682) && (sensorVal_A2 <= 1023)) {
    Serial.println("A2: rot, DRY!!!");
    digitalWrite(pump, HIGH);
    delay(3000);
    digitalWrite(pump, LOW);
    digitalWrite(blueA2, LOW);
    digitalWrite(greenA2, LOW);
    digitalWrite(redA2, HIGH);
  } else {
    Serial.println("FEHLER");
    return;
  };
}
