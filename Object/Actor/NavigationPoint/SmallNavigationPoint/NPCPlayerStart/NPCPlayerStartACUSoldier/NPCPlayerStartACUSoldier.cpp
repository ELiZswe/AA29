// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartACUSoldier/NPCPlayerStartACUSoldier.h"
#include "Materials/MaterialInstance.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCACUSoldierController/NPCACUSoldierController.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRecruiterController.h"

ANPCPlayerStartACUSoldier::ANPCPlayerStartACUSoldier()
{
	Volume = 1;
	Radius = 64;
	Pitch = 1;
	fpPlayerDetectionRange = 200;
	asRandomFaceTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_AfrA_Mat.Soldier_FACE_AfrA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_AfrB_Mat.Soldier_FACE_AfrB_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_AfrC_Mat.Soldier_FACE_AfrC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucA_Mat.Soldier_FACE_CaucA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucB_Mat.Soldier_FACE_CaucB_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucC_Mat.Soldier_FACE_CaucC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucD_Mat.Soldier_FACE_CaucD_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucE_Mat.Soldier_FACE_CaucE_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_LatinA_Mat.Soldier_FACE_LatinA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_LatinB_Mat.Soldier_FACE_LatinB_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_LatinC_Mat.Soldier_FACE_LatinC_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomHandTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Afr_New_1P_Mat.Soldier_HAND_Inf_Afr_New_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Afr_New_1P_Mat.Soldier_HAND_Inf_Afr_New_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Afr_New_1P_Mat.Soldier_HAND_Inf_Afr_New_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_New_1p_Mat.Soldier_HAND_Inf_Cauc_New_1p_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_New_1p_Mat.Soldier_HAND_Inf_Cauc_New_1p_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_New_1p_Mat.Soldier_HAND_Inf_Cauc_New_1p_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_New_1p_Mat.Soldier_HAND_Inf_Cauc_New_1p_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_New_1p_Mat.Soldier_HAND_Inf_Cauc_New_1p_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Latin_New_1P_Mat.Soldier_HAND_Inf_Latin_New_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Latin_New_1P_Mat.Soldier_HAND_Inf_Latin_New_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Latin_New_1P_Mat.Soldier_HAND_Inf_Latin_New_1P_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomShirtTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_crable_Mat.t_char_inf_acu_shirt_crable_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_alexander_Mat.t_char_inf_acu_shirt_alexander_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_perez_Mat.t_char_inf_acu_shirt_perez_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_scott_Mat.t_char_inf_acu_shirt_scott_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_foster_Mat.t_char_inf_acu_shirt_foster_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_kunz_Mat.t_char_inf_acu_shirt_kunz_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_kozlowski_Mat.t_char_inf_acu_shirt_kozlowski_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_davidson_Mat.t_char_inf_acu_shirt_davidson_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_blattner_Mat.t_char_inf_acu_shirt_blattner_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_champlin_Mat.t_char_inf_acu_shirt_champlin_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_koltunov_Mat.t_char_inf_acu_shirt_koltunov_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_ray_Mat.t_char_inf_acu_shirt_ray_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_crable_Mat.t_char_inf_acu_shirt_crable_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_nascone_Mat.t_char_inf_acu_shirt_nascone_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_soares_Mat.t_char_inf_acu_shirt_soares_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_whiting_Mat.t_char_inf_acu_shirt_whiting_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_crable_Mat.t_char_inf_acu_shirt_crable_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_bossant_Mat.t_char_inf_acu_shirt_bossant_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_salter_Mat.t_char_inf_acu_shirt_salter_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Inf/t_char_inf_acu_shirt_ambrogi_Mat.t_char_inf_acu_shirt_ambrogi_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomSFFaceTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_FACE_SF_AfrA_Mat.Soldier_FACE_SF_AfrA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_FACE_SF_AfrB_Mat.Soldier_FACE_SF_AfrB_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_FACE_Sf_CaucA_Mat.Soldier_FACE_Sf_CaucA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_FACE_SF_CaucB_Mat.Soldier_FACE_SF_CaucB_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_FACE_SF_LatinA_Mat.Soldier_FACE_SF_LatinA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_FACE_SF_LatinB_Mat.Soldier_FACE_SF_LatinB_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_FACE_Sf_LatinC_Mat.Soldier_FACE_Sf_LatinC_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomSFHandTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_HAND_SF_Afr_1P_Mat.Soldier_HAND_SF_Afr_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_HAND_SF_Afr_New_1P_Mat.Soldier_HAND_SF_Afr_New_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_HAND_Sf_Cauc_Mat.Soldier_HAND_Sf_Cauc_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_HAND_Sf_Cauc_Mat.Soldier_HAND_Sf_Cauc_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_HAND_SF_Latin_1P_Mat.Soldier_HAND_SF_Latin_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_HAND_SF_Latin_1P_Mat.Soldier_HAND_SF_Latin_1P_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Soldier_HAND_SF_Latin_1P_Mat.Soldier_HAND_SF_Latin_1P_Mat'"), NULL, LOAD_None, NULL)
	};
	sDefaultMeshName = "A_AA2_CharactersUS.InfantryBasicACU";
	sDefaultPawnClass = "AGP_Characters.NPC_ACUBasicSoldier";
	//ControllerClass = ANPCACUSoldierController::StaticClass();
	iNPCInitialMentalState = 99;
	iNPCLeadershipMentalStateRange = 250;
	iNPCTeamID = 3;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNPCBlue.S_PNPCBlue'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;

