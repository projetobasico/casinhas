/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi

 */

#include <SPI.h>
#include <Ethernet.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>
/////////////////////////////////////////////////////

#define DHTPIN 2     // what digital pin we're connected to
#define DHTPIN2 7     // what digital pin we're connected to
#define DHTPIN3 8     // what digital pin we're connected to
#define DHTPIN4 9     // what digital pin we're connected to



#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);

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

void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
  
      Serial.println("DHTxx test!");

  dht.begin();
    
    
    ; // wait for serial port to connect. Needed for native USB port only
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {

  ////////DHT/////
delay(2000);

 
  float h = dht.readHumidity();
 
  float t = dht.readTemperature();
  
  float h2 = dht2.readHumidity();
 
  float t2 = dht2.readTemperature();

    float h3 = dht3.readHumidity();
 
  float t3 = dht3.readTemperature();

float h4 = dht4.readHumidity();
 
  float t4 = dht4.readTemperature();
  

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    //return;
  }

    Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  
  Serial.print("Humidity2: ");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperature2: ");
  Serial.print(t2);
  Serial.println(" *C ");
 
Serial.print("Humidity3: ");
  Serial.print(h3);
  Serial.print(" %\t");
  Serial.print("Temperature3: ");
  Serial.print(t3);
  Serial.println(" *C ");

Serial.print("Humidity4: ");
  Serial.print(h4);
  Serial.print(" %\t");
  Serial.print("Temperature4: ");
  Serial.print(t4);
  Serial.println(" *C ");
  /////////////////////////////
  
  
  
  
  
  
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
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          

                        client.print("<center> ");

             client.print("<h1> UNIVERSIDADE ESTADUAL DE MARINGA</h1>");
            client.print("<h1> UEM </h1>");
            ////////////////////////////////////////////////////////////
client.print("<h2> ");

client.print("Humidity: ");
  client.print(h);
  client.print(" %\t");
  client.print("Temperature: ");
  client.print(t);
  client.println(" *C ");
 client.print("<br/ > ");

  /////sengudo sensor
client.print("Humidity2: ");
  client.print(h2);
  client.print(" %\t");
  client.print("Temperature2: ");
  client.print(t2);
  client.println(" *C ");

  client.print("<br/ > ");

 
//////terceiro sensor

client.print("<h2> ");

client.print("Humidity3: ");
  client.print(h3);
  client.print(" %\t");
  client.print("Temperature3: ");
  client.print(t3);
  client.println(" *C ");
 client.print("<br/ > ");

//////quarto sensor

client.print("<h2> ");

client.print("Humidity4: ");
  client.print(h4);
  client.print(" %\t");
  client.print("Temperature4: ");
  client.print(t4);
  client.println(" *C ");
 client.print("<br/ > ");



  /////////


            //////////////////////////////////////////////////////
            client.print(" <a href='http://www.folha-digital.com/campus/?temperatura=11'>FOLHA DIGITAL</a>");
            client.print(" ");
            client.print(" ");
            client.print(" ");
             client.println("<br />");
             client.stop();
        }}}}}
