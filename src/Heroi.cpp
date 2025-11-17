#include "Heroi.hpp"
#include "Entidade.hpp"
#include "Item.hpp" 
#include <string>
#include <vector>
#include <iostream>

Heroi::Heroi(int vida, int vidaMAX, int defesa, int defesa_base, bool vivo, int x, int y,
             int vel, int atk, const std::string &sprite,
             const std::string& classe, int xp, const std::string& status, int dinheiro)
  : Entidade(vida, vidaMAX, defesa, defesa_base, vivo, x, y, vel, atk, sprite), _classe(classe), _experiencia(xp), _status(" "), _dinheiro(0) {}

Heroi::~Heroi() {}

void Heroi::set_classe(const std::string& classe) {
    this->_classe = classe;
}

std::string Heroi::get_classe() const {
    return this->_classe;
}

void Heroi::set_experiencia(int pontos_experiencia) {
    this->_experiencia = pontos_experiencia;
}

int Heroi::get_experiencia() const {
    return this->_experiencia;
}

void Heroi::set_status(const std::string& novo_status) {
    this->_status = novo_status;
}

std::string Heroi::get_status() const {
    return this->_status;
}

int Heroi::get_dinheiro() const{
    return this->_dinheiro;
}

void Heroi::set_dinheiro(int quantidade){
    this->_dinheiro = quantidade;
}

void Heroi::adicionar_item(const Item& item_novo){

}

void Heroi::remover_item(int item_selecionado_indice){

}

void Heroi::usar_item(int item_selecionado_indice){

}

void Heroi::listar_inventario() const {

}
