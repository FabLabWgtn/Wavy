int LED = 10; // put your LED light in pin 10
int echoPin = 8;//put echoPin in pin 8
int trigPin = 9; //put trigPin in pin 9

int distance;
int Brightness=0;

/*change here*/
int minDistance=1; //set your min distance to get full brightness, 1=1cm
int maxDistance=15; // set your max distance to get the fastest control distance, 25 means up to 25cm as rang
/*change here*/

void setup(){
  Serial.begin(9600);  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
}

void loop() {
  
  /*PART1: calculate distance through sensor, dont change*/
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  
  
  /*PART2: brightness setting*/
  if(distance <= maxDistance){  
  Brightness = map (distance,maxDistance, minDistance, 0, 255);
  analogWrite(LED, Brightness);
  }

  if(distance>maxDistance && distance<=(maxDistance+5)){
   digitalWrite(LED,LOW);
  }

}

