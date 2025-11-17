
#include "Combat.hpp"
#include "raylib.h"

void Combat::Attack (Entidade& Heroi, Entidade& Monstro) {
  int dano = Heroi.get_ataque() - (int)(Monstro.get_defesa() * 0.75);
  
  if (dano < 0) dano = 0;

  Monstro.set_vida(Monstro.get_vida() - dano);

}

void Combat::MagicAttack (Entidade& Heroi, Entidade& Monstro) {
  int danomgk = (int)(Heroi.get_ataque() * 1.25) - Monstro.get_defesa();

  if (danomgk < 0) danomgk = 0;

  Monstro.set_vida(Monstro.get_vida () - danomgk);
}

void Combat::Defense (Entidade& Entidade) {
  
  Entidade.set_defesa((int)(Entidade.get_defesa() * 1.25));
}

void Combat::Heal (Entidade& Entidade) {
  int cura = GetRandomValue(0, 20);
  Entidade.Curar(cura);
}
void Combat::Run () {
  
  int runchance = GetRandomValue(0,100);
  
  //alterar essa linha depois
  int lixo = (runchance > 90)? OPEN_WORLD : MONSTER_TURN;
}
