// All the original content belonged to the US Army


#include "NPCPlayerStartCivilian.h"

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
	//ControllerClass = class'AGP.NPCBaseCivilianController'
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