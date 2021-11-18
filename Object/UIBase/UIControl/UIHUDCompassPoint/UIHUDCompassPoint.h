// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIHUDCompassPoint.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIHUDCompassPoint : public UUIControl
{
	GENERATED_BODY()
public:
	UUIHUDCompassPoint();

	UPROPERTY()										int32 _iOrder;							//var int _iOrder;
	UPROPERTY()										uint8 _FT;								//var byte _FT;
	UPROPERTY()										UMaterialInstance* _CompassIcon;		//var Material _CompassIcon;
	UPROPERTY()										AActor* _TrackingActor;					//var Actor _TrackingActor;

	void Destroyed();
	void SetActor(AActor* pTrack);
	void SetTexture(UMaterialInstance* pTexture);
	void setFT(uint8 FT);
	void setOrder(int32 Order);
	int32 getOrder();
	uint8 getFT();
	bool IsOnCompass(AController* ctrlRequesting);
	FVector GetLocation();
	float GetRotation(AActor* fromactor, FVector fromlocation);
	UMaterialInstance* GetTexture();
	void CompareHeight(AActor* fromactor, FVector fromlocation);
	
};
