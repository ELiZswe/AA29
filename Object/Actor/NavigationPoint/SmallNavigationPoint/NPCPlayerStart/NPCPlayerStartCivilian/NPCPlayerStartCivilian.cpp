// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartCivilian/NPCPlayerStartCivilian.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/NPCBaseCivilianController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ANPCPlayerStartCivilian::ANPCPlayerStartCivilian()
{
	fpFollowDistance = 200;
	sDefaultMeshName = "A_AA2_CharactersCiv.CivilianM";
	sDefaultPawnClass = "AGP_Characters.NPC_Civilian_A";
	
	asOldRandomFaceTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Civilian/t_char_civ_face_a_Mat.t_char_civ_face_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Civilian/t_char_civ_face_b_Mat.t_char_civ_face_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Civilian/t_char_civ_face_c_Mat.t_char_civ_face_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Civilian/t_char_civ_face_d_Mat.t_char_civ_face_d_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Civilian/t_char_civ_face_jon_Mat.t_char_civ_face_jon_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/CivilianA_FACE_Cauc_MaleA_Mat.CivilianA_FACE_Cauc_MaleA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/CivilianA_FACE_Cauc_MaleB_Mat.CivilianA_FACE_Cauc_MaleB_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/CivilianA_FACE_Cauc_MaleC_Mat.CivilianA_FACE_Cauc_MaleC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/CivilianA_FACE_Cauc_MaleD_Mat.CivilianA_FACE_Cauc_MaleD_Mat'"), NULL, LOAD_None, NULL)
	};
	asOldRandomHandTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleC_Mat.Civ_HAND_MaleC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleC_Mat.Civ_HAND_MaleC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleC_Mat.Civ_HAND_MaleC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleC_Mat.Civ_HAND_MaleC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleC_Mat.Civ_HAND_MaleC_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleA_Mat.Civ_HAND_MaleA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleA_Mat.Civ_HAND_MaleA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleA_Mat.Civ_HAND_MaleA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_HAND_MaleB_Mat.Civ_HAND_MaleB_Mat'"), NULL, LOAD_None, NULL)
	};
	asOldRandomPantTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_PANTS_Slacks_black_Mat.Civ_PANTS_Slacks_black_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_PANTS_Jeans_Blue_Mat.Civ_PANTS_Jeans_Blue_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_PANTS_Slacks_Brown_Mat.Civ_PANTS_Slacks_Brown_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_PANTS_Slacks_Green_Mat.Civ_PANTS_Slacks_Green_Mat'"), NULL, LOAD_None, NULL)
	};
	asOldRandomShirtTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_SHIRT_blue_Mat.Civ_SHIRT_blue_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_SHIRT_Vest_WhiteA_Mat.Civ_SHIRT_Vest_WhiteA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_SHIRT_WhiteA_Mat.Civ_SHIRT_WhiteA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Civilian/Civ_SHIRT_yellow_Mat.Civ_SHIRT_yellow_Mat'"), NULL, LOAD_None, NULL)
	};
	
	fpMinTimeBetweenAudio =  25;
	cmtMeshType = ECivMeshType::CivMeshType_Custom;
	//ControllerClass = ANPCBaseCivilianController::StaticClass()
	DamageTag = "Civiliandamage";
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagCivilian.S_PSTagCivilian'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;

#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA
}

AAGP_Pawn* ANPCPlayerStartCivilian::GetPawnSpawnClass()
{
	/*
	switch (cmtMeshType)
	{
	case 2:
		return class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_Civilian_A", Class'Class'));
	case 3:
		return class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_Civilian_B", Class'Class'));
	case 0:
		return class<AGP_Pawn>(DynamicLoadObject(sDefaultPawnClass, Class'Class'));
	case 1:
	default:
		if (PawnSpawnClass == nullptr)
		{
			return class<AGP_Pawn>(DynamicLoadObject(sDefaultPawnClass, Class'Class'));
			break;
		}
		return PawnSpawnClass;
	}
	*/
	return nullptr;    //FAKE   /ELiZ
}

