// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_DAMAGEINSTIGATOR/Action_DAMAGEINSTIGATOR.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/DamageType/Crushed/Crushed.h"

UAction_DAMAGEINSTIGATOR::UAction_DAMAGEINSTIGATOR()
{
	Damage = 10;
	//DamageType = ACrushed::StaticClass();
	ActionString = "Damage instigator";

}

bool UAction_DAMAGEINSTIGATOR::InitActionFor(AScriptedController* C)
{
	APawn* Damaged = nullptr;
	/*
	Damaged = C.GetInstigator();
	Damaged.TakeDamage(Damage, Damaged, Damaged->GetActorLocation(), FVector(0,0,0), DamageType);
	*/
	return false;
}
FString UAction_DAMAGEINSTIGATOR::GetActionString()
{
	//return ActionString @ DamageType @ Damage;
	return "";    //FAKE   /ELiZ
}
