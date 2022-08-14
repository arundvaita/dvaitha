//  prority chnge and view
// security

//     full, not checked

const int sensorInl = A8;    //main current
int mVperAmpl = 100; // use 100 for 20A Module and 66 for 30A Module

double Voltagel = 0;
double VRMSl = 0;
double AmpsRMSl = 0;


int trigPin =50;
int echoPin =51;
  long duration, distance;
  int tresd=80;


  int secure=100;
  int secureala= 100;

  

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);
String mes;
char con = "";


int buz = 15;
int mc=A1;   //  mc sensor

int mcval = 350;   // mc sensor limit
int mcvalr=0;
int ledb=24;
int it=0;
 

#include <dht.h>
dht DHT;
#define DHT11_PIN 22 // humidity sensor  , pin changed to 22
int f = 23 ;    //    pin changed to 23
float hum;  //Stores humidity value
float temp; //Stores temperature value
int p = A2;   // pot value                   connect 10 0hm resistor t0 ground
unsigned long endtime = 0;
int x = 0;  // time flag set
int y = 3;  // fan on time in minutes
int z = 35;   // temp limit
const int butpin = 25;
  int a = 0;
      int b = 1;  
      int d  = 0;
      int buts = 0;


int mcnt=0;  // main current
int cntlmt = 1;  // limit 1a change it
int brk = 0;
int e=4;

int cntlmte = 1;  // limit 1a change it , earth



#include<LiquidCrystal.h>
LiquidCrystal lcd(31,30,29,28,27,26);





#include <Keypad.h>
const byte Rows = 4;
const byte Cols = 3;
int i = 0;
String pass = "" ; 
String passn1 = "" ;
String passn2 = "" ;
String password = "1234";
int ap=20;

String voice;
char c = "";
char keymap[Rows][Cols] =
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rPins[Rows] =  {14, 13, 12, 11};   //Rows 0 to 3
byte cPins[Cols] = {10, 9, 8};      //Columns 0 to 2
Keypad kpd = Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);


//                                        change pins
// priorities, m1 , m2, m3, m4
char prior[4][2] =
{
  {'4', '1'},
  {'5', '2'},
  {'6', '3'},
  {'7', '4'}
};
int k = 0;


int v1=A3;
int v2=A4;
int v3=A5;
int v4=A6;
int v1b,v1c,v1count=0;
float v1a;  


//     int c1=A7;  main current sensorInl
int c2=A8;

int Rin=38;
int Yin=39;
int Bin=40;
int Nin=41;

int Rs=42;
int Ys=43;
int Bs=44;

int Gen=45;
int Gn=46;


int leda=21;

void setup()
{


  mySerial.begin(9600);  
 mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
  

  Serial.begin(9600);
  lcd.begin(16, 2);        //  print name and something
 lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor        ***************************
      lcd.print("DVAITHA "); 
      lcd.setCursor(0, 1);                         // set culsor        **************************
      lcd.print("SMART SUPPLY SOLUTIONS"); 

      
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
 pinMode(p, INPUT);
   pinMode(f, OUTPUT);
   digitalWrite(f, HIGH);
   pinMode(butpin, INPUT_PULLUP);          // check cheyyanam
  pinMode(ledb, OUTPUT);
 
pinMode(v1, INPUT);
pinMode(v2, INPUT);
pinMode(v3, INPUT);
pinMode(v4, INPUT);


  buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW); 
  } 

  else  
  {
    digitalWrite(ledb, HIGH);
  }

 
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);   
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

 digitalWrite(4, LOW);
   digitalWrite(5, LOW);
      digitalWrite(6, LOW);
          digitalWrite(7, LOW);
 
  pinMode(Rin,OUTPUT);
  pinMode(Yin,OUTPUT);   
  pinMode(Bin,OUTPUT);
  pinMode(Nin,OUTPUT);

  digitalWrite(Rin, LOW);
   digitalWrite(Yin, LOW);
      digitalWrite(Bin, LOW);
          digitalWrite(Nin, LOW);



  pinMode(Rs,OUTPUT);
  pinMode(Ys,OUTPUT);   
  pinMode(Bs,OUTPUT);
  pinMode(Gen,OUTPUT);
  pinMode(Gn,OUTPUT);
  
  digitalWrite(Rs, HIGH);
   digitalWrite(Ys, HIGH);
      digitalWrite(Bs, HIGH);
          digitalWrite(Gen, HIGH);
          digitalWrite(Gn, HIGH);
 
  
   
    pinMode(mc,INPUT);    
      pinMode(buz,OUTPUT);
          pinMode(leda,OUTPUT);
        
}




