// C++ code
//Claire Ann Lampios BSCpE-4A
//Round Robin


void setup()
{
  pinMode(2, OUTPUT); //set port 13 to output
  pinMode(3, OUTPUT); //set port 12 to output
  pinMode(4, OUTPUT); //set port 11 to output
  pinMode(5, OUTPUT); //set port 10 to output
  pinMode(6, OUTPUT); //set port 9 to output
  pinMode(7, OUTPUT); //set port 8 to output
}

void loop()
{
  round_robin(); //calling the function.
}

void round_robin(){
  int time_quantum = 2000;
  int burst_time[6] = {10000, 5000, 8000, 3000, 1000, 2000}; 
  int pin[6] = {2, 3, 4, 5, 6, 7};
  int ready_queue[6];
  int arrival_time[6] = {0,5000, 8000, 3000, 1000, 2000}; 
  
  int temp;
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (arrival_time[i] < arrival_time[j]){
      	temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;
        
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  }
  
  for (int i=0; i<6; i++){
  	digitalWrite(pin[i], HIGH);
    delay(time_quantum);
    digitalWrite(pin[i], LOW);
    burst_time[i] = burst_time[i] - time_quantum;  
  }  
}