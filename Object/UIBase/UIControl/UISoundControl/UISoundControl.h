// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UISoundControl.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUISoundControl : public UUIControl
{
	GENERATED_BODY()
public:
	UUISoundControl();


	UPROPERTY()										FString _sClickSound;						//var string _sClickSound;
	UPROPERTY()										FString _sOverSound;						//var string _sOverSound;
	UPROPERTY()										USoundBase* _sMouseClick;					//var Sound _sMouseClick;
	UPROPERTY()										USoundBase* _sMouseOver;					//var Sound _sMouseOver;


	void Destroyed();
	void Create(UUIFrame* frame, UUIScreen* screen, int32 pID, int32 pUIEvent, int32 pParams);
	void LoadSounds();

};
