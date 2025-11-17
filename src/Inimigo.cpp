#include "Inimigo.hpp"

Inimigo::Inimigo() : Entidade(0, 0, 0, 0, false, 0, 0, 0, 0, ""), itens{}, _tier(0) {}

Inimigo::Inimigo(int vida, int vidaMax, int def, int def_base, bool vivo, int x, int y, int vel, int atk, const std::string& sprite, int tier) : 
    Entidade(vida, vidaMax, def, def_base, vivo, x, y, vel, atk, sprite),
    itens{}, _tier(tier) {}

Inimigo::~Inimigo(){  
}

void Inimigo::desenhar_inimigo() const{
}

bool Inimigo::acertou(const Entidade &herois){
    srand(time(0));
    int numeroEntre0e9 = rand() % 10;
    if(numeroEntre0e9 <= 9){ return true; }
    return false;
}

const Item* Inimigo::drop(int valor){
    return nullptr;
}

void Inimigo::acao_batalha(){
}

