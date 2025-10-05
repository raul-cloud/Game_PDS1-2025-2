#ifndef TELA_HPP
#define TELA_HPP
class Tela {
private:
    int _width;
    int _height;

public:
    Tela(int width, int height, const char* texto);
    ~Tela();

   const bool tela_deve_fechar() const;
   const void tela_desenhar() const;
   const void tela_apagar() const;
};
#endif
