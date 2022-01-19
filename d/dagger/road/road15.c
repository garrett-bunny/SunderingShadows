#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(0);
   set_short("The Dagger Sea coast road");
   set_long("%^CYAN%^You are very near the seaport of Torm, it is just to the northeast. A little to the north of it is the ghost town of Nurval, where the road turns inland . To the northeast you can still see the emerald Yniam plains. To the south a grand temple stands upon an outcropping along the cliffs, overlooking the sea.\n%^RESET%^");
   set_smell("default", "You can smell the salt of the sea on the cool breeze.");
   set_listen("default", "The waves hit the cliffs far below and within the temple the sounds of people talking and training can be heard.");
   set_items(([
      "beaches" : "Golden sand lines the beaches along the Dagger Sea.",
      "sea" : "The great waves crash against the cliffs hundreds of feet below.",
      "temple" : "The grand temple of Cevahir stands perched upon the cliff here, crafted from white marble.",
      "cliff" : "The cliff leads up to the temple and then shoots straight down into the water below.",

   set_long("%^CYAN%^You are very near the %^BOLD%^%^BLUE%^seaport of Torm%^RESET%^%^CYAN%^, which lays just to the northeast, cradled by the cape of Gailden. A little to the north of it is the %^RESET%^ghost city of Nurval%^CYAN%^, where the road turns inland and away from the cape. Beyond Torm, you can still see the %^RESET%^%^GREEN%^emerald Yniam plains%^RESET%^%^CYAN%^. To the southeast, a %^BOLD%^%^WHITE%^grand temple%^RESET%^%^CYAN%^ stands upon an outcropping along the cliffs and overlooking the sea. To the northwest, there is a building under construction.\n%^RESET%^");
   set_smell("default", "You can smell the salt of the sea on the cool breeze.");
   set_listen("default", "The sound of waves below, and the noise of soldiers chatting and training.");
   set_items(([
      "beaches" : "Golden sand lines the beaches along the Dagger Sea.",
      "sea" : "The great waves crash against the cliffs hundreds of feet below.",
      "torm" : "Just beyond the temple here, lays the path to the seaport of Torm.",
      "temple" : "A grand temple with white marble walls stand upon the cliff here, overlooking Torm and the sea.",
      "building" : "A building to the northwest appears to be under construction.",
   ]));
   set_exits(([
      "northeast" : RPATH "road16",
      "southwest" : RPATH "road14",
      "temple" : "/d/magic/temples/cevahir/cevahir",
      "northwest" : "/realms/kismet/rooms/phomes/resort", //Uriah's last resort mercenary hall. Leaving this in my realm for now, because it is a WIP. Kismet.
   ]));
}
