#include <HardwareSerial.h>

HardwareSerial TxSerial(1);

//Definição dos pinos dos potenciômetros
const int sensor1Pin = 14;
const int sensor2Pin = 27;

//Variáveis que receberão os valores lidos nos potenciômetros
int svalor1 = 0;
int svalor2 = 0;

//Variável que guardará a mensagem enviada
String mensagem;

void setup() {
    Serial.begin(115200);
    //Configuração do rádio transmissor
    TxSerial.begin(2400,SERIAL_8N1,16,17); //(Baud Rate,Protocol,Rx_Pin,Tx_Pin)
    Serial.println("Radio_Transmissor");
    delay(1000);
}

void loop() {
  //Leitura dos valores nos potenciômetros
  svalor1 = analogRead(sensor1Pin);
  svalor2 = analogRead(sensor2Pin);

  //Envio dos valores  
  TxSerial.flush();
  mensagem = svalor1;
  TxSerial.print(mensagem);
  delay(5);

  //Separação dos dados enviados
  TxSerial.flush();
  mensagem = ' ';
  TxSerial.print(mensagem);
  delay(5);

  TxSerial.flush();
  mensagem = svalor2;
  TxSerial.print(mensagem);
  delay(5);

  //O ';' marca o fim da mensagem
  TxSerial.flush();
  mensagem = ';';
  TxSerial.print(mensagem);
  delay(5);
  
}
