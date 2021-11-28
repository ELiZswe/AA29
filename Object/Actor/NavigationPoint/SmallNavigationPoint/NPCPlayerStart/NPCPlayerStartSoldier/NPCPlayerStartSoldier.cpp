// All the original content belonged to the US Army


#include "NPCPlayerStartSoldier.h"

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
	
	//ControllerClass = class'AGP.NPCGruntController'
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