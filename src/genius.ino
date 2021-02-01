#define PORTA_LED_VERDE 2
#define PORTA_LED_AMARELO 3
#define PORTA_LED_VERMELHO 4
#define PORTA_LED_AZUL 5
#define MEIO_SEGUNDO 500

#include "leds.h"
#include "portas.h"

void setup(){
  configurarPortasDigitais();
}

void loop(){
  piscarTodosLeds();
  
  piscarLed(PORTA_LED_VERDE);
  piscarLed(PORTA_LED_AMARELO);
  piscarLed(PORTA_LED_VERMELHO);
  piscarLed(PORTA_LED_AZUL);

  piscarLed(PORTA_LED_VERMELHO);
  piscarLed(PORTA_LED_AMARELO);
  piscarLed(PORTA_LED_VERDE);
}
