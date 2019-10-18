//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  
  //Serial.println(analogRead(0));
  //Serial.println(analogRead(1));
  int left=map(analogRead(1), 0, 1023, -255, 254);
  int right=map(analogRead(0), 0, 1023, -255, 254);
  Serial.print(left);
  Serial.print(right);
  int power[2]={left,right};
  //Send message to receiver
  radio.write(&power, sizeof(power));
}
