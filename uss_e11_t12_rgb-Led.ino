const int trigPin = 12;
const int echoPin = 11;
int redPin = 2;
int greenPin = 3;
int bluePin = 4;

long duration;
int distance;

void setup() 
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.println(distance);
  setColor(0,0,0);
  
  
  if (distance < 15){
    setColor(255, 0, 0);  // red
    //Serial.println("<10");
  }


  if (15 < distance < 30){
    setColor(0,0,255);  //blue
  }


  if (distance > 50){
    setColor(0,255,0);  //green
  }
  
}



void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
