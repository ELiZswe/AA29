// All the original content belonged to the US Army


#include "NPCPlayerStartMortarSpotter.h"

ANPCPlayerStartMortarSpotter::ANPCPlayerStartMortarSpotter()
{

	sDefaultPawnClass = "AGP_Characters.NPC_ISoldierSpotter";
	//ControllerClass = class'AGP.NPCMortarSpotterController';
	iNPCInitialMentalState = 25;
	iNPCLeadershipMentalStateRange = 1000;
	fpNPCMaxVisualRange = 50000;
	fpNPCWeaponAccuracy = 30;
	fNPCExperience = 30;
	iMinThreatLevel = 2;
	iSquadID = 0;
	iFragGrenadeCount = 3;
	iSmokeGrenadeCount = 2;
	bHasBinoculars = true;
	iPrimaryWeaponReloads = 6;
	sPrimaryWeaponDefaultClass = "AGP_Inventory.Weapon_AK47_suRifle";
	fpMortarRequestSkill = 50;
	fpNPCWeaponEffectiveRange = 2000;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagOfficer.S_PSTagOfficer'"), NULL, LOAD_None, NULL);

#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

}