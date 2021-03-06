#include "portas.h"
#include "leds.h"

void setup(){
  configurarPortasDigitais();
}

void loop(){
  for (const auto mapx : mapBotaoLed){
    int estadoBotao = digitalRead(mapx.first);
    if (estadoBotao == LOW){
      acenderLed(mapx.second);
    }
    else {
      apagarLed(mapx.second);
    }
  }
}
