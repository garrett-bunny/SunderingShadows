


#include <std.h>
#include "../../serakii.h"

inherit "/std/church";

void create(){
   ::create();
    set_short("%^C058%^de%^C243%^s%^C058%^ecrat%^C243%^e%^C058%^d chur%^C243%^c%^C058%^h%^CRST%^");
    set_long("%^C248%^This %^C241%^stone building%^C248%^ is %^C058%^dark %^C248%^and %^C124%^desolate%^C248%^. The walls have been smeared with %^C241%^ash %^C248%^and %^C088%^blood %^C248%^and everything in the building has been %^C251%^cracked %^C248%^and %^C058%^destroyed%^C248%^. The %^C058%^altar %^C248%^has sustained even more damage, smeared with %^C055%^unknown substances%^C248%^ and %^C244%^carved %^C248%^with obscene and %^C092%^fell runes%^C248%^. Even the %^C241%^shadows%^C248%^ linger more than they should in this room.%^CRST%^\n");
   set_exits(([
		  "north" : TOWN"14",



   ]));

}


