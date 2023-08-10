int lamp = 8; // choose the pin for the RELAY
int inputPin = 4; // choose the input pin (for PIR sensor)

int val = 0; pin status

void setup() {

pinMode(lamp, OUTPUT); // declare lamp as output

pinMode(inputPin, INPUT); // declare sensor as input

Serial.begin(9600);

}

void loop(){

val = digitalRead(inputPin); // read input value

Serial.println(val);

if( val== 1) {

digitalWrite(lamp,HIGH); // turn ON the lamp

} else {

digitalWrite(lamp,LOW); // turn OFF the lamp

}

}