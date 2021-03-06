// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartSoldier/NPCPlayerStartCommando/NPCPlayerStartMortarSpotter/NPCPlayerStartMortarSpotter.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCMortarSpotterController/NPCMortarSpotterController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCCamperFirePositionPathNode/NPCCamperFirePositionPathNode.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"
ANPCPlayerStartMortarSpotter::ANPCPlayerStartMortarSpotter()
{

	sDefaultPawnClass = "AGP_Characters.NPC_ISoldierSpotter";
	//ControllerClass = ANPCMortarSpotterController::StaticClass();
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

void ANPCPlayerStartMortarSpotter::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
	Super::CustomCreation(npbcController, agpPawn);
	Cast<ANPCMortarSpotterController>(npbcController)->bSmokeAssaultLocation = bSmokeAssaultLocation;
	if (bStartAndSpawnAtRandomNode)
	{
		if (((GetRequestedPathNode(npbcController, iStartingPathNodeIndex) != nullptr) && GetRequestedPathNode(npbcController, iStartingPathNodeIndex)->IsA(ANPCCamperFirePositionPathNode::StaticClass())) && Cast<ANPCCamperFirePositionPathNode>(GetRequestedPathNode(npbcController, iStartingPathNodeIndex))->bSpotterPosition)
		{
			Cast<ANPCMortarSpotterController>(npbcController)->pnCurrentLocation = Cast<ANPCPathNode>(GetRequestedPathNode(npbcController, iStartingPathNodeIndex));
		}
	}
}
