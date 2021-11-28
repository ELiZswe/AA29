// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/VehicleKillMessage/VehicleKillMessage.h"

AVehicleKillMessage::AVehicleKillMessage()
{
	KillString = {"Road Kill!","Hit and Run!","Road Rage!","Vehicular Manslaughter!","Pancake!","Eagle Eye!","Top Gun!","Fender Bender!"};
	KillSound = {"Road_Kill","Hit_and_run","Road_Rage","Vehicular_manslaughter","Pancake","EagleEye","top_gun","fender_bender"};
	bIsUnique = true;
	bFadeMessage = true;
	Lifetime = 3;
	DrawColor = FColor(0, 0, 255, 255);
	StackMode = EStackMode::SM_Down;
	PosY = 0.242;
	FontSize = 1;
}


void AVehicleKillMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	Return Default.KillString[Min(Switch, 7)];
	*/
}
void AVehicleKillMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	p.PlayRewardAnnouncement(Default.KillSound[Min(Switch, 7)], 1, true);
	*/
}