void ANPCPlayerStartCivilian::ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew)
{
	AActor* Item = nullptr;
	/*
	agpPawnNew.DamageEvent = DamageEvent;
	agpPawnNew.DamageTag = DamageTag;
	agpPawnNew.KillEvent = KillEvent;
	agpPawnNew.KillHealth = KillHealth;
	agpPawnNew.ConfigureLinkDamage();
	if (bUserSetSkin)
	{
		if (setPants != nullptr)
		{
			switch (string(meshPawn))
			{
			case "A_AA2_CharactersCiv.DocF_Nurse":
				agpPawnNew.Skins[4] = setHair;
			case "A_AA2_CharactersCiv.DocM_Nurse":
			case "A_AA2_CharactersCiv.CivilianM":
			case "A_AA2_CharactersCiv.George_FlakVest":
				agpPawnNew.Skins[0] = setPants;
				agpPawnNew.Skins[1] = setShirt;
				agpPawnNew.Skins[2] = setHands;
				agpPawnNew.Skins[3] = setFace;
				break;
			default:
				agpPawnNew.Skins[0] = setFace;
				agpPawnNew.Skins[1] = setPants;
				agpPawnNew.Skins[2] = setHands;
				agpPawnNew.Skins[3] = setShirt;
				break;
			}
		}
		else
		{
			ConfigureRandomSkins(agpPawnNew);
		}
		if (meshPawn != nullptr)
		{
			agpPawnNew.LinkMesh(meshPawn, true);
			agpPawnNew.RagdollOverride = RagdollOverride;
		}
		else
		{
			agpPawnNew.RagdollOverride = "OpforM";
			agpPawnNew.LinkMesh(Mesh(DynamicLoadObject(sDefaultMeshName, Class'Mesh')), true);
		}
		if (bDebugInit)
		{
			Log("Setting NPC " + FString::FromInt(Tag) + " to mesh: " + FString::FromInt(meshPawn));
		}
	}
	else
	{
		ConfigureRandomSkins(agpPawnNew);
		agpPawnNew.LinkMesh(agpPawnNew.Mesh);
		agpPawnNew.RagdollOverride = "OpforM";
	}
	agpPawnNew.RagdollLifeSpan = RagdollLifeSpan;
	agpPawnNew.RagInvInertia = RagInvInertia;
	agpPawnNew.RagDeathVel = RagDeathVel;
	agpPawnNew.RagShootStrength = RagShootStrength;
	agpPawnNew.RagSpinScale = RagSpinScale;
	agpPawnNew.RagDeathUpKick = RagDeathUpKick;
	agpPawnNew.RagProneProjectileScale = RagProneProjectileScale;
	agpPawnNew.bNPCDisableSkinSwapping = true;
	if (bSunglasses)
	{
		Item = Spawn(class<ItemAttachment>(DynamicLoadObject("AGP_Inventory.Attch_NPC_CivilianSunglasses", Class'Class')));
		if (bDebugInit)
		{
			Log(string(this) + " spawning sunglasses: " + FString::FromInt(Item));
		}
		if (Item != nullptr)
		{
			Item.SetDrawScale(1.2);
			agpPawnNew.AttachToBone(Item, ItemAttachment(Item).AttachBone);
		}
	}
	*/
}

void ANPCPlayerStartCivilian::ConfigureRandomSkins(AAGP_Pawn* agpPawnNew)
{
	int32 iHandsFaceIndex = 0;
	if (!bUseRandomSkins)
	{
		return;
	}
	if ((cmtMeshType == ECivMeshType::CivMeshType_A) || (cmtMeshType == ECivMeshType::CivMeshType_B))
	{
		return;
	}
	/*
	iHandsFaceIndex = Rand(asOldRandomFaceTextures.Num());
	switch (string(meshPawn))
	{
	case "A_AA2_CharactersCiv.DocM_Nurse":
	case "A_AA2_CharactersCiv.DocM_Nurse":
	case "A_AA2_CharactersCiv.CivilianM":
	case "A_AA2_CharactersCiv.George_FlakVest":
		DebugLog(DEBUG_Warn, "Random skins are not supported for older skeletal meshes");
		agpPawnNew.Skins[0] = Texture(DynamicLoadObject(asOldRandomPantTextures[Rand(asOldRandomPantTextures.Num())], Class'Texture'));
		agpPawnNew.Skins[1] = Texture(DynamicLoadObject(asOldRandomShirtTextures[Rand(asOldRandomShirtTextures.Num())], Class'Texture'));
		agpPawnNew.Skins[2] = Texture(DynamicLoadObject(asOldRandomHandTextures[iHandsFaceIndex], Class'Texture'));
		agpPawnNew.Skins[3] = Texture(DynamicLoadObject(asOldRandomFaceTextures[iHandsFaceIndex], Class'Texture'));
		break;
	default:
		agpPawnNew.Skins[2] = Texture(DynamicLoadObject(asOldRandomHandTextures[iHandsFaceIndex], Class'Texture'));
		agpPawnNew.Skins[0] = Texture(DynamicLoadObject(asOldRandomFaceTextures[iHandsFaceIndex], Class'Texture'));
		agpPawnNew.Skins[1] = Texture(DynamicLoadObject(asOldRandomPantTextures[Rand(asOldRandomPantTextures.Num())], Class'Texture'));
		agpPawnNew.Skins[3] = Texture(DynamicLoadObject(asOldRandomShirtTextures[Rand(asOldRandomShirtTextures.Num())], Class'Texture'));
		break;
	}
	*/
}

