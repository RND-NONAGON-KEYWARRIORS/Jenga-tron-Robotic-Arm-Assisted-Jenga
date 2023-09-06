#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <ESP32Servo.h>
#include <BlynkSimpleEsp32.h>




// Create an instance of the color sensor
Adafruit_TCS34725 colorSensor;




// Blynk authentication token and Wi-Fi credentials
char auth[] = "zXnxsbboQ_3xpQZcw8EltxBWJ18ln_Ty";
char ssid[] = "Dayonkneel";
char pass[] = "12345678";




// Blynk template information
#define BLYNK_TEMPLATE_ID "TMPL6TAT0g3Hl"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"




// Servo motor objects
Servo servo1, servo2, servo3, servo4, servo5;




// Variables for tracking color button presses and rotation angles
int redbutton = 12, greenbutton = 14, bluebutton = 13;
int redled1 = 26, greenled1 = 32, blueled1 = 27;
int startbutton = 34, buttonstop = 35;
int base = 19, firstservo = 18, secondservo = 17, endeffector = 5, platform = 16;
int redval = 0, greenval = 0, blueval = 0;
int rotate = 0;
int maxstacknotif = 0;
int start = 0;
int placeangle;
int redcheckpoint = 1, greencheckpoint = 1, bluecheckpoint = 1;
int revolute = 0;
int slightmove = 0;




