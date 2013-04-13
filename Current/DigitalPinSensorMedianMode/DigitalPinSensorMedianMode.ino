/* This script is designed to take several readings from the maxbotix sonar and generate a mode/median.
 Original Author: Jason Lessels
 Date created: 2011/June/06
 Lisence: GPL (=>2)
 This work has been compileed using many sources mainly posts/wiki posts from;
 Allen, Bruce (2009/July/23) and Gentles, Bill (2010/Nov/12)
 
 Robert Werner - 04/03/13 
 This script adds a HIGH/LOW feature on the RX pin, which turns sensor off and on to decrease 
 interferance with other sensors. In addition, I added pin 13 light within range
 
 1. Need to fix the timer, which delays turning off the LED
 */
 long currentMillis = 0;
 long stepTime = 0;
int led = 13; //led pin to show that subject is in range
//Set the pin to recieve the signal.
const int pwPin = 4;
int configPin = 3; //RX pin, which allows sensor to be off/on     
//variables needed to store values
int arraysize = 9; //quantity of values to find the median (sample size). Needs to be an odd number
//declare an array to store the samples. not necessary to zero the array values here, it just makes the code clearer
int rangevalue[] = { 
  0, 0, 0, 0, 0, 0, 0, 0, 0};
long pulse;
int modE;
void setup() {
  //Open up a serial connection
  Serial.begin(9600);
  //Wait for the serial connection
  pinMode(configPin, OUTPUT); //set configPin to output trigger sensor HIGH/LOW
  pinMode(led, OUTPUT);
  delay(500);
}
//Main loop where the action takes place


void loop() {
  currentMillis = millis();
  digitalWrite(configPin, HIGH);//raise the reset pinn high
  delay(120);                   //start of calibration ring

  pinMode(pwPin, INPUT);
  for(int i = 0; i < arraysize; i++)
  {								    
    pulse = pulseIn(pwPin, HIGH);
    rangevalue[i] = pulse/58;
    delay(10);
  }
  Serial.print("Unsorted: ");
  printArray(rangevalue,arraysize);
  isort(rangevalue,arraysize);
  Serial.print("Sorted: ");
  printArray(rangevalue,arraysize);
  modE = mode(rangevalue,arraysize);
  Serial.print("The mode/median is: ");
  Serial.print(modE);
  Serial.println();
  if (modE <= 200) {            //if subject is within range
    digitalWrite(led, HIGH);  // make light turn on 
  }
  else{
    if(currentMillis - stepTime >= 0){ //this timer isn't working yet
      Serial.println("currentMillis =");
      Serial.println(currentMillis);
    
    digitalWrite(led, LOW);   //or else, leave light off
    }
    stepTime = currentMillis;
    Serial.println("stepTime = ");
    Serial.println( stepTime);
  }

  digitalWrite(configPin, LOW);   //turn off Calibration ring and sensor
  Serial.println("configPin LOW");  
  delay(500);                     //set delay time for sensor to remain off
}
/*-----------Functions------------*///Function to print the arrays.
void printArray(int *a, int n) {
  for (int i = 0; i < n; i++)
  {
    Serial.print(a[i], DEC);
    Serial.print(' ');
  }
  Serial.println();
}
//Sorting function
// sort function (Author: Bill Gentles, Nov. 12, 2010)
void isort(int *a, int n){
  // *a is an array pointer function
  for (int i = 1; i < n; ++i)
  {
    int j = a[i];
    int k;
    for (k = i - 1; (k >= 0) && (j < a[k]); k--)
    {
      a[k + 1] = a[k];
    }
    a[k + 1] = j;
  }
}
//Mode function, returning the mode or median.
int mode(int *x,int n){
  int i = 0;
  int count = 0;
  int maxCount = 0;
  int mode = 0;
  int bimodal;
  int prevCount = 0;
  while(i<(n-1)){
    prevCount=count;
    count=0;
    while(x[i]==x[i+1]){
      count++;
      i++;
    }
    if(count>prevCount&count>maxCount){
      mode=x[i];
      maxCount=count;
      bimodal=0;
    }
    if(count==0){
      i++;
    }
    if(count==maxCount){//If the dataset has 2 or more modes.
      bimodal=1;
    }
    if(mode==0||bimodal==1){//Return the median if there is no mode.
      mode=x[(n/2)];
    }
    return mode;
  }
}



