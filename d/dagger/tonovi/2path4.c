// Chernobog (3/15/22)
// Northern Yniam Road

#include <std.h>
#include "/d/dagger/tonovi/short.h"
inherit "/d/dagger/yniam/inherit/road";

void create(){
    ::create();
    set_exits(([
        "west" : RPATH "2path5",
        "east" : RPATH "2path3",
        "north" : RPATH "tower2",
        ]));
}

