#ifndef CONFIGURACOES_HPP
#define CONFIGURACOES_HPP

//este .hpp é utilizado para definir elementos de escopo global, tal como musica e efeitos sonoros(som)

class Musica{
    float volume_Musica = 0.5f;
    public:
    void set_volumeMusica(float volumeMusica);
    float get_volumeMusica() const;
};

class Som{
    float volume_Som = 0.5f;
    public:
    void set_volumeSom(float volumeSom);
    float get_volumeSom() const;
};

//variável "extern" -> fala para o compilador que musicaGlobal e somGlobal serão definidas apenas uma vez, sem a necessidade de "recriá-las" em cada .cpp
extern Musica musicaGlobal;
extern Som somGlobal;

#endif