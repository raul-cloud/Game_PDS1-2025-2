#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "Entidade.hpp"

enum GameState {
  OPEN_WORLD,
  PLAYER_TURN,
  MONSTER_TURN,
  ANIMATION,
  GAME_OVER,
};

class Combat {
  public:
  void DrawCombat ();

  void Attack (Entidade& Heroi, Entidade& Monstro);
  void MagicAttack (Entidade& Heroi, Entidade& Monstro);
  
  void Defense (Entidade& Entidade);
  void Heal (Entidade& Entidade);
  void Run ();
  void UseItem (Entidade& Entidade);

};



#endif
