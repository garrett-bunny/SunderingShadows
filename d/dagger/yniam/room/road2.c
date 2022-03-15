// Chernobog (3/15/22)
// Interior Yniam Road

#include <std.h>
#include "../defs.h"
inherit INH"road2";

void create(){
    ::create();
    set_exits(([
        "southwest" : ROOMS"road1",
        "northeast" : ROOMS"palisade1",
        ]));
}

