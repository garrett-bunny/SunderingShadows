//This is the spell associated with the
//Infernal Practicioner Feat

#include <spell.h>
#include <magic.h>

//How many rounds they spend in the hellscape
#define DUR 5
#define DELAY 300

inherit SPELL;

void hurl_effect(int dur, object room, object, victim, int dam);

void create()
{
    ::create();
    set_spell_name("hurl through hell");
    set_spell_level(([ "warlock" : 4 ]));
    set_syntax("cast CLASS hurl through hell on TARGET");
    set_damage_desc("Untyped Damage over several rounds and blind and shaken upon return.");
    set_description(""
    "This invocation represents the highest level of dominance that a "
    "powerful hellfire warlock can assert over an opponent. This "
    "invocation will cause the victim to be thrown through a portal to "
    "the Nine Hells, where they will suffer the most intense physical "
    "and psychological trauma. Even though the visit is brief, the effects "
    "will be severe, causing a large amount of damage and leaving the victim "
    "blind and shaken from the horrors they've witnessed.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_property("keywords", ({ "offensive", "targeted", }));
    set_save("will");
    set_feats_required(([ "warlock" : "infernal practitioner"]));
}

int preSpell()
{
    if(!caster->ok_to_kill(target))
    {
        tell_object(caster, "That is not a valid target.");
        return 0;
    }
   
    if ((int)caster->query_property("spell hurl hell time") + DELAY > time()) {
        tell_object(caster, "You cannot use hurl through hell yet.");
        return 0;
    }
  
    return 1;
}
string query_cast_string()
{
    tell_object(caster, "%^RESET%^%^MAGENTA%^Your eyes begin to %^BOLD%^" + "%^RED%^glow%^RESET%^%^MAGENTA%^ as you focus on your %^RED%^" + "pact. %^MAGENTA%^Gesturing towards " + target->QCN + ", you attempt to rip " + "the walls of reality and bridge a path to the %^BOLD%^%^RED%^N%^BLACK%^i" + "%^RED%^n%^MAGENTA%^e %^RED%^H%^MAGENTA%^e%^RED%^l" + "%^BLACK%^l%^RED%^s%^RESET%^%^MAGENTA%^!%^RESET%^");
    tell_room(environment(caster), "%^MAGENTA%^With an %^BOLD%^%^RED%^i" + "%^BLACK%^n%^RED%^f%^MAGENTA%^e%^RED%^r%^BLACK%^n" + "%^RED%^al %^BLACK%^g%^RED%^l%^MAGENTA%^o%^RED%^w " + "%^RESET%^%^MAGENTA%^filling " + caster->QP + " eyes,"  + caster->QCN + " points towards " + target->QCN + "... and the %^BOLD%^%^WHITE%^fa" + "%^RESET%^i%^BOLD%^%^BLACK%^nt %^WHITE%^ec%^RESET%^h" + "%^BOLD%^%^BLACK%^oes %^RESET%^%^MAGENTA%^of %^RED%^" + "pain %^MAGENTA%^and %^RED%^torment %^MAGENTA%^sound from all " + "around.%^WHITE%^", ({ caster }));
    return "display";
}

void spell_effect(int prof)
{
    object room, hell_room;
    
    room = environment(caster);
    
    if(room != environment(target))
    {
        tell_object(caster, "Your target is no longer here.");
        return;
    }
    
    hell_room = load_object("/d/magic/room/hellscape");
    
    if(!objectp(hell_room))
    {
        tell_object(caster, "Error, destination error. Contact a wiz.");
        return;
    }
    
    spell_successful();
    caster->set_property("spell hurl hell time", time());
    
    if(do_save(target, 0))
    {
        tell_object(caster, sprintf("%s resists your attempts to throw them through the nine hells.", target->QCN));
        tell_object(target, "You shake off the effects of the spell.");
        spell_kill(target,caster);
        return;
    }
    
    tell_object(caster, "%^RESET%^%^RED%^You focus your %^BOLD%^will %^RESET%^%^RED%^forward as you %^MAGENTA%^lash out%^RED%^, sending " + target->QCN + " falling backwards into the awaiting %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^w %^RESET%^%^RED%^of the %^BOLD%^p%^MAGENTA%^l%^RED%^a%^BLACK%^n%^MAGENTA%^a%^RED%^r r%^BLACK%^i%^MAGENTA%^f%^RED%^t%^RESET%^%^RED%^!%^RESET%^");
    tell_object(target, "%^RESET%^%^RED%^CASTER %^MAGENTA%^thrusts %^RED%^an outstretched %^WHITE%^palm %^RED%^towards you, and you feel yourself falling backwards into a %^BOLD%^%^BLACK%^fo%^WHITE%^r%^BLACK%^eb%^RESET%^o%^BOLD%^%^BLACK%^d%^RESET%^i%^BOLD%^n%^BLACK%^g %^MAGENTA%^p%^RED%^l%^BLACK%^a%^RED%^n%^MAGENTA%^a%^RED%^r r%^BLACK%^i%^MAGENTA%^f%^RED%^t%^RESET%^%^RED%^...%^RESET%^");
    tell_room(room, "%^RESET%^%^RED%^With the %^MAGENTA%^thrust %^RED%^of an outstretched %^WHITE%^palm%^RED%^, CASTER sends TARGET back through a %^BOLD%^r%^BLACK%^i%^MAGENTA%^f%^RED%^t %^RESET%^%^RED%^torn in %^BOLD%^%^BLACK%^re%^WHITE%^a%^BLACK%^l%^RESET%^i%^BOLD%^t%^BLACK%^y%^RESET%^%^RED%^!%^RESET%^", ({ caster, target }));
    
    target->move(hell_room);
    
    call_out("hurl_effect", DUR, room, target, sdamage, DUR);
}

void hurl_effect(object room, object victim, int dam, int dur)
{
    if(!living(victim))
    {
        tell_object(caster, "You sense your victim has perished in hell...");
        dest_effect();
        return;
    }
    
    switch(random(4))
    {
        case 0:
        tell_object(victim, "%^RESET%^%^RED%^With a THUD, you land on a rough %^ORANGE%^wooden table%^RED%^. %^BOLD%^D%^MAGENTA%^e%^RED%^v%^MAGENTA%^i%^RED%^l%^MAGENTA%^i%^RED%^s%^MAGENTA%^h %^RED%^g%^MAGENTA%^l%^RED%^e%^MAGENTA%^e %^RESET%^%^RED%^fills the faces of the %^BOLD%^fiends %^RESET%^%^RED%^surrounding you, and they waste no time before %^BOLD%^%^BLACK%^stabbing %^RESET%^%^RED%^you with every %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^p %^RESET%^%^RED%^implement in reach! With a cackle, the nearest %^BOLD%^devil %^RESET%^%^RED%^grabs you by the ankle and throws you into a %^BOLD%^gl%^MAGENTA%^o%^RED%^w%^BLACK%^i%^RED%^ng %^MAGENTA%^r%^RED%^i%^BLACK%^f%^RED%^t!%^RESET%^");
        break;
        case 1:
        tell_object(victim, "%^RESET%^%^BLUE%^You land... in %^BOLD%^%^BLACK%^e%^RESET%^m%^BOLD%^%^BLACK%^p%^WHITE%^t%^BLACK%^in%^RESET%^e%^BOLD%^s%^BLACK%^s%^RESET%^%^BLUE%^. Nothing. No light. No sensation. Just %^MAGENTA%^inky black void %^BLUE%^stretching in every direction forever. Has it been seconds? Hours? Days? The %^BOLD%^%^BLACK%^l%^WHITE%^o%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^l%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^es%^RESET%^s %^BLUE%^and %^BOLD%^%^BLACK%^i%^WHITE%^s%^BLACK%^ol%^RESET%^a%^BOLD%^%^BLACK%^t%^WHITE%^i%^RESET%^o%^BOLD%^%^BLACK%^n %^RESET%^%^BLUE%^twist and taunt your mind... Suddenly, you are %^BOLD%^%^WHITE%^blinded %^RESET%^%^BLUE%^by a %^BOLD%^gl%^MAGENTA%^o%^RED%^w%^BLACK%^i%^RED%^ng %^MAGENTA%^r%^RED%^i%^BLACK%^f%^RED%^tt that appears and swallows you!%^RESET%^");
        break;
        case 2:
        tell_object(victim, "%^RESET%^%^ORANGE%^You fall headlong into a murky brown sludge... a pool of %^BOLD%^%^BLACK%^offal%^RESET%^%^ORANGE%^! It %^RED%^s%^MAGENTA%^q%^RED%^ui%^MAGENTA%^rt%^RED%^s %^ORANGE%^up into your nose and slips past your lips and down your throat as you get pulled below the surface, suffocating in %^GREEN%^re%^BOLD%^p%^RESET%^%^GREEN%^u%^BOLD%^l%^RESET%^%^GREEN%^s%^BOLD%^io%^RESET%^%^GREEN%^n%^ORANGE%^... You feel a pull, and a sludgy %^GREEN%^whirlpool %^ORANGE%^forms, yanking you down into another %^BOLD%^%^RED%^p%^MAGENTA%^l%^RED%^an%^BLACK%^a%^RED%^r r%^BLACK%^i%^MAGENTA%^f%^RED%^t%^RESET%^%^ORANGE%^.%^RESET%^.");
        break;
        default:
        tell_object(victim, "%^RESET%^%^CYAN%^Your vision is obscurred by a %^BOLD%^f%^WHITE%^r%^CYAN%^eez%^WHITE%^i%^CYAN%^ng %^WHITE%^s%^CYAN%^le%^WHITE%^e%^CYAN%^t st%^WHITE%^o%^CYAN%^rm%^RESET%^%^CYAN%^, leeching away what warmth you used to possess. The %^BOLD%^ch%^WHITE%^i%^CYAN%^ll %^RESET%^%^CYAN%^enters your bones, and you can feel your flesh coating with %^BOLD%^i%^WHITE%^c%^CYAN%^e%^RESET%^%^CYAN%^, locking you into place... until you feel a familiar, %^RED%^hateful %^CYAN%^pull as you slip into another %^BOLD%^%^RED%^r%^BLACK%^i%^MAGENTA%^f%^REDt%^RESET%^%^CYAN%^.%^RESET%^");
        break;
    }
    
    //Put some kind of check here for devil race -> won't be damaged
    if(victim->query_race() != "devil")
        damage_targ(victim, victim->return_target_limb(), roll_dice(1, 10) + dam / DUR, "untyped");
    
    dur--;
    
    if(dur < 1)
    {
        tell_object(victim, "You fall back through a portal to the prime material.");
        tell_room(room, victim->QCN + " falls through a portal back into the room.", victim);
        victim->move(room);
        victim->set_temporary_blinded(roll_dice(1,6));
        "/std/effect/status/sickened"->apply_effect(victim,roll_dice(1,6));
        spell_kill(victim,caster);
        dest_effect();
        return;
    }
    
    call_out("hurl_effect", dur, room, victim, dam, dur);
}
