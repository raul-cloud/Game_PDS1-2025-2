#include "raylib.h"
#include "Menu.hpp"
#include "Entidade.hpp"
#include "Dungeon.hpp"
int main() {
    InitWindow(1366, 728, "Teste");
    InitAudioDevice();
    SetTargetFPS(60);

    Menu menu;
    menu.CarregarRecursos();
    Entidade e;

    while (!WindowShouldClose()) {
        menu.Atualizar();

        BeginDrawing();
        ClearBackground(BLACK);

        
        if (IsKeyDown(KEY_D)){
        e.Andar(e.get_velocidade(), 0);}
        if (IsKeyDown(KEY_A)){
          e.Andar(-(e.get_velocidade()), 0);}
        if (IsKeyDown(KEY_W)){
          e.Andar(0, -(e.get_velocidade()));}
        if (IsKeyDown(KEY_S)){
          e.Andar(0, e.get_velocidade());}
        
        e.Draw(BLUE);


        if (menu.get_sair()) {
            break;
        }
        else if (menu.get_jogar()) {
            Dungeon dungeon;
            dungeon.GerarDungeon();
            dungeon.DesenharDungeon();
        }
        else {
            menu.Desenhar();
        }

        EndDrawing();
    }
    menu.LiberarRecursos();
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
