// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "CoolImage.generated.h"

class UGUIController;

UCLASS()
class AA29_API UCoolImage : public UGUIComponent
{
	GENERATED_BODY()
public:
	UCoolImage();

	UPROPERTY()											int32 FullAlpha;								//var int FullAlpha;
	UPROPERTY()											float MaxResetDelay;							//var float MaxResetDelay;
	UPROPERTY()											float MinResetDelay;							//var float MinResetDelay;
	UPROPERTY()											float MaxFadeTime;								//var float MaxFadeTime;
	UPROPERTY()											float MinFadeTime;								//var float MinFadeTime;
	UPROPERTY()											float MinScale;									//var float MinScale;
	UPROPERTY()											float MaxScale;									//var float MaxScale;
	UPROPERTY()											int32 NoAnims;									//var int NoAnims;
	UPROPERTY()											TArray<FAnimInfo> Anims;						//var array<AnimInfo> Anims;
	UPROPERTY()											UMaterialInstance* Image;						//var() Material Image;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void GetPos(float Scale, float& X, float& Y);
	bool DoCollisionTest(int32 i);
	bool TestCollision(int32 i, int32 j);
	void ResetItem(int32 i);
};
