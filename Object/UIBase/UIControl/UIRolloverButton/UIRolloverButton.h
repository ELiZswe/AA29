// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIRolloverButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIRolloverButton : public UUIControl
{
	GENERATED_BODY()
public:
	UUIRolloverButton();

	UPROPERTY()										USoundBase* _sndClick;					//var Sound _sndClick;
	UPROPERTY()										USoundBase* _sndOver;					//var Sound _sndOver;
	UPROPERTY()										bool _bFirstOver;						//var bool _bFirstOver;
	UPROPERTY()										int32 _iState;							//var int _iState;
	UPROPERTY()										FString _sTexture;						//var string _sTexture;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;



	void Destroyed();
	void CreateTexture();
	void SetSounds(USoundBase* sOver, USoundBase* sClick);
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTextureString(FString tString);
	void PlaySound(USoundBase* pSound);
};
