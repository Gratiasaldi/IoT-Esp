#include <ESP8266WiFi.h>  // Jika menggunakan ESP8266
//#include <WiFi.h>        // Jika menggunakan ESP32

const char* ssid = "Nama_WiFi_Anda";
const char* password = "Kata_Sandi_WiFi_Anda";

void setup() {
  Serial.begin(115200);

  // Menghubungkan ke Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: " + WiFi.localIP());
}

void loop() {
  // Kode lain yang ingin Anda tambahkan setelah koneksi terhubung
}
