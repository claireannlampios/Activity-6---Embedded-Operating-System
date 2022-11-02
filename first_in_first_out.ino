// C++ code
//Claire Ann Lampios BSCpE-4A
//First In First Out

 int pin[6] = {2,3,4,5,6,7};
 int time[]={10000,5000,8000,3000,1000,2000};
  //an array of time in milliseconds to be used in delay function.
  //index 0 or the P1 has a time of 10 seconds.
  //index 1 or the P2 has a time of 5 seconds.
  //index 2 or the P3 has a time of 8 seconds.
  //index 3 or the P4 has a time of 3 second.
  //index 4 or the P5 has a time of 1 second.
  //index 5 or the P6 has a time of 2 seconds.
int numled= 6;
	//number of LEDs

void setup()
{
  Serial.begin(9600);
  for(int i=0; i<numled; i++){
    pinMode(pin[i], OUTPUT);
	}
}

void loop(){
  for (int i = 0; i <numled; i++){
    digitalWrite(pin[i],HIGH);
    delay(time[i]);
    digitalWrite(pin[i],LOW);
  } 
  for(;;){
  }
}