#include <SPI.h>
#include <dht11.h>
 #include <nRF24L01.h>
 #include <RF24.h>
 #define CE_PIN 9
 #define CSN_PIN 10
 
int DhtPin=5; // DhtPin olarak Dijital 2'yi belirliyoruz.
dht11 dht_sensor;
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
RF24 radio(CE_PIN, CSN_PIN);
int data[4]; // depending on the number of sensors you want to use
int vresistor = A0; 
int vrdata; 
 
void setup()
 {
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
 pinMode(vresistor,INPUT);
 
 }
 
void loop()
 {
 
int chk = dht_sensor.read(DhtPin);

  int f= dht_sensor.fahrenheit();
  int nem= dht_sensor.humidity;
  //int text =0 ; // maksimium 32 karakter olabilir
  //radio.write(&f, sizeof(f));
  Serial.print(f);
  delay(1000);
 
data[0] = 232;  // code to identify the transmitter. 
data[1] = f; 
radio.write( data, sizeof(data) );
 }
