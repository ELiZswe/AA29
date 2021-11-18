// All the original content belonged to the US Army


#include "NPCPlayerStartCommando.h"

ANPCPlayerStartCommando::ANPCPlayerStartCommando()
{
	bAttachCommandoKnife = true;
	sDefaultMeshName = "A_AA2_CharactersOpfor.Commando";
	sDefaultPawnClass = "AGP_Characters.NPC_EnemyCommando";
	
	asRandomFaceTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_a_Mat.t_char_commando_face_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_b_Mat.t_char_commando_face_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_c_Mat.t_char_commando_face_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_d_Mat.t_char_commando_face_d_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_e_Mat.t_char_commando_face_e_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_f_Mat.t_char_commando_face_f_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_face_g_Mat.t_char_enemy_commando_face_g_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_h_Mat.t_char_commando_face_h_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomHandTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomPantTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_pants_a_Mat.t_char_enemy_commando_pants_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_pants_b_Mat.t_char_enemy_commando_pants_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_pants_camo_b_Mat.t_char_enemy_commando_pants_camo_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_pants_camo_a_Mat.t_char_enemy_commando_pants_camo_a_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomShirtTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_shirt_a_Mat.t_char_enemy_commando_shirt_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_shirt_b_Mat.t_char_enemy_commando_shirt_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_shirt_camo_a_Mat.t_char_enemy_commando_shirt_camo_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_shirt_camo_b_Mat.t_char_enemy_commando_shirt_camo_b_Mat'"), NULL, LOAD_None, NULL)
	};
	
	eshgHeadGear = ESoldierHeadGear::SoldierHeadgear_None;
	//ControllerClass = class'AGP.NPCCommandoController';
	iNPCInitialMentalState = 75;
	iNPCLeadershipMentalStateRange = 750;
	fpNPCHearingRadius = 5000;
	fpNPCMaxVisualRange = 10000;
	fpNPCWeaponAccuracy = 70;
	fNPCExperience = 60;
	iMinThreatLevel = 3;
	iVoiceIndex = 1;
	iPlatoonID = 0;
	iFragGrenadeCount = 5;
	iSmokeGrenadeCount = 3;
	iPrimaryWeaponReloads = 5;
	sPrimaryWeaponDefaultClass = "AGP_Inventory.Weapon_Vintorez_Sniper";
	fpMortarRequestSkill = 65;
	fpNPCWeaponEffectiveRange = 3000;
	fpBOPMinorDisadvantageThreshold = -2;
	fpBOPMajorDisadvantageThreshold = -2.5;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagCommando.S_PSTagCommando'"), NULL, LOAD_None, NULL);
#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

}