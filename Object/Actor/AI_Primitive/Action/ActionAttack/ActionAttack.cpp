// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Action/ActionAttack/ActionAttack.h"
#include "AA29/Object/Actor/AI_Primitive/Contact/Contact.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

AActionAttack::AActionAttack()
{

}

float AActionAttack::evaluateAction()
{
	AContact* enemy_contact = nullptr;
	float lowAmmo = 0;
	float longRange = 0;
	float lof = 0;
	float Range = 0;
	float effectiveRange = 0;
	int32 AmmoAmount = 0;
	/*
	if (checkFailure())
	{
		return 0;
	}
	lowAmmo = 0;
	longRange = 0;
	enemy_contact = Controller.enemyCont;
	if (enemy_contact == nullptr)
	{
		DebugLog(DEBUG_AI, "dnback:: ActionAttack.evaluationAction(); no enemy Contact");
		return 0;
	}
	if (Controller.weaponJammed() || Controller.weaponOutOfAmmo())
	{
		return 0;
	}
	DebugLog(DEBUG_AI, "ActionAttack::evaluateAction()	" + enemy_contact @ enemy_contact.Target @ enemy_contact.isInvisible());
	if (enemy_contact.isInvisible())
	{
		return 0;
	}
	AmmoAmount = GetWeapon().GetCurrentAmmoType().AmmoAmount;
	if (AmmoAmount < 5)
	{
		lowAmmo = 5 - AmmoAmount * 0.1;
	}
	else
	{
		lowAmmo = 1;
	}
	Range = VSize(getPawn().Location - getEnemy().Location);
	effectiveRange = Cast<AAGP_Weapon>(GetWeapon()).GetMaximumRange();
	if (Range < effectiveRange)
	{
		longRange = 1;
	}
	else
	{
		longRange = 1 - Range - effectiveRange / effectiveRange;
	}
	lof = enemy_contact.lineOfFireToHim(getPawn());
	returnFMath::Clamp(lowAmmo * longRange * lof, 0, 1);
	*/
	return 0;      //FAKE   /ELiZ
}
void AActionAttack::executeAction()
{
	//Controller.registerNotification(this);
	//Controller.Attack(0);
}
