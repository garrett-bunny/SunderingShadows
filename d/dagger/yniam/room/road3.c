// Chernobog (3/15/22)
// Interior Yniam Road

#include <std.h>
#include "../defs.h"
inherit INH"road2";

void create(){
    ::create();
    set_exits(([
        "southwest" : ROOMS"palisade2",
        "northeast" : "/d/dagger/tonovi/2path1",
        ]));
}

