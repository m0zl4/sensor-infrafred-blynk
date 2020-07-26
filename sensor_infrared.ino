#define BLYNK_PRINT Serial // definisi serial pada blynk

// Setting Library
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// definisi variabel token, ssid, password
char auth[] = "token blynk";
char ssid[] = "wifiname";
char pass[] = "pasword";

// definisi pin widget LED pad blynk menggunakan virtual pin
WidgetLED led(V1);

// definisi pin sensor IR yang digunakan
int sensor = D1;

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  // setting mode pin menjadi pin input
  pinMode(sensor, INPUT);

  // setting test koneksi
  while(Blynk.connected() == false){
    Serial.println("Tidak terkoneksi");
  }

}

void loop() {
  // Pembacaan sensor IR
  int sensorval = digitalRead(sensor);

  // menampilkan nilai sensor IR
  Serial.println(sensorval);
  delay(2000);

  //Pembuatan kondisi sensor dengan aktuator (led)
  if(sensorval == 1){
    led.on();
  }

  if(sensorval == 0){
    led.off();
  }

  Blynk.run();

}
