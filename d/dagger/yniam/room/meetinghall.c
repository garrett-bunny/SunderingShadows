// Chernobog (3/15/22)
// Yniam Waystation - Meeting Hall

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_name("A meeting hall within the waystation");
    set_short("%^RESET%^%^CRST%^%^C046%^A %^C136%^meeting hall %^C046%^within the %^C144%^waystation%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C136%^Smooth timber walls frame this structure, varnished and affecting a rugged warmth in the light offered by a large %^C059%^wrought %^C245%^ir%^C247%^o%^C245%^n %^RESET%^%^C214%^ch%^C220%^an%^C226%^de%^C220%^li%^C214%^er %^RESET%^%^C136%^overhead. The focal point is a %^C130%^large oblong table %^C136%^near the far wall, surrounded by six wooden chairs. They are overseen by a large tapestry displayed on the wall behind, that of the %^C144%^Yniam Plains insignia %^C136%^in bold %^C046%^gre%^C040%^e%^C046%^ns %^C136%^and %^C255%^whit%^C252%^e%^C255%^s%^RESET%^%^C136%^. There are wooden banisters in place to bisect the room, with a couple rows of benches leading to the entrance.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C058%^Hints of oak and varnish flit through the air.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C202%^You can hear the occasional hiss of the %^C214%^wax c%^C220%^a%^C226%^ndl%^C220%^e%^C214%^s %^RESET%^%^C202%^overhead.%^CRST%^");
    set_items(([
        ({"chandelier", "candles"}) : "%^RESET%^%^CRST%^%^C130%^A circle of %^C059%^wrought %^C245%^ir%^C247%^o%^C245%^n %^RESET%^%^C130%^has been suspended from the ceiling, intersected by spokes like that of a wheel. At each juncture around the rim rest a setting for a %^C214%^wax c%^C220%^a%^C226%^nd%^C220%^l%^C214%^e%^C130%^, the whole offering illumination to the entire room below.%^CRST%^",
        ({"table", "chairs"}) : "%^RESET%^%^CRST%^%^C130%^Two large chairs sit central to the table, with two smaller chairs flanking on either side. Each is fashioned from %^C136%^mahogany %^C130%^and shaped by a skillful hand, with the %^C144%^insignia of Yniam %^C130%^carved into the center of each back. The edge of the table facing the rest of the room has been left empty, so that those seated may address supplicants.%^CRST%^",
        "benches" : "%^RESET%^%^CRST%^%^C130%^These are simple wooden benches, likely here for any supplicants awaiting their turn to address the council.%^CRST%^",
        ({"tapestry", "insignia"}) : "%^RESET%^%^CRST%^%^C130%^The insignia of %^C144%^Yniam %^C130%^has been picked out in durable cloth, that of an %^C040%^e%^C046%^me%^C040%^r%^C046%^a%^C040%^l%^C046%^d c%^C040%^i%^C046%^rcl%^C040%^e %^C130%^containing a white stylized silhouette of gathered %^C144%^stalks of wheat %^C130%^alongside a %^C136%^pair of barrels%^C130%^. It hangs from a %^C243%^s%^C245%^i%^C247%^lv%^C245%^e%^C243%^r b%^C245%^a%^C243%^r%^RESET%^%^C130%^, suspended by bleached rope%^C130%^.%^CRST%^",
        ]));
    set_exits(([
        "southeast" : ROOMS"outpost_hub",
        ]));
}