void vosm()
{
     
  
  while (mySerial.available())
  {
    delay(10);                       //Delay for get calmmmmm
    char con = mySerial.read();
    if (con == '#')
    {
      break;
    }
    mes = mes + con;
  }
  if (mes.length() > 0)
  {
    Serial.println(mes);
    if (mes == "power off")
    {
      poweroff();
      ap=20;
      
      
    }
       mes = "";
  }
}






void vos()
{

  while (Serial.available())
  {
    delay(10);                       //Delay for get calmmmmm
    char c = Serial.read();
    if (c == '#')
    {
      break;
    }
    voice = voice + c;
  }
  if (voice.length() > 0)
  {
    Serial.println(voice);
    if (voice == "view priority")
    {
      viewpriority();


    }

    else if (voice == "change priority")
    {
      delay(10);
     passwordd();
     if(ap==10)
     {
      changepriority();
      ap=20;

     }
    }











    else if (voice == "priority drip on")
    {
   delay(10);
      prioritydripon();
      ap=20;

     
    }
     else if (voice == "power off")
    {
    delay(10);
      poweroff();
      ap=20;

     
    }
 else if (voice == "power on")
    {
      delay(10);
     passwordd();
     if(ap==10)
     {
      poweron();
      ap=20;

     }
    }


 else if (voice == "security off")
    {
      delay(10);
     passwordd();
     if(ap==10)
     {
      secureala= 50;
      ap=20;

     }
    }


 else if (voice == "full security off")
    {
      delay(10);
     passwordd();
     if(ap==10)
     {
      secure= 50;
      ap=20;

     }
    }



else if (voice == "security on")
    {
      delay(10);
     passwordd();
     if(ap==10)
     {
      secureala= 100;
      ap=20;

     }
    }


 else if (voice == "full security on")
    {
      delay(10);
     passwordd();
     if(ap==10)
     {
      secure= 100;
      ap=20;

     }
    }

    
   else if (voice == "system temperature")
    {
      lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor
      lcd.print("S/M TEMPERATURE "); 
      lcd.setCursor(4, 1);                         // set culsor
      lcd.print((int)DHT.temperature);  
      lcd.print((char)223);                         //   degree
      lcd.print("c      ");            
      delay(500);
      lcd.clear();
      lcd.setCursor(3, 0);
       it=millis+3500;
    }
      else if (voice == "system humidity")
    {

      lcd.clear();
      lcd.setCursor(2, 0);                         // set culsor
      lcd.print("S/M HUMIDITY  "); 
      lcd.setCursor(5, 1);                             // set culsor
      lcd.print((int)DHT.humidity); 
      lcd.print(" %     "); 
      delay(500);
      lcd.clear();
      lcd.setCursor(3, 0);
       it=millis+3500;
    }



  else if (voice == "set fan time")
    {
delay(10);
      passwordd();
     if(ap==10)
     {
      buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
      } 

     else 
  {
    digitalWrite(ledb, HIGH);
  }
       a = buts;
       b = !a;

      while(1)
      {
       lcd.clear();
      lcd.setCursor(2, 0);                         // set culsor
      lcd.print("SET FAN TIME  "); 
      delay(1000);
     d  = analogRead(p);
      d = map(d, 0, 1023, 0, 59);
     lcd.setCursor(3, 1);                         // set culsor
      lcd.print(d); 
      lcd.setCursor(6, 1);                         // set culsor
      lcd.print("MINUTES   "); 
       delay(1000);
        buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
     } 

    else 
     {
     digitalWrite(ledb, HIGH);
     }
      a = buts;

       if(a== b) break;

      }
       y = d;  // fan on time in minutes
       lcd.clear();
       lcd.setCursor(3, 0);                         // set culsor
     lcd.print(d); 
      lcd.setCursor(6, 0);                         // set culsor
      lcd.print("MINUTES   "); 
      lcd.setCursor(3, 1);                         // set culsor
      lcd.print("CONFIRMED  "); 
      delay(1000);
    lcd.clear();
    }
          
      ap=20;
       it=millis+3500;
    }







 else if (voice == "set alarm limit")
    {
delay(10);
      passwordd();
     if(ap==10)
     {
      buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
      } 

     else 
  {
    digitalWrite(ledb, HIGH);
  }
       a = buts;
       b = !a;

      while(1)
      {
       lcd.clear();
      lcd.setCursor(2, 0);                         // set culsor
      lcd.print("SET ALARM LIMIT "); 
      delay(1000);
     d  = analogRead(p);
      d = map(d, 0, 1023, 0, 1000);
     lcd.setCursor(3, 1);                         // set culsor
      lcd.print(d); 
      lcd.setCursor(6, 1);                         // set culsor
      lcd.print("  CM   "); 
       delay(1000);
        buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
     } 

    else 
     {
     digitalWrite(ledb, HIGH);
     }
      a = buts;

       if(a== b) break;

      }
       tresd = d;  // fan on time in minutes
       lcd.clear();
       lcd.setCursor(3, 0);                         // set culsor
     lcd.print(d); 
      lcd.setCursor(6, 0);                         // set culsor
      lcd.print("cm "); 
      lcd.setCursor(3, 1);                         // set culsor
      lcd.print("CONFIRMED  "); 
      delay(1000);
    lcd.clear();
    }
          
      ap=20;
       it=millis+3500;
    }





    



 else if (voice == "set gas sensitivity")
    {
delay(10);
      passwordd();
     if(ap==10)
     {
      buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
      } 

     else 
  {
    digitalWrite(ledb, HIGH);
  }
       a = buts;
       b = !a;

      while(1)
      {
       lcd.clear();
      lcd.setCursor(2, 0);                         // set culsor
      lcd.print("GAS SENSITIVTY"); 
      delay(1000);
     d  = analogRead(p);
      d = map(d, 0, 1023, 0, 100);
     lcd.setCursor(3, 1);                         // set culsor
      lcd.print(d); 
      lcd.setCursor(6, 1);                         // set culsor
      lcd.print("  %   "); 
       delay(1000);
        buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
     } 

    else 
     {
     digitalWrite(ledb, HIGH);
     }
      a = buts;

       if(a== b) break;

      }
       mcval = analogRead(p);  // gas limit
       lcd.clear();
       lcd.setCursor(3, 0);                         // set culsor
     lcd.print(d); 
      lcd.setCursor(6, 0);                         // set culsor
      lcd.print("%   "); 
      lcd.setCursor(3, 1);                         // set culsor
      lcd.print("CONFIRMED  "); 
      delay(500);
    lcd.clear();
    }
          
      ap=20;
       it=millis+3500;
    }





    
    else if (voice == "set temperature limit")
    {
delay(10);
        passwordd();
     if(ap==10)
     {
      buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
      } 

     else 
  {
    digitalWrite(ledb, HIGH);
  }
       a = buts;
       b = !a;

      while(1)
      {
       lcd.clear();
      lcd.setCursor(2, 0);                         // set culsor
      lcd.print("SET TEMP LIMIT"); 
      delay(1000); 
     d  = analogRead(p);
      d = map(d, 0, 1023, 20, 100);
     lcd.setCursor(5, 1);                         // set culsor
      lcd.print(d); 
      lcd.setCursor(8, 1);                         // set culsor
       lcd.print((char)223);                         //   degree
      lcd.print("c");    
       delay(1000);
        buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
     } 

    else 
     {
     digitalWrite(ledb, HIGH);
     }
      a = buts;

       if(a== b) break;

      }
       z = d;  // temp limit
       lcd.clear();
       lcd.setCursor(5, 0);                         // set culsor
      lcd.print(d); 
      lcd.setCursor(8, 0);                         // set culsor
       lcd.print((char)223);                         //   degree
      lcd.print("c");
      lcd.setCursor(3, 1);                         // set culsor
      lcd.print("CONFIRMED"); 
      delay(500);
    lcd.clear();
    }

      ap=20;
       it=millis+3500;
    }
 else if (voice == "change password")
    {
    
         passwordd();
     if(ap==10)
     {

  lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("ENTER NEW PASSWORD"); 
   for(i=0;i<=3;)
     {
     char keypressed = kpd.getKey();
     if (keypressed != NO_KEY)
      { 
      passn1= passn1 + keypressed;
      lcd.setCursor(0, 1);                         // set culsor                        ********************
      lcd.print("*"); 
          i++;   
      }
     }
 lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("CONFIRM PASSWORD"); 
    
   for(i=0;i<=3;)
     {
     char keypressed = kpd.getKey();
     if (keypressed != NO_KEY)
        { 
         passn2= passn2 + keypressed;
      lcd.setCursor(0, 1);                         // set culsor                        ********************
      lcd.print("*"); 

          i++;   
        }
      } 
   if( passn1 == passn2)
 {

    password = passn1;
     lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("PASSWORD CHANGED"); 

       
  }
  else 
  {
        lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("PASSWORD MISSMATCH"); 

  }
  
  }

      ap=20;
      pass="";
      passn1 =""; 
      passn2 = "";
    it=millis+3500;   
}
    
    voice = "";
  }
}





