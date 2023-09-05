
//#include<Wire.h>

  int led=8;
  int Buzzer=7;
  int trigger=3;
  int echo=2;
  int tiempo=0;
  int distancia=0;
  int contador=0;
  bool detectSomething = false;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
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
    digitalWrite(Buzzer,HIGH);
    delay(1000);
    digitalWrite(Buzzer,LOW);
  }else{
    digitalWrite(led,LOW);
    contador=contador;
    digitalWrite(Buzzer,LOW);
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