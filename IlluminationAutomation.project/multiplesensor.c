#include <Thread.h>

int rly1 = 4;
int rly2 = 2;
int rly3 = 7;
int pir1 = 8;
int pir2 = 12;
int pir3 = 13;

void setup() {
  pinMode(rly1, OUTPUT);
  pinMode(rly2, OUTPUT);
  pinMode(rly3, OUTPUT);
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(pir3, INPUT);

  Serial.begin(9600);
}

void loop() {
  Thread t1 = Thread(detectMotion, "detectMotion1");
  Thread t2 = Thread(detectMotion, "detectMotion2");
  Thread t3 = Thread(detectMotion, "detectMotion3");
  t1.run();
  t2.run();
  t3.run();
}

void detectMotion(void args) {
  String threadName = String((const char)args);
  Serial.println("Starting thread " + threadName);

  int pirPin;
  int rlyPin;
  if (threadName == "detectMotion1") {
    pirPin = pir1;
    rlyPin = rly1;
  } else if (threadName == "detectMotion2") {
    pirPin = pir2;
    rlyPin = rly2;
  } else if (threadName == "detectMotion3") {
    pirPin = pir3;
    rlyPin = rly3;
  } else {
    Serial.println("Invalid thread name: " + threadName);
    return;
  }

  while (true) {
    int motion = digitalRead(pirPin);
    Serial.println(threadName + ": motion detected = " + String(motion));

    if (motion == HIGH) {
      digitalWrite(rlyPin, HIGH);
      Serial.println(threadName + ": relay turned on");
    } else {
      digitalWrite(rlyPin, LOW);
      Serial.println(threadName + ": relay turned off");
    }

    Thread::yield(); // Allow other threads to run
    delay(10); // Wait a short time before checking again
  }
}