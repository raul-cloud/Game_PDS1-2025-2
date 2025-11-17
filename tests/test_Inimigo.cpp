#define NOUSER //Problema com CloseWindow() e ShowCursor()
#define NOGDI //Deixa de incluir a GDI do Windows, que tem elementos conflitantes (como Rectangle..)
#include "Inimigo.hpp"
#include "doctest.h"

TEST_CASE("Testando o Inimigo") {

    //Objeto do tipo Inimigo
    Inimigo inimigoTeste;

    CHECK(inimigoTeste.get_x() == 0);
    CHECK(inimigoTeste.get_y() == 0);
    CHECK(inimigoTeste.get_ativo() == false);
    CHECK(inimigoTeste.get_mana() == 0);
    CHECK(inimigoTeste.get_vida() == 0);
    CHECK(inimigoTeste.get_fraqueza() == "");
}
