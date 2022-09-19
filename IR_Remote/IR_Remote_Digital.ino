#include <IRremote.hpp>
int RECV_PIN = 11; // Declare variables to hold pin number
int RECV_LED = 13; // Controls LED beside receiver

int A = 7;
int B = 6;
int C = 4;
int D = 3;
int E = 2;
int F = 8;
int G = 9;
int DP = 5;

// Remote Control Decoder
const long int ZERO = 0xE916FF00; const int ZERO_SEQ = 0xEE;
const long int ONE = 0xF30CFF00; const int ONE_SEQ = 0x28;
const long int TWO = 0xE718FF00; const int TWO_SEQ = 0xCD;
const long int THREE = 0xA15EFF00; const int THREE_SEQ = 0x6D;
const long int FOUR = 0xF708FF00; const int FOUR_SEQ = 0x2B;
const long int FIVE = 0xE31CFF00; const int FIVE_SEQ = 0x67;
const long int SIX = 0xA55AFF00; const int SIX_SEQ = 0xE7;
const long int SEVEN = 0xBD42FF00; const int SEVEN_SEQ = 0x2C;
const long int EIGHT = 0xAD52FF00; const int EIGHT_SEQ = 0xEF;
const long int NINE = 0xB54AFF00; const int NINE_SEQ = 0x6F;

int get_sequence(long int code) {
  switch(code) {
    case ZERO:
      return ZERO_SEQ;
    case ONE:
      return ONE_SEQ;
    case TWO:
      return TWO_SEQ;
    case THREE:
      return THREE_SEQ;
    case FOUR:
      return FOUR_SEQ;
    case FIVE:
      return FIVE_SEQ;
    case SIX:
      return SIX_SEQ;
    case SEVEN:
      return SEVEN_SEQ;
    case EIGHT:
      return EIGHT_SEQ;
    case NINE:
      return NINE_SEQ;
    default:
      return 0;
  }
}

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
    digitalWrite(RECV_LED, HIGH);
    Serial.print("Decoded Signal = "); //Print text on serial monitor
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    int seq = get_sequence(IrReceiver.decodedIRData.decodedRawData);
    Serial.println(seq, HEX);
    if (seq) {
      digitalWrite(E, seq & 0x80 ? HIGH:LOW);
      digitalWrite(D, seq & 0x40 ? HIGH:LOW);
      digitalWrite(C, seq & 0x20 ? HIGH:LOW);
      digitalWrite(DP, seq & 0x10 ? HIGH:LOW);
      digitalWrite(B, seq & 0x08 ? HIGH:LOW);
      digitalWrite(A, seq & 0x04 ? HIGH:LOW);
      digitalWrite(F, seq & 0x02 ? HIGH:LOW);
      digitalWrite(G, seq & 0x01 ? HIGH:LOW);
    }
    IrReceiver.resume(); // Enable receiving of the next value
    digitalWrite(RECV_LED, LOW);
  }
  delay(100);
}

#include <IRremote.hpp>
