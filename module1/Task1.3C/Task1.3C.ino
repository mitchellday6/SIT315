// C++ code
//
int sensorValue = 0;
int GREEN_LIGHT = 8;
int interruptPin = 2;
bool isStopped = false;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(GREEN_LIGHT, OUTPUT);
  pinMode(interruptPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interruptPin), changeLedState, CHANGE); 
}

void loop()
{
  //check if the interrupt is true
  if(!isStopped){
    sensorValue = analogRead(A0);
    Serial.print("Attentutor Input: ");
    Serial.println(sensorValue);
    
    // turn the LED on
    Serial.print("Light Delay: ");
    Serial.println(1024-sensorValue);
    digitalWrite(GREEN_LIGHT, HIGH);
    // pause the program for inverse <sensorValue> millseconds
    delay(1024- sensorValue); // Wait for sensorValue millisecond(s)
    // turn the LED off
    digitalWrite(GREEN_LIGHT, LOW);
    // pause the program for inverse <sensorValue> millseconds
    delay(1024-sensorValue); // Wait for sensorValue millisecond(s)
  }
}
                  
void changeLedState(){
  if(isStopped){
    isStopped = !isStopped;
    Serial.println("Lets Continue");
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    isStopped = !isStopped;
    Serial.println("HALT");
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
