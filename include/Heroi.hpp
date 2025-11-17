/**
* @file Heroi.hpp
* @brief Definição da classe Heroi, representação do personagem do jogador.
*/


#ifndef HEROI_HPP
#define HEROI_HPP

#include "Entidade.hpp"
#include "Item.hpp"
#include <string>
#include <vector>

/**
 *@class Heroi 
 *@brief A classe Heroi herda de Entidade, reprensenta o personagem controlado pelo jogador
 */
class Heroi : public Entidade{
    private:
        /// @brief A classe do heroi("Mago", "Guerreiro", ...)
        std::string _classe;
        /// @brief Pontos de experiencia do heroi
        int _experiencia;
        /// @brief Status atual do herói (ex: "Normal", "Envenenado")
        std::string _status;
        /// @brief Item selecionado pelo usuario
        Item _item;
        /// @brief Quantidade de dinheiro do heroi
        int _dinheiro;

    public:
         
        /** 
        * @brief Construtor da classe heroi
        * @param vida Vida inicial do heroi.
        * @param vivo Estado inicial de vida do heroi
        * @param classe_inicial A classe inicial do heroi
        * @param experiencia A quantidade inicial de experiencia
        * @param status O status inicial do heroi
        * @param dinheiro A quantidade inicial de dinheiro
        */
        Heroi(int vida,int vidaMAX,int defesa,int defesa_base, bool vivo, int x, int y, int vel, int atk,const std::string& sprite, const std::string& classe_inicial, int experiencia, const std::string& status, int dinheiro);
        
        /// @brief destrutor da classe heroi
        ~Heroi();

        /// @brief Define a classe do heroi
        void set_classe(const std::string& classe);

        /// @brief Retorna a classe do heroi("Mago", "Guerreiro", ...)
        std::string get_classe() const;

        /**  
        *   @brief Aumenta ou Diminui a experiencia do heroi
        *   @param pontos_experiencia A quantidade de experiencia a ser removida
        */
        void set_experiencia(int pontos_experiencia);

        /// @brief Retorna a quantidade atual de experiencia do heroi
        int get_experiencia() const;

        /** 
        * @brief Atualiza o status atual do heroi
        *  @param novo_status o novo status do heroi
        */
        void set_status(const std::string& novo_status);
        
        /// @brief Retorna o status atual do heroi
        std::string get_status() const;

        /// @brief Retorna a quantidade de dinheiro do heroi
        int get_dinheiro() const;
        
        /** 
        *   @brief Adiciona ou Remove uma quantidade de dinheiro do heroi 
        *   @param quantidade Valor a ser Subtraido
        */
        void set_dinheiro(int quantidade);

        ///@brief Adiciona um novo item ao inventario do heroi
        void adicionar_item(const Item& item_novo);

        ///@brief Remove um item do inventario de acordo com o indice
        void remover_item(int item_selecionado_indice);

        ///@brief Seleciona um item do inventario para ser utilizado pelo heroi
        void usar_item(int item_selecionado_indice);
        
        ///@brief Lista todos os itens do inventario
        void listar_inventario() const;

};

#endif
