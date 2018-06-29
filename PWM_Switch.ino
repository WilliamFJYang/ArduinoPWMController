int outPin_500us = 8;                  // digital pin 8
int outPin_333us = 7;
int outPin_100us = 4;
int inPut_analog = 2;
int val=0;
int counter=0;
int Duty_Time[3] = {480,320,100};
int Low_Pos = 16666; 
void setup()
{
  pinMode(outPin_500us, OUTPUT);      // sets the digital pin as output
  pinMode(outPin_333us, OUTPUT);
  pinMode(outPin_100us, OUTPUT);
  pinMode(inPut_analog, INPUT);
  //              Serial.begin(9600);
}

void loop()
{  
  val = digitalRead(inPut_analog);
  //Serial.print(val);
  //Serial.print("\r\n");
  if(val == HIGH) {
    counter ++;
    delay(3000);
  }
  else{
    counter = counter;
  }
  
  switch(counter%3)
  {
    case 0:
      //Serial.print("case 0\r\n");
      digitalWrite(outPin_100us, LOW);
      digitalWrite(outPin_333us, LOW);
      digitalWrite(outPin_500us, HIGH);   // sets the pin on
      delayMicroseconds(Duty_Time[0]);
      digitalWrite(outPin_500us, LOW);    
      delayMicroseconds(Low_Pos-Duty_Time[0]);  
      break;
    case 1:
      //Serial.print("case 1\r\n");
      digitalWrite(outPin_100us, LOW);
      digitalWrite(outPin_500us, LOW);
      digitalWrite(outPin_333us, HIGH);   // sets the pin on
      delayMicroseconds(Duty_Time[1]); 
      digitalWrite(outPin_333us, LOW);    
      delayMicroseconds(Low_Pos-Duty_Time[1]);
      break; 
    case 2:
      //Serial.print("case 2\r\n");
      digitalWrite(outPin_333us, LOW);
      digitalWrite(outPin_500us, LOW);  
      digitalWrite(outPin_100us, HIGH);   // sets the pin on
      delayMicroseconds(Duty_Time[2]); 
      digitalWrite(outPin_100us, LOW);    
      delay(17); 
      break;   
    default : 
      digitalWrite(outPin_100us, LOW);  
      digitalWrite(outPin_333us, LOW);
      digitalWrite(outPin_500us, LOW);
  }
}
