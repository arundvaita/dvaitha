int s1=2;
int s2=3;
int s3=4;
int s4=5;
int s5=6;
int s6=7;  // 7 is not good in my arduino so change this to 7 in new one
int z= 8;  // zero crossing
int x=0; 


void setup() 
{
  
  pinMode(s1, OUTPUT);
   digitalWrite(s1, LOW); 
  pinMode(s2, OUTPUT);
   digitalWrite(s2, LOW); 
  pinMode(s3, OUTPUT);
   digitalWrite(s3, LOW); 
  pinMode(s4, OUTPUT);
   digitalWrite(s4, LOW); 
  pinMode(s5, OUTPUT);
   digitalWrite(s5, LOW); 
  pinMode(s6, OUTPUT);
   digitalWrite(s6, LOW); 

    
}

void loop() 

{
int t = digitalRead(z);
if( t== HIGH)
{
  x= 1;
}


while(x==0)
 {
 
  
  digitalWrite(s4, LOW);   // starts from 30 degree 
  digitalWrite(s1, HIGH);
  delayMicroseconds(3333);
  digitalWrite(s5, LOW);
  digitalWrite(s2, HIGH);
  delayMicroseconds(3333);
  digitalWrite(s6, LOW);
  digitalWrite(s3, HIGH);
  delayMicroseconds(3333);
  digitalWrite(s1, LOW);
  digitalWrite(s4, HIGH);
  delayMicroseconds(3333);
  digitalWrite(s2, LOW);
  digitalWrite(s5, HIGH);
  delayMicroseconds(3333);
  digitalWrite(s3, LOW);
  digitalWrite(s6, HIGH);
  delayMicroseconds(3333);


 }
}
  
  