void setup() {
  // Set color sensor integration time and gain
  colorSensor.setIntegrationTime(0xF6); // 700ms integration time
  colorSensor.setGain(TCS34725_GAIN_4X);




  // Initialize Blynk with Wi-Fi credentials and authentication token
  Blynk.begin(auth, ssid, pass);
  Serial.begin(115200);




  // Attach servo motors to their respective pins
  servo1.attach(base);
  servo2.attach(firstservo);
  servo3.attach(secondservo);
  servo4.attach(endeffector);
  servo5.attach(platform);




  // Set pin modes for LEDs
  pinMode(redled1, OUTPUT);
  pinMode(greenled1, OUTPUT);
  pinMode(blueled1, OUTPUT);




  // set led initially off
  digitalWrite(redled1, HIGH);
  digitalWrite(greenled1, HIGH);
  digitalWrite(blueled1, HIGH);
}
// Function to increment the servo position for slight movements
void smallmoveincrement(){
  slightmove = 15;
  for (int rotate = 0; rotate <= slightmove; rotate++){
    servo5.write(rotate);
    delay(10);
  }  
}
// Function to increment the servo position for big movements
void bigmoveincrement(){
  slightmove = 75;
  for (int rotate = 90; rotate >= slightmove; rotate--){
    servo5.write(rotate);
    delay(10);
  }  
}
// Function to rotate the servo to a specific angle
void bigrotatefirst(){
  int revolute = 95;
  for (int rotate = 15; rotate <= revolute; rotate++){
    servo5.write(rotate);
    delay(10);
  }  
}
// Function to rotate the servo to a specific angle
void biggggrotatefirst(){
  int revolute = 5;
  for (int rotate = 75; rotate >= revolute; rotate--){
    servo5.write(rotate);
    delay(10);
  }  
}
// Blynk virtual write function for the red button
BLYNK_WRITE(V4) {
  int value = param.asInt();
  if (value >= 1) {
    redval++;
    delay(200);
    digitalWrite(blueled1, HIGH);
    digitalWrite(greenled1, HIGH);
    digitalWrite(redled1, LOW);
  }
}
// Blynk virtual write function for the blue button
BLYNK_WRITE(V5) {
  int value = param.asInt();
  if (value >= 1) {
    blueval++;
    delay(200);
    digitalWrite(blueled1, LOW);
    digitalWrite(greenled1, HIGH);
    digitalWrite(redled1, HIGH);
  }
}
// Blynk virtual write function for the green button
BLYNK_WRITE(V6) {
  int value = param.asInt();
  if (value >= 1) {
    greenval++;
    delay(200);
    digitalWrite(blueled1, HIGH);
    digitalWrite(greenled1, LOW);
    digitalWrite(redled1, HIGH);
  }
}
// Function to adjust the angle before placing the object
void dropangle() {
  placeangle++;
   // Set different angles based on placeangle value
  if (placeangle == 1 || placeangle == 2) {
    servo2.write(60);
    delay(1000);
    servo4.write(30);
    delay(1000);
    servo2.write(10);
    delay(1000);
  } else if (placeangle == 3 || placeangle == 4) {
    servo2.write(50);
    delay(1000);
    servo4.write(30);
    delay(1000);
    servo2.write(10);
    delay(1000);
  } else if (placeangle == 5 || placeangle == 6) {
    servo2.write(40);
    delay(1000);
    servo4.write(30);
    delay(1000);
    servo2.write(10);
    delay(1000);
  } else if (placeangle == 7 || placeangle == 8) {
    servo2.write(30);
    delay(1000);
    servo4.write(30);
    delay(1000);
    servo2.write(10);
    delay(1000);
  } else if (placeangle == 9 || placeangle == 10) {
    servo2.write(20);
    delay(1000);
    servo4.write(30);
    delay(1000);
    servo2.write(10);
    delay(1000);
  }
}
// Function to move the robotic arm to its default position
void defaultposition(){
    servo1.write(90);
    delay(500);
    servo2.write(10);
    delay(500);
    servo3.write(0);
    delay(500);
    servo4.write(0);
    delay(500);
}
void loop() {
  Blynk.run();
 
  // Check the color using the color sensor
  float red, green, blue;
  colorSensor.getRGB(&red, &green, &blue);
  if ((red - green > 50) && (red - blue > 50)) {
    delay(200);
    redval++;
    digitalWrite(blueled1, LOW);
    digitalWrite(greenled1, LOW);
    digitalWrite(redled1, HIGH);
    delay(200);
  } else if ((green - blue > 10) && (green - red > 30)) {
    greenval++;
    digitalWrite(blueled1, LOW);
    digitalWrite(greenled1, HIGH);
    digitalWrite(redled1, LOW);
    delay(200);
  } else if ((blue - green > 20) && (blue - red > 40)) {
    blueval++;
    digitalWrite(blueled1, HIGH);
    digitalWrite(greenled1, LOW);
    digitalWrite(redled1, LOW);
    delay(200);
  } else {
    digitalWrite(blueled1, LOW);
    digitalWrite(greenled1, LOW);
    digitalWrite(redled1, LOW);
  }








  if (redval == 1 && redcheckpoint == 1) {
    defaultposition();
    delay(15);
    maxstacknotif++;
    Serial.print("Stack: ");
    Serial.println(maxstacknotif);
    digitalWrite(greenled1, HIGH);
    digitalWrite(redled1, LOW);
    digitalWrite(blueled1, HIGH);
    servo1.write(180);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(60);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(5);
    delay(1000);
    dropangle();
    delay(1000);
    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      smallmoveincrement();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      bigmoveincrement();
    }
    servo1.write(180);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(70);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(20);
    delay(1000);
    dropangle();
    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      bigrotatefirst();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      biggggrotatefirst();
    }
    redcheckpoint = 2;
    redval = 0;
  } else if (redval == 1 && redcheckpoint == 2) {
    defaultposition();
    delay(15);
    maxstacknotif++;
    Serial.print("Stack: ");
    Serial.println(maxstacknotif);
    digitalWrite(greenled1, HIGH);
    digitalWrite(redled1, HIGH);
    digitalWrite(blueled1, HIGH);
    servo1.write(160);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(60);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(5);
    delay(1000);




    dropangle();
    delay(1000);




    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      smallmoveincrement();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      bigmoveincrement();
    }




    servo1.write(160);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(70);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(20);
    delay(1000);




    dropangle();




    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      bigrotatefirst();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      biggggrotatefirst();
    }
    redcheckpoint = 3;
    redval = 0;




  } else if (redval == 1 && redcheckpoint == 3) {




    delay(200);
    redcheckpoint = 0;
    redval = 0;
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(redled1, LOW);
  }




  if (greenval == 1 && greencheckpoint == 1) {




    defaultposition();
    delay(15);
    maxstacknotif++;
    Serial.print("Stack: ");
    Serial.println(maxstacknotif);
    digitalWrite(greenled1, LOW);
    digitalWrite(redled1, HIGH);
    digitalWrite(blueled1, HIGH);
     
    servo1.write(140);
    delay(1000);




    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(60);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(5);
    delay(1000);




    dropangle();
    delay(1000);




    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      smallmoveincrement();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      bigmoveincrement();
    }








    servo1.write(140);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(70);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(20);
    delay(1000);








    dropangle();








    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      bigrotatefirst();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      biggggrotatefirst();
    }
    greencheckpoint = 2;
    greenval = 0;




  } else if (greenval == 1 && greencheckpoint == 2) {




    defaultposition();
    delay(15);
    maxstacknotif++;
    Serial.print("Stack: ");
    Serial.println(maxstacknotif);
    digitalWrite(greenled1, HIGH);
    digitalWrite(redled1, HIGH);
    digitalWrite(blueled1, HIGH);
     
    servo1.write(120);
    delay(1000);
   
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(60);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(5);
    delay(1000);
   
    dropangle();
    delay(1000);




    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      smallmoveincrement();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      bigmoveincrement();
    }
   
    servo1.write(120);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(70);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(20);
    delay(1000);




    dropangle();
    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      bigrotatefirst();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      biggggrotatefirst();
    }
    delay(1000);
    greencheckpoint = 3;
    greenval = 0;
  } else if (greenval == 1 && greencheckpoint == 3) {
    delay(200);
    greencheckpoint = 0;
    greenval = 0;
    digitalWrite(greenled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
  }




  if (blueval == 1 && bluecheckpoint == 1) {




    defaultposition();
    delay(15);
    maxstacknotif++;
    Serial.print("Stack: ");
    Serial.println(maxstacknotif);
    digitalWrite(greenled1, HIGH);
     
    digitalWrite(redled1, HIGH);
     
    digitalWrite(blueled1, LOW);
     




    servo1.write(100);
    delay(1000);
   
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(60);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(5);
    delay(1000);




    dropangle();
    delay(1000);
     if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      smallmoveincrement();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      bigmoveincrement();
    }




    servo1.write(100);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(70);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(20);
    delay(1000);




    dropangle();
    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      bigrotatefirst();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      biggggrotatefirst();
    }




    bluecheckpoint = 2;
    blueval = 0;




  } else if (blueval == 1 && bluecheckpoint == 2) {




    defaultposition();
    delay(15);
    maxstacknotif++;
    Serial.print("Stack: ");
    Serial.println(maxstacknotif);
    digitalWrite(greenled1, HIGH);
     
    digitalWrite(redled1, HIGH);
     
    digitalWrite(blueled1, HIGH);
     




    servo1.write(80);
    delay(1000);
   
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(60);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(5);
    delay(1000);




    dropangle();
    delay(1000);
    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      smallmoveincrement();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      bigmoveincrement();
    }




    servo1.write(80);
    delay(1000);
    servo3.write(0);
    servo4.write(30);
    delay(1000);
    servo2.write(70);
    delay(1000);
    servo4.write(0);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(100);
    delay(1000);
    servo1.write(20);
    delay(1000);




    dropangle();
    if (placeangle == 1 || placeangle == 2 || placeangle == 5 || placeangle == 6 || placeangle == 9 || placeangle == 10){
      bigrotatefirst();
    } else  if (placeangle == 3 || placeangle == 4 || placeangle == 7 || placeangle == 8){
      biggggrotatefirst();
    }
 
    bluecheckpoint = 3;
    blueval = 0;
  } else if (blueval == 1 && bluecheckpoint == 3) {




    delay(200);
    bluecheckpoint = 0;
    blueval = 0;
    digitalWrite(blueled1, HIGH);
    delay(500);
    digitalWrite(blueled1, LOW);
    delay(500);
    digitalWrite(blueled1, HIGH);
    delay(500);
    digitalWrite(blueled1, LOW);
    delay(500);
    digitalWrite(blueled1, HIGH);
    delay(500);
    digitalWrite(blueled1, LOW);
    delay(500);
    digitalWrite(blueled1, HIGH);
    delay(500);
    digitalWrite(blueled1, LOW);
    delay(500);
    digitalWrite(blueled1, HIGH);
    delay(500);
    digitalWrite(blueled1, LOW);
  }




  // Check if the maximum stack notification is reached and alert using LEDs
  if (maxstacknotif >= 5){
    // Flash the LEDs as an alert
    digitalWrite(greenled1, HIGH);
    digitalWrite(blueled1, HIGH);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    digitalWrite(blueled1, LOW);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    digitalWrite(blueled1, HIGH);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    digitalWrite(blueled1, LOW);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    digitalWrite(blueled1, HIGH);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    digitalWrite(blueled1, LOW);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    digitalWrite(blueled1, HIGH);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    digitalWrite(blueled1, LOW);
    digitalWrite(redled1, LOW);
    delay(500);
    digitalWrite(greenled1, HIGH);
    digitalWrite(blueled1, HIGH);
    digitalWrite(redled1, HIGH);
    delay(500);
    digitalWrite(greenled1, LOW);
    digitalWrite(blueled1, LOW);
    digitalWrite(redled1, LOW);
