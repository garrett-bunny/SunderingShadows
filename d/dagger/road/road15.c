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
   set_long("%^CYAN%^You are very near the seaport of Torm, it is just to the northeast. A little to the north of it is the ghost town of Nurval, where the road turns inland and away from the cape of Gailden which Torm sits within. To the northeast you can still see the emerald Yniam plains. To the south a grand temple stands upon an outcropping along the cliffs, overlooking the sea.\n%^RESET%^");
   set_smell("default", "You can smell the salt of the sea on the cool breeze.");
   set_listen("default", "The waves hit the cliffs far below and within the temple the sounds of people talking and training can be heard.");
   set_items(([
      "beaches" : "Golden sand lines the beaches along the Dagger Sea.",
      "sea" : "The great waves crash against the cliffs hundreds of feet below.",
      "temple" : "The grand temple of Cevahir stands perched upon the cliff here, crafted from white marble.",
      "cliff" : "The cliff leads up to the temple and then shoots straight down into the water below.",
   ]));
   set_exits(([
      "northeast" : RPATH "road16",
      "southwest" : RPATH "road14",
      "temple" : "/d/magic/temples/cevahir/cevahir"
   ]));
}
