// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_DAMAGEINSTIGATOR/Action_DAMAGEINSTIGATOR.h"

UAction_DAMAGEINSTIGATOR::UAction_DAMAGEINSTIGATOR()
{
	Damage = 10;
	//DamageType = Class'Engine.Crushed';
	ActionString = "Damage instigator";

}


bool UAction_DAMAGEINSTIGATOR::InitActionFor(UScriptedController* C)
{
	/*
	local Pawn Damaged;
	Damaged = C.GetInstigator();
	Damaged.TakeDamage(Damage, Damaged, Damaged.Location, vect(0 0 0), DamageType);
	*/
	return false;
}
FString UAction_DAMAGEINSTIGATOR::GetActionString()
{
	//Return ActionString @ DamageType @ Damage;
	return "";    //FAKE   /ELiZ
}