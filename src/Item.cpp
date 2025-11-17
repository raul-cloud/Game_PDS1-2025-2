#include <string>
#include "Item.hpp"

Item::Item() : 
    Objeto(0, 0, true, ""),
    _valor(0), 
    _tipo(""),
    _categoria(""),
    _raridade(""), 
    _usado(false) {}

Item::Item(const std::string& categoria, int valor, const std::string& tipo, const std::string& raridade, bool usado, const std::string& sprite) :
    Objeto(0, 0, true, sprite),    
    _valor(valor), 
    _tipo(tipo),
    _categoria(categoria),
    _raridade(raridade), 
    _usado(usado) {}

Item::~Item() {}

int Item::get_valor() const { return this->_valor; }

const std::string& Item::get_tipo() const { return this->_tipo; }

const std::string& Item::get_categoria() const { return this->_categoria; }

const std::string& Item::get_raridade() const { return this->_raridade; }

bool Item::get_usado() const { return this->_usado; }

void Item::Draw() {
    DrawTexture(this->get_sprite(), this->get_x(), this->get_y(), WHITE);
}
