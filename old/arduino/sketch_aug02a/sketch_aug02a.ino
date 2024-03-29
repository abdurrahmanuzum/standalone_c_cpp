#include <Enrf24.h>
#include <nRF24L01.h>
#include <SPI.h>

Enrf24 nRF(9, 10, 2);  // CE , CSN/CS/SS , IRQ bacaklarının Arduino ile bağlantıları tanımlandı

// verici adresi tanımlandı aynı adres alıcıda da tanımlanmalıdır
const byte address1[] = { 0xDC, 0xAD, 0xBE, 0x0F, 0x01 };  //0xDE, 0xAD, 0xBE, 0x0F, 0x01
const byte address2[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };
const byte address3[] = { 0xDA, 0xAD, 0xBE, 0x0F, 0x01 };


void setup() 
{
  

  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); // SPI MODE0 seçildi, nrf24l01 MODE0 ile iletişim kurmaktadır
  SPI.setBitOrder(MSBFIRST); // bit sıralaması MSB'den LSB'ye doğru ayarlandı
  
  // datarate 250000/1000000/2000000, channel 0/125
  // 1000000 datarate seçildi , 124 nolu kanal seçildi
  nRF.begin(1000000,124);  

}

void loop() 
{
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  int pot2 = analogRead(A2);

  nRF.setTXaddress(address1);
  nRF.print(pot0),
  nRF.flush();

  
  nRF.setTXaddress(address2);
  nRF.print(pot1);
  nRF.flush();

  nRF.setTXaddress(address3);
  nRF.print(pot2);
  nRF.flush();

  
  
 


  
  











  
}
