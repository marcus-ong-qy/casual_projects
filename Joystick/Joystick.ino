// code referenced and modified from 
// http://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-joystick-with-serial-monitor-1f04f0

int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int xErr = 0;
int yErr = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = !digitalRead(SW);

  if (SW_state) {
    xErr = xPosition - 512;
    yErr = yPosition - 512;
    Serial.println("Controls Calibrated");
  }

  mapX = map(xPosition - xErr, 0, 1023, -512, 512);
  mapY = map(yPosition - yErr, 0, 1023, -512, 512);

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  delay(100);
  
}
