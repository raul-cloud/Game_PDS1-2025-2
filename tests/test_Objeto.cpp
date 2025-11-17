#define NOUSER //Problema com CloseWindow() e ShowCursor()
#define NOGDI //Deixa de incluir a GDI do Windows, que tem elementos conflitantes (como Rectangle..)
#include "Objeto.hpp"
#include "doctest.h"

TEST_CASE("Testando o Objeto") {

    //Objeto do tipo Objeto
    Objeto objetoTeste;

    CHECK(objetoTeste.get_x() == 0);
    CHECK(objetoTeste.get_y() == 0);
    CHECK(objetoTeste.get_ativo() == false);

    Rectangle r = objetoTeste.get_espaco_colisao(); //cria um retângulo e copia os dados do construtor base

    CHECK(r.x == 0);
    CHECK(r.y == 0);
    CHECK(r.width == 0);
    CHECK(r.height == 0);
}
