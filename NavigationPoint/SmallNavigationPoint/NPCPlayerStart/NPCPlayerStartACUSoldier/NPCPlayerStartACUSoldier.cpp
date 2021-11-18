// All the original content belonged to the US Army


#include "NPCPlayerStartACUSoldier.h"
#include "Materials/MaterialInstance.h"

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
	//ControllerClass = class'AGP.NPCACUSoldierController';
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