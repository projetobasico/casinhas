/*
 * TimeRTC.pde
 * Example code illustrating Time library with Real Time Clock.
 * This example is identical to the example provided with the Time Library,
 * only the #include statement has been changed to include the DS3232RTC library.
 */

#include <DS3232RTC.h>    //http://github.com/JChristensen/DS3232RTC
#include <Time.h>         //http://www.arduino.cc/playground/Code/Time  
#include <Wire.h>         //http://arduino.cc/en/Reference/Wire (included with Arduino IDE)


int umidade,umidade1,umidade2,umidade3=0;
int resumidade,resumidade1,resumidade2,resumidade3=0;

int a,b,c;

void setup(){
  
  Serial.begin(9600);
a=0;
b=0;
c=0;

/////////////////////RTC/////////////////////////////////////////////////
    setSyncProvider(RTC.get);   //// the function to get the time from the RTC
    if(timeStatus() != timeSet) 
        Serial.println("Unable to sync with the RTC");
    else
        Serial.println("RTC has set the system time");      

/////////////////////////////////////////////////////////////////////////

}

void loop()
{
/////////////////////RTC/////////////////////////////////////////////////

 
 digitalClockDisplay();  
    delay(1000);

/////////////////////////////////////////////////////////////////////////
////////////sensor 1/////////////////////////////


umidade=0;  
int i=0;
  for(i = 0; i< 10; i++) {

 umidade=analogRead(A0);
  resumidade=(resumidade+umidade);
   
  }
delay(1000);

 resumidade=resumidade/10; 
 // Serial.println("media da umidade ");
   //Serial.println(resumidade);
 //Serial.println("  ");

 if ((resumidade>=50)and (a==0)){
 Serial.println("media do sensor 1 acima de 50  ");
   Serial.println(resumidade);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
a=1;
 }

if ((resumidade>=200)and (b==0)){
 Serial.println("media do sensor 1 acima de 200  ");
   Serial.println(resumidade);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
b=1;
}
if ((resumidade>=500)and (c==0)){
 Serial.println("media do sensor 1 acima de 500  ");
   Serial.println(resumidade);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
c=1;

 }



 ///////////////////////////////////////////////////////////////////////////////////////
////////////////////sensor 2/////////////////////////////////////////////////////////

umidade1=0;  
int p=0;
  for(p = 0; p< 10; p++) {
 
 // Serial.println(ab);
 umidade1=analogRead(A1);
  resumidade1=(resumidade1+umidade1);
  }
 resumidade1=resumidade1/10; 
 // Serial.print( " media da umidade 1 ");
   //Serial.println(resumidade1);


   if ((resumidade1>=50)and (a==1)){
 Serial.println("media do sensor 2 acima de 50  ");
   Serial.println(resumidade1);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
a=2;


if ((resumidade1>=200)and (b==1)){
 Serial.println("media do sensor 2 acima de 200  ");
   Serial.println(resumidade1);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
b=2;
}

if ((resumidade1>=500)and (c==1)){
 Serial.println("media do sensor 2 acima de 500  ");
   Serial.println(resumidade1);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
c=2;

 }
    }/////////////////////////////////////////////////////
  

umidade2=0;  
int o=0;
  for(o = 0; o< 10; o++) {
 
 // Serial.println(ab);
 umidade2=analogRead(A2);
  resumidade2=(resumidade2+umidade2);
   
  }
 resumidade2=resumidade2/10; 
  //Serial.print(" media da umidade ");
   //Serial.print(resumidade2);
 //  delay(1000);
if ((resumidade2>=50)and (a==2)){
 Serial.println("media do sensor 3 acima de 50  ");
   Serial.println(resumidade2);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
a=3;


if ((resumidade2>=200)and (b==2)){
 Serial.println("media do sensor 3 acima de 200  ");
   Serial.println(resumidade2);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
b=3;
}

if ((resumidade2>=500)and (c==2)){
 Serial.println("media do sensor 3 acima de 500  ");
   Serial.println(resumidade2);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
c=3;

 }

}

///////////////////////////////////////////////////////////////////////////////////////
////////////////////sensor 4/////////////////////////////////////////////////////////

umidade3=0;  
int r=0;
  for(r = 0; r< 10; r++) {
  // Serial.println(ab);
 umidade3=analogRead(A3);
  resumidade3=(resumidade3+umidade3);
   
  }

 resumidade3=resumidade3/10; 
  //Serial.print( "  media da umidade 3 ");
  // Serial.println(resumidade3);


 if ((resumidade3>=50)and (a==3)){
 Serial.println("media do sensor 4 acima de 500  ");
   Serial.println(resumidade3);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
a=4;
 }

if ((resumidade3>=200)and (b==3)){
 Serial.println("media do sensor 4 acima de 800  ");
   Serial.println(resumidade3);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
b=4;
}
if ((resumidade3>=500)and (c==3)){
 Serial.println("media do sensor 4 acima de 1000  ");
   Serial.println(resumidade3);
 Serial.println("  ");
  Serial.println("horas do acionamento  ");
  Serial.print(hour());
   printDigits(minute());
  printDigits(second());
   Serial.println("  ");
c=4;

 }

 //Serial.println(resumidade);
 //Serial.println(resumidade1);
 //Serial.println(resumidade2);
 //Serial.println(resumidade3);


////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

}
void digitalClockDisplay(void)
{
    // digital clock display of the time
  //  Serial.print(hour());
  //  printDigits(minute());
    //printDigits(second());
    //Serial.print(' ');
    //Serial.print(day());
   // Serial.print(' ');
   // Serial.print(month());
    //Serial.print(' ');
    //Serial.print(year()); 
    //Serial.println(); 
}

void printDigits(int digits)
{
    // utility function for digital clock display: prints preceding colon and leading 0
    Serial.print(':');
    if(digits < 10)
        Serial.print('0');
    Serial.print(digits);
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////



}
