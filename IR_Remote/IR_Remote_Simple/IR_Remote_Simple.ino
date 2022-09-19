#include <IRremote.hpp>
int RECV_PIN = 11; // Declare variables to hold pin number

IRrecv irrecv(RECV_PIN); // Create irrecv object
decode_results results; // declare variable to hold decoded IR receiver result
 
void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600); //Initialize serial monitor
  Serial.println("Enabling IR Receiver"); // Print text on serial monitor
//  irrecv.enableIRIn(); // Start the IR receiver
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  Serial.println("Enabled IR Receiver"); // Print text on serial monitor

  
}
 
void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) { // Checks the code received or not
    Serial.print("Decoded Signal = "); //Print text on serial monitor
//    Serial.println(IrReceiver.decode()); // Print the decoded value on serial monitor
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
//    IrReceiver.printIRResultShort(&Serial); // optional use new print version
    IrReceiver.resume(); // Enable receiving of the next value
  }
  delay(100);
}

#include <IRremote.hpp>


//void loop() {
//  if (IrReceiver.decode()) {
//      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
//      IrReceiver.printIRResultShort(&Serial); // optional use new print version
//      ...
//      IrReceiver.resume(); // Enable receiving of the next value
//  }
//  ...
//}
