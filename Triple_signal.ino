int   Channel_I     = 8;                // output Pin setting
int   Channel_II    = 7;
int   Channel_III   = 4;
float PWM_fequency  = 60;               // Setting output signal fequency(MAX=100K Hz)
float Dutycycle_I   = 3.0;              // Setting Duty Cycle
float Dutycycle_II  = 2.0;
float Dutycycle_III = 0.6;
int   period_us=0,period_ms=0,temp=0;
int   Array[3];
void setup()
{
  pinMode(Channel_I  , OUTPUT);      // Initial Program
  pinMode(Channel_II , OUTPUT);
  pinMode(Channel_III, OUTPUT);
  digitalWrite(Channel_I  , LOW);
  digitalWrite(Channel_II , LOW);
  digitalWrite(Channel_III, LOW);
  period_us= 1000000/PWM_fequency;
  Array[0] = period_us*Dutycycle_I/100;
  Array[1] = period_us*Dutycycle_II/100;
  Array[2] = period_us*Dutycycle_III/100;
  for (int a=0; a<3; a++){
    for (int b=a; b<3; b++){
        if( Array[b] < Array[a] ) {
                temp = Array[b];
                Array[b] = Array[a];
                Array[b] = temp;
      }
    }
  }
  Serial.begin(9600);
}

void loop()
{     period_us= 1000000/PWM_fequency;
      //Serial.print(period_us);
      // Serial.print("\r\n");
      digitalWrite(Channel_I   , HIGH);
      digitalWrite(Channel_II  , HIGH);
      digitalWrite(Channel_III , HIGH);
      delayMicroseconds(Array[2]);
      //Serial.print(Array[0]);
      //Serial.print("\r\n");
      digitalWrite(Channel_III, LOW);
      delayMicroseconds(Array[1]-Array[2]);
      //Serial.print(Array[1]);
      //Serial.print("\r\n");
      digitalWrite(Channel_II , LOW);
      delayMicroseconds(Array[0]-Array[1]);
      digitalWrite(Channel_I  , LOW);
      //Serial.print(Array[2]);
      //Serial.print("\r\n");
      period_ms = (period_us-Array[0])/10000;
      period_us = (period_us-Array[0])%10000;
      delayMicroseconds(period_us);
      delay(period_ms*10);

      
}
