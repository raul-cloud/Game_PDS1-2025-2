#include "doctest.h"
#include "Heroi.hpp"

TEST_CASE("Teste Heroi - Definir classe do heroi"){
    Heroi heroi(100, 50, true, "Novato", 0, "Normal", 0);
    heroi.set_classe("Guerreiro");
    CHECK(heroi.get_classe() == "Guerreiro");
}

TEST_CASE("Teste heroi - Definir Experiencia"){
    Heroi heroi(100, 50, true, "Novato", 0, "Normal", 0);
    heroi.set_experiencia(100);
    CHECK(heroi.get_experiencia() == 100);
}

TEST_CASE("Teste heroi - Definir status"){
    Heroi heroi(100, 50, true, "Novato", 0, "Normal", 0);
    heroi.set_status("envenenado");
    CHECK(heroi.get_status() == "envenenado");
}

TEST_CASE("Teste heroi - Definir Dinheiro"){
    Heroi heroi(100, 50, true, "Novato", 0, "Normal", 0);
    heroi.set_dinheiro(20);
    CHECK(heroi.get_dinheiro() == 20);
}
