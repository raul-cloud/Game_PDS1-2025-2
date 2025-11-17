#define NOUSER //Problema com CloseWindow() e ShowCursor()
#define NOGDI //Deixa de incluir a GDI do Windows, que tem elementos conflitantes (como Rectangle..)
#include "Skill.hpp"
#include "doctest.h"

TEST_CASE("Testando a Skill"){

    //Objeto do tipo Entidade
    Skill SkillTeste;

    CHECK(SkillTeste.get_sprite().id == 0);
    CHECK(SkillTeste.get_custo() == 0);
    CHECK(SkillTeste.get_dano() == 0);
    CHECK(SkillTeste.get_magico() == false);
    CHECK(SkillTeste.get_elemento() == "");
}
