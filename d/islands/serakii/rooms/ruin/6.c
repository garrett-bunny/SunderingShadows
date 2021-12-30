#include <std.h>
#include "../../serakii.h"

inherit STORAGE"tree_lined.c";

void create(){
   ::create();

   set_long(::query_long()+"\n%^C241%^To the north is a massive closed and barred gate%^CRST%^\n");


   set_exits(([

        "heavy gate" : CAER"foyer",
        "south" : RUINS"5",
         "east" : RUINS"9",
          "west" : RUINS"7",

   ]));

    set_door("heavy gate",CAER"foyer","heavy gate",0);
    set_door_description("heavy gate","%^C094%^Formed from solid "+
        "wood, this door looks very"+

" heavy. An %^C244%^iron ring %^C094%^hangs from it to allow it "+
"to be opened.%^CRST%^");
    set_string("heavy gate", "open", "%^C060%^It takes all your "+
        "strength to open the door.%^CRST%^");
    set_string("heavy gate", "close", "%^C060%^You push the door "+
    "with all your weight to close it.%^CRST%^");
}
