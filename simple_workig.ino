int  LedBuiltInReadVal  = 0; // variable to store the read value
int  inputSerialChar    = 0; // for incoming serial data

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
  if(Serial.available() > 0)
  {
    LedBuiltInReadVal = digitalRead(LED_BUILTIN);
    inputSerialChar   = Serial.read();

    if (inputSerialChar == '1')
    {
      if(LedBuiltInReadVal != HIGH)
      {
        // turn the LED on (HIGH is the voltage level)
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("### LED ON");
      }
      else
      {
        Serial.println("*** LED ALREADY ON");
      }
    }
    else if (inputSerialChar == '0')
    {
      if(LedBuiltInReadVal != LOW)
      {
        // turn the LED off by making the voltage LOW
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("$$$ LED OFF");
      }
      else
      {
        Serial.println("*** LED ALREADY OFF");
      }
    }
    else
    {
      Serial.println("!!!!!!!! Press one of the \"0\" or \"1\" keys !!!!!!!!");
    }
  }
  delay(100); // wait for a little time
}
