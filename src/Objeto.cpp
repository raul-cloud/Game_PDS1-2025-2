#include "Objeto.hpp"

Objeto::Objeto () : _x(0), _y(0), _ativo(false), _sprite({}){
    this->_espaco_colisao.x = 0;
    this->_espaco_colisao.y = 0;
    this->_espaco_colisao.width = 0;
    this->_espaco_colisao.height = 0;
}  

Objeto::Objeto (int x, int y, bool ativo, const std::string& sprite) : _x(x), _y(y), _ativo(ativo){
    this->_sprite = LoadTexture(sprite.c_str());
    this->_espaco_colisao.x = (int)this->_x;
    this->_espaco_colisao.y = (int)this->_y;
    //this->_espaco_colisao.width = (float)this->_sprite.width;
    //this->_espaco_colisao.height = (float)this->_sprite.height;
    this->_espaco_colisao.width = 10;
    this-> _espaco_colisao.height = 10;
}

Objeto::~Objeto(){
    UnloadTexture(this->_sprite);
}

int Objeto::get_x () const{
    return this->_x;
}

int Objeto::get_y () const{
    return this->_y;
}

bool Objeto::get_ativo () const{
    return this->_ativo;
}

void Objeto::set_x (int novo_x){
    this->_x = novo_x;
}

void Objeto::set_y (int novo_y){
    this->_y = novo_y;
}

void Objeto::set_ativo (bool novo_state) {
  this->_ativo = novo_state;
}

Rectangle Objeto::get_espaco_colisao () const {
    return this->_espaco_colisao;
}

Texture2D Objeto::get_sprite () const {
  return _sprite;
}

void Objeto::Draw (Color cor) const{
  DrawRectangleRec(get_espaco_colisao(), cor);
}

