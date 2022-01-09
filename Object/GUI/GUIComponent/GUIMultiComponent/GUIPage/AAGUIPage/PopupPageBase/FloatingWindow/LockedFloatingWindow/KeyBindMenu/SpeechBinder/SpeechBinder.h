// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/KeyBindMenu/KeyBindMenu.h"
#include "SpeechBinder.generated.h"

class UAATab_PlayerSettings;

UCLASS()
class USpeechBinder : public UKeyBindMenu
{
	GENERATED_BODY()
public:
	USpeechBinder();

	UPROPERTY()			FString								VoiceType;				//var FString VoiceType;
	UPROPERTY()			UAATab_PlayerSettings*				tp_Player;				//var AATab_PlayerSettings tp_Player;
	UPROPERTY()			bool								bNoMatureLanguage;		//var transient bool bNoMatureLanguage;

	
};
