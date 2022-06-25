#include <HardwareSerial.h>
HardwareSerial RxSerial(1);

void setup() {
  Serial.begin(115200);
  //Configuração do rádio transmissor
  RxSerial.begin(2400,SERIAL_8N1,16,17); //(Baud Rate,Protocol,Rx_Pin,Tx_Pin)
  Serial.println("Radio_Receptor");
  delay(1000);
}

void loop() {
  //Variável que recebe a mensagem completa
  String receive;
  /* Variável que recebe a primeira parte da mensagem, 
  até o ' ' que demarca a separação */
  String result1;
  /* Variável que recebe a segunda parte da mensagem, 
  do ' ' até o fim demarcado por ';' */
  String result2;
  //Variáveis para a troca de String para inteiro
  int iresult1;
  int iresult2;
  while(RxSerial.available()){  
    //Leitura da mensagem recebida  
    receive = RxSerial.readStringUntil(';');
    //Separação da primeira metade
    result1 = receive.substring(0,receive.indexOf(' ')+1);
    //Separação da segunda metade
    result2 = receive.substring(receive.indexOf(' ')+1);

    //String para inteiro
    iresult1=result1.toInt() ;
    Serial.print(iresult1);
    /*Vírgula para separação no Excel, 
    utilizado paa plotar gráfico*/
    Serial.print(',');
    iresult2=result2.toInt() ;
    Serial.println(iresult2);
  }
}
