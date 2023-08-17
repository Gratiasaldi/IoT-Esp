#include <ESP8266WiFi.h>  // Jika menggunakan ESP8266
//#include <WiFi.h>        // Jika menggunakan ESP32

const char* ssid = "Nama_WiFi_Anda";
const char* password = "Kata_Sandi_WiFi_Anda";
const char* serverUrl = "http://example.com/data_receiver";

void setup() {
  Serial.begin(115200);

  // Menghubungkan ke Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Kirim data ke server melalui HTTP POST
    String data = "sensor=temperature&value=25.5";
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST(data);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.println("Error in HTTP POST request");
    }
    http.end();
    
    delay(5000); // Kirim data setiap 5 detik
  }
  else {
    // Jika koneksi terputus, coba sambungkan ulang
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Reconnecting to WiFi...");
    }
    Serial.println("Reconnected to WiFi");
  }
}
