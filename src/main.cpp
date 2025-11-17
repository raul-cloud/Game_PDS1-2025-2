#include "Menu.hpp"
#include "Entidade.hpp"
#include "Dungeon.hpp"
#include "raylib.h"

enum GameState {
  MENU,
  JOGANDO,
};

int main() {
    InitWindow(1366, 728, "Teste");
    InitAudioDevice();
    SetTargetFPS(60);

    Menu menu;
    menu.CarregarRecursos();

    Entidade player;
    Dungeon dungeon;

    bool jogando = false;     // controla se já saiu do menu

    // Loop principal
    while (!WindowShouldClose()) {

        // Enquanto não está jogando, atualiza menu
        if (!jogando) {
            menu.Atualizar();

            if (menu.get_sair())
                break;

            if (menu.get_jogar()) {
                jogando = true;
                dungeon.GerarDungeon();
                dungeon.SetPosInicial(player);
            }
        }

        // Atualização do jogador (só se estiver jogando)
        if (jogando) {
            if (IsKeyDown(KEY_D)) player.Andar(player.get_velocidade(), 0);
            if (IsKeyDown(KEY_A)) player.Andar(-player.get_velocidade(), 0);
            if (IsKeyDown(KEY_W)) player.Andar(0, -player.get_velocidade());
            if (IsKeyDown(KEY_S)) player.Andar(0, player.get_velocidade());
        }

        // ------------------------------------------
        // DESENHO
        // ------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

        if (!jogando) {
            menu.Desenhar();
        } else {
            dungeon.DesenharDungeon();
            player.Draw(BLUE);
        }

        EndDrawing();
    }

    menu.LiberarRecursos();
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

