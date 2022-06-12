int pot =A0;
int feedback=A1;
int pwm =3;
int duty=0;

void setup() {


TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
pinMode(pwm,OUTPUT);
pinMode(feedback,INPUT);
pinMode(pot,INPUT);
Serial.begin(9600);

// put your setup code here, to run once:

}

void loop() {
  int voltage = analogRead(pot);
  int volt= map(voltage,0,1023,0,255);
  voltage =map(voltage,0,1023,0,15);
  Serial.print("voltage:");
  Serial.println(voltage);
  
  int output = analogRead(feedback);
  output=map(output,0,1023,0,15);
  Serial.print("output:");
  Serial.println(output);
  if (voltage>output)
  {
    duty= duty+1;
    duty =constrain(duty,1,254);
  }
   if (voltage<output)
  {
    duty= duty-1;
    duty =constrain(duty,1,254);
  }

  // duty=map(duty,0,1023,0,255);
    Serial.print("duty:");
  Serial.println(duty);

analogWrite(pwm,duty);
// put your main code here, to run repeatedly:


}