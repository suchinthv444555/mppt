 int current = A2;
  int voltage = A0;
  int batvolt =A1;
  int batcurr=A3;
  int pwm = 3;
  int r1=11000,r2=2200;
  float input_voltage=0,temp=0,power=0,powernew;
  int duty=155;

void setup() {
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
  
 pinMode(pwm, OUTPUT);
  Serial.begin(9600);
 pinMode(current,INPUT);
 pinMode(voltage,INPUT);
 pinMode(batvolt,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
unsigned int x=0;
float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;
AcsValue = analogRead(current);     
AcsValueF = (2.5 - (AcsValue * (5.0 / 1024.0)) )/0.185;
AcsValueF=pow(pow(AcsValueF+.5,2),.5);

int analog_value = analogRead(voltage);     
temp = (analog_value * 5.0) / 1024.0;   
input_voltage = temp /0.166; 
power=current*input_voltage;

// Serial.print(AcsValueF);
// Serial.print("  :  ");
// Serial.print(input_voltage);
// Serial.print("  :  ");
// Serial.println(power);

analogWrite(3,pwm);
while(true){

AcsValue = analogRead(current);     
AcsValueF = (2.5 - (AcsValue * (5.0 / 1024.0)) )/0.185;
AcsValueF=pow(pow(AcsValueF+.5,2),.5);

analog_value = analogRead(voltage);     
temp = (analog_value * 5.0) / 1024.0;   
input_voltage = temp /0.166; 
powernew=(AcsValueF*input_voltage);
Serial.print(AcsValueF);
Serial.print("  :  ");
Serial.print(input_voltage);
Serial.print("  :  ");
Serial.println(powernew);

if (powernew>power){
  duty++;
  analogWrite(3,duty);
  power=powernew;
}
else{
  duty--;
  analogWrite(3,duty);
  power=powernew;

}
}

}
