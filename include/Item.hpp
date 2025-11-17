/**
 * @file Item.hpp
 * @brief Definicao da classe Item, que representa um objeto coletavel no jogo
 */
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "Objeto.hpp"

/**
 * @class Item
 * @brief Armazena todas as informacoes de um item, como tipo, ...
 */
class Item : public Objeto {
    private:
        /// @brief O valor do item em moedas
        int _valor;

        /// @brief O tipo do item
        std::string _tipo;

        /// @brief A categoria do item
        std::string _categoria;

        /// @brief A raridade do item
        std::string _raridade;

        /// @brief Indica se o item ja foi utilizado
        bool _usado;
    public:
        /// @brief Construtor padrao de item
        Item();

        /**
        * @brief Construtor da classe Item
        * @param valor O valor do item
        * @param tipo O tipo do item
        * @param categoria A categoria do item
        * @param raridade O nivel de raridade do item
        * @param usado O estado inicial de uso do item (padrao: "false")
        */
        Item(const std::string& categoria, int valor, const std::string& tipo, const std::string& raridade, bool usado, const std::string& sprite);
        
        /// @brief Destrutor da classe Item
        ~Item();

        /// @brief Retorna o valor monetario do item
        int get_valor() const;

        /// @brief Retorna o tipo do item
        const std::string& get_tipo() const;

        /// @brief Retorna a categoria do item
        /// @return 
        const std::string& get_categoria() const;

        /// @brief Retorna a raridade do item
        const std::string& get_raridade() const;

        /// @brief Verifica se o item ja foi usado.
        bool get_usado() const;

        /// @brief Desenha o item
        void Draw();
};

#endif
