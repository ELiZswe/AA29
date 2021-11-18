// All the original content belonged to the US Army


#include "NPCPlayerStartNCO.h"

ANPCPlayerStartNCO::ANPCPlayerStartNCO()
{

	sDefaultPawnClass = "AGP_Characters.NPC_ISoldierNCO";
	
	asRandomFaceTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_nco_face_a_Mat.t_char_nco_face_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_nco_face_b_Mat.t_char_nco_face_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_b_Mat.t_char_commando_face_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_c_Mat.t_char_commando_face_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_e_Mat.t_char_commando_face_e_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_face_g_Mat.t_char_enemy_commando_face_g_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomHandTextures =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_nco_hands_a_Mat.t_char_nco_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_enemy_nco_hands_b_Mat.t_char_enemy_nco_hands_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomPantTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_enemy_nco_pants_a_Mat.t_char_enemy_nco_pants_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_enemy_nco_pants_b_Mat.t_char_enemy_nco_pants_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_enemy_nco_pants_b_Mat.t_char_enemy_nco_pants_b_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomShirtTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_enemy_nco_shirt_a_Mat.t_char_enemy_nco_shirt_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_enemy_nco_shirt_b_Mat.t_char_enemy_nco_shirt_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyNCO/t_char_enemy_nco_shirt_c_Mat.t_char_enemy_nco_shirt_c_Mat'"), NULL, LOAD_None, NULL)
	};
	
	//ControllerClass = class'AGP.NPCNCOController';
	iNPCInitialMentalState = 35;
	iNPCLeadershipMentalStateRange = 1250;
	fpNPCHearingRadius = 5000;
	fpNPCMaxVisualRange = 10000;
	fpNPCWeaponAccuracy = 40;
	fNPCExperience = 45;
	iMinThreatLevel = 1;
	iVoiceIndex = 2;
	iPlatoonID = 0;
	iFragGrenadeCount = 2;
	bHasBinoculars = true;
	iPrimaryWeaponReloads = 4;
	iSecondaryWeaponReloads = 2;
	sPrimaryWeaponDefaultClass = "AGP_Inventory.Weapon_RPK_SAW";
	sSecondaryWeaponDefaultClass = "AGP_Inventory.Weapon_M9_Pistol";
	fpMortarRequestSkill = 50;
	fpNPCWeaponEffectiveRange = 2000;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagNCO.S_PSTagNCO'"), NULL, LOAD_None, NULL);

#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

}