
/*         
 
           
           
         y 
   z  _  /\
     |\  |
       \ |
        \|_______> x 
*/

const byte y[]={13,12,11,10};
const byte x[]={9,8,7,6};
const byte z[]={5,4,3,2};

bool LEDs[64];
int thing=0;



void setup() {
  while(thing <= 64){ 
  LEDs[thing] = 0;
  thing++;
}
thing = 0;

for(int pin = 2; pin<14; pin++){
  pinMode(pin,OUTPUT);
}

for(int pin = 2; pin<10; pin++){
  digitalWrite(pin,LOW);
}

for(int pin = 10; pin<14; pin++){
  digitalWrite(pin,HIGH);
}

}
byte Layer = 0;
byte xRow = 0;
byte zRow = 0;
byte ledData= 0;
long startMillis;
long triggerTime;
byte pattern = 0;
int button = 0;
byte value;
byte LedToLight;
byte LedsLighten = 0;
byte repeat = 0;
int repeated = 0;
int randomNum;




         
void loop() { 
switch(pattern){
  case 0:{
       while(thing <= 64){ 
       LEDs[thing] = 1;
       thing++;
       } 
       thing = 0;
       while(pattern== 0){
        startLEDs(LEDs,0,0);
       }
       } 
       break;
  case 1:{
       while(thing <= 64){ 
       LEDs[thing] = 0;
       thing++;
       } 
       thing = 0;
       while(pattern == 1){
        startLEDs(LEDs,0,1);
       }
       } 
       break;
  case 2:{
          int LedToLight;
          while(thing <= 64){ 
          LEDs[thing] = 0;
          thing++;
          } 
          thing = 0;
          while(pattern == 2){
           LedToLight = random(0,64); 
           LEDs[LedToLight] = 1;
           startLEDs(LEDs,50,2);
           LEDs[LedToLight] = 0;
          }
         }
         break;



   case 3:{
    int LedToLight;
    int LedToLight2;
          while(thing <= 64){ 
          LEDs[thing] = 0;
          thing++;
          } 
          thing = 0;
          while(pattern == 3){
           LedToLight = random(0,64);
           LedToLight2 = random(0,64); 
           LEDs[LedToLight] = 1;
           LEDs[LedToLight2] = 1;
           startLEDs(LEDs,75,3);
           LEDs[LedToLight] = 0;
           LEDs[LedToLight2] = 0;
          }
   }
   break;
   case 4:{
           while(thing <= 64){ 
            LEDs[thing] = 0;
            thing++;
          } 
          thing = 0;
           value;
          LedToLight;
          LedsLighten = 0;
          repeat = 0;
         repeated = 0;
           while(thing <= 64){ 
            LEDs[thing] = 0;
            thing++;
           } 
          thing = 0;
          while(pattern == 4){
           
           value = 0;           
           LedToLight = random(0,(64-LedsLighten)); 
           repeat= LedToLight;
           LedToLight = 0;
           repeated = -1;
           do{
           repeated++;
           if(LEDs[LedToLight] == 1){
            while(LEDs[LedToLight] == 1){LedToLight++;}
           }
           LedToLight++;
           }while(repeated != repeat);
           LedToLight--;
           LEDs[LedToLight] = 1;
           startLEDs(LEDs,30,4);
           LedsLighten++;
           for(int index=0; index<64; index++){
            value+= LEDs[index];
           }
           if(value == 64){
            LedsLighten = 0;
            startLEDs(LEDs,500,4);
            while(value != 0 && pattern == 4 ){
             value = 1;
           LedToLight = random(0,(64-LedsLighten)); 
           repeat= LedToLight;
           LedToLight = 0;
           repeated = -1;
           do{
           repeated++;
           if(LEDs[LedToLight] == 0){
            while(LEDs[LedToLight] == 0){LedToLight++;}
           }
           LedToLight++;
           }while(repeated != repeat);
           LedToLight--;
             LEDs[LedToLight] = 0;
             startLEDs(LEDs,30,4);
             LedsLighten++;
             for(int index=0; index<64; index++){
              value+= LEDs[index];
             }
             value = value-1;
            }
            LedsLighten = 0;
            startLEDs(LEDs,500,4);
           }
          }   
          }
           break;
    case 5:{
         while(thing <= 64){ 
          LEDs[thing] = 0;
          thing++;
         } 
         thing = 0; 
         while(pattern== 5){
          while(thing <= 64){ 
           LEDs[thing] = random(0,2);
           thing++;
          }
          thing = 0; 
          startLEDs(LEDs,300,5); 
         }
    }
    break;

    
      
}
}



void startLEDs(bool LEDArray[],int Time,byte case_){
  startMillis= millis();
  button = 0;
do{
button =analogRead(4);
if(pattern != case_){return;}


Layer = 0;
ledData= 0;  
while(Layer <= 3){
  xRow = 0;
  digitalWrite(y[Layer],LOW);
  while(xRow <= 3){
    
   zRow = 0;  
   digitalWrite(x[xRow],HIGH);
   while(zRow <= 3){
     if(LEDArray[ledData]){
       digitalWrite(z[zRow],HIGH) ; 
     } 
    zRow++; ledData++; 
   }
   delay(0);
   digitalWrite(z[0],LOW); 
   digitalWrite(z[1],LOW); 
   digitalWrite(z[2],LOW); 
   digitalWrite(z[3],LOW); 
   digitalWrite(x[xRow],LOW);
   xRow++;
  }
  digitalWrite(y[Layer],HIGH);
  Layer++;
}
if(button>1020){
pattern+=1;
if(pattern>5){pattern=0;}
while(button != 0){button =analogRead(4);delay(2);}
}
}while(startMillis+Time > millis());
}
