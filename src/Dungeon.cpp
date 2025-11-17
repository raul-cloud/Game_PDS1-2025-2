#include "Dungeon.hpp"
#include "raylib.h"
#include "Entidade.hpp"


#define CAMINHO_MUSICA_DUNGEON "resources/sons/musicadungeon.wav"

//Construtor para evitar erro de memoria
Dungeon::Dungeon () {
  dungeon.resize(MAX_GRID_SIZE, std::vector<int>(MAX_GRID_SIZE, 0));
  
}

//Destrutor padrao
Dungeon::~Dungeon () {}


//Gera a dungeon
std::vector<std::vector<int>>& Dungeon::GerarDungeon () {
    while (true) {
        for (int i = 0; i < MAX_GRID_SIZE; ++i) {
            for (int j = 0; j < MAX_GRID_SIZE; ++j) {
                dungeon[i][j] = (GetRandomValue(0, 100) < 45) ? 1 : 0;
            }
        }

        for (int k = 0; k < 5; ++k) {
            SimularGeracao(dungeon);
        }

        dungeon[start.y][start.x] = 0;
        dungeon[exit.y][exit.x]   = 0;

        if (TemCaminho(start, exit)) {
            break;
        }
    }
    AdicionarBau(dungeon);
    AdicionarInimigo(dungeon);
    AdicionarSaida(dungeon);
    CriarInimigos(dungeon);
    return dungeon;
}

//conta os vizinhos de cada celula
int Dungeon::ContarVizinhosVivos (const std::vector<std::vector<int>>& current_grid, int row, int col) {
  int alive_neighbors = 0;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {

      if (i == 0 && j == 0) continue;
      int neighbor_row = row + i;
      int neighbor_col = col + j;


      if (neighbor_row < 0 || neighbor_row >= (int)current_grid.size() ||
          neighbor_col < 0 || neighbor_col >= (int)current_grid[0].size()) {
          
          alive_neighbors ++;
      } 
      else {
          alive_neighbors += current_grid[neighbor_row][neighbor_col];


        }
      }
    }
  return alive_neighbors;
  }

//Aplica a regra do cellular automata(>4 morre, <4 vive)
int Dungeon::AplicarRegra (int current_state, int alive_neighbors) {
  if (alive_neighbors > 4) {
    return 1;
  }
  if (alive_neighbors < 4) {
    return 0;
  }
  return current_state;
}

//"Gera" a matriz Celullar automata
void Dungeon::SimularGeracao (std::vector<std::vector<int>>& grid) {
  std::vector<std::vector<int>> cp_grid = grid;

  for (int i = 0; i < (int)grid.size(); ++i) {
    for (int j = 0; j < (int)grid[0].size(); ++j) {
      int alive_neighbors = ContarVizinhosVivos(grid, i, j);
      cp_grid[i][j] = AplicarRegra(grid[i][j], alive_neighbors);
    }
  }
  grid = cp_grid;
}

//funcao que verifica se existe um caminho possivel entre a entrada da dungeon ate a saida
bool Dungeon::TemCaminho(Coordenada comeco, Coordenada end) {
  int H = dungeon.size();
  int W = dungeon[0].size();
  
  std::vector<std::vector<bool>> visitado(H, std::vector<bool>(W, false));

  std::queue<Coordenada> fila;
  fila.push(comeco);
  visitado[comeco.y][comeco.x] = true;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  while (!fila.empty()) {
    auto c = fila.front();
    fila.pop();

    if (c.x == end.x && c.y == end.y) return true;

    for (int i = 0; i < 4; ++i) {
      int nx = c.x + dx[i];
      int ny = c.y + dy[i];

      if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
        if (!visitado[ny][nx] && dungeon[ny][nx] == 0) {
          visitado[ny][nx] = true;
          fila.push({nx,ny});
        }
      }
    }
  }
  return false;
}

void Dungeon::ResetarDungeon () {
  GerarDungeon();
  return;
}

