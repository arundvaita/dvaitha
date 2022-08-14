  int x= 0;
int s1=5;
int s2=6;
int s3=4;
int s4=3;
int s5=2;
int a1=7;    // 7 is not good in my arduino so change this to 7 in new one
int a2=8;
int a3=9;
int a4=10;
int c1=11;
int c2 = 12;
void setup() 
{
  
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(s5, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  
}

void loop()     //             checkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk

{
 while(x==0)
 { digitalWrite(c2, LOW); 
  digitalWrite(c1, HIGH); 
  digitalWrite(a2, HIGH); 
  digitalWrite(a4, HIGH); 
  delayMicroseconds(769);   
  digitalWrite(a2, LOW);   
  digitalWrite(s5, HIGH);  
  delayMicroseconds(769); 
  digitalWrite(s5, LOW); 
  digitalWrite(s4, HIGH);   
  delayMicroseconds(769); 
  digitalWrite(s4, LOW); 
  digitalWrite(s3, HIGH);
  delayMicroseconds(769); 
  digitalWrite(s3, LOW); 
  digitalWrite(s2,HIGH);    
  delayMicroseconds(769); 
  digitalWrite(s2, LOW); 
  digitalWrite(s1,HIGH);   
  delayMicroseconds(769); 
  digitalWrite(s1, LOW);  
  digitalWrite(a1,HIGH);   
  delayMicroseconds(769);   
  digitalWrite(a1, LOW);  
  digitalWrite(s1,HIGH);   
  delayMicroseconds(769);     
  digitalWrite(s1, LOW);  
  digitalWrite(s2,HIGH);   
  delayMicroseconds(769); 
  digitalWrite(s2, LOW);  
  digitalWrite(s3,HIGH);   
  delayMicroseconds(769);  
  digitalWrite(s3, LOW);  
  digitalWrite(s4,HIGH);   
  delayMicroseconds(769); 
  digitalWrite(s4, LOW);  
  digitalWrite(s5,HIGH);   
  delayMicroseconds(769);
  digitalWrite(s5, LOW);   
  digitalWrite(a2, HIGH);  
  delayMicroseconds(769); 
  digitalWrite(c1, LOW); 
  digitalWrite(c2, HIGH); 
  delayMicroseconds(769); 
   digitalWrite(a4, LOW);   
  digitalWrite(s5, HIGH);  
  delayMicroseconds(769); 

   digitalWrite(s5, LOW); 
  digitalWrite(s4, HIGH);   
  delayMicroseconds(769); 
  digitalWrite(s4, LOW); 
  digitalWrite(s3, HIGH);
  delayMicroseconds(769); 
  digitalWrite(s3, LOW); 
  digitalWrite(s2,HIGH);    
  delayMicroseconds(769); 
  digitalWrite(s2, LOW); 
  digitalWrite(s1,HIGH);   
  delayMicroseconds(769); 
  digitalWrite(s1, LOW);  
  digitalWrite(a3,HIGH);   
  delayMicroseconds(769);   
  digitalWrite(a3, LOW);  
  digitalWrite(s1,HIGH);   
  delayMicroseconds(769);     
  digitalWrite(s1, LOW);  
  digitalWrite(s2,HIGH);     
  delayMicroseconds(769); 
  digitalWrite(s2, LOW);  
  digitalWrite(s3,HIGH);   
  delayMicroseconds(769);  
  digitalWrite(s3, LOW);  
  digitalWrite(s4,HIGH);   
  delayMicroseconds(769); 
  digitalWrite(s4, LOW);  
  digitalWrite(s5,HIGH);   
  delayMicroseconds(769);
    digitalWrite(s5, LOW);  
  digitalWrite(a4,HIGH);   
  delayMicroseconds(769);
 }
}
