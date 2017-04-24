int dist() {
  int distance, duration;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  return distance = duration / 58.2;
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);

