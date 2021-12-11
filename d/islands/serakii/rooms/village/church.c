


#include <std.h>
#include "../../serakii.h"

inherit "/std/church";

void create(){
   ::create();
    set_short("%^C058%^de%^C243%^s%^C058%^ecrat%^C243%^e%^C058%^d chur%^C243%^c%^C058%^h%^CRST%^");
set_long("%^C251%^This small %^C245%^stone building%^C251%^ was a %^C105%^church%^C251%^, however something feels wrong about it. The %^C095%^pews%^C251%^ have been destroyed and the %^C254%^altar%^C251%^ has been defaced with %^C056%^fell runes%^C251%^. The room itself is %^C109%^clean%^C251%^ however there is an %^C001%^ominous%^C251%^ feeling about it.%^CRST%^\n");
   set_exits(([
		  "north" : TOWN"14",



   ]));

}


