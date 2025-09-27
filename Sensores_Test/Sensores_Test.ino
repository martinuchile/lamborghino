void setup(){ Serial.begin(9600); initSensores(); Serial.println("==== Test Sensores QTR ===="); }
void loop(){ int pos=getPos(); printLecturas(pos); delay(100); }
