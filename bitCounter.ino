#include <stdlib.h>
#include <stdio.h>

#define LED_WHITE    5
#define LED_BLUE     6
#define LED_GREEN    7
#define LED_YELLOW   8
#define LED_RED      9
#define DIT        200
#define DAH        (DIT * 3)

void setup() {
  for (int pin = LED_WHITE; pin <= LED_RED; ++pin) {
    pinMode(pin, OUTPUT);
  }
}

int *get_bits(int numero, int quantidadeBits){
  int *mapa = malloc(sizeof(int) * quantidadeBits);

  for(int posicao = 0; posicao < quantidadeBits; ++posicao){
    int mascara        = 1 << posicao;
    int mascaraPosicao = numero & mascara;
    int situacaoBit    = mascaraPosicao >> posicao;

    mapa[posicao]      = situacaoBit;
  }

  return mapa;
}
/*
  0 00000
  1 00001
  2 00010
  3 00011
  4 00100
  5 00101
  6 00110
  7 00111
  8 01000
  9 01001
 10 01010
 11 01011
 12 01100
 13 01101
 14 01110
 15 01111
 16 10000
 17 10001
 18 10010
 19 10011
 20 10100
 21 10101
 22 10110
 23 10111
 24 11000
 25 11001
 26 11010
 27 11011
 28 11100
 29 11101
 30 11110
 31 11111
 */
void loop() {
  int quantidadeBits = 8;
  int quantidadeLEDs = 5;
  int limite         = 32;

  for (int numero = 0; numero < limite; ++numero) {
    int  led  = 0;
    int *mapa = get_bits(numero, quantidadeBits);

    for (int posicao = quantidadeLEDs; posicao > 0; --posicao) {
      int  pin = LED_WHITE + led;
      digitalWrite(pin, mapa[posicao - 1]);
     ++led;
    }

    delay(DIT);
  }
}
