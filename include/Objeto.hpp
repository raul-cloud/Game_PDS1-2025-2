/**
 * @file Objeto.hpp
 * @brief Definicao da classe Objeto, a classe base para todos os elementos do jogo.
 */

#ifndef OBJETO_HPP
#define OBJETO_HPP

#include "raylib.h"
#include <string>

/**
 * @class Objeto
 * @brief Representa a entidade responsavel pela posição, representação visual e colisão
 * dos elementos do jogo
 */
class Objeto {

    protected:
        /// @brief A coordenada da posicao do objeto no eixo X
        int _x;

        /// @brief A coordenada da posicao do objeto no eixo Y
        int _y;

        /// @brief Indica se o objeto esta ativo
        bool _ativo; //excluir ou não da tela

        /// @brief A textura grafica (sprite)
        Texture2D _sprite;

        /// @brief O retangulo que define a area de colisao
        Rectangle _espaco_colisao;

    public:
        /**
        * @brief Construtor da classe Objeto
        * @param x A posição inicial no eixo X
        * @param y A posição inicial no eixo Y
        * @param ativo O estado inicial do objeto
        * @param sprite O caminho para o arquivo de imagem do sprite
        */

        /// @brief Construtor base de Objeto
        Objeto ();

        /// @brief Construtor parametrizado de Objeto
        Objeto (int x, int y, bool ativo, const std::string& sprite);

        /// @brief Descontrutor da classe Objeto
        virtual ~Objeto ();
        
        /// @brief Retorna a posicao do objeto no eixo X
        int get_x () const;

        /// @brief Retorna a posicao do objeto no eixo Y
        int get_y () const;

        /// @brief Verifica se o objeto esta ativo
        bool get_ativo () const;

        /**@brief Define a posicao do objeto no eixo X
         * @param nova posicao x do objeto
         */
        void set_x (int novo_x);

        /**@brief Define a posicao do objeto no eixo Y
         * @param nova posicao y do objeto 
         */
        void set_y (int novo_y);

        /**@brief Define o estado do objeto
         * @param novo estado do objeto
         */
        void set_ativo (bool novo_state);

        /// @brief Retorna o sprite
        Texture2D get_sprite() const;
       
        ///@brief Retorna o retangulo de colisão do objeto
        Rectangle get_espaco_colisao () const;

        /**@brief Desenha o sprite do objeto na tela em sua posicao atual.
         * @param Cor do objeto
         */
        void Draw (Color cor) const;
};

#endif
