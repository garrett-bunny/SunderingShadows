#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("instant");
    feat_category("General");
    feat_name("dazzling display");
    feat_prereq("Weapon Focus");
	feat_syntax("dazzling_display");
    feat_desc("While wielding the weapon in which you have Weapon Focus, you can perform a bewildering show of prowess as a full-round action. Make an Intimidate check to demoralize all foes within 30 feet who can see your display.");
    set_target_required(1);
    set_save("will");
}

int prerequisites(object ob) {
	if(!FEATS_D->has_feat(ob, "weapon focus")) {
    dest_effect();
	return 0; }
    return ::prerequisites(ob); }
	
void execute_feat() {
	object *foes=({}),target;
	int i;
	
	foes = target_selector();
	foes -= ({ caster });
	
	for(i=0;i<sizeof(foes);i++) {
	
	if(!objectp(targ = foes[i]))
    continue;
	
	if(target->query_property("effect_shaken"))
    continue;
	
	if(do_save(targ, 0) || PLAYER_D->immunity_check("fear"))
        {
            tell_object(target,"%^C107%^You watch the weapons display with keen interest, however, it fails to inspire %^C194%^fear in you.%^C107%^");
            
			damage_targ(targ,targ->return_target_limb(),sdamage/2,"mental");
            "/std/effect/status/shaken"->apply_effect(targ, roll_dice(1, 4));
        }
        else
        {
            tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^Nigh%^BLUE%^t%^BLACK%^mar%^BLUE%^e%^BLACK%^s%^BLACK%^ pierce into your mind!%^RESET%^%^RESET%^");
            tell_room(place,"%^BOLD%^%^GREEN%^"+targ->QCN+"%^BOLD%^%^BLACK%^'s mind is %^BLACK%^ravag%^BLUE%^e%^BLUE%^d%^BLACK%^ by the %^BLUE%^n%^BLACK%^i%^BLUE%^g%^BLUE%^h%^BLACK%^tma%^BLUE%^r%^BLUE%^e%^BLUE%^s%^BLACK%^!%^RESET%^%^RESET%^",({targ}));
            //targ->set_paralyzed(1,"%^RESET%^%^BLUE%^No! No! NO! I must run away! This can't be real!%^RESET%^");
            "/std/effect/status/cowering"->apply_effect(targ, roll_dice(1, 4));
            damage_targ(targ,targ->return_target_limb(),sdamage,"mental");
        }
	
	
	
	
	
	