#include "portas.h"
#include "leds.h"

void setup(){
  configurarPortasDigitais();
}

void loop(){
  /*piscarTodosLeds();
  
  piscarLed(PORTA_LED_VERDE);
  piscarLed(PORTA_LED_AMARELO);
  piscarLed(PORTA_LED_VERMELHO);
  piscarLed(PORTA_LED_AZUL);

  piscarLed(PORTA_LED_VERMELHO);
  piscarLed(PORTA_LED_AMARELO);
  piscarLed(PORTA_LED_VERDE);*/

  piscarTodosLedsAleatoriamente();
}
