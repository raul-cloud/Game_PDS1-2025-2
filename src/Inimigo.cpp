#include "Inimigo.hpp"

Inimigo::Inimigo() : Entidade(0, 0, 0, 0, false, 0, 0, 0, 0, ""), _status(""), itens{}, _tier(0), _fraqueza("") {}

Inimigo::Inimigo(int vida, int vidaMax, int defesa, int defesa_base, bool vivo, int x, int y, int velocidade, int atk, const std::string& sprite, int tier, std::string& fraqueza, std::string &status) : 
    Entidade(vida, vidaMax, defesa, defesa_base, vivo, x, y, velocidade, atk, sprite),
    _status(status), itens{}, _tier(tier),  _fraqueza(fraqueza) {}

Inimigo::~Inimigo(){  
}

void Inimigo::desenhar_inimigo() const{
}

void Inimigo::set_status(const std::string& stat){
    this->_status = stat;
}

const std::string Inimigo::get_status() const{
    return this->_status;
}

void Inimigo::set_fraqueza(std::string& fraqueza){
    this->_fraqueza = fraqueza;
}

const std::string& Inimigo::get_fraqueza() const{
    return this->_fraqueza;
}

bool Inimigo::acertou(const Entidade &herois){
    srand(time(0));
    int numeroEntre0e9 = rand() % 10;
    if(numeroEntre0e9 <= 7){ return true; }
    return false;
}

const Item* Inimigo::drop(int valor){
    return nullptr;
}

void Inimigo::acao_batalha(){
}

