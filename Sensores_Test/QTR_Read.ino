#define pinIR 11
int s[6]={0,0,0,0,0,0};
int pos=0, lastPos=0;

void initSensores(){ pinMode(pinIR, OUTPUT); }

void leerSensores(){
  digitalWrite(pinIR, HIGH);
  s[0]=analogRead(A1); s[1]=analogRead(A2); s[2]=analogRead(A3);
  s[3]=analogRead(A4); s[4]=analogRead(A5); s[5]=analogRead(A6);
  digitalWrite(pinIR, LOW);
  for(int i=0;i<6;i++){ s[i]=map(s[i],0,1023,1023,0); } // invertir (línea negra)
}

int getPos(){
  leerSensores();
  float sp=-2.5*s[0]-1.5*s[1]-0.5*s[2]+0.5*s[3]+1.5*s[4]+2.5*s[5];
  float su=(float)(s[0]+s[1]+s[2]+s[3]+s[4]+s[5]);
  bool onLine = (su>1000);
  if(onLine){ pos=(int)(100.0*sp/su); }
  else{ pos=(lastPos<0)?-255:255; }
  lastPos=pos; return pos;
}

void printLecturas(int posicion){
  Serial.print("s: ");
  for(int i=0;i<6;i++){ Serial.print(s[i]); if(i<5) Serial.print('\t'); }
  Serial.print(" | pos="); Serial.println(posicion);
}
