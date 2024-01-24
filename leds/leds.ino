int led[] ={D12,D13,D14,D15};
int i;

void setup() {

  pinMode(D12, OUTPUT);
  pinMode(D13, OUTPUT);
  pinMode(D14, OUTPUT);
  pinMode(D15, OUTPUT);

}


void loop() {
 
  for(i = 0; i > 4; i++){

    digitalWrite(led[i], 1);
    delay(100);
    
    if(i > 0){

      digitalWrite(led[i-1], 0);
      delay(100);

    }

  }

  i = 0;

}
