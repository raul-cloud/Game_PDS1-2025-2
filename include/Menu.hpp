#pragma once
#include "raylib.h"

class Menu {
private:
    // --- Resources utilizados ---
    Font fontMenuTitulo; 
    Font fontMenuBotao;
    Music musicaMenu;
    Music musicaAjustes;
    Sound somFala;
    Sound somAjustes;
    Sound somBotao;
    Texture2D spriteCorvo; 
    Texture2D rosto1;
    Texture2D rosto2;
    Texture2D rosto3;
    Texture2D rosto4;
    Texture2D rosto5;
    Texture2D rosto6;
    Texture2D rosto7;
    Texture2D rosto8;
    Texture2D personagemW;
    Texture2D personagemA;
    Texture2D personagemS;
    Texture2D personagemD;
    Texture2D letraW;
    Texture2D letraA;
    Texture2D letraS;
    Texture2D letraD;

    //Diálogo (Ajuda)
    int parte_dialogo = 0;
    float tempoAtual = 0.0f;
    const float Tempo_entre_falas = 1.2f;

    //animação rosto (Ajuda)
    float tempo_cada_rosto = 0.0f;
    int indiceRosto = 1; //alternar entre os 8 sprites (assume valores de 1 a 8)

    // --- VARIÁVEIS DE ESTADO INTERNO ---
    bool jogar = false; // controla se começa a jogar
    bool ajustes = false; //controla se entra em config 
    bool menu = true; // controla se está no menu
    bool sair = false; //controla o fechamento do jogo
    bool ajuda = false; //controla se Ajuda está aberto ou não

    //Caixas para controle de volume + e - 
    Rectangle retAumentarMusica; 
    Rectangle retDiminuirMusica; 
    Rectangle retAumentarEfeitos;   
    Rectangle retDiminuirEfeitos; 

    // --- Caixas dos botões ---
    Rectangle retIniciar;
    Rectangle retAjustes;
    Rectangle retSair;
    Rectangle retAjuda;

public:

    // --- PROPRIEDADES DE BOTÕES ---
    const int largura_botao = 100;
    const int altura_botao = 30;
    const float espaco_botao = 30.0f;

    // Construtor
    Menu(); 
    // Destrutor
    ~Menu(); 
    
    // Inicializa os recursos do raylib
    void CarregarRecursos();
    // Descarrega os recursos
    void LiberarRecursos();
    
    // Métodos Principais de Loop
    void Atualizar();
    void Atualizar_ajustes();
    void Atualizar_ajuda();
    void Desenhar();
    void Desenhar_ajustes();
    void Desenhar_ajuda();
    
    bool get_sair() const;
    bool get_ajustes() const;
    bool get_jogar() const;
    bool get_menu() const;

    Texture2D get_rosto();

    bool CliqueMouse(Rectangle rec) const;
};
