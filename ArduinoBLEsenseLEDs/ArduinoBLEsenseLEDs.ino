void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PWR, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_PWR, LOW);
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

void loop() {

  if(Serial.available() > 0)
  {
    String at = Serial.readStringUntil('\n');

    if(at == "AT+LED=LEDR:0") { digitalWrite(LEDR, HIGH); Serial.println("Led LEDR off!"); }
    else if(at == "AT+LED=LEDR:1") { digitalWrite(LEDR, LOW); Serial.println("Led LEDR on!"); }
    else if(at == "AT+LED=LEDG:0") { digitalWrite(LEDG, HIGH); Serial.println("Led LEDG off!"); }
    else if(at == "AT+LED=LEDG:1") { digitalWrite(LEDG, LOW); Serial.println("Led LEDG on!"); }
    else if(at == "AT+LED=LEDB:0") { digitalWrite(LEDB, HIGH); Serial.println("Led LEDB off!"); }
    else if(at == "AT+LED=LEDB:1") { digitalWrite(LEDB, LOW); Serial.println("Led LEDB on!"); }
    else if(at == "AT+LED=LED_BUILTIN:0") { digitalWrite(LED_BUILTIN, LOW); Serial.println("Led LED_BUILTIN off!"); }
    else if(at == "AT+LED=LED_BUILTIN:1") { digitalWrite(LED_BUILTIN, HIGH); Serial.println("Led LED_BUILTIN on!"); }
    else if(at == "AT+LED=LED_PWR:0") { digitalWrite(LED_PWR, LOW); Serial.println("Led LED_PWR off!"); }
    else if(at == "AT+LED=LED_PWR:1") { digitalWrite(LED_PWR, HIGH); Serial.println("Led LED_PWR on!"); }
  }
}
