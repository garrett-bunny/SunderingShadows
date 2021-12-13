#include <std.h>
#include <daemons.h>
inherit FEAT;

object feat;

void create() {
    ::create();
    feat_type("instant");
    feat_category("WeaponMastery");
    feat_name("dazzling display");
    feat_prereq("Weapon Focu");
	feat_syntax("dazzling_display");
    feat_desc("While wielding the weapon in which you have Weapon Focus, you can perform a bewildering show of prowess as a full-round action. Make an Intimidate check to demoralize all foes within 30 feet who can see your display.");
}

int prerequisites(object ob) {
	if(!FEATS_D->has_feat(ob, "weapon focus")) {
    dest_effect();
	return 0; }
    return ::prerequisites(ob); 
}
	
int cmd_dazzling_display(string str) {
    if(!this_player())
        return 0;

    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
	
}

void execute_feat() {
	
	::execute_feat();
	if(caster->cooldown("dazzling display")) {
    tell_object(caster, "You are not ready to perform your dazzling display yet!");
    return 1; }
	
	if((int)caster->query_property("using instant feat")) {
    tell_object(caster, "You are already in the middle of using a feat!");
    dest_effect();
	return 1; }
	
	tell_object(target,"%^C107%^" + caster->query_cap_name() + " begins to dance and twirl as they display and an awesome display of control. With an abrupt stop they end in an intimidating stance, facing you with a small smile.",({target}));
	tell_object(caster,"%^C107%^You begin your dance, ensuring every moment is visible to your enemies to ensure that they fully appreciate the skill you hold.");
	caster->use_stamina(roll_dice(2,6));
	caster->set_property("using instant feat", 1);
	caster->set_property("dazzling_display", 1);
    caster->add_cooldown("dazzling display", 60); 

}
	
void execute_attack() {
	object *foes=({}),target;
	int i, damage;
	::execute_attack();
	
	foes = caster->query_attackers();
	foes -= ({ caster }); 
	
	for(i=0;i<sizeof(foes);i++) {
	
	if(!objectp(target = foes[i]))
    continue;
	
	if(target->query_property("effect_shaken"))
    continue;
	
	if(PLAYER_D->immunity_check("fear")){
	tell_object(caster,"You realize your dance is having no effect on your target.");
	tell_object(target,"%^C107%^You shrug off the effect of the display.");
	return 1; }
	
	if(BONUS_D->intimidate_check(target, caster)) {
    tell_object(caster,"You finish your dance, hoping for the best.");
    tell_object(target,"%^C107%^You watch the weapons display with keen interest, however, it fails to inspire much %^C194%^fear at all in you.%^C107%^");
    "/std/effect/status/shaken"->apply_effect(target, roll_dice(1, 2)); }
    
	else {
		
	tell_object(caster,"You finish your dance, hoping for the best.");
	tell_object(target,"%^C107%^The dazzling display makes you realize, deep down, you cannot complete...%^C107%^",({target}));
    "/std/effect/status/cowering"->apply_effect(target, roll_dice(1, 4)); }
} }
	
void dest_effect() {
    ::dest_effect();
    remove_feat(caster);
    return;
}