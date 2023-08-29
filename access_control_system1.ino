
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);
byte f=0;byte h=0;byte l=0;byte w=0;byte s=0; bool t=0;byte d=0;
byte serNum[5]={};
byte sw[4][5]=
{
  {11,47,14,58,112},
  {12,46,23,67,114},
  {13,45,24,57,113},
  {14,43,11,88,117}
};
byte acc[2][5]=
{
  {11,47,14,58,112},
  {13,45,24,57,113}
};
char k[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};

byte rpins[4]={2,3,4,5};
byte cpins[4]={6,7,8,9};
char myk;
Keypad mypad (makeKeymap(k),rpins,cpins,4,4);
char pass[]={'1','3','4','5'};
char upass[sizeof(pass)]={0};
byte counter=0,ii=0,i=0;
byte buttonstate=-1;
byte swp[]={0,1,10,A3};
byte ID[]={A2,11,12,13,A0,A1};
byte c =0;
char cont=0;


void reslcd(){
 lcd.home();
 lcd.clear();
 lcd.print("Enter password");
 lcd.setCursor(0,1);
}

void setup() {
  for(c=0;c<6;c++){
    pinMode(ID[c],INPUT_PULLUP);}
  for(byte m=0;m<4;m++){
    pinMode(swp[m],INPUT);}
 lcd.init();
 lcd.backlight();
 reslcd();
  Serial.begin(9600);
}

void loop() {
  
 RFID();
  
  
}


void keypad(){
  myk=mypad.getKey();
  while(!myk)myk=mypad.getKey();
  lcd.print("*");
  if(myk=='C'){
     reslcd();}
  else if(myk=='D'){
    Serial.println(counter);
    lcd.clear();  
    lcd.home();
    for(i=0;i<sizeof(upass);i++){
      if(upass[i]!=pass[i])break;}
    
  
    
  if((i==sizeof(upass))&&(counter==0)){
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("User authorized");
  digitalWrite(10,1);
  delay(3000);
  digitalWrite(10,0);
  
  
  }
  else {
    
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("Wrong password");
  delay(2000);
  
  
  }
  }
  else
    *(upass+counter)=myk;
 counter=(counter>=3)?-1:counter;
 counter++; 
}




void id_button() {
  
  buttonstate=0xFF;
  for(c=0;buttonstate==0xFF;c++){
  buttonstate=(!digitalRead(ID[c]))?c:0xFF;
  c=(c>=6)?-1:c;
  }
  if (buttonstate==0xFF){  
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.home();
    lcd.print("Enter you finger");
    delay(2000);
    buttonstate=0xFF;
  }
  else {
    lcd.clear();
    lcd.home();
    lcd.print("The ID is : "+String(c));
     delay(2000);
    reslcd();
    buttonstate=0xFF;
    
  }
 }

bool isCard(){
    for(byte h=0;h<=3;h++ ){
      if (digitalRead(swp[h]))
        t=1;}}
bool readCardSerial(){
    if(t){
    for(h=0;h<=3;h++){
         if (digitalRead(swp[h])){
            for(byte j=0;j<=4;j++)
            {serNum[j]=sw[h][j]; d=1;return d; }}}}}

void RFID(){
  isCard();
  readCardSerial();

  if(d){for(byte e=0;e<=4;e++){if(serNum[e]==acc[0][e]||serNum[e]==acc[1][e])
               {f=1;}
               else{f=0;}
             }
         } if (f) {lcd.clear(); lcd.print("welcome"); delay(1000); f=0; }
         else {lcd.clear(); lcd.print("error"); delay(1000); }
         

}

