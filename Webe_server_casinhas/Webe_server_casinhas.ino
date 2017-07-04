// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;

#include <SD.h>
const int chipSelect = 4;

#include <SPI.h>
#include <Ethernet.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>
/////////////////////////////////////////////////////

#define DHTPIN  6     // sensor c1=c2-1
#define DHTPIN2 7     // sensor c2=c4-1
#define DHTPIN3 8     // sensor c3=c4-2
#define DHTPIN4 9     // sensor c4=c1-2
#define DHTPIN5 22    // sensor c5=c1-1
#define DHTPIN6 24    // sensor c6=c3-2
#define DHTPIN7 26    // sensor c7=c3-1
#define DHTPIN8 28    // sensor c8=c2-2
String d,da;

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);
DHT dht6(DHTPIN6, DHTTYPE);
DHT dht7(DHTPIN7, DHTTYPE);
DHT dht8(DHTPIN8, DHTTYPE);

////////////////////////////////////////////
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 2, 20, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

long previousMillis = 0;        // Variável de controle do tempo
//long intColetas = 300000; ///tempo certo     // Tempo em ms do intervalo a ser executado
long intColetas = 60000; ////apagar esta linha    // Tempo em ms do intervalo a ser executado

void setup(){
Serial.begin(9600);
pinMode(53,OUTPUT);
  digitalWrite(53,HIGH);

  Serial.print("Initializing SD card...");
pinMode(10, OUTPUT);
  digitalWrite(10,HIGH);
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    d=("er");
    // don't do anything more:
    ///voltar aqui para corrigir linha do cartão
    
    //return;
  }
  Serial.println("card initialized.");

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  while (!Serial) {
  
      Serial.println("DHTxx test!");

  dht.begin();
    
    
    ; // wait for serial port to connect. Needed for native USB port only
  }

digitalWrite(10,LOW);
digitalWrite(4,HIGH);

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

}

void loop()