void Dungeon::DesenharDungeon() {
    int larguraTela = GetScreenWidth();
    int alturaTela = GetScreenHeight();

    int tileW = larguraTela / (int)dungeon.size();
    int tileH = alturaTela / (int)dungeon.size();

    for (int i = 0; i < (int)dungeon.size(); ++i) {
        for (int j = 0; j < (int)dungeon[0].size(); ++j) {

            Color cor;

            switch (dungeon[i][j]) {
                case 0: cor = DARKBLUE; break;       // chão
                case 1: cor = LIGHTGRAY; break;      // parede
                case 2: cor = GREEN; break;          // saída
                case 3: cor = BROWN; break;          // baú
                case 4: cor = RED; break;            // inimigo
                default: cor = BLACK; break;
            }

            DrawRectangle(j * tileW, i * tileH, tileW, tileH, cor);

            for (auto& inimigo : inimigos) {
              inimigo.Draw(GREEN);
            }
        }
    }
  //  if(SairDungeon()) {
      
    //  ClearBackground(BLACK);
      //DrawText("Proxima Dungeon?", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, WHITE);
      
     // retNao = {40 + GetScreenWidth() / 2, GetScreenHeight() / 2, 50, 30};
      //retSim = {30 + GetScreenWidth() / 2, GetScreenHeight() / 2, 50 ,30};
      //DrawText("Sim", 40 + GetScreenWidth() / 2, GetScreenHeight() / 2, 10, WHITE);
      //DrawText("Nao", 60 + GetScreenWidth() / 2, GetScreenHeight() / 2, 10, WHITE);
      //DrawRectangle(retNao, RED);
      //DrawRectangle(retSim, GREEN);
    //}
}

//void Dungeon::Atualizar () {
  //if(CliqueMouse(retNao)) {

  //}
  //if(CliqueMouse(retSim)){
   // ResetarDungeon();
  //}
  //return;
//}

bool Dungeon::LoadMusica () {
  MusicaDungeon = LoadMusicStream(CAMINHO_MUSICA_DUNGEON);
  return true;

}

bool Dungeon::LiberarRecursos () {
  UnloadMusicStream(MusicaDungeon);
  }

//Implementa baus aleatoriamente pela dungeon
void Dungeon::AdicionarBau (std::vector<std::vector<int>>& grid) {
  int randnum = 0;
  
  for (int i = 0; i < (int)grid.size(); ++i) {
    for (int j = 0; j < (int)grid[0].size(); ++j) {
      if (grid[i][j] == 0) {
        randnum = GetRandomValue(0, 100);
        if (randnum > 97) {
          grid[i][j] = 3;
        }
      }
    }
  }
}

//Implementa Inimigos aleatoriamente pela dungeon
void Dungeon::AdicionarInimigo (std::vector<std::vector<int>>& grid) {
  int randnum = 0;

  for (int i = 0; i < (int)grid.size(); ++i) {
    for (int j = 0; j < (int)grid[0].size(); ++j) {
      if(grid[i][j] == 0) {
        randnum = GetRandomValue(0, 100);
        if (randnum > 95) {
          grid[i][j] = 4;
        }
      }
    }
  }
}

void Dungeon::CriarInimigos (std::vector<std::vector<int>>& grid) {
  inimigos.clear();
    int larguraTela = GetScreenWidth();
    int alturaTela = GetScreenHeight();

    int tileW = larguraTela / (int)dungeon.size();
    int tileH = alturaTela / (int)dungeon.size();


  for(int i = 0; i < (int)grid.size(); ++i) {
    for (int j = 0; j < (int)grid[0].size(); ++j) {
      if (grid[i][j] == 4) {
        Entidade e(10, 10, 10, 10, true, j * tileW, i * tileH, 10, 10, " ");
        inimigos.push_back(e);
                            
      }
    }
  }
}

//Garante que nenhuma celula tenha no numero 2, e setta o ultimo ponto como saida
void Dungeon::AdicionarSaida (std::vector<std::vector<int>>& grid) {
  for (int i = 0; i < (int)grid.size(); ++i) {
    for (int j = 0; j < (int)grid[0].size(); ++j) {
      if (grid[i][j] == 2) {
        grid[i][j] = 0;
      }
    }
  }
  grid[exit.y][exit.x] = 2;
}

//bool Dungeon::SairDungeon (Entidade& player) {
  //int x = player.x;
 // int y = player.y;

  //if (dungeon[x][y] == 3) {
   // return true;
  //}
 // return false;
//}

//bool Dungeon::CliqueMouse (Rectangle rec) const {
  //return CheckCollisionPointRec((GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
//}

void Dungeon::SetPosInicial(Entidade& player) {
  player.set_x(start.x);
  player.set_y(start.y);
}
