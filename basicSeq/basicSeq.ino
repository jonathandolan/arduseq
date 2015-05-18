//Basic logic for a sequencer.
//Author: Jonathan Dolan
//5/18/15

bool sequence[16] = {true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false};
int step;
int timeBetweenSteps;
int timeForEachStep;
int led = 13; //builtin

void setup() {
  // put your setup code here, to run once:
  timeBetweenSteps = 1000;
  timeForEachStep = 1000;
  step = 0;
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(timeBetweenSteps);
  step++;
  bool next; 
  next = getNextStep();
  if (next == true){
   digitalWrite(led, HIGH);
   delay(timeForEachStep);
   digitalWrite(led, LOW);
  } 
  else {
       delay(timeForEachStep + timeBetweenSteps);
  }
}

bool getNextStep(){
  if (step == 16){
   step = 0; //loop 
  }
  bool answer = sequence[step];
  Serial.print(answer);
  Serial.print("\t");
  Serial.print(step);
  Serial.println();
  return answer;
}
