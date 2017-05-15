
//Funçao que retorna o valor da distancia 
//medida pelo sensor ultrassonico

int dist() {
  int distance, duration;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);    //Emite um pulso 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);    //Calcula o tempo ate que o pulso retorne ao sensor
  return distance = duration / 58.2;
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
