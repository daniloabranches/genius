#include "portas.h"
#include "leds.h"
#include "vector.h"

#define INDEFINIDO -1
#define RODADA_UM 1
#define RODADA_FINAL 3

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
        executarEventoSucesso();
        rodada = RODADA_UM;
      }
      else {
        rodada++;
      }
    }
  }
  else {
    executarEventoErro();
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

void executarEventoSucesso(){
  long tempoAgora = millis();
  long novoTempoAgora = 0;
  long diferencaTempoPassado = 0;
  int passoLed = 1;
  int passoSom = 1;
  while(passoLed <= 5){
    novoTempoAgora = millis();
    diferencaTempoPassado = novoTempoAgora - tempoAgora;
    passoLed = executarPassosLedEventoSucesso(passoLed, diferencaTempoPassado);
    passoSom = executarPassosSomEventoSucesso(passoSom, diferencaTempoPassado);
  }
}

int executarPassosLedEventoSucesso(int passoLed, long diferencaTempoPassado){
  if (passoLed == 1){
    acenderTodosLeds();
    passoLed++;
  }
  else if (passoLed == 2 && diferencaTempoPassado >= 500){
    apagarTodosLeds();
    passoLed++;
  }
  else if (passoLed == 3 && diferencaTempoPassado >= 1000){
    acenderTodosLeds();
    passoLed++;
  }
  else if (passoLed == 4 && diferencaTempoPassado >= 1500){
    apagarTodosLeds();
    passoLed++;
  }
  else if (passoLed == 5 && diferencaTempoPassado >= 2000){
    passoLed++;
  }
  return passoLed;
}

int executarPassosSomEventoSucesso(int passoSom, long diferencaTempoPassado){ 
  if (passoSom == 1){
    tone(13,262,200);
    passoSom++;
  }
  else if (passoSom == 2 && diferencaTempoPassado >= 200){
    tone(13,294,300);
    passoSom++;
  }
  else if (passoSom == 3 && diferencaTempoPassado >= 400){
    tone(13,330,300);
    passoSom++;
  }
  else if (passoSom == 4 && diferencaTempoPassado >= 600){
    tone(13,330,300);
    passoSom++;
  }
  else if (passoSom == 5 && diferencaTempoPassado >= 900){
    tone(13,349,300);
    passoSom++;
  }
  else if (passoSom == 5 && diferencaTempoPassado >= 1200){
    tone(13,349,300);
  }
  return passoSom;
}

void executarEventoErro(){
  tone(BUZZER, 300, 500);
  delay(500);
}
