
#include <L298N.h>


/* **************************************
 *  pinos de conexão do driver L298N
 *  CONFIRA A PINAGEM DA SUA  MONTAGEM
 ***************************************/
#define ENA1  3
#define IN11  2
#define IN12  4
#define IN21  5
#define IN22  7
#define ENA2  6

L298N motorE(ENA1, IN11, IN12);   // motor esquerdo
L298N motorD(ENA2, IN22, IN21);     // motor direito


/***********************************
 *  blocos  que foram criados
 **********************************/
void setupTracao(float veloc) ;
void espera(float tempo);
void frente(float veloc, float tempo)  ;
void tras(float veloc, float tempo);
void direita(float veloc, float tempo);
void esquerda(float veloc, float tempo);
void brake();
void pwmTeste();
void release();


/***********************************
 *  SKETCH - blocos principais
 **********************************/
 
void setup() 
{
      Serial.begin(115200);
      Serial.println("O robô esta vivo!\nBom dia!");
      setupTracao(100);
}

void loop() 
{ 
      frente(100,1.5);
      direita(50,2.5);
      frente(100,1.5);
      direita(50,2.5);
      frente(100,1.5);
      direita(50,2.5);
      frente(100,1.5);
      direita(50,2.5);
      espera(3);
      esquerda(50,4);
}


/************************************************ 
 *    Criação do blocos movimento do robô
 ***********************************************/
void setupTracao(int veloc) 
{
        motorE.setSpeed(veloc*255/100); // an integer between 0 and 255
        motorE.stop();
        motorD.setSpeed(veloc*255/100); // an integer between 0 and 255
        motorD.stop();
}


 void espera(float tempo)
{
    delay(1000*tempo);
}

void frente(float veloc, float tempo)
{
    motorE.setSpeed(veloc*255/100);  
    motorD.setSpeed(veloc*255/100);  
    motorE.forward();
    motorD.forward();
    delay(1000*tempo);
    brake();
}
  
  void tras(float veloc, float tempo)
{
    motorE.setSpeed(veloc*255/100);  
    motorD.setSpeed(veloc*255/100);  
    motorE.backward();
    motorD.backward();
    delay(1000*tempo);
    brake();
}

void direita(float veloc, float tempo)
{
    motorE.setSpeed(veloc*255/100);  
    motorD.setSpeed(veloc*255/100);  
    motorD.backward();
    motorE.forward();
    delay(1000*tempo);
    brake();
}

void esquerda(float veloc, float tempo)
{
    motorE.setSpeed(veloc*255/100);  
    motorD.setSpeed(veloc*255/100);  
    motorD.forward();
    motorE.backward();
    delay(1000*tempo);
    brake();
}

void brake()
{
    motorE.setSpeed(0);  
    motorD.setSpeed(0);  
    motorE.stop();
    motorD.stop();
}

void pwmTeste()
{
  for(int i=0;i<255;i++){
      motorE.setSpeed(i);  
      motorD.setSpeed(i);  
      motorE.forward();
      motorD.forward();
      delay(1000);
      Serial.println(i);
    }
}