#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

}

AAGP_Pawn* ANPCPlayerStartACUSoldier::GetPawnSpawnClass()
{
	if (PawnSpawnClass == nullptr)
	{
		//return class<AGP_Pawn>(DynamicLoadObject(sDefaultPawnClass, Class'Class'));
		return nullptr;    //FAKE  /EliZ
	}
	else
	{
		return PawnSpawnClass;
	}
}

void ANPCPlayerStartACUSoldier::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
	/*
	NPCACUSoldierController(npbcController).anameUserActivatedAudio = anameRecruiterLipSynchAudio;
	NPCACUSoldierController(npbcController).Volume = Volume;
	NPCACUSoldierController(npbcController).Radius = Radius;
	NPCACUSoldierController(npbcController).Pitch = Pitch;
	NPCACUSoldierController(npbcController).fpPlayerDetectionRange = fpPlayerDetectionRange;
	NPCACUSoldierController(npbcController).nameUserLeavingAudio = nameUserLeavingAudio;
	Log("NPC Recruiter has " + FString::FromInt(Cast<ANPCRecruiterController>(npbcController).anameUserActivatedAudio.Num()) + " lipsynchs");
	*/
}

void ANPCPlayerStartACUSoldier::ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew)
{
	AActor* Item = nullptr;
	AItemAttachment* IAClass = nullptr;
	Super::ConfigurePawn(npbcController, agpPawnNew);
	/*
	agpPawnNew.DamageEvent = DamageEvent;
	agpPawnNew.DamageTag = DamageTag;
	agpPawnNew.KillEvent = KillEvent;
	agpPawnNew.KillHealth = KillHealth;
	agpPawnNew.ConfigureLinkDamage();
	agpPawnNew.bEyeTrack = bEnableEyeTracking;
	if (bUserSetSkin)
	{
		if (setPants != nullptr)
		{
			agpPawnNew.Skins[0] = setFace;
			agpPawnNew.Skins[1] = setPants;
			agpPawnNew.Skins[2] = setHands;
			agpPawnNew.Skins[3] = setShirt;
		}
		else
		{
			ConfigureRandomSkins(agpPawnNew);
		}
	}
	else
	{
		ConfigureRandomSkins(agpPawnNew);
	}
	switch (eshgHeadGear)
	{
	case 1:
		Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_BDUCap", Class'Class')));
		break;
	case 2:
		Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_BDUCap_sgt", Class'Class')));
		break;
	case 3:
		Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_Beret", Class'Class')));
		break;
	case 4:
		Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_Helmet", Class'Class')));
		break;
	case 5:
		Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_DesertCap", Class'Class')));
		break;
	default:
	}
	if (Item != nullptr)
	{
		agpPawnNew.AttachToBone(Item, ItemAttachment(Item).AttachBone);
	}
	if (bMedicRucksack)
	{
		IAClass = class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_MedicRuck", Class'Class'));
		Item = Spawn(IAClass, agpPawnNew);
		if (Item != nullptr)
		{
			agpPawnNew.AttachToBone(Item, ItemAttachment(Item).Default.AttachBone);
			agpPawnNew.RegisterAttachment(Cast<AItemAttachment>(Item));
		}
	}
	*/
}