void ANPCPlayerStartCivilian::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
	int32 iSound = 0;
	
	Super::CustomCreation(npbcController, agpPawn);
	Cast<ANPCBaseCivilianController>(npbcController)->bShouldFollowUser = bShouldFollowUser;
	Cast<ANPCBaseCivilianController>(npbcController)->fpFollowDistance = fpFollowDistance;
	Cast<ANPCBaseCivilianController>(npbcController)->bStartsInjured = bStartsInjured;
	Cast<ANPCBaseCivilianController>(npbcController)->fpDistanceToTriggerPreHealingAudio = fpDistanceToTriggerPreHealingAudio;
	Cast<ANPCBaseCivilianController>(npbcController)->bMustBeHealedToCommand = bMustBeHealedToCommand;
	Cast<ANPCBaseCivilianController>(npbcController)->namePostHealingAnimation = namePostHealingAnimation;
	Cast<ANPCBaseCivilianController>(npbcController)->nameInitialInjuredAnimation = nameInitialInjuredAnimation;
	if (asndPostHealingAudio.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->asndPostHealingAudio.insert(0, asndPostHealingAudio.Num());
		for (iSound = 0; iSound < asndPostHealingAudio.Num(); iSound++)
		{
			Cast<ANPCBaseCivilianController>(npbcController)->asndPostHealingAudio[iSound] = asndPostHealingAudio[iSound];
		}
	}
	if (asndPreHealingAudio.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->asndPreHealingAudio.insert(0, asndPreHealingAudio.Num());
		for (iSound = 0; iSound < asndPreHealingAudio.Num(); iSound++)
		{
			Cast<ANPCBaseCivilianController>(npbcController)->asndPreHealingAudio[iSound] = asndPreHealingAudio[iSound];
		}
	}
	Cast<ANPCBaseCivilianController>(npbcController)->namePostHealedEvent = namePostHealedEvent;
	Cast<ANPCBaseCivilianController>(npbcController)->bStandAfterHealing = bStandAfterHealing;
	Cast<ANPCBaseCivilianController>(npbcController)->fpAnimationDelayAfterHealing = fpAnimationDelayAfterHealing;
	Cast<ANPCBaseCivilianController>(npbcController)->BuzzedEvent = BuzzedEvent;
	Cast<ANPCBaseCivilianController>(npbcController)->WoundedEvent = WoundedEvent;
	Cast<ANPCBaseCivilianController>(npbcController)->SeePlayerEvent = SeePlayerEvent;
	Cast<ANPCBaseCivilianController>(npbcController)->OrderAcknowledgement = OrderAcknowledgement;
	Cast<ANPCBaseCivilianController>(npbcController)->ReportedEvent = ReportedEvent;
	Cast<ANPCBaseCivilianController>(npbcController)->iReportEventDistance = iReportEventDistance;
	Cast<ANPCBaseCivilianController>(npbcController)->bReportableCivi = bReportableCivi;
	if (anameSeePlayer.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->anameSeePlayer.insert(0, anameSeePlayer.Num());
		for (iSound = 0; iSound < anameSeePlayer.Num(); iSound++)
		{
			Cast<ANPCBaseCivilianController>(npbcController)->anameSeePlayer[iSound] = anameSeePlayer[iSound];
		}
	}
	if (anameCannotFollow.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->anameCannotFollow.insert(0, anameCannotFollow.Num());
		for (iSound = 0; iSound < anameCannotFollow.Num(); iSound++)
		{
			Cast<ANPCBaseCivilianController>(npbcController)->anameCannotFollow[iSound] = anameCannotFollow[iSound];
		}
	}
	if (anameWaitForNPC.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->anameWaitForNPC.insert(0, anameWaitForNPC.Num());
		for (iSound = 0; iSound < anameWaitForNPC.Num(); iSound++)
		{
			Cast<ANPCBaseCivilianController>(npbcController)->anameWaitForNPC[iSound] = anameWaitForNPC[iSound];
		}
	}
	if (anameAcknowledgeOrderPositive.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->anameAcknowledgeOrderPositive.insert(0, anameAcknowledgeOrderPositive.Num());
		for (iSound = 0; iSound < anameAcknowledgeOrderPositive.Num(); iSound++)
		{
			//Cast<ANPCBaseCivilianController>(npbcController)->anameAcknowledgeOrderPositive[iSound] = anameAcknowledgeOrderPositive[iSound];
		}
	}
	if (anameAcknowledgeOrderNegative.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->anameAcknowledgeOrderNegative.insert(0, anameAcknowledgeOrderNegative.Num());
		for (iSound = 0; iSound < anameAcknowledgeOrderNegative.Num(); iSound++)
		{
			//Cast<ANPCBaseCivilianController>(npbcController)->anameAcknowledgeOrderNegative[iSound] = anameAcknowledgeOrderNegative[iSound];
		}
	}
	if (anameFrightened.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->anameFrightened.insert(0, anameFrightened.Num());
		for (iSound = 0; iSound < anameFrightened.Num(); iSound++)
		{
			//Cast<ANPCBaseCivilianController>(npbcController)->anameFrightened[iSound] = anameFrightened[iSound];
		}
	}
	if (anameWounded.Num() > 0)
	{
		//Cast<ANPCBaseCivilianController>(npbcController)->anameWounded.insert(0, anameWounded.Num());
		for (iSound = 0; iSound < anameWounded.Num(); iSound++)
		{
			//Cast<ANPCBaseCivilianController>(npbcController)->anameWounded[iSound] = anameWounded[iSound];
		}
	}
	Cast<ANPCBaseCivilianController>(npbcController)->fpMinTimeBetweenAudio = fpMinTimeBetweenAudio;
}
