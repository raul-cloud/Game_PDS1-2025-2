#include "doctest.h"
#include "Item.hpp"

TEST_CASE("Testando o estado de um Item após a construção") {
    Item item_teste("item-nome", 30, "item-tipo", "item-raridade", false);

    CHECK(item_teste.get_nome() == "item-nome");
    CHECK(item_teste.get_valor() == 30);
    CHECK(item_teste.get_tipo() == "item-tipo");
    CHECK(item_teste.get_raridade() == "item-raridade");
    CHECK(item_teste.get_usado() == false);
}