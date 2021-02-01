void acenderLed(int portaLed){
  digitalWrite(portaLed, HIGH);
}

void apagarLed(int portaLed){
  digitalWrite(portaLed, LOW);
}

void piscarTodosLeds(){
  acenderLed(PORTA_LED_VERDE);
  acenderLed(PORTA_LED_AMARELO);
  acenderLed(PORTA_LED_VERMELHO);
  acenderLed(PORTA_LED_AZUL);
  delay(MEIO_SEGUNDO);
  apagarLed(PORTA_LED_VERDE);
  apagarLed(PORTA_LED_AMARELO);
  apagarLed(PORTA_LED_VERMELHO);
  apagarLed(PORTA_LED_AZUL);
  delay(MEIO_SEGUNDO);
}

void piscarLed(int portaLed){
  acenderLed(portaLed);
  delay(MEIO_SEGUNDO);
  apagarLed(portaLed);
  delay(MEIO_SEGUNDO);
}
