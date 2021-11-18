// All the original content belonged to the US Army


#include "NPCPlayerStartOfficer.h"

ANPCPlayerStartOfficer::ANPCPlayerStartOfficer()
{

	sDefaultPawnClass = "AGP_Characters.NPC_ISoldierOfficer";
	
	asRandomFaceTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyOfficer/t_char_enemy_officer_face_a_Mat.t_char_enemy_officer_face_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_a_Mat.t_char_commando_face_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_b_Mat.t_char_commando_face_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_c_Mat.t_char_commando_face_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_face_e_Mat.t_char_commando_face_e_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_face_g_Mat.t_char_enemy_commando_face_g_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomHandTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyOfficer/t_char_enemy_officer_hands_a_Mat.t_char_enemy_officer_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_commando_hands_a_Mat.t_char_commando_hands_a_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomPantTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyOfficer/t_char_enemy_officer_pants_a_Mat.t_char_enemy_officer_pants_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_pants_b_Mat.t_char_enemy_infantry_pants_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_pants_a_Mat.t_char_enemy_infantry_pants_a_Mat'"), NULL, LOAD_None, NULL)
	};
	asRandomShirtTextures = 
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/EnemyOfficer/t_char_enemy_officer_shirt_a_Mat.t_char_enemy_officer_shirt_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/enemy_infantry/t_char_enemy_infantry_shirt_b_Mat.t_char_enemy_infantry_shirt_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("'/Game/AmericasArmy/Textures/T_AAO_Characters/Commando/t_char_enemy_commando_shirt_a_Mat.t_char_enemy_commando_shirt_a_Mat'"), NULL, LOAD_None, NULL)
	};
	

	//ControllerClass = class'AGP.NPCOfficerController';
	iNPCInitialMentalState = 25;
	iNPCLeadershipMentalStateRange = 1000;
	fpNPCHearingRadius = 5000;
	fpNPCMaxVisualRange = 10000;
	fpNPCWeaponAccuracy = 30;
	fNPCExperience = 30;
	iMinThreatLevel = 2;
	iVoiceIndex = 2;
	iSquadID = 0;
	iFragGrenadeCount = 1;
	iSmokeGrenadeCount = 0;
	iPrimaryWeaponReloads = 1;
	sPrimaryWeaponDefaultClass = "AGP_Inventory.Weapon_AK47_suRifle";
	fpMortarRequestSkill = 0;
	fpNPCWeaponEffectiveRange = 2000;
	
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagOfficer.S_PSTagOfficer'"), NULL, LOAD_None, NULL);
#if WITH_EDITORONLY_DATA
	if (Texture != nullptr)
	{
		SpriteComponent->Sprite = Texture;
	}
#endif // WITH_EDITORONLY_DATA

}