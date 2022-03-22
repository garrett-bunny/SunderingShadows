// Chernobog (3/15/22)
// Yniam Waystation - Hub

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("A waystation in the Yniam Plains");
    set_short("%^RESET%^%^CRST%^%^C058%^The %^C130%^hub %^C058%^of the %^C144%^Yniam waystation%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C058%^The walls of the palisade encircle this small outpost. Workers move about several projects in this clearing, building along the periphery and using the wooden walls as support in construction. A large ring of stones has started to form in the middle of the clearing.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A strange %^C156%^acrid scent %^C144%^is carried on the breeze.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C126%^The sounds of people at work fill the air.%^CRST%^");
    set_items(([
        ]));
    set_exits(([
        "southwest" : ROOMS"palisade1",
        "northeast" : ROOMS"palisade2",
        "north" : ROOMS"forge",
        ]));
}

