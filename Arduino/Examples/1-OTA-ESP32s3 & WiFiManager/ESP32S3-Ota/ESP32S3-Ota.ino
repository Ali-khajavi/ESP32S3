/* The ESP32S3-Ota pass the test by ESP32S3 R8N16 modele 
  To Use the Example please Edite the falowing code,
  except you prefer to use it as the defult
  Ali Khajavi 2024 Ingolstadt*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OTA Call Libraries ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// to enable OTA please uncomment the the definnition
#define OTA_Enable enable
// enable OTA

#ifdef OTA_Enable
  #include <ESPmDNS.h>
  #include <NetworkUdp.h>
  #include <ArduinoOTA.h>
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ End OTA Libraries ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WIFI Connection ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// There is two option for the esp to connect to your network
// 1- Connection with the fix ssid and password
// 2- if ESP has no network connection it will turn as access point 
// then manually you could select your network for the ESP
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Option 1 : to use the option one please uncomment the below code
/* #define wifi_pass "your wifi password"
#define wifi_ssid "your wifi ssid" */

// Option 2 : the option 2 is avtive by defult, to use the option 1 please comment falowong option 2 commands
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager


#ifdef wifi_pass & wifi_ssid
  #include <WiFi.h>
  #include <WiFiUdp.h>
#endif

void setup() {
  Serial.begin(115200);
  Serial.println('ESP32 Resterted');

  WiFiManager wifiManager;
  wifiManager.autoConnect("ESP32S3"); // your access point name
  Serial.println("Connected to the configured WiFi");

  // wifimanager can run in a blocking mode or a non blocking mode
  // Be sure to know how to process loops with no delay() if using non blocking
  bool wm_nonblocking = false; // change to true to use non blocking


  ArduinoOTA.setHostname("OTAESP32");  // OTA Name
  ArduinoOTA.setPassword("pass");      // OTA Password
  ArduinoOTA.begin();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Error Call Back Handler ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
  ArduinoOTA
    .onStart([]() {
      Serial.println("Started updating");
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", progress / (total / 100));
      
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
    });
}

void loop() {
  ArduinoOTA.handle();
}
