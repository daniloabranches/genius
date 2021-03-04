#define PORTA_LED_VERDE 2
#define PORTA_LED_AMARELO 3
#define PORTA_LED_VERMELHO 4
#define PORTA_LED_AZUL 5

void configurarPortasDigitais(){
  pinMode(PORTA_LED_VERDE, OUTPUT);
  pinMode(PORTA_LED_AMARELO, OUTPUT);
  pinMode(PORTA_LED_VERMELHO, OUTPUT);
  pinMode(PORTA_LED_AZUL, OUTPUT);
}
