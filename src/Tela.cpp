#include "Tela.hpp"

Tela::Tela(int width, int height, const char * texto) : 
            _width(width), _height(height) {
  InitWindow(_width, _height, texto);
  SetTargetFPS(60);
}

int Tela::get_width() const {
  return this->_width;
}

int Tela::get_height() const {
  return this->_height;
}

 void Tela::tela_desenhar() const {
  BeginDrawing();
  ClearBackground(RAYWHITE);
}

 void Tela::tela_atualizar() const {
  EndDrawing();
}

 bool Tela::tela_deve_fechar() const {
  return WindowShouldClose();
}

Tela::~Tela(){
  CloseWindow();
}

