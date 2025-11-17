#include "Configuracoes.hpp"
#include "raylib.h"

Musica musicaGlobal;
Som somGlobal;

void Musica::set_volumeMusica(float volumeMusica){
    this->volume_Musica = volumeMusica;
}

float Musica::get_volumeMusica() const{
    return this->volume_Musica;
}

void Som::set_volumeSom(float volumeSom){
    this->volume_Som = volumeSom;
}

float Som::get_volumeSom() const{
    return this->volume_Som;
}