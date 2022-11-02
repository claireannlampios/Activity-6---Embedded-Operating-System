// C++ code
//Claire Ann Lampios BSCpE-4A
//Shortest Job 

void setup()
{
  pinMode(2, OUTPUT); //set port 2 to output
  pinMode(3, OUTPUT); //set port 3 to output
  pinMode(4, OUTPUT); //set port 4 to output
  pinMode(5, OUTPUT); //set port 5 to output
  pinMode(6, OUTPUT); //set port 6 to output
  pinMode(7, OUTPUT); //set port 7 to output
}

void loop()
{
  shortest_job(); //calling the function.
}

void shortest_job(){
  int pin[6] = {2,3,4,5,6,7};
  int time[6] = {10000,5000,8000,3000,1000,2000};
  //an array of time in milliseconds to be used in delay function.
  //index 0 or the P1 has a time of 10 seconds.
  //index 1 or the P2 has a time of 5 seconds.
  //index 2 or the P3 has a time of 8 seconds.
  //index 3 or the P4 has a time of 3 second.
  //index 4 or the P5 has a time of 1 second.
  //index 5 or the P6 has a time of 2 seconds.
  
  
  int temp; //temporary value used in swapping.
  
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (time[i] < time[j]){
      	temp = time[i];
        time[i] = time[j];
        time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  } //after executing this loop, the time array as well as pin array will be sorted in ascending.
  
  int count = 0; //used to identifies the element of time array.
  while (count != 6){
  	digitalWrite(pin[count], HIGH);
    delay(time[count]);
    digitalWrite(pin[count], LOW);
    count++;
  } //executes shortest job scheduling.
}