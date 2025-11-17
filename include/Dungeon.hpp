#pragma once

#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include  "raylib.h"


#include <vector>
#include <queue>
#include "Entidade.hpp"

#define MAX_GRID_SIZE 40


struct Coordenada {
  int x, y;
};


class Dungeon {
  private:
  
  Music MusicaDungeon; 
  

  std::vector<std::vector<int>> dungeon;
  std::vector<Entidade> inimigos;
  
  Coordenada start = {1, 1};
  Coordenada exit = {MAX_GRID_SIZE - 2, MAX_GRID_SIZE - 2};

  Rectangle retSim;
  Rectangle retNao;

  public:
    
    Dungeon ();
    ~Dungeon ();

    std::vector<std::vector<int>>& GerarDungeon (); //ou na mao ou algoritmo estilo cellular automata
    int ContarVizinhosVivos (const std::vector<std::vector<int>>& current_grid, int r, int c);
    int AplicarRegra (int current_state, int alive_neighbor);
    void SimularGeracao (std::vector<std::vector<int>>& grid);

    void DesenharDungeon ();
    void AdicionarInimigo (std::vector<std::vector<int>>& grid);
    void AdicionarBau (std::vector<std::vector<int>>& grid);
    void AdicionarSaida (std::vector<std::vector<int>>& grid);
    bool TemCaminho(Coordenada comeco, Coordenada end);
//    bool SairDungeon (Entidade& player);
    void Atualizar ();
    void ResetarDungeon ();
    void SetPosInicial(Entidade& player);
 //   void SetPosInicial(Entidade& player);
    void CriarInimigos (std::vector<std::vector<int>>& grid);
    bool LoadSprites ();
    bool LoadMusica ();

    bool LiberarRecursos ();
    bool CliqueMouse (Rectangle rec) const;
};

#endif
