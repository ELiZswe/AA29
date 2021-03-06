// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartSoldier/NPCPlayerStartSoldier.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCGruntController/NPCGruntController.h"

ANPCPlayerStartSoldier::ANPCPlayerStartSoldier()
{
	sDefaultMeshName = "A_AA2_CharactersOpfor.EnemyInfantry";
	sDefaultPawnClass = "AGP_Characters.NPC_ISoldierGrunt";
	
	asRandomFaceTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_face_a_Mat.t_char_enemy_infantry_face_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_a_Mat.t_char_commando_face_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_b_Mat.t_char_commando_face_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_c_Mat.t_char_commando_face_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_e_Mat.t_char_commando_face_e_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_face_g_Mat.t_char_enemy_commando_face_g_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomHandTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_hands_a_Mat.t_char_enemy_infantry_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomPantTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_pants_a_Mat.t_char_enemy_infantry_pants_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_pants_b_Mat.t_char_enemy_infantry_pants_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_pants_a_Mat.t_char_enemy_infantry_pants_a_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomShirtTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_shirt_a_Mat.t_char_enemy_infantry_shirt_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_shirt_b_Mat.t_char_enemy_infantry_shirt_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_shirt_a_Mat.t_char_enemy_commando_shirt_a_Mat'"), NULL, LOAD_None, NULL)
	};
	
	bUseRandomSkins = true;
	aeshgHeadGearTypes =
	{
		ESoldierHeadGear::SoldierHeadgear_Random,
		ESoldierHeadGear::SoldierHeadgear_None,
		ESoldierHeadGear::SoldierHeadgear_WatchCap,
		ESoldierHeadGear::SoldierHeadgear_WatchCap_Black,
		ESoldierHeadGear::SoldierHeadgear_Beret,
		ESoldierHeadGear::SoldierHeadgear_Beanie,
		ESoldierHeadGear::SoldierHeadgear_Helmet,
		ESoldierHeadGear::SoldierHeadgear_PatrolCap,
		ESoldierHeadGear::SoldierHeadgear_PatrolCap_Black,
		ESoldierHeadGear::SoldierHeadgear_JungleHat,
		ESoldierHeadGear::SoldierHeadgear_JungleHat_Black
	};
	
	//ControllerClass = ANPCGruntController::StaticClass()
	iNPCInitialMentalState = 0;
	iNPCLeadershipMentalStateRange = 250;
	fpNPCWeaponAccuracy = 20;
	fNPCExperience = 15;
	fNPCLikesToCrouch = 25;
	iPlatoonID = 1;
	iSquadID = 1;
	iFragGrenadeCount = 3;
	iSmokeGrenadeCount = 2;
	iPrimaryWeaponReloads = 3;
	sPrimaryWeaponDefaultClass = "AGP_Inventory.Weapon_AK47_Rifle";
	fpMortarRequestSkill = 25;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagGrunt.S_PSTagGrunt'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;
#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

}

void ANPCPlayerStartSoldier::BeginPlay()
{
	Super::BeginPlay();
}

AAGP_Pawn* ANPCPlayerStartSoldier::GetPawnSpawnClass()
{
	if (PawnSpawnClass == nullptr)
	{
		//return class<AGP_Pawn>(DynamicLoadObject(sDefaultPawnClass, Class'Class'));
		return nullptr;    //FAKE   /ELiZ
	}
	else
	{
		return PawnSpawnClass;
	}
}