void loop()
{
  if(it<millis)
   {
     lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor        ***************************
      lcd.print("DVAITHA "); 
      lcd.setCursor(0, 1);                         // set culsor        **************************
      lcd.print("SMART SUPPLY SOLUTIONS"); 
      delay(500);
   }


 
  
  if(secure==100)
  {
    security(); 
  }
   getVPPl();  // line current
   prioritydrip();
   acv1();
   fan();
   
    buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
  } 

  else 
  {
    digitalWrite(ledb, HIGH);
  }



  

if (mySerial.available()>0)

{
  while (mySerial.available())
  {
    delay(10);                       //Delay for get calmmmmm
    char con = mySerial.read();
    if (con == '*')
    {
      
   
      vosm();
      break;
    }


  }
}  
  
  
  
  
  
  delay(100);
  if (Serial.available() > 0)
  {

    char in = Serial.read();
    if (in == '*')
    {
      vos();

    }
  }
}


void viewpriority()  
{
 
 
     lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("PRIORITY ORDER"); 
    delay(150);
lcd.setCursor(0,1);                        //              set cursor           *************************************
    for (k = 0; k < 4; k++)
    {
                
      lcd.print(prior[k][1]);           //                          ************************************
      delay(150);
    }
  it=millis+3500;
  
}

