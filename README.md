# Jenga-tron-Robotic-Arm-Assisted-Jenga
Project goal: Design a versatile robotic arm for precise Jenga block manipulation. Implement advanced control algorithms for accuracy. Enable IoT-based remote control via Blynk app. Thorough testing and documentation for reliability and performance.

<b>INTRODUCTION</b>

This project aims at designing and constructing a versatile robotic arm system with multiple degrees of freedom, specifically tailored for interacting with Jenga blocks. The system will incorporate a program to pick the Jenga blocks at a specific place, enabling precise and controlled movements. Advanced control algorithms will be implemented to facilitate accurate and coordinated manipulation of the robotic arm. To enhance user experience, an Internet of Things (IoT) will be designed, providing seamless interaction and control of the robotic arm system. Using the “Blynk” app as an IoT platform allows the user to remotely control the robotic arm by the use of a smartphone. Extensive testing and optimization will be conducted to ensure the system's reliability, stability, and overall performance, while comprehensive documentation will capture the entire development process, including design specifications, software code, and hardware schematics.


<b>MATERIAL</b><br>



![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/fc828e25-c676-483e-a765-ca40007b7f64)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/ada9d976-1e4a-4d79-af16-002209c37ad7)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/3b63675f-6767-4154-920b-f1b4ce0c2aeb)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/1e9b2f99-9448-47cc-8425-57f3562a3ed7)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/0c04625d-ad76-4a76-bb33-caacef28cc17)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/fabc5ee2-d982-408c-b27e-dab1c98e7a67)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/46edff77-2437-4a8c-bbec-b9990f73d249)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/28de761b-1b6c-4046-b33d-3500d468ec20)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/619908ba-2956-43d2-86c7-7481aec116c7)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/8c54be7b-326c-4299-9f3c-b268150ce850)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/16c37c0a-1a84-47f4-8737-432922f593bf)

<b>PSEUDO-CODE</b><br> 
	<b>Step 1. Import Libraries:</b><br>
<bullet>Import essential libraries for the color sensor, Wi-Fi module, and Blynk

<b>Step 2. Define Constants:</b><br>

*Define constants for Blynk authentication token and Wi-Fi credentials.
*Define pin numbers for the servos.


<b>Step 3. Initialize Objects and Variables:</b><br>

<bullet>Initialize the driver library for  color sensor (Adafruit_TCS34725).
<bullet>Create the five servo motor objects (servo1, servo2, servo3, servo4, servo5).
<bullet>Set pin values for LED Lights(redled1, greenled1,  blueled1) as integers
<bullet>Set pin values for Robot Arm Servos (base, firstservo, secondservo, end effector, platform) as integers
<bullet>Initialize color values(redval, greenval,  blueval) as integers and set all to 0
<bullet>Initialize variables (rotate, maxstacknotif, start, revolute, slightmove) as integers and set all  to 0
<bullet>Initialize placeangle as integer
<bullet>Initialize checkpoints (redcheckpoint,greencheckpoints, bluecheckpoints) as integers and set all to 1

<b>Step 4. Setup Function:</b><br>

<bullet>Initialize the color sensor integration time and gain.
<bullet>Initialize the Blynk authentication token with Wi-Fi credentials
<bullet>Connect to the Wi-Fi network and start Blynk (Blynk.begin).
<bullet>Attach the servos to their respective pins (servo1.attach, servo2.attach, servo3.attach, servo4.attach, servo5.attach).
<bullet>Set pinMode for LEds(redled1, greenled1, blueled1) as OUTPUT
<bullet>Set the LEDs to HIGH to turn off LEDs.

<b>Step 5. Increment Function:</b><br>

<bullet>Control the rotation of servo5 (platform) for slight and big movements by:
<bullet>Performing a function(smallmoveincrement)  to increment the servo position for slight movements 
<bullet>Performing a function(bigmoveincrement) to increment the servo position for big movements
<bullet>Performing a function(bigrotatefirst) to rotate the servo slightly to a specific angle
<bullet>Performing a function(biggggrotatefirst) to rotate the servo to a considerable  specific amount of angle.
<bullet>Define and get the parameter  from the virtual  buttons (V4, V5, V6) for red, blue, and green respectively of the Blynk app or website.

<b>Step 6. Drop angle  Function:</b><br>

<bullet>Initialize  increments for the placeangle of servo2 and servo4 based on their value
<bullet>Initialize default position function to set servo1 to 90 degrees, servo2 to 10 degrees, servo3 to 0 degrees, and servo4 to 0 degrees.

<b>Step 7.  Loop Function:</b><br>

<bullet>Call Blynk.run() to handle Blynk-related tasks.
<bullet>Get the RGB values from the color sensor and check for the dominant color (red, green, or blue).
<bullet>Increment the respective color counter (redval, greenval, blueval) based on the dominant color detected.
<bullet>If a specific number of color button presses, for instance (redval == 1) is reached, perform a series of actions based on the checkpoint for that color (redcheckpoint, greencheckpoint, bluecheckpoint). This includes moving the robotic arm to specific positions, rotating servos, and adjusting angles before placing the object.
<bullet>Check if the maximum stack notification is reached:
<bullet>If the maximum stack notification (maxstacknotif >= 5) is reached, flash the LEDs as an alert.

<b>Step 8. End:</b><br>


<b>HARDWARE SCHEMATICS</b><br>


![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/134179620/81526321-6311-4a5a-85ac-40c34003bf18)

<b>FLOW CHART</b><br>


![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/134179620/196d2c5d-7149-45d6-a41d-9e595ed19892)


