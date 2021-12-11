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
    return ::prerequisites(ob); 
}
	
int cmd_dazzling_display(string str) {
    object feat;
    if(!objectp(target)) { return 0; }
	
	if(caster->cooldown("dazzling_display")) {
    tell_object(caster, "You can't try to knock someone down yet!");
    return 1; }
	
	if((int)caster->query_property("using instant feat")) {
    tell_object(caster, "You are already in the middle of using a feat!");
    dest_effect();
	return 1; }
	tell_object(caster,"%^C107%^You take a deep breath and prepare yourself for your dazzling display.%^C107%^");
	caster->set_property("dazzling_display", 1);
    caster->add_cooldown("dazzling_display", 60); }
	call_out("begin_display",ROUND_LENGTH, target, caster); 
}

void begin_display() {
	tell_room(place,"%^C107%^" caster->query_cap_name() + " begins to dance and twirl as they display and an awesome display of control. With an abrupt stop they end in an intimidating stance, facing you with a small smile.");
	tell_object(caster,"%^C107%^You begin your dance, ensuring every moment is visible to " target->query_cap_name() + ", wanting to ensure that they fully appreciate the skill you hold.");
	caster->use_stamina(roll_dice(2,6));
	caster->set_property("using instant feat", 1);
	call_out("finish_display",ROUND_LENGTH * 2, target, caster); 
}
	
void finish_display() {
	object *foes=({}),target;
	int i, damage, mod;
	
	foes = target_selector();
	foes -= ({ caster });
	
	mod = BONUS_D->query_stat_bonus(caster, "charisma");
	damage = roll_dice(glvl, 4) + mod;
	
	for(i=0;i<sizeof(foes);i++) {
	
	if(!objectp(targ = foes[i]))
    continue;
	
	if(target->query_property("effect_shaken"))
    continue;
	
	if(do_save(targ, 0) || PLAYER_D->immunity_check("fear")) {
    tell_object(target,"%^C107%^You watch the weapons display with keen interest, however, it fails to inspire much %^C194%^fear at all in you.%^C107%^");
	damage_target(target,target->return_target_limb(),damage/2,"mental");
    "/std/effect/status/shaken"->apply_effect(target, roll_dice(1, 2)); }
    
	else {
	tell_object(target,"");
    tell_room(place,"",({target}));
    "/std/effect/status/cowering"->apply_effect(targ, roll_dice(1, 4));
    damage_target(target,target->return_target_limb(),damage,"mental");
    caster->remove_property("using instant feat");
	caster->set_property("dazzling_display", 1);
    caster->add_cooldown("dazzling_display", 60); }
	}
}
	
void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}