{if (d=="er"){
  da=("sd nao conectado ");}
if (d=="err"){
  da=("sd conectado ");}

  
  unsigned long currentMillis = millis();    //Tempo atual em ms



 
  float h = dht.readHumidity();
 
  float t = dht.readTemperature();
  
  float h2 = dht2.readHumidity();
 
  float t2 = dht2.readTemperature();

    float h3 = dht3.readHumidity();
 
  float t3 = dht3.readTemperature();

float h4 = dht4.readHumidity();
 
  float t4 = dht4.readTemperature();

float h5 = dht5.readHumidity();
 
  float t5 = dht5.readTemperature();
  
  float h6 = dht6.readHumidity();
 
  float t6 = dht6.readTemperature();

    float h7 = dht7.readHumidity();
 
  float t7= dht7.readTemperature();

float h8 = dht8.readHumidity();
 
  float t8 = dht8.readTemperature();
  


  // Check if any reads failed and exit early (to try again).
  ////if (isnan(h2) || isnan(t2)) {
    ///////Serial.println("Failed to read from DHT sensor!");
    //return


  
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
///         send a standard http response header
         client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
         client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          

                        client.print("<center> ");

             
             client.println("<td><img alt='Apagada' src='http://www.folha-digital.com/campus/im/top.jpg' width='100%'/></td></tr>");

             client.print("<h1> UNIVERSIDADE ESTADUAL DE MARINGA</h1>");
            client.print("<h1> UEM </h1>");
            ////////////////////////////////////////////////////////////
client.print("<br> ");

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
client.print("<table border='1'>");///cabeçalho tabela
client.print("<tr><td> ");///////////inicio da linha         
client.print("<br> ");
client.print("     C2-2 ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h8);
  client.print(" %\t");
  client.print("<br> ");
  client.print("TEMPERATURA : ");
  client.print(t8);
  client.println(" *C ");
 client.print("<br/ > ");
//client.print(" </td></tr>  ");////////fim da linha
client.print("</td> <td>");////////////criação da nova coluna
////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
client.print("<br> ");
client.print("     C1-2 ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h4);
  client.print(" %\t");
  client.print("<br> ");
  client.print("TEMPERATURA : ");
  client.print(t4);
  client.println(" *C ");
  client.print("<br/ > ");
client.print("</td> <td>");////////////criação da nova coluna
////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

client.print("<br> ");
client.print("     C4-2 : ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h3);
  client.print(" %\t");
  client.print("<br> ");
  client.print("TEMPERATURA : ");
  client.print(t3);
  client.println(" *C ");
 client.print("<br/ > ");
client.print("</td> <td>");////////////criação da nova coluna
////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

client.print("<br> ");
client.print("     C3-2 ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h6);
  client.print(" %\t");
  client.print("<br> ");
  client.print("TEMPERATURA : ");
  client.print(t6);
  client.println(" *C ");
 client.print("<br/ > ");
client.print("<br> ");

client.print(" </td></tr>  ");////////fim da linha
client.print("</table> ");///////////fim da tabela
client.print("<br> ");
client.print("<br> ");

client.print("<table border='1'>");///cabeçalho tabela
client.print("<tr><td> ");///////////inicio da linha         


////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
client.print("<br> ");
client.print("     C3-1 : ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h7);
  client.print(" %\t");
  client.print("<br> ");
  client.print("TEMPERATURA : ");
  client.print(t7);
  client.println(" *C ");
 client.print("<br/ > ");

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
client.print("</td> <td>");////////////criação da nova coluna
client.print("<br> ");
client.print("     C4-1 ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h2);
  client.print(" %\t");
  client.print("<br> ");
  client.print("TEMPERATURA : ");
  client.print(t2);
  client.println(" *C ");
 client.print("<br/ > ");
client.print("</td> <td>");////////////criação da nova coluna
client.print("<br> ");

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
client.print("<br> ");
client.print("     C2-1 ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h);
  client.print(" %\t");
  client.print("<br> ");
  client.print("TEMPERATURA : ");
  client.print(t);
  client.println(" *C ");
 client.print("<br/ > ");
client.print("<br> ");
client.print("</td> <td>");////////////criação da nova coluna
client.print("<br> ");
////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
client.print("<br> ");
client.print("     C1-1 ");
client.print("<br> ");
client.print("<br> ");
client.print("UMIDADE : ");
  client.print(h5);
  client.print(" %\t");
  client.print("<br> ");
    client.print("TEMPERATURA : ");
  client.print(t5);
  client.println(" *C ");
 client.print("<br/ > ");
client.print(" </td></tr>  ");////////fim da linha
client.print("</table> ");///////////fim da tabela

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


  /////////           //////////////////////////////////////////////////////
client.print("<br> ");
String a,b,c,x;
a=("<td><img alt='' src='http://www.folha-digital.com/campus/?temperatura=");
b=("'/></td></tr>");
x=("?");
c=a+t2+b+x+h+t2+h2;
client.println(c);
//client.print("<table border='1'>");///cabeçalho tabela
//client.print("<tr><td> ");///////////inicio da linha         





            
            client.print(" ");
            client.print(" ");
            client.print(" ");
             client.println("<br />");

             client.print("<br> ");
             
///////////////////////////////tabela///////////////////////////////
///////////////////////////////////////////////////////////////////
/*
client.print("<table border='1'>");///cabeçalho tabela
client.print("<tr><td> ");///////////continução tabela         


client.print(" </td></tr>  ");////////fim da tabela
client.print("</table> ");///////////fim da tabela

///////////////////////////fim da tabela///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
*/
client.print(da);
client.print("<br/ > ");
client.stop();
}}}}

DateTime now = rtc.now();


 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////continuação função milis
///////////////////////////
//Lógica de verificação do tempo
  if (currentMillis - previousMillis > intColetas) { 
    previousMillis = currentMillis;    // Salva o tempo atual

Serial.println(" ");
Serial.println(" "); 
 
Serial.println("coleta de leituras"); 
DateTime now = rtc.now();
    
    
    Serial.print(now.day(), DEC);
    Serial.print("/");
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(' ');
   Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println(" ");
    Serial.println(" ");
///////////////////////////////////////////
//////////////////cartão
   pinMode(10, OUTPUT);   // desliga web para acionar o sd
  

  File dataFile = SD.open("casinhas.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
  
   dataFile.print(now.day(), DEC);
    dataFile.print(" ");
   dataFile.print('/');
    dataFile.print(now.month(), DEC);
    dataFile.print('/');
dataFile.print(now.year(), DEC);
    dataFile.print(',');
        dataFile.print(now.hour(), DEC);
    dataFile.print(':');
    dataFile.print(now.minute(), DEC);
    dataFile.print(':');
    dataFile.print(now.second(), DEC);
    dataFile.print("");
    dataFile.print(",");


    dataFile.print(t8);
    dataFile.print(",");
    dataFile.print(h8);
    dataFile.print(",");
    dataFile.print(t4);
    dataFile.print(",");
    dataFile.print(h4);
    dataFile.print(",");
    dataFile.print(t3);
    dataFile.print(",");
    dataFile.print(h3);
    dataFile.print(",");
    dataFile.print(t6);
    dataFile.print(",");
    dataFile.print(h6);
    dataFile.print(",");
    dataFile.print(t7);
    dataFile.print(",");
    dataFile.print(h7);
    dataFile.print(",");
    dataFile.print(t2);
    dataFile.print(",");
    dataFile.print(h2);
    dataFile.print(",");
    dataFile.print(t);
    dataFile.print(",");
    dataFile.print(h);
    dataFile.print(",");
    dataFile.print(t5);
    dataFile.print(",");
    dataFile.println(h5);
    dataFile.close();
    // print to the serial port too:
    //Serial.println();
    
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }




}
}
