#include "Menu.hpp"
#include "Configuracoes.hpp"
#include <string>

// -------- DEFINIÇÃO DE CAMINHOS PARA OS RECURSOS UTILIZADOS ----------

#define CAMINHO_FONTE_BOTAO "resources/fontes/fonteMenuBotoes.ttf"
#define CAMINHO_FONTE_TITULO "resources/fontes/fonteMenuTitulo.ttf"

#define CAMINHO_MUSICA_MENU "resources/sons/musicaMenu.wav"
#define CAMINHO_MUSICA_AJUSTES "resources/sons/musicaAjustes.wav"
#define CAMINHO_SOM_BOTAO "resources/sons/botaoMenu.wav"
#define CAMINHO_SOM_FALA_AJUDA "resources/sons/falaAjuda.wav"
#define CAMINHO_SOM_AJUSTES "resources/sons/somAjustes.wav"

#define CAMINHO_CORVO_PNG "resources/imagens/Menu/CorvoMenu.png"
#define CAMINHO_PLACA_AJUDA_PNG "resources/imagens/Ajuda/placaAjuda.png"
#define CAMINHO_ROSTO1_PNG "resources/imagens/Ajuda/face1.png"
#define CAMINHO_ROSTO2_PNG "resources/imagens/Ajuda/face2.png"
#define CAMINHO_ROSTO3_PNG "resources/imagens/Ajuda/face3.png"
#define CAMINHO_ROSTO4_PNG "resources/imagens/Ajuda/face4.png"
#define CAMINHO_ROSTO5_PNG "resources/imagens/Ajuda/face5.png"
#define CAMINHO_ROSTO6_PNG "resources/imagens/Ajuda/face6.png"
#define CAMINHO_ROSTO7_PNG "resources/imagens/Ajuda/face7.png"
#define CAMINHO_ROSTO8_PNG "resources/imagens/Ajuda/face8.png"
#define CAMINHO_PERSONAGEM_W_PNG "resources/imagens/Ajuda/personagemW.png"
#define CAMINHO_PERSONAGEM_A_PNG "resources/imagens/Ajuda/personagemA.png"
#define CAMINHO_PERSONAGEM_S_PNG "resources/imagens/Ajuda/personagemS.png"
#define CAMINHO_PERSONAGEM_D_PNG "resources/imagens/Ajuda/personagemD.png"
#define CAMINHO_LETRA_W_PNG "resources/imagens/Ajuda/letraW.png"
#define CAMINHO_LETRA_A_PNG "resources/imagens/Ajuda/letraA.png"
#define CAMINHO_LETRA_S_PNG "resources/imagens/Ajuda/letraS.png"
#define CAMINHO_LETRA_D_PNG "resources/imagens/Ajuda/letraD.png"


