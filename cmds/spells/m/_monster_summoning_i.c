#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object* monsters = ({});
int duration;

create()
{
    ::create();
    set_spell_name("monster summoning i");
    set_spell_level(([ "mage" : 1, "bard" : 1, "cleric" : 1, "paladin" : 1 ]));
    set_syntax("cast CLASS monster summoning i");
    set_spell_sphere("conjuration_summoning");
    set_description("This spell will summon astral defenders of equivalent power to protect the caster. They will react aggressively to anyone attempting to harm the caster. They will fight till slain, and when the casting time is up, the monsters will vanish.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


int preSpell()
{
    if (present(caster->query_name() + "_monster 3", place)) {
        tell_object(caster, "There are already too many monsters.");
        return 0;
    }

    return 1;
}

int spell_effect(int prof)
{
    object monster;
    int num, i;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    num = 4 + roll_dice(1, 4);

    for (i = 0; i < num; i++) {
        monster = new("/d/magic/mon/astral_defender.c");
        if (!objectp(monster)) {
            continue;
        }

        monsters += ({ monster });

        monster->set("aggressive", 1);
        monster->remove_property("swarm");
        monster->set_mlevel("fighter", clevel);
        monster->set_guild_level("fighter", clevel);
        monster->set_hd(clevel, query_spell_level(spell_type));
        monster->set_attacks_num(1);
        monster->set_property("spelled", ({ TO }));
        monster->set_property("spell_creature", TO);
        monster->set_property("spell", TO);
        monster->add_id(caster->query_true_name() + "_monster");
        monster->set_new_exp(1, "low");
        monster->set_property("minion", caster);
        monster->move(environment(caster));
        
        if(caster->is_class("sorcerer") && (caster->query_bloodline() == "abyssal"))
        {
            monster->set_property("damage resistance", 1 + clevel / 10);
            monster->set_property("spell damage resistance", 1 + clevel / 10);
            monster->set_short("%^BOLD%^%^BLACK%^Dark w%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ng%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^d d%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^n%^RESET%^");
            monster->set_long("%^BOLD%^%^BLACK%^Flapping in the air, this horrifying demon is a %^CYAN%^chilling %^BLACK%^sight to behold. It’s eyes are glowing %^RESET%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^e%^RESET%^%^MAGENTA%^t %^BOLD%^o%^RESET%^%^MAGENTA%^rbs %^BOLD%^%^BLACK%^and it’s lupine snout is wrinkled in a perpetual snarl, revealing rows of %^RESET%^%^RED%^jagged %^WHITE%^teeth%^BOLD%^%^BLACK%^. Pitch black skin shot through with v%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ins of %^RESET%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^e%^RESET%^%^MAGENTA%^t %^BOLD%^%^BLACK%^is stretched over a lean muscular body. Large m%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^mbr%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^no%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^s w%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ngs hold it aloft while wicked claws tip it’s fingers and toes which it rends at the air with, its hunger for %^RED%^v%^RESET%^%^RED%^i%^BOLD%^ol%^RESET%^%^RED%^e%^BOLD%^nc%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^palpable. %^RESET%^");
            monster->set_race("demon");
            monster->add_id("demon");
        }
        
        caster->add_follower(monster);
        caster->add_protector(monster);

        tell_room(place, "%^CYAN%^Reality rips and astral prism manifests itself to protect " + caster->QCN + "!%^RESET%^", caster);
        tell_object(caster, "%^CYAN%^Reality rips and astral prism manifests itself to protect you!%^RESET%^");
    }

    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 300;
    duration = time() + spell_duration;
    set_end_time();
    call_out("dest_effect",spell_duration);

    addSpellToCaster();
    spell_successful();

    check();
}

void check()
{
    object monster, * attackers, att;
    int i, j;

    monsters -= ({ 0 });

    if ((!objectp(caster)) || (time() > duration) || (!sizeof(monsters)) || (!objectp(place = environment(caster)))) {
        dest_effect();
        return;
    }

    for (i = 0; i < sizeof(monsters); i++) {
        if (!objectp(monster = monsters[i])) {
            continue;
        }

        if (!present(monster, place)) {
            tell_room(environment(monster), "%^YELLOW%^With its creator gone, " + monster->QCN + " turns back into a piece of regular foliage.");
            monster->move("/d/shadowgate/void");
            monster->remove();
            continue;
        }

        caster->add_protector(monster);
        caster->add_follower(monster);

        if (!sizeof(attackers = (object*)caster->query_attackers())) {
            continue;
        }

        for (j = 0; j < sizeof(attackers); j++) {
            if (!objectp(att = attackers[j])) {
                continue;
            }
            if (member_array(att, (object*)monster->query_attackers()) != -1) {
                continue;
            }

            monster->kill_ob(att, 0);
        }
    }
    call_out("check", 5);
}

void dest_effect()
{
    int i;

    if (objectp(caster)) {
        removeSpellFromCaster();
        tell_object(caster, "%^ORANGE%^%^BOLD%^Summoned prisms vanish!");
    }

    if (sizeof(monsters)) {
        for (i = 0; i < sizeof(monsters); i++) {
            if (!objectp(monsters[i])) {
                continue;
            }
            monsters[i]->move("/d/shadowgate/void");
            monsters[i]->remove();
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