void  changepriority()
{






 buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
      } 

     else 
  {
    digitalWrite(ledb, HIGH);
  }
       a = buts;
       b = !a;

      while(1)
      {
        lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("PRIORITY OREDR"); 
    
      lcd.setCursor(0, 1);                         // set culsor                        ********************
     
    for (k = 0; k < 4; k++)
    {

      lcd.print(prior[k][1]); 
      delay(150);
    }
     lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("ENTER NEW ORDER"); 
      lcd.setCursor(0, 1);                         // set culsor                        ********************
    
    for (k = 0; k < 4;)
    {
      char keypressed = kpd.getKey();
      if (keypressed != NO_KEY)
      {
        
        prior[k][1] = keypressed;
      lcd.print(keypressed); 
         tone(buz,1000, 75);   // best free
        k++;
      }
    } 
       delay(2000);
        buts = digitalRead(butpin);
     if (buts == HIGH)
     {
    digitalWrite(ledb, LOW);
     } 

    else 
     {
     digitalWrite(ledb, HIGH);
     }
      a = buts;

       if(a== b) break;

      }
      

      
       
       lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("NEW PRIORITY ORDER"); 
    delay(150);
  
      lcd.setCursor(0, 1);                         // set culsor                        ********************
   

    for (k = 0; k < 4; k++)
    {


      lcd.print(prior[k][1]); 
   
      delay(250);
    }


  lcd.clear();
      lcd.setCursor(0, 0);     
      lcd.print("CONFIRMED  "); 
      delay(500);
    lcd.clear();

     
     it=millis+3500;
  }


  float getVPPl()
{

  
  int readValuel;             //value read from the sensor
  int maxValuel = 0;          // store max value here
  int minValuel = 1024;          // store min value here
  
   uint32_t start_timel = millis();
   while((millis()-start_timel) < 1000) //sample for 1 Sec
   {
       readValuel = analogRead(sensorInl);
       // see if you have a new maxValue
       if (readValuel > maxValuel) 
       {
           maxValuel = readValuel;
       }
       if (readValuel < minValuel) 
       {
           
           minValuel = readValuel;
       }
   }
   
   // Subtract min from max
  Voltagel = ((maxValuel - minValuel) * 5.0)/1024.0;
      

 VRMSl = (Voltagel/2.0) *0.707; 
 AmpsRMSl = (VRMSl * 1000)/mVperAmpl;


  lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor
      lcd.print("LOAD CURRENT "); 
      lcd.setCursor(0, 1);                         // set culsor
      lcd.print(AmpsRMSl);  
      lcd.print(" Amps RMS");            
      delay(500);
    
      lcd.setCursor(3, 0);
   //    it=millis+2000;

 }


 
 
