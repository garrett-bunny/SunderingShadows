#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();
    set_exits(([
"west": RPATH "m_p007_p003",
"southeast": RPATH "m_p009_p002",

    ]));
}