void ANPCPlayerStartACUSoldier::ConfigureRandomSkins(AAGP_Pawn* agpPawnNew)
{
	int32 iFaceHandsIndex = 0;
	/*
	if (espPantsType == 0)
	{
		agpPawnNew.Skins[1] = setPants;
	}
	else
	{
		if (espPantsType == 1)
		{
			agpPawnNew.Skins[1] = Texture(DynamicLoadObject("T_AAO_Characters.Inf.T_CHAR_INF_ACU_LOWERTORSO1A", Class'Texture'));
		}
		else
		{
			if (espPantsType != 3)
			{
				agpPawnNew.Skins[1] = Texture(DynamicLoadObject("T_AAO_Characters.SF.T_CHAR_SF_ACU_LOWERTORSO1A", Class'Texture'));
			}
		}
	}
	switch (esfFaceType)
	{
	case 1:
		iFaceHandsIndex = Rand(asRandomFaceTextures.Num());
		agpPawnNew.Skins[0] = Texture(DynamicLoadObject(asRandomFaceTextures[iFaceHandsIndex], Class'Texture'));
		break;
	case 2:
		iFaceHandsIndex = Rand(asRandomFaceTextures.Num());
		agpPawnNew.Skins[0] = Texture(DynamicLoadObject(asRandomFaceTextures[iFaceHandsIndex] + "_CAMO", Class'Texture'));
		break;
	case 3:
		iFaceHandsIndex = Rand(asRandomSFFaceTextures.Num());
		agpPawnNew.Skins[0] = Texture(DynamicLoadObject(asRandomSFFaceTextures[iFaceHandsIndex], Class'Texture'));
		break;
	case 0:
		iFaceHandsIndex = Rand(asRandomFaceTextures.Num());
		agpPawnNew.Skins[0] = setFace;
		break;
	default:
	}
	switch (eshHandType)
	{
	case 1:
		if (esfFaceType == 3)
		{
			agpPawnNew.Skins[2] = Texture(DynamicLoadObject(asRandomSFHandTextures[iFaceHandsIndex], Class'Texture'));
			break;
		}
		agpPawnNew.Skins[2] = Texture(DynamicLoadObject(asRandomHandTextures[iFaceHandsIndex], Class'Texture'));
	}
	GOTO JL040E;
	case 2:
		agpPawnNew.Skins[2] = Texture(DynamicLoadObject("T_AA2_Characters.SF.SOLDIER_HAND_SF_BLK_GLOVES", Class'Texture'));
		GOTO JL040E;
	case 3:
		agpPawnNew.Skins[2] = Texture(DynamicLoadObject("T_AA2_Characters.Inf.SOLDIER_HAND_ARCTIC_BLK_GLOVES", Class'Texture'));
		GOTO JL040E;
	case 4:
		agpPawnNew.Skins[2] = Texture(DynamicLoadObject("T_AA2_Characters.Inf.SOLDIER_HAND_DESERT_GREEN_GLOVES", Class'Texture'));
		GOTO JL040E;
	case 5:
		agpPawnNew.Skins[2] = Texture(DynamicLoadObject("T_AA2_Characters.Inf.SOLDIER_HAND_FOREST_GREEN_GLOVES", Class'Texture'));
		GOTO JL040E;
	case 0:
		agpPawnNew.Skins[2] = setHands;
		GOTO JL040E;
	default:
	JL040E:
		switch (essShirtType)
		{
		case 2:
			agpPawnNew.Skins[3] = Texture(DynamicLoadObject("T_AAO_Characters.SF.T_CHAR_INF_ACU_VESTIBAMOLLE1A", Class'Texture'));
			break;
		case 3:
			agpPawnNew.Skins[3] = Texture(DynamicLoadObject("T_AAO_Characters.SF.T_CHAR_SF_ACU_VESTCIRAS1A", Class'Texture'));
			break;
		case 1:
			agpPawnNew.Skins[3] = Texture(DynamicLoadObject(asRandomShirtTextures[Rand(asRandomShirtTextures.Num())], Class'Texture'));
			break;
		case 0:
			agpPawnNew.Skins[3] = setShirt;
			break;
		default:
		}
	*/
}
