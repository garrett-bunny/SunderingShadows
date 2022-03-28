#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("red leatherbound book");
   set_id(({"book","leather book","old book","red-leatherbound book"}));
   set_short("%^C160%^re%^C088%^d%^C160%^ l%^C088%^e%^C160%^ather"+
   "-bou%^C088%^n%^C160%^d b%^C088%^o%^C160%^ok%^CRST%^");
   set_long("%^C088%^This small book is bound in %^C160%^fine red leather%^C088%^. On the cover, in %^C178%^gold filigree%^C088%^ is a symbol of a a %^C190%^parapet%^C088%^. The pages are mostly empty but some have writing you could >read<.%^CRST%^\n");
   set_weight(0);
   set_read("%^C129%^~ * ~%^CRST%^\n%^C135%^The Hounds have proven useful so far. Such a distraction! All of the commotion around the conclave has allowed the outsider to breach the realm. %^CRST%^\n\n %^C129%^~ * ~%^CRST%^\n%^C147%^ .\n%^C147%^ %^CRST%^\n\n %^C129%^~ * ~%^CRST%^\n%^C135%^ .%^CRST%^\n");
   set_language("common");
}
