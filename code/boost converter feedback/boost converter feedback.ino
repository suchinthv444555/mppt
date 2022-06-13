// #define F_CPU 8000000
int pwm = 3;
int potinput = A0;
int feedbackinput = A1;
int potinputval;
int feedbackinputval;
int pwmval;

void setup() {
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
  
  pinMode(pwm, OUTPUT);
  pinMode(potinput, INPUT);
  pinMode(feedbackinput, INPUT);
  digitalWrite(pwm, LOW);
  Serial.begin(9600);
  pwmval = 0;
}

void loop() {
  potinputval = analogRead(potinput);
  potinputval = map(potinputval, 1023, 0, 255, 0);
  // Serial.println(potinputval);
  feedbackinputval = analogRead(feedbackinput);
  feedbackinputval = map(feedbackinputval, 1023, 0, 255, 0);
  Serial.println(feedbackinputval);
  while (potinputval > feedbackinputval) {
    if (pwmval == 230) {
      potinputval = analogRead(potinput);
      potinputval = map(potinputval, 1023, 0, 255, 0);
      Serial.println(potinputval);
      feedbackinputval = analogRead(feedbackinput);
      feedbackinputval = map(feedbackinputval, 1023, 0, 255, 0);
      Serial.println(feedbackinputval);
    }
    else {
      pwmval = pwmval + 1;
      analogWrite(pwm, pwmval);
      potinputval = analogRead(potinput);
      
      potinputval = map(potinputval, 1023, 0, 255, 0);
      Serial.println(potinputval);
      feedbackinputval = analogRead(feedbackinput);
      feedbackinputval = map(feedbackinputval, 1023, 0, 255, 0);
      Serial.println(feedbackinputval);
    }
  }
  while (potinputval < feedbackinputval) {
    if (pwmval == 0) {
      potinputval = analogRead(potinput);
      potinputval = map(potinputval, 1023, 0, 255, 0);
      Serial.println(potinputval);
      feedbackinputval = analogRead(feedbackinput);
      feedbackinputval = map(feedbackinputval, 1023, 0, 255, 0);
      Serial.println(feedbackinputval);
    }
    else {
      pwmval = pwmval - 1;
      analogWrite(pwm, pwmval);
      potinputval = analogRead(potinput);
      potinputval = map(potinputval, 1023, 0, 255, 0);
      Serial.println(potinputval);
      feedbackinputval = analogRead(feedbackinput);
      feedbackinputval = map(feedbackinputval, 1023, 0, 255, 0);
      Serial.println(feedbackinputval);
    }
  }
}
