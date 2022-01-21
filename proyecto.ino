//by :Mademoisellefou (Melany E.C.)
//definir los servomotores
#include <Servo.h>
int pos = 0;
Servo servo_2;

// definir sensores
const int valorPirEntrada =A4;
const int valorPirSalida  =A5;
int ultimoEstadoEntrada=0;
int pirEntrada=1;
int ultimoEstadoSalida=0;
int pirSalida=1;

// definir array numeros
int display1[7]      ={9,10,6,5,4,8,7};
int display2[7]      ={A2,A3,13,12,11,A1,A0};
int contador=11;
int cero[7]={1,1,1,1,1,1,0};
int uno[7]={0,1,1,0,0,0,0};
int dos[7]={1,1,0,1,1,0,1};
int tres[7]={1,1,1,1,0,0,1};
int cuatro[7]={0,1,1,0,0,1,1};
int cinco[7]={1,0,1,1,0,1,1};
int seis[7]={1,0,1,1,1,1,1};
int siete[7]={1,1,1,0,0,0,0};
int ocho[7]={1,1,1,1,1,1,1};
int nueve[7]={1,1,1,0,0,1,1};
// definicion buzzer
int buzzer_pin =3;

void setup(){
    
    Serial.begin(9600);
    // set  sermotor
  	servo_2.attach(2, 500, 2500);
    // set pir
    pinMode(valorPirSalida,INPUT);
    pinMode(valorPirEntrada,INPUT);
  	//set buzzer
    pinMode(buzzer_pin, OUTPUT);
  	//set 2 display  
    for(int i=0;i<=6;i++){
        pinMode(display1[i],OUTPUT);
        pinMode(display2[i],OUTPUT);            
    }
}

// muestra  el numero del contador ,fija valores en los 2 sets
void displayLeds(int a[],int b[]){
    for(int i=0;i<=6;i++){
        digitalWrite(display1[i],a[i]);
        digitalWrite(display2[i],b[i]);
    }
}
// mueve el servo  de 90 a 0
void mover90degrees(){
  for (pos = 0; pos <= 90; pos += 1) {
    //pos of servo
    servo_2.write(pos);
    // wait 15 ms 
    delay(15); 
  }
}
void  retornar90degrees(){
  servo_2.write(0);
}
// suena el buzzer con el contador mayor a 12
void maxNumero(){
  for (int i=0;i<3;i++){
  	noTone(buzzer_pin);
  	tone(buzzer_pin, 880, 20); 
  	delay(100); 
  }
}
// busca el valor del contador
void mostrarnumero(int contador){
      switch(contador){
            case 0:
            displayLeds(cero,cero);
            break;
            case 1:
            displayLeds(cero,uno);
            break;
            case 2:
            displayLeds(cero,dos);
            break;
            case 3:
            displayLeds(cero,tres);
            break;
            case 4:
            displayLeds(cero,cuatro);
            break;
            case 5:
            displayLeds(cero,cinco);
            break;            
            case 6:
            displayLeds(cero,seis);
            break;                 
            case 7:
            displayLeds(cero,siete);
            break;                 
            case 8:
            displayLeds(cero,ocho);
            break;                
            case 9:
            displayLeds(cero,nueve);
            break;
            case 10:
            displayLeds(uno,cero);
            break;               
            case 11:
            displayLeds(uno,uno);
            break;              
            case 12:
            displayLeds(uno,dos);
            break;                                                                                                
    }
}
// el contador es mayor que 12
bool esMayor(int c){
  if (c>11){
  	return true;
  }
  return false;
}
// el contador es menor que 12
bool esMenor(int c){
  if (c<0){
  	return true;
  }
  return false;
}
void loop(){
  pirEntrada=digitalRead(valorPirEntrada);
  
  pirSalida= digitalRead(valorPirSalida); 
  
  if(pirEntrada!=ultimoEstadoEntrada){
      if(pirEntrada==LOW){
        contador++;
        Serial.println(contador);
        if (esMayor(contador)){
          	maxNumero();
            mover90degrees();
        }else{
        	digitalWrite(buzzer_pin,HIGH);
        }
      }
      
  }
  retornar90degrees();
  digitalWrite(buzzer_pin,LOW);
  ultimoEstadoEntrada=pirEntrada;

  if(pirSalida!=ultimoEstadoSalida){
      if(pirSalida==LOW){
        contador--;
        if(esMenor(contador)){
        	contador=0;
        }
        digitalWrite(buzzer_pin,HIGH);
      }
  }
  ultimoEstadoSalida=pirSalida;
  digitalWrite(buzzer_pin,LOW);
  mostrarnumero(contador);
  
}
//https://www.tinkercad.com/things/fGpujH0CM0x-super-albar/editel?sharecode=PVRp5mp_tozZwiQ_JihIf1gfN6tGrLqWZhyGWbxRSTg&sharecode=PVRp5mp_tozZwiQ_JihIf1gfN6tGrLqWZhyGWbxRSTg
