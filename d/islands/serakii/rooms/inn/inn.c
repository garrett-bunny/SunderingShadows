// borked room

#include <std.h>
#include "../../serakii.h"

inherit VAULT;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);

    set_name("ruined inn");
    set_property("light",2);
    set_short("%^C101%^r%^C241%^u%^C101%^ined i%^C241%^n%^C101%^n%^CRST%^");
    set_long("This room has been completely and utterly %^C102%^devastated %^CRST%^by some attack. The roof has enough %^C101%^gaping holes%^CRST%^ that you can see the %^C116%^sky %^CRST%^and nothing has remained. The floor was a nice %^C094%^wooden construction%^CRST%^, and there is a %^C241%^scorched fireplace%^CRST%^ off to one side. A %^C058%^bar%^CRST%^, torn into three pieces lies in a corner. There are blood stains in several places. \n");
 


set_smell("default","You smell %^C241%^ash %^CRST%^and %^C124%^blood%^CRST%^");
set_listen("default","You hear little over the rush of %^C183%^wind %^CRST%^through the holes in the ceiling");


    set_exits(([
                   "out" : INN"1",
        ]));


    set_door("door",INN"1","out",0);

}
