//Reserve A1 pin for gas sensor and name it as gas
int gas = A1;
//Reserve pin 4 for green led and name it as G_LED
int G_LED = 4;
//Reserve pin 7 for piezo buzzer and name it as Buzzer
int Buzzer = 7;
//Reserve pin 8 for red led and named it R_LED
int R_LED = 8;

// Define a variable val that stores the analog reading from A1 pin
int val;
//Initialize the max threshold as 300
int MAX = 300;

//Setup the sensors and actuator in arduino uno
void setup() {
  Serial.begin(9600);
  pinMode(gas ,INPUT);
  pinMode(R_LED ,OUTPUT);
  pinMode(G_LED ,OUTPUT);
  pinMode(Buzzer ,OUTPUT);
}

//Loop to check gas leakage
void loop() {
  val = analogRead(A1);
  if (val >= MAX) {
    digitalWrite(R_LED ,HIGH);
    digitalWrite(Buzzer ,HIGH);
    digitalWrite(G_LED ,LOW);
    Serial.println(val);
    Serial.println("GAS LEAKAGE DETECTED");
  }
  else {
    digitalWrite(R_LED ,LOW);
    digitalWrite(Buzzer ,LOW);
    digitalWrite(G_LED ,HIGH);
    Serial.println(val);
  }
}
