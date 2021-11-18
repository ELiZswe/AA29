// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Hat_Attachment.h"
#include "Attch_JungleHat.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttch_JungleHat : public AAttch_Hat_Attachment
{
	GENERATED_BODY()
public:
	AAttch_JungleHat();
	//var StaticMesh GuerrillaHelmetMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* GuerrillaHelmetMesh;

	//var StaticMesh SFBoonieStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* SFBoonieStaticMesh;

	//var StaticMesh ArcticStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* ArcticStaticMesh;
};
