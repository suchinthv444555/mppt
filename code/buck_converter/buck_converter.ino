int pot =A0;
int feedback=A1;
int pwm =3;
int duty=0;

void setup() {


TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
pinMode(pwm,OUTPUT);
pinMode(pot,INPUT);
Serial.begin(9600);

// put your setup code here, to run once:

}

void loop() {
  int voltage = analogRead(pot);
  int volt= map(voltage,0,1023,0,255);
  
analogWrite(pwm,125);
// put your main code here, to run repeatedly:


}