int relay1 = 12;
int relay2 = 14;

void setup() {
  pinMode(relay1, OUTPUT)
  pinMode(relay2, OUTPUT);
}

void loop() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  delay(1000);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  delay(1000);                      
}
