#define MEIO_SEGUNDO 500
#define UM_SEGUNDO 500

void acenderLed(int portaLed){
  digitalWrite(portaLed, HIGH);
}

void apagarLed(int portaLed){
  digitalWrite(portaLed, LOW);
}

void piscarLed(int portaLed, int numeroVezes = 1, int tempoMs = MEIO_SEGUNDO){
  for(int i = 0; i < numeroVezes; i++){
    acenderLed(portaLed);
    delay(tempoMs);
    apagarLed(portaLed);
    delay(tempoMs);    
  }
}

void acenderTodosLeds(){
  acenderLed(LED_VERDE);
  acenderLed(LED_AMARELO);
  acenderLed(LED_VERMELHO);
  acenderLed(LED_AZUL);
}

void apagarTodosLeds(){
  apagarLed(LED_VERDE);
  apagarLed(LED_AMARELO);
  apagarLed(LED_VERMELHO);
  apagarLed(LED_AZUL);
}

void piscarTodosLeds(){
  acenderTodosLeds();
  delay(MEIO_SEGUNDO);
  apagarTodosLeds();
  delay(MEIO_SEGUNDO);
}

void piscarTodosLedsAleatoriamente(){
  for (int i = 0; i < 4; i++){
    long portaLed = random(LED_VERDE, LED_AZUL + 1);
    acenderLed(portaLed);
    delay(UM_SEGUNDO);
    apagarLed(portaLed);
  }
}

int getLedAleatorio(){
  return random(LED_VERDE, LED_AZUL + 1);
}
