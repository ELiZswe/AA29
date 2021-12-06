// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/TextDisplay/TextDisplay.h"
#include "AA29/MyStructs.h"

ATextDisplay::ATextDisplay()
{

	DigitSpacing = 8;
	DigitScale = 1;
	DigitScale3D = FVector(1, 1, 1);

	Courier.SetNum(123);
	LED.SetNum(59);

	Courier[0] = nullptr;
	Courier[1] = nullptr;
	Courier[2] = nullptr;
	Courier[3] = nullptr;
	Courier[4] = nullptr;
	Courier[5] = nullptr;
	Courier[6] = nullptr;
	Courier[7] = nullptr;
	Courier[8] = nullptr;
	Courier[9] = nullptr;
	Courier[10] = nullptr;
	Courier[11] = nullptr;
	Courier[12] = nullptr;
	Courier[13] = nullptr;
	Courier[14] = nullptr;
	Courier[15] = nullptr;
	Courier[16] = nullptr;
	Courier[17] = nullptr;
	Courier[18] = nullptr;
	Courier[19] = nullptr;
	Courier[20] = nullptr;
	Courier[21] = nullptr;
	Courier[22] = nullptr;
	Courier[23] = nullptr;
	Courier[24] = nullptr;
	Courier[25] = nullptr;
	Courier[26] = nullptr;
	Courier[27] = nullptr;
	Courier[28] = nullptr;
	Courier[29] = nullptr;
	Courier[30] = nullptr;
	Courier[31] = nullptr;
	Courier[32] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Symbols/fonts_co_space_Mat.fonts_co_space_Mat'"), NULL, LOAD_None, NULL);
	Courier[33] = nullptr;
	Courier[34] = nullptr;
	Courier[35] = nullptr;
	Courier[36] = nullptr;
	Courier[37] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Symbols/FONTS_CO_PERCENT_Mat.FONTS_CO_PERCENT_Mat'"), NULL, LOAD_None, NULL);
	Courier[38] = nullptr;
	Courier[39] = nullptr;
	Courier[40] = nullptr;
	Courier[41] = nullptr;
	Courier[42] = nullptr;
	Courier[43] = nullptr;
	Courier[44] = nullptr;
	Courier[45] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Symbols/fonts_co_minus_Mat.fonts_co_minus_Mat'"), NULL, LOAD_None, NULL);
	Courier[46] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Symbols/fonts_co_dot_Mat.fonts_co_dot_Mat'"), NULL, LOAD_None, NULL);
	Courier[47] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Symbols/FONTS_CO_FORWARDSLASH_Mat.FONTS_CO_FORWARDSLASH_Mat'"), NULL, LOAD_None, NULL);
	Courier[48] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_0_Mat.fonts_co_0_Mat'"), NULL, LOAD_None, NULL);
	Courier[49] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_1_Mat.fonts_co_1_Mat'"), NULL, LOAD_None, NULL);
	Courier[50] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_2_Mat.fonts_co_2_Mat'"), NULL, LOAD_None, NULL);
	Courier[51] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_3_Mat.fonts_co_3_Mat'"), NULL, LOAD_None, NULL);
	Courier[52] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_4_Mat.fonts_co_4_Mat'"), NULL, LOAD_None, NULL);
	Courier[53] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_5_Mat.fonts_co_5_Mat'"), NULL, LOAD_None, NULL);
	Courier[54] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_6_Mat.fonts_co_6_Mat'"), NULL, LOAD_None, NULL);
	Courier[55] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_7_Mat.fonts_co_7_Mat'"), NULL, LOAD_None, NULL);
	Courier[56] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_8_Mat.fonts_co_8_Mat'"), NULL, LOAD_None, NULL);
	Courier[57] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/fonts_co_9_Mat.fonts_co_9_Mat'"), NULL, LOAD_None, NULL);
	Courier[58] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Symbols/fonts_co_colon_Mat.fonts_co_colon_Mat'"), NULL, LOAD_None, NULL);
	Courier[59] = nullptr;
	Courier[60] = nullptr;
	Courier[61] = nullptr;
	Courier[62] = nullptr;
	Courier[63] = nullptr;
	Courier[64] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Symbols/FONTS_CO_AMPERSAND_Mat.FONTS_CO_AMPERSAND_Mat'"), NULL, LOAD_None, NULL);
	Courier[65] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_A_Mat.FONTS_CO_UC_A_Mat'"), NULL, LOAD_None, NULL);
	Courier[66] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_B_Mat.FONTS_CO_UC_B_Mat'"), NULL, LOAD_None, NULL);
	Courier[67] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_C_Mat.FONTS_CO_UC_C_Mat'"), NULL, LOAD_None, NULL);
	Courier[68] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_D_Mat.FONTS_CO_UC_D_Mat'"), NULL, LOAD_None, NULL);
	Courier[69] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_E_Mat.FONTS_CO_UC_E_Mat'"), NULL, LOAD_None, NULL);
	Courier[70] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_F_Mat.FONTS_CO_UC_F_Mat'"), NULL, LOAD_None, NULL);
	Courier[71] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_G_Mat.FONTS_CO_UC_G_Mat'"), NULL, LOAD_None, NULL);
	Courier[72] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_H_Mat.FONTS_CO_UC_H_Mat'"), NULL, LOAD_None, NULL);
	Courier[73] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_I_Mat.FONTS_CO_UC_I_Mat'"), NULL, LOAD_None, NULL);
	Courier[74] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_J_Mat.FONTS_CO_UC_J_Mat'"), NULL, LOAD_None, NULL);
	Courier[75] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_K_Mat.FONTS_CO_UC_K_Mat'"), NULL, LOAD_None, NULL);
	Courier[76] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_L_Mat.FONTS_CO_UC_L_Mat'"), NULL, LOAD_None, NULL);
	Courier[77] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_M_Mat.FONTS_CO_UC_M_Mat'"), NULL, LOAD_None, NULL);
	Courier[78] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_N_Mat.FONTS_CO_UC_N_Mat'"), NULL, LOAD_None, NULL);
	Courier[79] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_O_Mat.FONTS_CO_UC_O_Mat'"), NULL, LOAD_None, NULL);
	Courier[80] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_P_Mat.FONTS_CO_UC_P_Mat'"), NULL, LOAD_None, NULL);
	Courier[81] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_Q_Mat.FONTS_CO_UC_Q_Mat'"), NULL, LOAD_None, NULL);
	Courier[82] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_R_Mat.FONTS_CO_UC_R_Mat'"), NULL, LOAD_None, NULL);
	Courier[83] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_S_Mat.FONTS_CO_UC_S_Mat'"), NULL, LOAD_None, NULL);
	Courier[84] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_T_Mat.FONTS_CO_UC_T_Mat'"), NULL, LOAD_None, NULL);
	Courier[85] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_U_Mat.FONTS_CO_UC_U_Mat'"), NULL, LOAD_None, NULL);
	Courier[86] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_V_Mat.FONTS_CO_UC_V_Mat'"), NULL, LOAD_None, NULL);
	Courier[87] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_W_Mat.FONTS_CO_UC_W_Mat'"), NULL, LOAD_None, NULL);
	Courier[88] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_X_Mat.FONTS_CO_UC_X_Mat'"), NULL, LOAD_None, NULL);
	Courier[89] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_Y_Mat.FONTS_CO_UC_Y_Mat'"), NULL, LOAD_None, NULL);
	Courier[90] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_UC_Z_Mat.FONTS_CO_UC_Z_Mat'"), NULL, LOAD_None, NULL);
	Courier[91] = nullptr;
	Courier[92] = nullptr;
	Courier[93] = nullptr;
	Courier[94] = nullptr;
	Courier[95] = nullptr;
	Courier[96] = nullptr;
	Courier[97] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_A_Mat.FONTS_CO_LC_A_Mat'"), NULL, LOAD_None, NULL);
	Courier[98] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_B_Mat.FONTS_CO_LC_B_Mat'"), NULL, LOAD_None, NULL);
	Courier[99] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_C_Mat.FONTS_CO_LC_C_Mat'"), NULL, LOAD_None, NULL);
	Courier[100] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_D_Mat.FONTS_CO_LC_D_Mat'"), NULL, LOAD_None, NULL);
	Courier[101] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_E_Mat.FONTS_CO_LC_E_Mat'"), NULL, LOAD_None, NULL);
	Courier[102] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_F_Mat.FONTS_CO_LC_F_Mat'"), NULL, LOAD_None, NULL);
	Courier[103] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_G_Mat.FONTS_CO_LC_G_Mat'"), NULL, LOAD_None, NULL);
	Courier[104] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_H_Mat.FONTS_CO_LC_H_Mat'"), NULL, LOAD_None, NULL);
	Courier[105] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_I_Mat.FONTS_CO_LC_I_Mat'"), NULL, LOAD_None, NULL);
	Courier[106] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_J_Mat.FONTS_CO_LC_J_Mat'"), NULL, LOAD_None, NULL);
	Courier[107] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_K_Mat.FONTS_CO_LC_K_Mat'"), NULL, LOAD_None, NULL);
	Courier[108] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_L_Mat.FONTS_CO_LC_L_Mat'"), NULL, LOAD_None, NULL);
	Courier[109] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_M_Mat.FONTS_CO_LC_M_Mat'"), NULL, LOAD_None, NULL);
	Courier[110] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_N_Mat.FONTS_CO_LC_N_Mat'"), NULL, LOAD_None, NULL);
	Courier[111] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_O_Mat.FONTS_CO_LC_O_Mat'"), NULL, LOAD_None, NULL);
	Courier[112] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_P_Mat.FONTS_CO_LC_P_Mat'"), NULL, LOAD_None, NULL);
	Courier[113] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_Q_Mat.FONTS_CO_LC_Q_Mat'"), NULL, LOAD_None, NULL);
	Courier[114] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_R_Mat.FONTS_CO_LC_R_Mat'"), NULL, LOAD_None, NULL);
	Courier[115] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_S_Mat.FONTS_CO_LC_S_Mat'"), NULL, LOAD_None, NULL);
	Courier[116] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_T_Mat.FONTS_CO_LC_T_Mat'"), NULL, LOAD_None, NULL);
	Courier[117] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_U_Mat.FONTS_CO_LC_U_Mat'"), NULL, LOAD_None, NULL);
	Courier[118] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_V_Mat.FONTS_CO_LC_V_Mat'"), NULL, LOAD_None, NULL);
	Courier[119] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_W_Mat.FONTS_CO_LC_W_Mat'"), NULL, LOAD_None, NULL);
	Courier[120] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_X_Mat.FONTS_CO_LC_X_Mat'"), NULL, LOAD_None, NULL);
	Courier[121] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_Y_Mat.FONTS_CO_LC_Y_Mat'"), NULL, LOAD_None, NULL);
	Courier[122] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Characters/FONTS_CO_LC_Z_Mat.FONTS_CO_LC_Z_Mat'"), NULL, LOAD_None, NULL);;
	LED[0] = nullptr;
	LED[1] = nullptr;
	LED[2] = nullptr;
	LED[3] = nullptr;
	LED[4] = nullptr;
	LED[5] = nullptr;
	LED[6] = nullptr;
	LED[7] = nullptr;
	LED[8] = nullptr;
	LED[9] = nullptr;
	LED[10] = nullptr;
	LED[11] = nullptr;
	LED[12] = nullptr;
	LED[13] = nullptr;
	LED[14] = nullptr;
	LED[15] = nullptr;
	LED[16] = nullptr;
	LED[17] = nullptr;
	LED[18] = nullptr;
	LED[19] = nullptr;
	LED[20] = nullptr;
	LED[21] = nullptr;
	LED[22] = nullptr;
	LED[23] = nullptr;
	LED[24] = nullptr;
	LED[25] = nullptr;
	LED[26] = nullptr;
	LED[27] = nullptr;
	LED[28] = nullptr;
	LED[29] = nullptr;
	LED[30] = nullptr;
	LED[31] = nullptr;
	LED[32] = nullptr;
	LED[33] = nullptr;
	LED[34] = nullptr;
	LED[35] = nullptr;
	LED[36] = nullptr;
	LED[37] = nullptr;
	LED[38] = nullptr;
	LED[39] = nullptr;
	LED[40] = nullptr;
	LED[41] = nullptr;
	LED[42] = nullptr;
	LED[43] = nullptr;
	LED[44] = nullptr;
	LED[45] = nullptr;
	LED[46] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/Fonts_led_period_Mat.Fonts_led_period_Mat'"), NULL, LOAD_None, NULL);
	LED[47] = nullptr;
	LED[48] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_0_Mat.FONTS_LED_0_Mat'"), NULL, LOAD_None, NULL);
	LED[49] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_1_Mat.FONTS_LED_1_Mat'"), NULL, LOAD_None, NULL);
	LED[50] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_2_Mat.FONTS_LED_2_Mat'"), NULL, LOAD_None, NULL);
	LED[51] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_3_Mat.FONTS_LED_3_Mat'"), NULL, LOAD_None, NULL);
	LED[52] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_4_Mat.FONTS_LED_4_Mat'"), NULL, LOAD_None, NULL);
	LED[53] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_5_Mat.FONTS_LED_5_Mat'"), NULL, LOAD_None, NULL);
	LED[54] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_6_Mat.FONTS_LED_6_Mat'"), NULL, LOAD_None, NULL);
	LED[55] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_7_Mat.FONTS_LED_7_Mat'"), NULL, LOAD_None, NULL);
	LED[56] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_8_Mat.FONTS_LED_8_Mat'"), NULL, LOAD_None, NULL);
	LED[57] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_9_Mat.FONTS_LED_9_Mat'"), NULL, LOAD_None, NULL);
	LED[58] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Fonts/Digits/FONTS_LED_DOTS_Mat.FONTS_LED_DOTS_Mat'"), NULL, LOAD_None, NULL);;

	DrawType = EDrawType::DT_Sprite;

	//bUseDynamicLights = false;
	//bUnlit = true;
	//bShadowCast = false;
	//bStaticLighting = true;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideActors = false;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	//bProjTarget = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void ATextDisplay::PreBeginPlay ()
{
	InitPosActors();
}
void ATextDisplay::SetValue (FName ItemName, FString str)
{
	int32 Index;
	Index=GetItemIndex(ItemName);
	SetItem(Index,str,items[Index].Font);
}
void ATextDisplay::SetItem (int32 ItemIndex, FString str, EFontType Font)
{
	int32 i;
	TArray<FString> Characters;
	DestroyDigits(ItemIndex);
	Characters.SetNum(str.Len());
	for (i=0; i<Characters.Num()-1; i++)
	{
		//items[ItemIndex].Digits[i]=Spawn('TextDisplay_Char');
		Characters[i]= str.Mid(i,1);

		InitDigit(ItemIndex,i);
		//SetCharacter(ItemIndex,i,Asc(Characters[i]),Font);
	}
}
void ATextDisplay::SetCharacter (int32 ItemIndex, int32 Place, int32 Ascii, EFontType Font)
{
	//items[ItemIndex].Digits[Place].Skins[0]=GetCharTex(Ascii,Font);
}
int32 ATextDisplay::GetItemIndex (FName Name)
{
	int32 i;
	for (i=0; i<items.Num()-1; i++)
	{
		if (items[i].Name == Name)
		{
			return i;
		}
	}
	//Log("ScoreDisplay()::GetItemIndex(): Error: ItemName " $ Name $ " Not Found");
	return -1;
}
void ATextDisplay::InitPosActors ()
{
	int32 i;
	for (i=0; i<items.Num()-1; i++)
	{
		//items[i].PosActor=GetActorByTag(items[i].PosActorTag);
		if (items[i].PosActor == nullptr)
		{
			//Log("ScoreDisplay::InitPosActors(): Warning: couldn't get actor with tag: " $ items[i].PosActorTag);
		}
	}
}
void ATextDisplay::InitDigit (int32 Item, int32 Place)
{
	/*
	local FVector LocOffset;
	local FVector loc;
	local Object.Rotator Rot;
	if (items[Item].PosActor == nullptr)
	{
		Rot=items[Item].Rotation;
		loc=items[Item].Location;
	}
	else
	{
		Rot=items[Item].PosActor.Rotation;
		loc=items[Item].PosActor.Location;
	}
	LocOffset=Normal( Vector(Rot + MakeRot(0,-16384,0))) * DigitSpacing * Place;
	Rot.Pitch *= -1;
	items[Item].Digits[Place].SetLocation(loc + LocOffset);
	items[Item].Digits[Place].SetRotation(Rot + MakeRot(0,16384,0));
	items[Item].Digits[Place].SetDrawScale(DigitScale);
	items[Item].Digits[Place].SetDrawScale3D(DigitScale3D);
	if (items[Item].bBaseToPosActor && items[Item].PosActor != nullptr)
	{
		items[Item].Digits[Place].SetBase(items[Item].PosActor);
	}
	*/
}
UMaterialInstance* ATextDisplay::GetCharTex(int32 Ascii, EFontType Font)
{
	switch(Font)
	{
		case EFontType::FT_Courier:
			return Courier[Ascii];
		case EFontType::FT_LED:
			return LED[Ascii];
		default:
			return Courier[Ascii];
	}
}
void ATextDisplay::DestroyDigits (int32 Index)
{
	int32 i;
	for (i=0; i<items[Index].Digits.Num()-1; i++)
	{
		//items[Index].Digits[i]->Destroy();
		
	}
	items[Index].Digits.SetNum(0);
}


