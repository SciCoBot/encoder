
volatile unsigned short int _pulses; 
unsigned long prevTime = 0;
unsigned long nowTime = 0;

void incrementPulses()
{
  _pulses = _pulses + 1;
}

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(8), incrementPulses, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  


  nowTime = micros();
  if((nowTime - prevTime) > 10000000) //dez segundo
  {
    detachInterrupt(digitalPinToInterrupt(8));
    Serial.print("Pulsos = ");
    Serial.println(_pulses);
    _pulses = 0;

    prevTime = nowTime;
    attachInterrupt(digitalPinToInterrupt(8), incrementPulses, FALLING);
  }
  
}
