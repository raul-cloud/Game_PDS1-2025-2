#include "Entidade.hpp"
#include <raylib.h>

Entidade::Entidade () : Objeto(0,0,false,""), _vida(100), _vida_maxima(100), _defesa(10), _defesa_base(10), _velocidade(10), _ataque(100) {}

Entidade::Entidade (int vida, int vida_maxima, int defesa, int defesa_base, bool vivo, int x, int y, int velocidade, int ataque ,const std::string& sprite)
    : Objeto(x, y, vivo, sprite), _vida(vida), _vida_maxima(vida_maxima), _defesa(defesa), _defesa_base(defesa_base), 
    _velocidade(velocidade), _ataque(ataque) {}
      
Entidade::~Entidade () {}

int Entidade::get_vida() const{
  return this->_vida;
}

int Entidade:: get_vida_maxima () const {
  return _vida_maxima;
}

int Entidade::get_velocidade () const { 
  return _velocidade;
}

int Entidade::get_defesa () const {
  return _defesa;
}

int Entidade::get_defesa_base () const {
  return _defesa_base;
}

int Entidade::get_ataque () const {
  return _ataque;
}

void Entidade::set_velocidade (int nova_velocidade) { 
  this->_velocidade = nova_velocidade;
}

void Entidade::set_vida (int nova_vida) {
  this->_vida = nova_vida;
}

void Entidade::set_vida_maxima (int nova_vida) {
  this->_vida_maxima = nova_vida;
}

void Entidade::set_defesa (int nova_defesa) {
  this->_defesa = nova_defesa;
}

void Entidade::set_defesa_base (int nova_defesa){
  this->_defesa_base = nova_defesa;
}

void Entidade::set_ataque (int ataque) {
  this->_ataque = ataque;
}

void Entidade::ReceberDano (int dano) {
  _vida -= dano;
  if (_vida <= 0){
    Morrer();
  }
}

void Entidade::Curar(int cura) {
  _vida += cura;
  if (_vida > _vida_maxima) {
    _vida = _vida_maxima;
  }
}

void Entidade::Morrer () {
  this->set_ativo(false);
}

void Entidade::Andar (int dx, int dy) {
  this->set_x(this->get_x() + dx);
  this->set_y(this->get_y() + dy);

  _espaco_colisao.x = get_x();
  _espaco_colisao.y = get_y();
}

