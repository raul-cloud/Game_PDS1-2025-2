/**
 * @file Skill.hpp
 * @brief Definicao da classe Skill, que representa uma habilidade ou magia no jogo
 */
#ifndef SKILL_HPP
#define SKILL_HPP

#include "raylib.h"
#include <string>

/**
 * @class Skill
 * @brief Armazena os atributos e metodos de uma habilidade de personagem
*/
class Skill {
    private:
        /// @brief A quantidade de dano que a habilidade causa
        int _dano_causado;

        /// @brief define se a habilidade e um ataque magico ou fisico
        bool _ataque_magico;

        /// @brief O custo em mana para utilizar a habilidade
        int _custo;

        /// @brief O elemento da habilidade
        std::string _elemento;

        /// @brief A textura grafica da habilidade
        Texture2D spriteSkill;

    public:
        /**
         * @brief Construtor da classe Skill
         * @param dano_causado A quantidade de dano da habilidade
         * @param ataque_magico Se o ataque e magico (true) ou fisico (false)
         * @param custo O custo de mana para usar a habilidade
         * @param elemento O tipo elemental da habilidade
         * @param sprite A textura para a habilidade
        */

        /// @brief Construtor base da classe Skill
        Skill();

        /// @brief Construtor da classe Skill
        Skill(int dano_causado, bool ataque_magico, int custo, const std::string& elemento, const std::string& sprite);
        
        /// @brief Descontrutor da classe Skill
        ~Skill();

        /// @brief Retorna o sprite
        Texture2D get_sprite() const;

        /// @brief Desenha o sprite da habilidade na tela
        void desenhar() const;

        /// @brief Retorna o custo de mana da habilidade
        int get_custo() const;

        /// @brief Retorna a quantidade de dano da habilidade
        int get_dano() const;

        /// @brief Verifica se a habilidade e magica ou fisica
        bool get_magico() const;
        
        /// @brief Retorna o elemento da habilidade
        const std::string& get_elemento() const; 
};

#endif
