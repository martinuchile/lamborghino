void setup() {
  Serial.begin(9600);
  initMotores();
  Serial.println("==== Test de Motores ====");
  delay(1000);
}

void loop() {
  Serial.println("[1] Avance 2s"); setMotores(120,120); delay(2000);
  Serial.println("[2] Stop");      setMotores(0,0);     delay(600);
  Serial.println("[3] Reversa");   setMotores(-120,-120); delay(2000);
  Serial.println("[4] Giro L/R");  setMotores(-120,120); delay(1200);
                                   setMotores(120,-120); delay(1200);
  setMotores(0,0); delay(600);
  Serial.println("[5] Rampa PWM"); for (int v=0; v<=255; v+=15){ setMotores(v,v); Serial.print("PWM="); Serial.println(v); delay(200); }
  setMotores(0,0);
  Serial.println("Repite en 2s..."); delay(2000);
}
