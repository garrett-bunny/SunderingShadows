//Christof - barkeep for Serakii - LoKi 2021


#include <std.h>

inherit BARKEEP;

create() {
  ::create();
  set_property("no bump", 1);
  set_name("Christof Miller");
  set_id( ({ "waiter","barkeep", "christof", "Christof Miller", "christof miller" })
);
  set_short("%^C141%^Christof Miller%^CRST%^, "+
  "%^C064%^barkeep%^CRST%^");
  set("aggressive", 0);
  set_long("%^C071%^Dressed in an %^C250%^old apron%^C071%^ "+
  "and wearing simple %^C064%^peasant clothing%^C071%^, this "+
  "man presents the inn with a %^C038%^friendly %^C071%^face "+
  "and a willing ear. He looks to be in his late twenties, "+
  "and with his %^C132%^girth %^C071%^and %^C124%^red "+
  "cheeks%^C071%^ he has not allowed the %^C050%^joys %^C071%^of "+
  "life to pass him by. %^C226%^Straw colored hair%^C071%^ pokes "+
  "out from under a %^C196%^red cloth%^C071%^ he has wrapped up "+
  "around his head. Striking %^C051%^blue eyes%^C071%^ look "+
  "out past similarly %^C226%^chaotic eyebrows%^C071%^. He "+
  "wears no %^C221%^jewelry %^C071%^or ornamentation.\n%^CRST%^");
  set_gender("male");
  set_alignment(2);
  set("race", "human");
  set_level(12);
  set_hd(12,2);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_mp(random(400));
  set_max_mp(query_mp());
  add_money("copper", random(20));
   set_emotes(10,({
      "%^C246%^A table of off duty %^C242%^militia %^C246%^quietly play a game of %^C231%^dice %^C246%^at a %^C100%^table %^C246%^in the corner%^CRST%^\n",
      "%^C251%^The%^C196%^ f%^C226%^i%^C196%^re %^C250%^in the%^C196%^ %^C245%^fireplace %^C196%^c%^C247%^r%^C196%^ack%^C247%^l%^C196%^es.%^CRST%^\n",
      "%^C140%^A %^C064%^farmer %^C140%^finishes their %^C249%^drink%^C140%^. They go over to the %^C241%^fireplace %^C140%^to place a hand on the %^C227%^plaque%^C140%^, mouthing something %^C250%^silently%^C140%^ before leaving.%^CRST%^\n",
        }),0);
  set_body_type("human");
  set_currency("gold");
  set_menu(
      ({"red wine", "whiskey", "dark ale", "water", "coffee", "meat platter", "bread platter"}),
      ({ "alcoholic", "alcoholic", "alcoholic", "soft drink", "caffeine",
         "food", "food"}),
      ({ 25, 30, 10, 1, 5, 20, 20 })
  );
 
  set_my_mess(({
    "%^C088%^You tip the glass back and drink the deep red wine.%^CRST%^\n",
    "%^C179%^The whiskey goes down perfectly and you feel it's warmth spread through you.%^CRST%^\n",
    "%^C095%^The ale is rich and as you drain the glass you feel like another.%^CRST%^\n",
    "%^C075%^The water is clear and refreshing.%^CRST%^\n",
    "%^C094%^The bitter coffee's warmth spreads through you.%^CRST%^\n",
    "%^C126%^The meat platter has all of the choices you'd expect.%^CRST%^\n",
    "%^C130%^The bread is plain and simple but very filling.%^CRST%^\n"
  }));
  
  set_your_mess(({
    "%^C088%^drinks the wine with a smile.%^CRST%^\n",
    "%^C179%^downs the whiskey, licking their lips.%^CRST%^\n",
    "%^C095%^drinks the pint of ale, then looks at the glass as if pondering.%^CRST%^\n",
    "%^C075%^drinks the water.%^CRST%^\n",
    "%^C094%^drinks the coffee and stretches.%^CRST%^\n",
    "%^C126%^slowly picks apart the meat platter.%^CRST%^\n",
    "%^C130%^breaks open the bread and devours it.%^CRST%^\n",

  }));
  
  set_menu_short(({
    "%^C088%^Dark Red wine%^CRST%^",
    "%^C179%^Aged Whiskey%^CRST%^",
    "%^C095%^Dark Ale%^CRST%^",
    "%^C075%^Water%^CRST%^",
    "%^C094%^Bitter Coffee%^CRST%^",
    "%^C126%^Meat Platter%^CRST%^",
    "%^C130%^Bread Platter%^CRST%^"

  }));
  
  set_menu_long(({
    "This is a %^C088%^full bodied local wine%^CRST%^ in a squat glass.%^CRST%^\n",
    "The %^C179%^golden whiskey%^CRST%^ in the glass has been aged for years.%^CRST%^\n",
    "This %^C095%^simple beer%^CRST%^ is dark and served in a tall pint glass.%^CRST%^\n",
    "A simple glass of %^C075%^water%^CRST%^ in a simple glass.%^CRST%^\n",
    "The %^C094%^coffee%^CRST%^ is simple and strong, served in a clay mug.%^CRST%^\n",
    "This wooden platter has been piled with all matter of %^C126%^meats%^CRST%^. Farmer's sausage, bacon and others.%^CRST%^\n",
    "This platter is loaded up with different %^C130%^breads%^CRST%^ and butter. Perfect for any meal.%^CRS%^\n",

  }));
}
