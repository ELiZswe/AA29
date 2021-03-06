// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_EnemyCommando/NPC_EnemyCommando.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"

ANPC_EnemyCommando::ANPC_EnemyCommando()
{
	MovementAnims  = {
		"PtrlWlkFwLg",
		"PtrlWlkBkLg",
		"PtrlWlkLtLg",
		"PtrlWlkRtLg"
	};
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/EnemyCommando.EnemyCommando'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void ANPC_EnemyCommando::BeginPlay()
{
	BeginPlay();
	if (GetNetMode() != ENetMode::NM_Client)
	{
		/*
		if (Cast<AAGP_GameInfo>(GetGameMode())->bNoInventory)
		{
			//DebugLog(DEBUG_Warn, "AGP_Pawn::BeginPlay()	Not giving InvContainers!");
		}
		else
		{
			if (_InvHands == nullptr)
			{
				//_InvHands = SpawnContainer("AGP_Inventory.InvHands");
				//_InvHands->bStasis = true;
				//_InvHands->SetPhysics(PHYS_None);
				//_InvShoulder = SpawnContainer("AGP_Inventory.InvShoulder");
				//_InvShoulder->bStasis = true;
				//_InvShoulder->SetPhysics(PHYS_None);
			}
		}
		*/
	}
}

void ANPC_EnemyCommando::LoadSkinsAndMeshes()
{
	int32 i = 0;
	if (GetNetMode() != ENetMode::NM_Client)
	{
		for (i = 0; i < Skins.Num(); i++)
		{
			FriendlyMaterial[i] = Skins[i];
		}
		//FriendlyMesh = Mesh;
	}
}

void ANPC_EnemyCommando::SetSkinsAndMeshes()
{
	int32 i = 0;
	if (!bUpdateSkinsAndMeshes)
	{
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Skins.Empty();
		//AlphaSkins.Num() = 0;
		//BlackSkins.Num() = 0;
		for (i = 0; i < 5; i++)
		{
			if (FriendlyMaterial[i] != nullptr)
			{
				Skins.Add(FriendlyMaterial[i]);
			}
			else
			{
			}
		}
		//LinkMesh(FriendlyMesh);
	}
	bUpdateSkinsAndMeshes = false;
}

void ANPC_EnemyCommando::AnimateWalking()
{
	if ((UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large) || (UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload))
	{
		if (GetNetMode() != ENetMode::NM_Client)
		{
			/*
			if ((((Controller.IsInState("WalkingPatrol") || Controller.IsInState("ReturnToPatrol")) || Controller.IsInState("GuardMode")) && (Weapon != nullptr)) && (!Weapon->IsA(ARocketWeapon::StaticClass())))
			{
				bWalkingPatrol = true;
			}
			else
			{
				bWalkingPatrol = false;
			}
			*/
		}
		if (bWalkingPatrol)
		{
			TurnLeftAnim = "PtrlWlkRotLtLg";
			TurnRightAnim = "PtrlWlkRotRtLg";
			MovementAnims[0] = "PtrlWlkFwLg";
			MovementAnims[1] = "PtrlWlkBkLg";
			MovementAnims[2] = "PtrlWlkLtLg";
			MovementAnims[3] = "PtrlWlkRtLg";
		}
		else
		{
			TurnLeftAnim = "StdRotLtLgFr";
			TurnRightAnim = "StdRotRtLgFr";
			MovementAnims[0] = "WlkFwLgFr";
			MovementAnims[1] = "WlkBkLgFr";
			MovementAnims[2] = "WlkLtLgFr";
			MovementAnims[3] = "WlkRtLgFr";
		}
	}
	else
	{
		TurnLeftAnim = "StdRotLtNo";
		TurnRightAnim = "StdRotRtNo";
		MovementAnims[0] = "WlkFwNo";
		MovementAnims[1] = "WlkBkNo";
		MovementAnims[2] = "WlkLtNo";
		MovementAnims[3] = "WlkRtNo";
	}
}

bool ANPC_EnemyCommando::IsFriend(APawn* Other)
{
	return false;
}
