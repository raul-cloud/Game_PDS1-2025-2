#define NOUSER //Problema com CloseWindow() e ShowCursor()
#define NOGDI //Deixa de incluir a GDI do Windows, que tem elementos conflitantes (como Rectangle..)
#include "Tela.hpp"
#include "doctest.h"

TEST_CASE("Testando a Tela") {

  Tela testeTela(180,200,"oi");

  CHECK(testeTela.tela_deve_fechar() == false);
  CHECK(testeTela.get_width() == 180);
  CHECK(testeTela.get_height() == 200);
}
