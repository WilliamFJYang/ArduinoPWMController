int Signal_1 = 8;                 // output Pin setting
int Signal_2 = 7;
float PWM_fequency  = 60;         // Setting output signal fequency(MAX=100K Hz)
int Timing   = 200;               // purse timing(us)
float Dutycycle_1   = 3.0;        // Setting Duty Cycle
float Dutycycle_2  = 2.0;
int period_us=0
void setup()
{
  pinMode(Signal_1, OUTPUT);      // Initial Program
  pinMode(Signal_2, OUTPUT);
  digitalWrite(Signal_1, LOW);
  digitalWrite(Signal_2, LOW);
}

void loop()
{    
      if(Timing>0){
        if(Dutycycle_1>Dutycycle_2){
          digitalWrite(Signal_2, HIGH);
          delayMicroseconds(500);
           digitalWrite(Signal_2, LOW);
           delayMicroseconds(2500);
          digitalWrite(Signal_1, HIGH); 
          digitalWrite(Signal_2, LOW);
          delayMicroseconds(500);
          digitalWrite(Signal_1, LOW);
          delayMicroseconds(3166);  
          delay(10);
        }
        else{
          digitalWrite(Signal_2, HIGH);
    
          delayMicroseconds(500);
           digitalWrite(Signal_2, LOW);
           delayMicroseconds(2500);
          digitalWrite(Signal_1, HIGH);
          
          digitalWrite(Signal_2, LOW);
          delayMicroseconds(500);
          digitalWrite(Signal_1, LOW);
     
          delayMicroseconds(3166);  
          delay(10);
        }  
      else{
         if(Dutycycle_1>Dutycycle_2){
            digitalWrite(outPin_100us, HIGH);

            delayMicroseconds(500);
            digitalWrite(outPin_100us, LOW);
            delayMicroseconds(2500);
            digitalWrite(outPin_500us, HIGH);

            digitalWrite(outPin_100us, LOW);
            delayMicroseconds(500);
            digitalWrite(outPin_500us, LOW);

            delayMicroseconds(3166);  
            delay(10); 
         }
         else{
            digitalWrite(outPin_100us, HIGH);

            delayMicroseconds(500);
            digitalWrite(outPin_100us, LOW);
            delayMicroseconds(2500);
            digitalWrite(outPin_500us, HIGH);

            digitalWrite(outPin_100us, LOW);
            delayMicroseconds(500);
            digitalWrite(outPin_500us, LOW);

            delayMicroseconds(3166);  
            delay(10); 
         }
      }
}
