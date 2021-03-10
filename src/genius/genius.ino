#include "portas.h"
#include "leds.h"
#include "vector.h"

#define INDEFINIDO -1
#define RODADA_UM 1
#define RODADA_FINAL 5

int rodada = RODADA_UM;

Vector<int> luzesRodada {};

void setup(){
  configurarPortasDigitais();
}

void loop(){
  bool podeSeguirProximaRodada = (luzesRodada.size() == 0 || luzesRodada.isLast());
  if (podeSeguirProximaRodada){
    configurarSequenciaLuzes();
    piscarSequenciaLuzes();    
  }
  else {
    validarSequenciaLuzesPressionada();
  }
}

void configurarSequenciaLuzes(){
  luzesRodada.clear();
  randomSeed(analogRead(0));
  for(int i = 0; i < rodada; i++) {
    luzesRodada.insert(getLedAleatorio());
  }
}

void piscarSequenciaLuzes(){
  for (const int luz : luzesRodada.iterator()){
    piscarLed(luz);
  }
}

void validarSequenciaLuzesPressionada(){
  int luzPressionada = getLuzPressionadaUsuario();
  if (luzPressionada == INDEFINIDO){
    return;
  }
  
  if (luzPressionada == luzesRodada.next()){
    piscarLed(luzPressionada, 1, 150);
    if (luzesRodada.isLast()){
      if (rodada == RODADA_FINAL){
        piscarTodosLeds();
        piscarTodosLeds();
        piscarTodosLeds();
        rodada = RODADA_UM;
      }
      else {
        rodada++;
      }
    }
  }
  else {
    piscarLed(LED_VERMELHO, 5, 100);
    rodada = RODADA_UM;
    luzesRodada.clear();
  }
}

int getLuzPressionadaUsuario(){
  for (const auto mapx : mapBotaoLed){
    int estadoBotao = digitalRead(mapx.first);
    if (estadoBotao == LOW){
      return mapx.second;
    }
  }
  return INDEFINIDO;
}
