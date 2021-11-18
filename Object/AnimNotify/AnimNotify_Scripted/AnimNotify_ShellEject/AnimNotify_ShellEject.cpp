// All the original content belonged to the US Army


#include "AA29/Object/AnimNotify/AnimNotify_Scripted/AnimNotify_ShellEject/AnimNotify_ShellEject.h"

UAnimNotify_ShellEject::UAnimNotify_ShellEject()
{

}

void UAnimNotify_ShellEject::Notify(AActor* Owner)
{
	/*
	local AGP_Effects.BaseShellEmitter SE;
	local HumanController HC;
	if (Owner.IsA('AGP_Weapon'))
	{
		HC = HumanController(Owner.Instigator.Controller);
		if (HC == None || HC.bNoClientSideEffects)
		{
			Return;
		}
		SE = BaseWeaponAttachment(AGP_Weapon(Owner).ThirdPersonActor).GetShellEmitter();
		SE.AnimControlledEject();
	}
	*/
}