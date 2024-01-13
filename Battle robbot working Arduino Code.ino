#define RCPin 11
int RCValue;
      
double ch1=2;  // for rc rx chnnel 1
double ch2=3; // for rc rx chnnel 2

       int AI1 = 4;     //motor A
       int AI2 = 5;
       int PWM_A = 9;
      
      int BI1 = 6;    // motor B
      int BI2 = 7;
      int PWM_B = 10;
void setup()
{
    Serial.begin(9600);
   //set all pins as output
      pinMode(AI2,OUTPUT); 
      pinMode(AI1,OUTPUT); 
      pinMode(PWM_A,OUTPUT);
      pinMode(BI2,OUTPUT);
      pinMode(BI1,OUTPUT);
      pinMode(PWM_B,OUTPUT);

      pinMode(RCPin, INPUT);
      pinMode(11,INPUT);
      pinMode(12,OUTPUT);
  
}

void loop()
{ 
  
  RCValue = pulseIn(RCPin, HIGH);
  Serial.println(RCValue);
  
  ch1 = pulseIn(2,HIGH);
  ch2 = pulseIn(3,HIGH);

  if (RCValue>1000)
{ digitalWrite(12,HIGH);
}
else { digitalWrite(12,LOW);
}

if((ch1==0)&&(ch2==0))
{     
    digitalWrite(AI2, LOW);
    digitalWrite(AI1, LOW);
    analogWrite(PWM_A, 0);
    digitalWrite(BI2, LOW);
    digitalWrite(BI1, LOW);
    analogWrite(PWM_B, 0);                     // motor 1 & motor 2 will not move
 
}

else if((ch1>1530)&&(ch2>1530))
{     
     //digitalWrite(a,HIGH); digitalWrite(b,LOW);
     //digitalWrite(c,LOW);digitalWrite(d,HIGH);
     
     digitalWrite(AI1,HIGH);
     digitalWrite(AI2,LOW);
     analogWrite(PWM_A,255);
     digitalWrite(BI1, LOW);
     digitalWrite(BI2,HIGH);
     analogWrite(PWM_B,255);    
}

else if((ch1>1530)&&(ch2<1460))
{ 
   //digitalWrite(a,HIGH); digitalWrite(b,LOW);
   //digitalWrite(c,HIGH);digitalWrite(d,LOW);

   digitalWrite(AI1,HIGH);
   digitalWrite(AI2, LOW);
   analogWrite(PWM_A,255);
   digitalWrite(BI1,HIGH);
   digitalWrite(BI2, LOW);
   analogWrite(PWM_B,255);

}

else if((ch1<1460)&&(ch2>1530))
{     
  //digitalWrite(a,LOW); digitalWrite(b,HIGH);
  //digitalWrite(c,LOW);digitalWrite(d,HIGH);

  digitalWrite(AI1, LOW);
  digitalWrite(AI2, HIGH);
  analogWrite(PWM_A, 255);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, HIGH);
  analogWrite(PWM_B, 255);
}

else if((ch1<1460)&&(ch2<1460))
{  //digitalWrite(a,LOW); digitalWrite(b,HIGH);
   ///digitalWrite(c,HIGH);digitalWrite(d,LOW);

   digitalWrite(AI1, LOW);
   digitalWrite(AI2, HIGH);
   analogWrite(PWM_A, 255);
   digitalWrite(BI1,HIGH);
   digitalWrite(BI2, LOW);
   analogWrite(PWM_B,255);
  

}

else
{     
  //digitalWrite(a,LOW); digitalWrite(b,LOW);   // motor 1 & motor 2 will not move
  //digitalWrite(c,LOW);digitalWrite(d,LOW);

  digitalWrite(AI2, LOW);
  digitalWrite(AI1, LOW);
  analogWrite(PWM_A, 0);
  digitalWrite(BI2, LOW);
  digitalWrite(BI1, LOW);
  analogWrite(PWM_B, 0);                     // motor 1 & motor 2 will not move
 

 
}

}
