#define NOUSER //Problema com CloseWindow() e ShowCursor()
#define NOGDI //Deixa de incluir a GDI do Windows, que tem elementos conflitantes (como Rectangle..)
#include "Entidade.hpp"
#include "doctest.h"

TEST_CASE("Testando a Entidade") {

    //Objeto do tipo Entidade
    Entidade entidadeTeste;

    CHECK(entidadeTeste.get_vida() == 100);
    CHECK(entidadeTeste.get_mana() == 0);
    CHECK(entidadeTeste.get_batalha() == false);
    CHECK(entidadeTeste.get_velocidade() == 0);
}

