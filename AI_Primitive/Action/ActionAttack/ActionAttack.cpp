// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Action/ActionAttack/ActionAttack.h"

AActionAttack::AActionAttack()
{

}

float AActionAttack::evaluateAction()
{
	/*
	local AGP.Contact enemy_contact;
	local float lowAmmo;
	local float longRange;
	local float lof;
	local float Range;
	local float effectiveRange;
	local int AmmoAmount;
	if (checkFailure())
	{
		Return 0;
	}
	lowAmmo = 0;
	longRange = 0;
	enemy_contact = Controller.enemyCont;
	if (enemy_contact == None)
	{
		DebugLog(DEBUG_AI, "dnback:: ActionAttack.evaluationAction(); no enemy Contact");
		Return 0;
	}
	if (Controller.weaponJammed() || Controller.weaponOutOfAmmo())
	{
		Return 0;
	}
	DebugLog(DEBUG_AI, "ActionAttack::evaluateAction()	" $ enemy_contact @ enemy_contact.Target @ enemy_contact.isInvisible());
	if (enemy_contact.isInvisible())
	{
		Return 0;
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
	effectiveRange = AGP_Weapon(GetWeapon()).GetMaximumRange();
	if (Range < effectiveRange)
	{
		longRange = 1;
	}
	else
	{
		longRange = 1 - Range - effectiveRange / effectiveRange;
	}
	lof = enemy_contact.lineOfFireToHim(getPawn());
	Return FClamp(lowAmmo * longRange * lof, 0, 1);
	*/
	return 0;      //FAKE   /ELiZ
}
void AActionAttack::executeAction()
{
	//Controller.registerNotification(Self);
	//Controller.Attack(0);
}
