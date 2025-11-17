#include "Skill.hpp"

Skill::Skill() : _dano_causado(0), _ataque_magico(false), _custo(0), _elemento(""), spriteSkill({}){    
}

Skill::Skill(int dano_causado, bool ataque_magico, int custo, const std::string& elemento, const std::string& sprite) : 
            _dano_causado(dano_causado), _ataque_magico(ataque_magico),
             _custo(custo), _elemento(elemento) {
                this->spriteSkill = LoadTexture(sprite.c_str());
    }

Skill::~Skill(){
}

Texture2D Skill::get_sprite() const{
    return this->spriteSkill;
}

void Skill::desenhar() const{
}

int Skill::get_custo() const{
    return this->_custo;
}

int Skill::get_dano() const{
    return this->_dano_causado;
}

bool Skill::get_magico() const {
    return this->_ataque_magico;
}

const std::string& Skill::get_elemento() const{
    return this->_elemento;
}