// Chernobog (3/15/22)
// Northern Yniam Road

#include <std.h>
#include "/d/dagger/tonovi/short.h"
inherit "/d/dagger/yniam/inherit/road";

void create(){
    ::create();
    set_exits(([
        "south" : RPATH "1path2",
        "north" : RPATH "1path4",
        ]));
}

