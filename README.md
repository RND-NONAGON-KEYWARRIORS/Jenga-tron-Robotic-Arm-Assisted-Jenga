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
*Import essential libraries for the color sensor, Wi-Fi module, and Blynk

<b>Step 2. Define Constants:</b><br>

*Define constants for Blynk authentication token and Wi-Fi credentials.<br>
*Define pin numbers for the servos.<br>


<b>Step 3. Initialize Objects and Variables:</b><br>

*Initialize the driver library for  color sensor (Adafruit_TCS34725).<br>
*Create the five servo motor objects (servo1, servo2, servo3, servo4, servo5).<br>
*Set pin values for LED Lights(redled1, greenled1,  blueled1) as integers<br>
*Set pin values for Robot Arm Servos (base, firstservo, secondservo, end effector, platform) as integers<br>
*Initialize color values(redval, greenval,  blueval) as integers and set all to 0<br>
*Initialize variables (rotate, maxstacknotif, start, revolute, slightmove) as integers and set all  to 0<br>
*Initialize placeangle as integer<br>
*Initialize checkpoints (redcheckpoint,greencheckpoints, bluecheckpoints) as integers and set all to 1<br>

<b>Step 4. Setup Function:</b><br>

*Initialize the color sensor integration time and gain.<br>
*Initialize the Blynk authentication token with Wi-Fi credentials<br>
*Connect to the Wi-Fi network and start Blynk (Blynk.begin).<br>
*Attach the servos to their respective pins (servo1.attach, servo2.attach, servo3.attach, servo4.attach, servo5.attach).<br>
*Set pinMode for LEds(redled1, greenled1, blueled1) as OUTPUT<br>
*Set the LEDs to HIGH to turn off LEDs.<br>

<b>Step 5. Increment Function:</b><br>

*Control the rotation of servo5 (platform) for slight and big movements by:<br>
>*Performing a function(smallmoveincrement)  to increment the servo position for slight movements 
*Performing a function(bigmoveincrement) to increment the servo position for big movements<br>
*Performing a function(bigrotatefirst) to rotate the servo slightly to a specific angle<br>
*Performing a function(biggggrotatefirst) to rotate the servo to a considerable  specific amount of angle.<br>
>
*Define and get the parameter  from the virtual  buttons (V4, V5, V6) for red, blue, and green respectively of the Blynk app or website.<br>

<b>Step 6. Drop angle  Function:</b><br>

*Initialize  increments for the placeangle of servo2 and servo4 based on their value<br>
*Initialize default position function to set servo1 to 90 degrees, servo2 to 10 degrees, servo3 to 0 degrees, and servo4 to 0 degrees.<br>

<b>Step 7.  Loop Function:</b><br>

*Call Blynk.run() to handle Blynk-related tasks.<br>
*Get the RGB values from the color sensor and check for the dominant color (red, green, or blue).<br>
*Increment the respective color counter (redval, greenval, blueval) based on the dominant color detected.<br>
*If a specific number of color button presses, for instance (redval == 1) is reached, perform a series of actions based on the checkpoint for that color (redcheckpoint, greencheckpoint, bluecheckpoint). This includes moving the robotic arm to specific positions, rotating servos, and adjusting angles before placing the object.<br>
*Check if the maximum stack notification is reached:<br>
>*If the maximum stack notification (maxstacknotif >= 5) is reached, flash the LEDs as an alert.<br>

<b>Step 8. End:</b><br>


<b>HARDWARE SCHEMATICS</b><br>


![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/134179620/81526321-6311-4a5a-85ac-40c34003bf18)

<b>FLOW CHART</b><br>


![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/134179620/196d2c5d-7149-45d6-a41d-9e595ed19892)

<b>SIMULATION/TESTING</b><br>
<b>A. SIMULATION RESULTS (Simulation link -https://wokwi.com/projects/370297394449006593)</b><br>
![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/134179620/d1a20348-7f23-4e1a-8e76-00d401426ced)
![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/134179620/5103bb7c-1f3f-4042-bb0f-6cdad62ec30f)



<b>A. ACTUAL RESULTS</b><br>

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/75fff169-ef76-4730-a903-11e154b3f10c)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/3051d9dd-7465-4212-b8a5-97783ae93329)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/faf01726-c4f6-479f-ab08-7f59368a96f3)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/407da56e-248d-449f-9fcf-176968ae778b)

<b>B. USING BLYNK APP</b><br>

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/1e672c0a-8247-4487-b494-f040ae8f6dee)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/286b4d18-0316-4c8b-8045-2e77c8d41eab)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/b993b76e-6d58-4dee-8a7e-a1dab85f1815)

![image](https://github.com/RND-NONAGON-KEYWARRIORS/Jenga-tron-Robotic-Arm-Assisted-Jenga/assets/143982031/1e359dec-4cb3-42db-8f6d-4b75ff250752)

<b>RECOMMENDATIONS</b><br>
*Plan and prototype thoroughly. This will help identify design flaws and potential challenges early on.
*Use real components early in the testing process. This will give a better understanding of the project's limitations and requirements.<br>
*Invest in high-quality servo motors. This will minimize the chances of malfunctions.<br>
*Ensure all connections are secure. Use appropriate connectors to avoid intermittent issues with the wires.<br>
*Perform code reviews and optimizations. This will identify and eliminate any potential bugs and inefficiencies.<br>
*Develop a realistic project timeline and adhere to it strictly. This will allow for better allocation of resources and time to address any unforeseen challenges.<br>
*Have backup components readily available. This will prevent delays caused by waiting for replacements.<br>
*Regularly test the robot arm and seek feedback from peers or mentors. This will help identify blind spots and suggest potential improvements.<br>
*Keep detailed records of the project's progress. This will facilitate troubleshooting and future improvements.<br>
*Conduct a thorough evaluation of the entire process. This will help identify what worked well, what could be improved, and what lessons were learned.<br>

