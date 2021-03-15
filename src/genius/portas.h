#include <ArxContainer.h>

#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 5
#define BOTAO_VERDE 8
#define BOTAO_AMARELO 9
#define BOTAO_VERMELHO 10
#define BOTAO_AZUL 11
#define BUZZER 13

arx::map<int, int> mapBotaoLed {
  {BOTAO_VERDE, LED_VERDE},
  {BOTAO_AMARELO, LED_AMARELO},
  {BOTAO_VERMELHO, LED_VERMELHO},
  {BOTAO_AZUL, LED_AZUL}
};

void configurarPortasDigitais(){
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(BOTAO_VERDE, INPUT_PULLUP);
  pinMode(BOTAO_AMARELO, INPUT_PULLUP);
  pinMode(BOTAO_VERMELHO, INPUT_PULLUP);
  pinMode(BOTAO_AZUL, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}
