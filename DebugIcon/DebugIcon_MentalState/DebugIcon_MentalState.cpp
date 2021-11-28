// All the original content belonged to the US Army

#include "AA29/DebugIcon/DebugIcon_MentalState/DebugIcon_MentalState.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ADebugIcon_MentalState::ADebugIcon_MentalState()
{
	MentalState_Pain_Texture		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/mental_pain_Mat.mental_pain_Mat"), NULL, LOAD_None, NULL);
	MentalState_Panic_Texture		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/mental_panic_Mat.mental_panic_Mat"), NULL, LOAD_None, NULL);
	MentalState_Suppress_Texture	= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/mental_suppress_Mat.mental_suppress_Mat"), NULL, LOAD_None, NULL);
	MentalState_Concerned_Texture	= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/mental_concern_Mat.mental_concern_Mat"), NULL, LOAD_None, NULL);
	MentalState_Normal_Texture		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/mental_normal_Mat.mental_normal_Mat"), NULL, LOAD_None, NULL);
	MentalState_Brave_Texture		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/mental_brave_Mat.mental_brave_Mat"), NULL, LOAD_None, NULL);
	MentalState_Reckless_Texture	= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/mental_reckless_Mat.mental_reckless_Mat"), NULL, LOAD_None, NULL);
	Texture							= MentalState_Normal_Texture;
}

void  ADebugIcon_MentalState::UpdateMentalState(ANPCBaseController* CheckController)
{
	if (CheckController->IsSuppressed())
	{
		Texture = MentalState_Suppress_Texture;
	}
	else
	{
		if (CheckController->IsInPanic())
		{
			Texture = MentalState_Panic_Texture;
		}
		else
		{
			if (CheckController->IsBrave())
			{
				Texture = MentalState_Brave_Texture;
			}
			else
			{
				if (CheckController->IsReckless())
				{
					Texture = MentalState_Reckless_Texture;
				}
				else
				{
					if (CheckController->IsConcerned())
					{
						Texture = MentalState_Concerned_Texture;
					}
					else
					{
						if (CheckController->IsNormal())
						{
							Texture = MentalState_Normal_Texture;
						}
					}
				}
			}
		}
	}
}