/**
 * @file Entidade.hpp
 * @brief Definicao da classe Entidade, que serve de base para todos os personagens
*/
#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include "raylib.h"
#include "Objeto.hpp"
#include <string>

/**
 * @class Entidade
 * @brief Herda de Objetos, adicionando atributos de combate e de estado de jogo
*/

class Entidade : public Objeto {
        private: 
            /// @brief Pontos de vida atuais da entidade
            int _vida;
            
            /// @brief Pontos de vida maximos que uma entidade pode ter
            int _vida_maxima;

            /// @brief Pontos de defesa da entidade
            int _defesa;
            
            /// @brief Pontos de defesa maximos que uma entidade pode ter
            int _defesa_base;

            /// @brief A velocidade da entidade no mapa
            int _velocidade;
            
            /// @brief O dano base da entidade
            int _ataque;

          public:

                
                ///@brief Construtor padrao da Entidade.
                Entidade ();

               /**
                * @brief Construtor personalizado da Entidade
                * @param vida Pontos de vida iniciais
                * @param ativo Se a entidade esta viva no jogo
                * @param batalha Se a entidade começa em estado de batalha
                * @param x Posicao inicial no eixo X
                * @param y Posicao inicial no eixo Y
                * @param velocidade Velocidade de movimento inicial
                * @param dano base
                * @param sprite imagem do sprite
                */
               Entidade (int vida, int vidaMAX, int defesa, int defesa_base ,bool viva, int x, int y, int velocidade, int ataque, const std::string& sprite); //o int x, o int y, ativo e sprite (dá LoadTexture depois) serão utilizados no construtor de Objeto também)
               
               /// @brief Destrutor da classe Entidade
               virtual ~Entidade ();

               /// @brief Retorna os pontos de vida atuais
               int get_vida () const;

               /// @brief Retorna a velocidade da entidade
               int get_velocidade () const;
               
               /// @brief Retorna a defesa da entidade
               int get_defesa () const;
              
               /// @brief Retorna a vida maxima da entidade
               int get_vida_maxima () const;

               /// @brief Retorna a defesa base da entidade
               int get_defesa_base () const;

               /// @brief Retorna o ataque da entidade
               int get_ataque () const;

               /// @brief Define a velocidade de movimento da entidade
               void set_velocidade (int nova_velocidade);

               /// @brief Define os pontos de vida da entidade
               void set_vida (int nova_vida);

               /// @brief Define os pontos de defesa da entidade
               void set_defesa (int nova_defesa);

               /// @brief Define a vida maxima da entidade
               void set_vida_maxima (int nova_vida);

               /// @brief Define a defesa base da entidade
               void set_defesa_base (int nova_defesa);
               
               /// @brief Causa dano
               void set_ataque (int novo_ataque);

               /**
                * @brief Recebe o dano causado
                * @param Inteiro que representa o dano causado
                */
               void ReceberDano (int dano);

               /**
                * @brief Cura a vida
                * @param Vida a ser curada
                */
               void Curar (int vida);

               /// @brief Altera o Estado de vida de uma entidade
               void Morrer ();
               
               /** @brief Atualiza a posicao da entidade no mapa com base em sua velocidade
                *  @param posicao x a ser somada
                *  @param posicao y a ser somada
                */
               void Andar (int dx, int dy);

};

#endif
