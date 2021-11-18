// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_Eyes.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttch_Eyes : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_Eyes();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* SFGogglesUpBoonie;			//var StaticMesh SFGogglesUpBoonie;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* SFGogglesUpCap;			//var StaticMesh SFGogglesUpCap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* SFGogglesUpBDU;			//var StaticMesh SFGogglesUpBDU;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* SFGogglesDown;				//var StaticMesh SFGogglesDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* OakleysRed;				//var StaticMesh OakleysRed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* OakleysGrey;				//var StaticMesh OakleysGrey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* OakleysGreen;				//var StaticMesh OakleysGreen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* OakleysBlue;				//var StaticMesh OakleysBlue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* GogglesUp;					//var StaticMesh GogglesUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* GogglesDown;				//var StaticMesh GogglesDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* ACUGogglesDown;			//var StaticMesh ACUGogglesDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* ACUGogglesUp;				//var StaticMesh ACUGogglesUp;
};
