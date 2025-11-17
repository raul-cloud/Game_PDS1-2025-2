/**
 * @file Inimigo.hpp
 * @brief Definicao da classe Inimigo, que representa os adversarios do jogador
*/

#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Entidade.hpp"
#include "Item.hpp"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime> 

/**
 * @class Inimigo
 * @brief Representa um adversario no jogo, herdando de Entidade
*/
class Inimigo : public Entidade {
    private:

        /// @brief O status atual do inimigo
        std::string _status;

        /// @brief O vetor de itens que o inimigo pode derrubar ao ser derrotado
        std::vector<Item> itens;

        /// @brief O nivel de poder do inimigo.
        int _tier;

        /// @brief A fraqueza do inimigo
        std::string _fraqueza;

    public:
        /**
        * @brief Construtor principal da classe Inimigo
        * @param vida Pontos de vida iniciais
        * @param vivo Se o inimigo esta vivo
        * @param em_batalha Se o inimigo esta em batalha
        * @param status O status inicial do inimigo
        * @param tier O nivel de poder do inimigo
        * @param fraqueza A fraqueza do inimigo
        */
        Inimigo(int vida, int vidaMAX, int defesa, int defesa_base, bool vivo, int x, int y, int velocidade, int atk, const std::string& sprite, int tier, std::string& fraqueza, std::string &status);
        ///@brief Construtor padrao da classe Inimigo
        Inimigo();

        ///@brief Destrutor da classe Inimigo
        ~Inimigo();

        ///@brief Desenha o inimigo na tela
        void desenhar_inimigo() const;

        ///@brief Define o status atual do inimigo
        void set_status(const std::string& stat);

        ///@brief Retorna o status atual do inimigo
        const std::string get_status() const;

        ///@brief Define a fraqueza do inimigo
        void set_fraqueza(std::string& fraqueza);

        ///@brief Retorna a fraqueza do inimigo
        const std::string& get_fraqueza() const;

        /**
        * @brief Verifica se um ataque do inimigo acertou um alvo
        * @param heroiS A referencia para o heroi alvo do ataque
        */
        bool acertou(const Entidade &herois);

        /// @brief Determina e retorna um item que o inimigo derruba ao ser derrotado
        const Item* drop(int valor);

        /// @brief Executa a acao do inimigo durante um turno de batalha
        void acao_batalha();
};

#endif
