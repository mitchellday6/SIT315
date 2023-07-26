// C++ code
//
int sensorValue = 0;
int GREEN_LIGHT = 12;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(GREEN_LIGHT, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(A0);
  Serial.println("Attentutor Input: "+sensorValue);
  if(sensorValue == 1023){
    Serial.println("Attentutor Max");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // turn the LED on
    Serial.println("Light Delay: "+1024-sensorValue);
    digitalWrite(GREEN_LIGHT, HIGH);
    // pause the program for <sensorValue> millseconds
    delay(1024- sensorValue); // Wait for sensorValue millisecond(s)
    // turn the LED off
    digitalWrite(GREEN_LIGHT, LOW);
    // pause the program for <sensorValue> millseconds
    delay(sensorValue); // Wait for sensorValue millisecond(s)
  }
}
