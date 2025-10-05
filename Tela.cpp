#include "Tela.hpp"
#include "raylib.h"

Tela::Tela(int width, int height, const char* texto)
  : _width(width), _height(height) 
{
  InitWindow(_width, _height, texto);
  SetTargetFPS(60);
}
const void Tela::tela_desenhar() const {
  BeginDrawing();
  ClearBackground(RAYWHITE);
}
const void Tela::tela_apagar() const {
  EndDrawing();
}
const bool Tela::tela_deve_fechar() const {
  if (WindowShouldClose()) {
    return true;
  }
  return false;
}
Tela::~Tela() {
  CloseWindow();
}

