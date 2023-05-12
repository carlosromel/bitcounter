#include <stdlib.h>
#include <stdio.h>

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

void mostrarPossicoes(int quantidadeBits, int limite) {
  printf(" #  ");
  for (int posicao = quantidadeBits - 1; posicao >= 0; --posicao) {
    printf("%d ", posicao);
    if (posicao % 4 == 0) {
      printf("- ");
    }
  }

  printf("%s", "Byte\n");

  for (int numero = 0; numero < limite; ++numero) {
    int *mapa = get_bits(numero, quantidadeBits);

    printf("%03d:", numero);

    for(int posicao = quantidadeBits - 1; posicao >= 0; --posicao){
      printf("%d ", mapa[posicao]);
      if (posicao % 4 == 0 && posicao > 0) {
        printf("- ");
      }
    }

    for(int posicao = quantidadeBits - 1; posicao >= 0; --posicao){
        printf("%d", mapa[posicao]);
    }

    printf("\n");
  }
}

void mostrarPossibilidadesLEDs(int quantidadeBits, int limite) {
  char *leds[] = {
                   "LED_VERMELHO",
                   "LED_AMARELO",
                   "LED_VERDE",
                   "LED_AZUL",
                   "LED_BRANCO"
                 };

  for (int numero = 0; numero < limite; ++numero) {
    int  led  = 0;
    int *mapa = get_bits(numero, quantidadeBits);

    printf("Decimal: %03d, binário: ", numero);

    for(int posicao = quantidadeBits - 1; posicao >= 0; --posicao) {
      printf("%d", mapa[posicao]);
    }

    if (numero % 2) {
      printf("\n");
    } else {
      printf("  ");
    }

    /*
    for(int posicao = quantidadeBits; posicao >= 0; --posicao) {
      char temp[13];
      char buffer[13];
      sprintf(temp,   "%s,", leds[led]);
      sprintf(buffer, "%-13s", temp);
      printf("blink(%s %d);\n", buffer, mapa[posicao]);
      ++led;
    }
     */
  }
}

int main() {
  int quantidadeBits = 8;
  int limite         = 256;

//  mostrarPossicoes(quantidadeBits, limite);
//  mostrarPossibilidadesLEDs(quantidadeBits, limite);
  mostrarPossibilidadesLEDs(5, 32);

  return 0;
}
