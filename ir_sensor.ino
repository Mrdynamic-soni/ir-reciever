#include<IRremote.h>
  const int recieverPin=7;
  IRrecv reciever(recieverPin);
  decode_results results;
  unsigned long key_value = 0;
  void setup(){
    Serial.begin(9600);
    reciever.enableIRIn();
    reciever.blink13(true);
  }
  void loop(){
    if(reciever.decode(&results)){
      if(results.value == 0xFFFFFFFF){
      results.value = key_value;
    }
     switch (results.value){
      case 0xFF6897:
      Serial.println("0");
      break;

      case 0xFFB04F:
      Serial.println("1");
      break;

      case 0xFF9867:
      Serial.println("2");
      break;

      case 0xFFD827:
      Serial.println("3");
      break;

      case 0xFF807F:
      Serial.println("4");
      break;

      case 0xFF8877:
      Serial.println("5");
      break;

      case 0xFFA857:
      Serial.println("6");
      break;

      case 0xFFE817:
      Serial.println("7");
      break;

      case 0xFF609F:
      Serial.println("8");
      break;

      case 0xFF48B7:
      Serial.println("9");
      break;
      }
      key_value = results.value;
      reciever.resume();
    }
  }