void ANPCPlayerStartSoldier::ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew)
{
	AActor* Item;
	agpPawnNew->DamageEvent = DamageEvent;
	agpPawnNew->DamageTag = DamageTag;
	agpPawnNew->KillEvent = KillEvent;
	agpPawnNew->KillHealth = KillHealth;
	agpPawnNew->ConfigureLinkDamage();
	if (bUserSetSkin)
	{
		if ((setPants != nullptr) && (!bUseRandomSkins))
		{
			agpPawnNew->Skins[0] = setFace;
			agpPawnNew->Skins[1] = setPants;
			agpPawnNew->Skins[2] = setHands;
			agpPawnNew->Skins[3] = setShirt;
		}
		else
		{
			ConfigureRandomSkins(agpPawnNew);
		}
		if (meshPawn != nullptr)
		{
			//agpPawnNew->LinkMesh(meshPawn, true);
			agpPawnNew->RagdollOverride = RagdollOverride;
		}
		else
		{
			agpPawnNew->RagdollOverride = "OpforM";
			//agpPawnNew->LinkMesh(Mesh(DynamicLoadObject(sDefaultMeshName, Class'Mesh')), true);
		}
		if (bDebugInit)
		{
			//Log("Setting NPC " + FString::FromInt(Tag) + " to mesh: " + FString::FromInt(meshPawn));
		}
	}
	else
	{
		ConfigureRandomSkins(agpPawnNew);
		//agpPawnNew->LinkMesh(agpPawnNew.Mesh);
		agpPawnNew->RagdollOverride = "OpforM";
	}
	agpPawnNew->RagdollLifeSpan = RagdollLifeSpan;
	agpPawnNew->RagInvInertia = RagInvInertia;
	agpPawnNew->RagDeathVel = RagDeathVel;
	agpPawnNew->RagShootStrength = RagShootStrength;
	agpPawnNew->RagSpinScale = RagSpinScale;
	agpPawnNew->RagDeathUpKick = RagDeathUpKick;
	agpPawnNew->RagProneProjectileScale = RagProneProjectileScale;
	agpPawnNew->bNPCDisableSkinSwapping = true;
	Item = nullptr;
	if (eshgHeadGear == ESoldierHeadGear::SoldierHeadgear_Random)
	{
		//eshgHeadGear = aeshgHeadGearTypes[Rand(aeshgHeadGearTypes.Num())];
	}
	switch (eshgHeadGear)
	{
		case ESoldierHeadGear::SoldierHeadgear_WatchCap:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyWatchCap", Class'Class')));
			break;
		case ESoldierHeadGear::SoldierHeadgear_WatchCap_Black:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyWatchCap_Black", Class'Class')));
			break;
		case ESoldierHeadGear::SoldierHeadgear_Beret:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_EnemyCommando_Beret", Class'Class')));
			break;
		case ESoldierHeadGear::SoldierHeadgear_Beanie:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyBeanie", Class'Class')));
			break;
		case ESoldierHeadGear::SoldierHeadgear_Helmet:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyHelmet", Class'Class')));
			break;
		case ESoldierHeadGear::SoldierHeadgear_PatrolCap:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyPatrolCap", Class'Class')));
			break;
		case ESoldierHeadGear::SoldierHeadgear_PatrolCap_Black:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyPatrolCap_Black", Class'Class')));
			break;
		case ESoldierHeadGear::SoldierHeadgear_JungleHat:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyJungleHat", Class'Class')));
			break;
		default:
			break;
	}
	if (Item != nullptr)
	{
		npbcController->actAttachments.Insert(Item, 0);
		//agpPawnNew->AttachToBone(Item, Cast<AItemAttachment>(Item)->AttachBone);
	}
	Item = nullptr;
	switch (esbpBackpack)
	{
		case ESoldierBackpack::SoldierBackpack_Standard:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_EnemyBackpack", Class'Class')));
			break;
		case ESoldierBackpack::SoldierBackpack_RPG:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_RPGBackpack", Class'Class')));
			break;
		case ESoldierBackpack::SoldierBackpack_Radio:
			//Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_RPGBackpack", Class'Class')));
			break;
		default:
			break;
	}
	if (Item != nullptr)
	{
		npbcController->actAttachments.Insert(Item, 0);
		//agpPawnNew.AttachToBone(Item, ItemAttachment(Item).AttachBone);
	}
}

void ANPCPlayerStartSoldier::ConfigureRandomSkins(AAGP_Pawn* agpPawnNew)
{
	int32 iHandsFaceIndex = 0;
	int32 iShirtPantsIndex = 0;
	/*
	iHandsFaceIndex = Rand(asRandomFaceTextures.Num());
	if (bDebugInit)
	{
		Log(string(this) + " using hands/face index: " + FString::FromInt(iHandsFaceIndex));
	}
	agpPawnNew.Skins[2] = Texture(DynamicLoadObject(asRandomHandTextures[iHandsFaceIndex], Class'Texture'));
	agpPawnNew.Skins[0] = Texture(DynamicLoadObject(asRandomFaceTextures[iHandsFaceIndex], Class'Texture'));
	iShirtPantsIndex = Rand(asRandomPantTextures.Num());
	agpPawnNew.Skins[1] = Texture(DynamicLoadObject(asRandomPantTextures[iShirtPantsIndex], Class'Texture'));
	agpPawnNew.Skins[3] = Texture(DynamicLoadObject(asRandomShirtTextures[iShirtPantsIndex], Class'Texture'));
	*/
}
