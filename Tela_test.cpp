#include "Tela.hpp"
#include "raylib.h"
int main(void) {
  Tela tela(1920, 1080, "Hello Raylib!");
  while (!tela.tela_deve_fechar()) {
    tela.tela_desenhar();
    DrawCircle(960, 540, 15.4, PINK);
    tela.tela_apagar();
  }
}
