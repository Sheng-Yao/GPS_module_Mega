#include <Arduino.h>
#include <TinyGPS++.h>

// create a instance for GPS module to use the library function
TinyGPSPlus gps;

//Timer variable (in milliseconds)
unsigned long time;

void setup() {

  //setup Serial port to monitor and troubleshooting purpose.
  Serial.begin(9600);

  //setup communication with NEO-6M (GPS module)
  Serial3.begin(4800);
  /* Check is it pin 14 and 15 */

  //initialize the value for timer
  time = millis();
}

void loop() {

  //Create a temperary timer that holds current time.
  unsigned long tempTimer = millis();

  //put timer to allow GPS module sending in data in fixed period (2 seconds)
  if(tempTimer - time >= 2000){

    //check for gps data to be sent from Serial3 port
    if(Serial3.available()){

      //ensure data can be encode by gps library
      if(gps.encode(Serial3.read())){

        //latitude
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(),6);

        //longitude
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(),6);

        //altitude
        Serial.print("Altitude: ");
        Serial.println(gps.altitude.feet());

        //speed
        Serial.print("Speed: ");
        Serial.println(gps.speed.mph());

        //number of connected satellites
        Serial.print("No of satellites: ");
        Serial.println(gps.satellites.value());

        //update the timer here (to ensure that the data must be obtained in 2 seconds, continuously try is failed)
        time = tempTimer;

      }else{

        //Error handling and troubleshooting purpose
        Serial.println("Failed to encode GPS data.");
      }
    }else{

      //Error handling and troubleshooting purpose
      Serial.println("No data being obtained from Serial 3 port.");
    }
    
    //Adding seperator for ease of reading
    Serial.println();
    Serial.println("-------------------------------");
    Serial.println();
  }
}