void prioritydrip()      // hardwaere not chejed  ********************
{
if(AmpsRMSl>cntlmt)
{

 for (k = 0; k < 4; k++)
    {
      if(prior[k][1] == e)
      {
      brk = (prior[k][0]);
      digitalWrite(brk, HIGH);

      
    }
  
}
      e=e-1;

}


  
}
void prioritydripon()                        // not checked
{
e=e+1;

for (k = 0; k < 4; k++)
    {
      if(prior[k][1] == e)
      {
      brk = (prior[k][0]);
      digitalWrite(brk, LOW);
      

      
    }
  
}



  
}



void security()       //  , gas sensor flame sensor, alarm drip , sms
{

  securitygas();
  if(secureala==100)
  {
 securitytress();
  }

}

void securitytress()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
  if (distance < tresd)
  { 
SendMessagetres();
 tone(buz, 110, 2000);
 lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor
      lcd.print("TRESSPASS DETECTED");
  }
   else
  {
    noTone(buz);
  }
  delay(100);

}

void SendMessagetres()
{
 
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919061343648\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("tress pass detected");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);

}


void securitygas()
{

 mcvalr= analogRead(mc);

if (mcvalr> mcval)
  {
 
    tone(buz, 110, 2000);
    drip();                          // sms, app, light add cheyyanam
    SendMessagegas();
    
  }
  else
  {
    noTone(buz);
  }
  delay(100);


}

void acv1()
{
 
  for(v1count=0;v1count<1500;v1count++)
  {
v1b=analogRead(v4);
      v1a = map(v1b, 0, 540, 0, 30);
if(v1c<v1a)
{
  v1c=v1a;
}
v1count++;
  }

v1c=v1c/sqrt(2);

 lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor
      lcd.print("VOLTAGE "); 
      lcd.setCursor(0, 1);                         // set culsor
      lcd.print(v1c);  
      lcd.print(" V RMS");            
      delay(500);
   
      lcd.setCursor(3, 0);
   //    it=millis+2000;

 
}

 void SendMessagegas()
{
 
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919061343648\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("gas leak detected");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);

}



void   poweroff()
{
lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("POWER OFF"); 
              delay(150); 
drip();
   
}
void poweron()
{
  lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("POWERING ON"); 
   tone(buz,500, 2000);   // best free
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
       it=millis+3500;
}


void drip()
{
   tone(buz,500, 2000);   // best free
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor
      lcd.print("DRIP ");
              delay(150); 
}
void fan()
{


   x = endtime - (millis() / 60000);
   int chk = DHT.read11(DHT11_PIN);    // humidity temp variable
  Serial.println("tmp");               //  app
  Serial.println((int)DHT.temperature);
  Serial.println("hmt");           //  app
  Serial.println((int)DHT.humidity);
   
  hum = DHT.humidity;
  temp= DHT.temperature;

  if(temp> z)
    {
lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor
      lcd.print("FAN ON ");
              delay(150); 
        digitalWrite(f, LOW); 
         endtime = (millis() / 60000) + y;
    }
    else if (x <= 0)
    {
      digitalWrite(f, HIGH); 
    }
    
  
}

void passwordd()
{


 lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("ENTER PASSWORD"); 
  delay(150);                       //          avoid delayssss
  lcd.setCursor(0,1);
  for(i=0;i<=3;)
  {
     char keypressed = kpd.getKey();
     if (keypressed != NO_KEY)
     { 
      pass= pass + keypressed;
      
   tone(buz,1000, 75);   // best free
      lcd.print("*"); 
          i++;   
     }
  }
 
  if(pass == password)
  {
      Serial.println(pass);
       lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("ACCESS ALLOWED"); 
       tone(buz,1000, 75);   // best free
        ap=10;
  }
   else
   {
     lcd.clear();
      lcd.setCursor(0, 0);                         // set culsor                        ********************
      lcd.print("INCORRECT PASSWORD"); 
      lcd.setCursor(0, 1);                         // set culsor                        ********************
      lcd.print("ANTHASSU UNDODA");   
        delay(150); 
   }
        it=millis+3500;
   pass="";
      passn1 =""; 
      passn2 = "";
      
}
