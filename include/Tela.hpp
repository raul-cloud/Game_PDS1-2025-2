/**
 * @file Tela.hpp
 * @brief Definicao da classe Tela, responsavel por gerenciar a janela do jogo
 */

#ifndef TELA_HPP
#define TELA_HPP
#include "raylib.h"
#include <string>

/**
 * @class Tela
 * @brief Gerencia a janela principal do jogo utilizando a biblioteca Raylib
*/
class Tela {
    private:
        /// @brief Largura da janela em pixels
        int _width;

        /// @brief Altura da janela em pixels
        int _height;


    public:
        /**
        * @brief Construtor da classe Tela
        * @param texto O titulo que aparecera na barra da janela
        */
        Tela(int width, int height, const char * texto);

        ///@brief Destrutor da classe Tela
        ~Tela();

        ///@brief Verifica se a janela recebeu um sinal para fechar
        bool tela_deve_fechar() const;

        ///@brief Prepara a janela para o desenho de um novo frame
         void tela_desenhar() const;

        ///@brief Atualiza e apaga a janela
        void tela_atualizar() const;

        /// @brief  Retorna a largura da tela
        int get_width() const;

        /// @brief  Retorna a Altura da tela
        int get_height() const;
};

#endif