//função que verifica se o mouse clica em um retângulo
bool Menu::CliqueMouse(Rectangle rec) const{
  return (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

// --------- DEFINIÇÃO DE GETTERS, CONSTRUTOR E DESTRUTOR -------------

Menu::Menu(){
}

Menu::~Menu(){
    LiberarRecursos();
}

bool Menu::get_sair() const{
  return this->sair;
}

bool Menu::get_ajustes() const{
    return this->ajustes;
}

bool Menu::get_jogar() const{
    return this->jogar;
}

bool Menu::get_menu() const{
    return this->menu;
}


// ------------------------- CARREGAMENTO E LIBERAÇÃO DE RECURSOS -------------------------

// Carrega os recursos
void Menu::CarregarRecursos() {

    if (!IsAudioDeviceReady()) InitAudioDevice();

    //Fontes
    fontMenuTitulo = LoadFont(CAMINHO_FONTE_TITULO);
    fontMenuBotao = LoadFont(CAMINHO_FONTE_BOTAO);

    //Sons
    musicaMenu = LoadMusicStream(CAMINHO_MUSICA_MENU);
    musicaAjustes = LoadMusicStream(CAMINHO_MUSICA_AJUSTES);
    somBotao = LoadSound(CAMINHO_SOM_BOTAO);
    somFala = LoadSound(CAMINHO_SOM_FALA_AJUDA);
    SetMusicVolume(musicaAjustes, musicaGlobal.get_volumeMusica());
    SetMusicVolume(musicaMenu, musicaGlobal.get_volumeMusica());
    PlayMusicStream(musicaMenu);

    //Sprites
    rosto1 = LoadTexture(CAMINHO_ROSTO1_PNG);
    rosto2 = LoadTexture(CAMINHO_ROSTO2_PNG);
    rosto3 = LoadTexture(CAMINHO_ROSTO3_PNG);
    rosto4 = LoadTexture(CAMINHO_ROSTO4_PNG);
    rosto5 = LoadTexture(CAMINHO_ROSTO5_PNG);
    rosto6 = LoadTexture(CAMINHO_ROSTO6_PNG);
    rosto7 = LoadTexture(CAMINHO_ROSTO7_PNG);
    rosto8 = LoadTexture(CAMINHO_ROSTO8_PNG);
    letraW = LoadTexture(CAMINHO_LETRA_W_PNG);
    letraA = LoadTexture(CAMINHO_LETRA_A_PNG);
    letraS = LoadTexture(CAMINHO_LETRA_S_PNG);
    letraD = LoadTexture(CAMINHO_LETRA_D_PNG);
    personagemW = LoadTexture(CAMINHO_PERSONAGEM_W_PNG);
    personagemA = LoadTexture(CAMINHO_PERSONAGEM_A_PNG);
    personagemS = LoadTexture(CAMINHO_PERSONAGEM_S_PNG);
    personagemD = LoadTexture(CAMINHO_PERSONAGEM_D_PNG);
    spriteCorvo = LoadTexture(CAMINHO_CORVO_PNG);
}

// Descarrega os recursos
void Menu::LiberarRecursos(){
  UnloadTexture(spriteCorvo);
  UnloadTexture(rosto1);
  UnloadTexture(rosto2);
  UnloadTexture(rosto3);
  UnloadTexture(rosto4);
  UnloadTexture(rosto5);
  UnloadTexture(rosto6);
  UnloadTexture(rosto7);
  UnloadTexture(rosto8);
  UnloadTexture(letraW);
  UnloadTexture(letraA);
  UnloadTexture(letraS);
  UnloadTexture(letraD);
  UnloadTexture(personagemW);
  UnloadTexture(personagemA);
  UnloadTexture(personagemS);
  UnloadTexture(personagemD);
  UnloadMusicStream(musicaMenu);
  UnloadMusicStream(musicaAjustes);
  UnloadSound(somBotao);
  UnloadSound(somFala);
  UnloadSound(somAjustes);
  UnloadFont(fontMenuTitulo);
  UnloadFont(fontMenuBotao);
}

//Função para determinar o sprite do narrador presente em Ajuda
Texture2D Menu::get_rosto(){
  switch (indiceRosto) {
        case 1: return rosto1;
        case 2: return rosto2;
        case 3: return rosto3; 
        case 4: return rosto4;
        case 5: return rosto5;
        case 6: return rosto6;
        case 7: return rosto7;
        case 8: return rosto8;
        default: return rosto1; 
    }
}

// -------------------------------------------------------------------------------------------------------
//  ----------------------------------- DEFINIÇÃO DAS FUNÇÕES DESENHAR ---------------------------------
// ---------------------------------------------------------------------------------------------------


void Menu::Desenhar() {

  if(menu){
float baseY = GetScreenHeight() / 2 + 200;
float baseX = GetScreenWidth() / 2 + 130;

//criação de diferentes retângulos para cada uma das opções do menu
retIniciar = { baseX - 10.0f, baseY, (float)largura_botao + 15.0f, (float)altura_botao };
retAjustes = { baseX - 5.0f, baseY + 5.0f + espaco_botao, (float)largura_botao + 13.0f , (float)altura_botao };
retSair = { baseX + 35.0f, baseY + 40.0f + espaco_botao, (float)largura_botao - 25.0f, (float)altura_botao };

//decide a cor dos retângulos conforme o mouse do jogador
Color corCliqueMouseIniciar = CheckCollisionPointRec(GetMousePosition(), retIniciar) ? DARKGRAY : BLACK;
Color corCliqueMouseAjustes = CheckCollisionPointRec(GetMousePosition(), retAjustes) ? DARKGRAY : BLACK;
Color corCliqueMouseSair = CheckCollisionPointRec(GetMousePosition(), retSair) ? DARKGRAY : BLACK;
    ClearBackground(BLACK);

  //desenha os retângulos de cada opção
  DrawRectangleRec(retIniciar, corCliqueMouseIniciar);  
  DrawRectangleRec(retSair, corCliqueMouseSair);
  DrawRectangleRec(retAjustes, corCliqueMouseAjustes);

    //Desenha o png do corvo
 DrawTexture(spriteCorvo, (GetScreenWidth() - spriteCorvo.width) / 2,
                (GetScreenHeight() - spriteCorvo.height) / 2 - 100, WHITE);

    //Define o tamanho do título com base na fonte utilizada 
    Vector2 tituloSize = MeasureTextEx(fontMenuTitulo, 
                                    "The Dungeon Master", 
                                    100.0f, 
                                    4.0f);
    // Escreve o título
    DrawTextEx(fontMenuTitulo, "The Dungeon Master", 
               { ((float)GetScreenWidth() - tituloSize.x) / 2.0f - 5.0f, 
                 (float)GetScreenHeight() / 2.0f - 50.0f }, 
                100.0f, 4.0f, GRAY);

    // Escreve "Iniciar"
    DrawTextEx(fontMenuBotao, "Iniciar", 
               { baseX - 10.0f, baseY + 5.0f }, 
                35.0f, 3.0f, WHITE);

    // Escreve "Opções"
    DrawTextEx(fontMenuBotao, "Ajustes", 
               { baseX - 7.5f, baseY + 5.0f + espaco_botao }, 
               35.0f, 3.0f, WHITE);
    // Escreve "Sair"
    DrawTextEx(fontMenuBotao, "Sair",
        { baseX + 40.0f, baseY + 40.0f + espaco_botao },
        35.0f, 3.0f, WHITE);
    }
    if(ajustes){
    Desenhar_ajustes(); //criei uma função à parte para deixar a função mais limpa
    }
    if(ajuda){
      Desenhar_ajuda();
    }
}

// --------------- FUNÇÃO PARA DESENHAR A TELA DE AJUSTES ------------------------------

void Menu::Desenhar_ajustes(){

  float comprimento_botao = 20.0f;
  float altura_botao = 20.0f;

  float x_centralizado = (float)GetScreenWidth() / 2;

  retAjuda = { (float)GetScreenWidth() - 150.0f, (float)GetScreenHeight() - 55.0f, (float)largura_botao + 20.0f, (float)altura_botao };
  retAumentarEfeitos = { x_centralizado + 50.0f, 305.0f, comprimento_botao, altura_botao };
  retDiminuirEfeitos = { x_centralizado + 120.0f, 305.0f, comprimento_botao, altura_botao };
  retAumentarMusica =  { x_centralizado + 50.0f, 355.0f, comprimento_botao, altura_botao };
  retDiminuirMusica =  { x_centralizado + 120.0f, 355.0f, comprimento_botao, altura_botao };

    Color corCliqueMouseAjuda = CheckCollisionPointRec(GetMousePosition(), retAjuda) ? DARKGRAY : BLACK;

    ClearBackground(BLACK);

    DrawRectangleRec(retAjuda, corCliqueMouseAjuda);
    DrawRectangleRec(retAumentarEfeitos, GRAY);
    DrawRectangleRec(retDiminuirEfeitos, GRAY);
    DrawRectangleRec(retAumentarMusica, GRAY);
    DrawRectangleRec(retDiminuirMusica, GRAY);


    DrawTextEx(fontMenuTitulo, "Ajustes", 
               { x_centralizado - 100.0f, 20 }, 
                50.0f, 6.0f, WHITE);

    DrawTextEx(fontMenuBotao, "Audio",
        {x_centralizado - 40.0f, 170.0f },
        35.0f, 3.0f, WHITE);

    DrawTextEx(fontMenuBotao, "Efeitos Sonoros",
        {x_centralizado - 200.0f, 300.0f },
        25.0f, 3.0f, WHITE);
        
    DrawTextEx(fontMenuBotao, "Musica",
        {x_centralizado - 200.0f,350.0f },
        25.0f, 3.0f, WHITE);
        
    DrawTextEx(fontMenuTitulo, "Ajuda",
        { (float)GetScreenWidth() - 150.0f, (float)GetScreenHeight() - 70.0f },
        45.0f, 3.0f, WHITE); 
        
    DrawTextEx(GetFontDefault(), "+", {retAumentarEfeitos.x + 5.0f, retAumentarEfeitos.y + 2.0f}, 20.0f, 1.0f, BLACK); 
    DrawTextEx(GetFontDefault(), "-", {retDiminuirEfeitos.x + 5.0f, retDiminuirEfeitos.y + 2.0f}, 20.0f, 1.0f, BLACK); 
        
    DrawTextEx(GetFontDefault(), "+", {retAumentarMusica.x + 5.0f, retAumentarMusica.y + 2.0f}, 20.0f, 1.0f, BLACK);
    DrawTextEx(GetFontDefault(), "-", {retDiminuirMusica.x + 5.0f, retDiminuirMusica.y + 2.0f}, 20.0f, 1.0f, BLACK);

    DrawText("Aperte E para voltar", 80, GetScreenHeight() - 80, 20, WHITE);
}

// --------------- FUNÇÃO PARA DESENHAR A TELA DE AJUDA ------------------------------

void Menu::Desenhar_ajuda() {
    ClearBackground(BLACK);
    
    // Posições base
    const int LETRA_X = GetScreenWidth()/2 + 50;
    const float POS_X_ROSTO = 50.0f;
    const float POS_Y_DIÁLOGO = 150.0f;
    const float POS_X_ROBÔ = (float)GetScreenWidth() / 2;
    
    // título da página
    DrawText("AJUDA", GetScreenWidth() / 2 - 50, 20, 40, WHITE);
    
    //imagem do "narrador"
    DrawTexture(get_rosto(), (int)POS_X_ROSTO, 100, WHITE);
    
     if (parte_dialogo >= 3) {
        DrawTexture(personagemW, (int)POS_X_ROBÔ, 200, WHITE); 
        DrawTexture(personagemA, (int)POS_X_ROBÔ - 100, 300, WHITE); 
        DrawTexture(personagemS, (int)POS_X_ROBÔ, 400, WHITE); 
        DrawTexture(personagemD, (int)POS_X_ROBÔ + 100, 300, WHITE); 
        DrawTexture(letraW, LETRA_X + 15, 170, WHITE);
        DrawTexture(letraA, LETRA_X - 170, 400, WHITE); 
        DrawTexture(letraS, LETRA_X + 15, 550, WHITE);
        DrawTexture(letraD, LETRA_X + 170, 400, WHITE); 

    }
    
    //temporização das falas
    if (parte_dialogo == 0) {
        DrawText("Olá, vejo que precisa de ajuda", (int)POS_X_ROSTO + 150, (int)POS_Y_DIÁLOGO, 20, WHITE);
    }
    if (parte_dialogo == 1) {
        DrawText("Vou te ensinar alguns comandos básicos do jogo", (int)POS_X_ROSTO + 150, (int)POS_Y_DIÁLOGO, 20, WHITE);
    }
    if (parte_dialogo == 2) {
        DrawText("Utilize as teclas WASD para se movimentar", (int)POS_X_ROSTO + 150, (int)POS_Y_DIÁLOGO, 20, YELLOW);
    }
    if (parte_dialogo == 4) {
        DrawText("É só isso kkkk, boa sorte ai", (int)POS_X_ROSTO + 150, (int)POS_Y_DIÁLOGO, 20, YELLOW);
    }
}

// -------------------------------------------------------------------------------------------------------
//  ----------------------------------- DEFINIÇÃO DAS FUNÇÕES ATUALIZAR ---------------------------------
// ---------------------------------------------------------------------------------------------------


void Menu::Atualizar(){
    if(ajustes){
        SetMusicVolume(musicaAjustes, musicaGlobal.get_volumeMusica());
        UpdateMusicStream(musicaAjustes);
      Atualizar_ajustes();
      return;
    }
    if(ajuda){
      Atualizar_ajuda();
      return;
    }
    if(menu){
    SetMusicVolume(musicaMenu, musicaGlobal.get_volumeMusica());
        UpdateMusicStream(musicaMenu);
      if (CliqueMouse(retIniciar)) {
          PlaySound(somBotao);
          StopMusicStream(musicaMenu); 
          jogar = true;
      }
      if (CliqueMouse(retAjustes)){
        PlaySound(somBotao);
        StopMusicStream(musicaMenu);
        PlayMusicStream(musicaAjustes);
         ajustes = true;
         menu = false;
      }
      if (CliqueMouse(retSair)){
        PlaySound(somBotao);
        StopMusicStream(musicaMenu);
        sair = true;
      } 
    }
}

// --------------- FUNÇÃO PARA ATUALIZAR A TELA DE AJUSTES ------------------------------

void Menu::Atualizar_ajustes(){

const float MUDANCA_VOLUME = 0.10f;

if(ajustes && IsKeyPressed(KEY_E)){
        ajustes = false;
        menu = true;
        StopMusicStream(musicaAjustes);
        PlayMusicStream(musicaMenu);
    }
if(ajustes && CliqueMouse(retAjuda)){
        ajustes = false;
        ajuda = true;
        StopMusicStream(musicaAjustes);
    }

 if (CliqueMouse(retAumentarEfeitos) || CliqueMouse(retDiminuirEfeitos)) {
      float novoVolume;
      if(CliqueMouse(retAumentarEfeitos)){
       novoVolume = somGlobal.get_volumeSom() + MUDANCA_VOLUME;
      }
      else if(CliqueMouse(retDiminuirEfeitos)){
        novoVolume = somGlobal.get_volumeSom() - MUDANCA_VOLUME;
      }

      if (novoVolume > 1.0f) novoVolume = 1.0f;
      if (novoVolume < 0.0f) novoVolume = 0.0f;

      somGlobal.set_volumeSom(novoVolume);
      SetSoundVolume(somBotao, somGlobal.get_volumeSom()); 
        PlaySound(somBotao);
  }    

  if (CliqueMouse(retAumentarMusica) || CliqueMouse(retDiminuirMusica)) {
    float novoVolume;
      if(CliqueMouse(retAumentarMusica)){
          novoVolume = musicaGlobal.get_volumeMusica() + MUDANCA_VOLUME;
      }
      else if(CliqueMouse(retDiminuirMusica)){
          novoVolume = musicaGlobal.get_volumeMusica() - MUDANCA_VOLUME;
      }
      if (novoVolume > 1.0f) novoVolume = 1.0f;
      if (novoVolume < 0.0f) novoVolume = 0.0f;
          musicaGlobal.set_volumeMusica(novoVolume);
          SetMusicVolume(musicaAjustes, musicaGlobal.get_volumeMusica());
          PlaySound(somBotao);
  }        
}

// --------------- FUNÇÃO PARA ATUALIZAR A TELA DE AJUDA ------------------------------



  void Menu::Atualizar_ajuda() {
  
    if (IsKeyPressed(KEY_E)) {
        parte_dialogo = 0;
        ajuda = false;
        ajustes = true;
        StopSound(somFala);
        PlayMusicStream(musicaAjustes);
        return;
    }
    
    // função getframetime() determina quanto tempo se passou desde que o último frame foi criado
    tempo_cada_rosto += GetFrameTime();
    if (tempo_cada_rosto >= 0.2f) { // muda o rosto a cada 0.2s
        indiceRosto = (indiceRosto + 1) % 9; // varia entre 1 e 8
        tempo_cada_rosto = 0.0f;
    }

    SetSoundVolume(somFala, 0.2f); 

    // toca o som de fala enquanto o diálogo está ativo
    if (parte_dialogo < 5 && !IsSoundPlaying(somFala)) {
        PlaySound(somFala); 
    } else if (parte_dialogo == 5 && IsSoundPlaying(somFala)) {
        StopSound(somFala);
    }

    //lógica para iniciar as diferentes partes do diálogo
    else {
        tempoAtual += GetFrameTime(); 
        
        if (tempoAtual >= Tempo_entre_falas) {
            tempoAtual = 0.0f;
            
            switch (parte_dialogo) {
                case 0: // Início: "Olá, vejo que precisa de ajuda."
                    parte_dialogo = 1; 
                    break;
                case 1: // "Vou te ensinar alguns comandos básicos..."
                    parte_dialogo = 2; 
                    break;
                case 2: // "Utilize as teclas WASD para se movimentar"
                    parte_dialogo = 3; 
                    break;
                case 3: //mostra as coisas na tela (teclas e robô W A S D)
                    parte_dialogo = 4;
                    break;
                case 4: // "É isso, boa sorte ai kkkkk"
                    parte_dialogo = 5; 
                    break;
            }
        }
    }
  }