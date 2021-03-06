// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_Eyes.generated.h"

UCLASS()
class AAttch_Eyes : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_Eyes();
	
	UPROPERTY(EditAnywhere)		UStaticMesh* SFGogglesUpBoonie;			//var StaticMesh SFGogglesUpBoonie;
	UPROPERTY(EditAnywhere)		UStaticMesh* SFGogglesUpCap;			//var StaticMesh SFGogglesUpCap;
	UPROPERTY(EditAnywhere)		UStaticMesh* SFGogglesUpBDU;			//var StaticMesh SFGogglesUpBDU;
	UPROPERTY(EditAnywhere)		UStaticMesh* SFGogglesDown;				//var StaticMesh SFGogglesDown;
	UPROPERTY(EditAnywhere)		UStaticMesh* OakleysRed;				//var StaticMesh OakleysRed;
	UPROPERTY(EditAnywhere)		UStaticMesh* OakleysGrey;				//var StaticMesh OakleysGrey;
	UPROPERTY(EditAnywhere)		UStaticMesh* OakleysGreen;				//var StaticMesh OakleysGreen;
	UPROPERTY(EditAnywhere)		UStaticMesh* OakleysBlue;				//var StaticMesh OakleysBlue;
	UPROPERTY(EditAnywhere)		UStaticMesh* GogglesUp;					//var StaticMesh GogglesUp;
	UPROPERTY(EditAnywhere)		UStaticMesh* GogglesDown;				//var StaticMesh GogglesDown;
	UPROPERTY(EditAnywhere)		UStaticMesh* ACUGogglesDown;			//var StaticMesh ACUGogglesDown;
	UPROPERTY(EditAnywhere)		UStaticMesh* ACUGogglesUp;				//var StaticMesh ACUGogglesUp;

	bool HasNVG();
	UStaticMesh* GetSFStaticMesh();
	UStaticMesh* GetStaticMesh(bool bFriendly);
	UStaticMesh* GetSFGogglesUp();
};
