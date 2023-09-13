#include<EasyBuzzer.h>;

int led=8;
int trigger=3;
int echo=2;
int tiempo=0;
int distancia=0;
int contador=0;
bool detectSomething = false;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  EasyBuzzer.setPin(7);
}

void loop() {
  digitalWrite(trigger,LOW);
  delay(2);
  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger,LOW);
  tiempo=pulseIn(echo,HIGH);
  distancia=(tiempo/2)/29;
//  Serial.println(distancia);
  if(distancia<50){
    digitalWrite(led,HIGH);
    EasyBuzzer.singleBeep(440, 500);
    delay(1000);
  }else{
    digitalWrite(led,LOW);
    contador=contador;
    detectSomething = false;
  }
  if(digitalRead(led)==HIGH && !detectSomething)
  {
    contador++;
    delay(300);
    detectSomething=true;
  }
  Serial.println(contador);
  Serial.print(" ");
  Serial.print(distancia);
  Serial.print(" cm ");

}