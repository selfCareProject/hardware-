int initial=0;
int heartbeats=0;
const int pulseRead=2;
char incomingByte;  // incoming data
int  LED = 13;      // LED pin
 double reading ;
double voltage ;
double tempreture;
void setup() {
  Serial.begin(9600); // initialization
  pinMode(LED, OUTPUT);
  //pinMode(pulseRead,INPUT);
  attachInterrupt(0,heartRate,RISING);
  //Serial.println("Press 1 to LED ON or 0 to LED OFF...");
}
 
void loop() {
  if (Serial.available() > 0) 
  {  // if the data came
    incomingByte = Serial.read(); // read byte
    if(incomingByte == '0') 
    {
       /*digitalWrite(LED, LOW);  // if 1, switch LED Off
       Serial.println("LED OFF. Press 1 to LED ON!");*/
       // print message
       reading=analogRead(A0);
       voltage = reading*5 ;
       voltage /= 1024.0 ;
      /* Serial.print(voltage);
       Serial.println("volts");*/     
       tempreture=voltage*100;
       Serial.print(tempreture);  
    }
    if(incomingByte == '1') 
    {
      digitalWrite(LED, HIGH); // if 0, switch LED on
      Serial.print(heartbeats*6);
      heartbeats=0;
     
       //Serial.println("LED ON. Press 0 to LED OFF!");
    }
  }
}

void heartRate()
  { 
   // intitial=millis();
    if(millis()-initial<10000)
        {
          
           heartbeats++;
        }
    
  }
