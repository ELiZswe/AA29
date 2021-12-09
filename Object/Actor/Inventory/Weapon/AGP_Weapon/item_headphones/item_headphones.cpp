// All the original content belonged to the US Army


#include "item_headphones.h"

Aitem_headphones::Aitem_headphones()
{
	special_tag       = "_new";
	DisplayFOV        = 80;
	fWeight           = 0.85;
	PlayerViewOffset  = FVector(0, 0, 0);
	ItemName          = "Headphones";
	Mesh              = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Headphones_1P.Headphones_1P"), NULL, LOAD_None, NULL);
}

void Aitem_headphones::Fire(float Value)
{
}
void Aitem_headphones::Reload()
{
}
void Aitem_headphones::FixJam()
{
}
void Aitem_headphones::ChangeFireMode()
{
}
void Aitem_headphones::SpawnAndAttachMILESGear()
{
}
void Aitem_headphones::NotifyBaseChange()
{
}
void Aitem_headphones::SetMesh()
{
}
void Aitem_headphones::GetStaticMesh(bool bFriendly)
{
}
void Aitem_headphones::AltFire(float Value)
{
}
bool Aitem_headphones::ShouldDrawCrosshair()
{
	return false;
}
bool Aitem_headphones::ShouldBreatheCycle()
{
	return false;
}
EUpperBodyAnim Aitem_headphones::GetUpperBodyLowerAnim()
{
	// Big hack here: The default 3rd person anim is too short and cuts off the 1st person anim. Put this here because its long enough - Ramm 12/8/03
	return EUpperBodyAnim::UBANIM_RPG_LowerRPG;
}
EUpperBodyAnim Aitem_headphones::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_WEAP_RaiseLg;
}
EUpperBodyAnim Aitem_headphones::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_NONE_Large;
}
void Aitem_headphones::PlayIdleAnim()
{
	//RunAnimation('OnStill',1,0.05,True);
}
void Aitem_headphones::TweenDown()
{
	//RunAnimation('Down',1,0.05);
}
