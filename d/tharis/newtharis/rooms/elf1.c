#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("A road in the city");
    set_short("%^ORANGE%^An abandoned road in the city%^RESET%^");
    set_long("%^RESET%^%^CRST%^%^C003%^Drawing the eye before anything else here is the vast, looming bulk of the hovering %^CRST%^%^C019%^Shadovar %^C003%^fortress, far in the sky above. It casts the entire city under a pall of unrelenting %^CRST%^%^C059%^darkness%^C003%^. Beneath its shadow, the streets in this area of the city are more narrow, more haphazard. The road is a collection of unmatched cobblestones, while the buildings have the look of something that has been destroyed and rebuilt a thousand times but one - the %^CRST%^%^C240%^Bastion of the E%^C019%^clips%^C240%^e%^C003%^, a massive %^CRST%^%^C244%^black-walled%^C003%^ compound to the north that rises up from the ruins, a literal %^CRST%^%^C160%^monolith%^C003%^ of %^CRST%^%^C243%^stability%^C003%^ and %^CRST%^%^C243%^order%^RESET%^%^C003%^ in a sea of poverty and chaos. The din of clashing steel and bellowing soldiers cut through the eerie silence here, the Bastion's %^CRST%^C160%^martial ambiance%^C003%^ defiant in the face of destitution, their %^CRST%^%^RESET%^%^C059%^fl%^C255%^a%^C059%^g %^C003%^proudly on display in the wind. A small, abandoned office lies to the south. Further west, the road meanders into the city slums.%^RESET%^%^CRST%^\n");
    set_smell("default","%^RESET%^%^ORANGE%^The smell of blood, sweat, and leather emanate from the compound to the north.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^You can hear martial drumbeats nearby.%^RESET%^");
    set_items(([
      "fortress" : "%^BLUE%^Above the city looms the ever-present Shadovar fortress, casting the entire area into a state of perpetual twilight.%^RESET%^",
      "vegetation" : "%^RESET%^%^GREEN%^Wild vegetation grows everywhere, springing from cracks and pushing through every available space.%^RESET%^",
      "flag" : "%^RESET%^%^CRST%^%^C248%^This flagpole towers above the %^RESET%^%^C058%^compound%^C248%^ to the north, a flag emblazoned with a %^C241%^black starburst %^C248%^on a %^RESET%^%^C124%^r%^C160%^e%^C124%^d %^RESET%^%^C248%^background fluttering dramatically in the %^RESET%^%^C030%^wind%^RESET%^%^C248%^. The sheer height of the pole and size of the flag ensure its %^RESET%^%^C031%^vi%^C039%^s%^C038%^i%^C045%^b%^C014%^i%^C045%^l%^C038%^i%^C039%^t%^C031%^y %^RESET%^%^C248%^from well beyond the Bastion’s %^C241%^w%^C244%^a%^C247%^l%^C241%^ls%^RESET%^%^C248%^.%^CRST%^",
    ]));
    set_exits(([
        "east" : ROOMS"elf2",
        "west" : ROOMS"east3",
        "south" : ROOMS"office",
        "north" : "/d/player_houses/caledor/room/courtyard",
        ]));
    set_door("wooden gate", "/d/player_houses/caledor/room/courtyard", "north", 0, 0);
    //set_door("wooden gate", "/d/player_houses/caledor/room/courtyard", "north", "caledor_gate", "lock");
	//set_locked("wooden gate", 1, "lock");
    //lock_difficulty("wooden gate", 55, "lock");
    //set_lock_description("wooden gate", "lock", "%^RESET%^%^CRST%^%^C058%^This is a huge wooden bar that glides across to secure the gate.%^CRST%^");
	set_door_description("wooden gate", "%^RESET%^%^CRST%^%^C058%^Before you is a massive wooden gate bound together with what seems to be forged cold iron bands. A great edifice in the shape of a starburst emblazoned upon it.%^CRST%^");
}

void init(){
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

