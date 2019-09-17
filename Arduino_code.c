
const int t0 = 38;
const int e0 = 40;

const int t2 = 34;
const int e2 = 36;

const int t1 = 42;
const int e1 = 44;

const int t3 = 46;
const int e3 = 48;

const int t4 = 30;
const int e4 = 32;

const int t5 = 26;
const int e5 = 28;

int counter = 0;


#define enA 39
#define inA1 41
#define inA2 43

#define enB 49
#define inB1 45
#define inB2 47

// defines variables
int duration;
int distance;


void setup() {
  pinMode(t0, OUTPUT);
  pinMode(e0, INPUT);

  pinMode(t1, OUTPUT);
  pinMode(e1, INPUT);

   pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);

   pinMode(t3, OUTPUT);
  pinMode(e3, INPUT);

   pinMode(t4, OUTPUT);
  pinMode(e4, INPUT);

   pinMode(t5, OUTPUT);
  pinMode(e5, INPUT);


  pinMode(enA, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

//scans[sensor#][scan#]
int scans[5][100];

void pingSet(int trigP) {
  digitalWrite(trigP, LOW);
  delayMicroseconds(2);
  digitalWrite(trigP, HIGH);
  delayMicroseconds(10);
}
float pingScan(int trig, int echo) {
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  if (distance < 0){
    distance = 0;
    }
  return distance;
}
void loop() {
  delay(20);/*
  analogWrite(enA, 200);
  analogWrite(enB, 255);

  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);

  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);*/

    pingSet(t0);
    Serial.print("c");
    Serial.println(pingScan(t0, e0));

    pingSet(t1);
    Serial.print("d");
    Serial.println(pingScan(t1, e1));

    pingSet(t2);
    Serial.print("e");
    Serial.println(pingScan(t2, e2));

    pingSet(t3);
    Serial.print("f");
    Serial.println(pingScan(t3, e3));

    pingSet(t4);
    Serial.print("g");
    Serial.println(pingScan(t4, e4));

    pingSet(t5);
    Serial.print("h");
    Serial.println(pingScan(t5, e5));

    delay(200);

  /*
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 100; i++) {
      Serial.print(scans[j][i]);
      Serial.print(", ");
    }
    
    for (int v = 0; v < 20; v++) {
      Serial.print(" ");
    }
    Serial.println(" ");
  }
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);

  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
  delay(20000000);
  */

}
