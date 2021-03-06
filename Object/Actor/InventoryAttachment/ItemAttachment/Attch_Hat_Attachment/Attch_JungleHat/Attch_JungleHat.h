// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Hat_Attachment.h"
#include "Attch_JungleHat.generated.h"

UCLASS()
class AAttch_JungleHat : public AAttch_Hat_Attachment
{
	GENERATED_BODY()
public:
	AAttch_JungleHat();

	UPROPERTY()		UStaticMesh*	ArcticStaticMesh;			//var StaticMesh* ArcticStaticMesh;
	UPROPERTY()		UStaticMesh*	SFBoonieStaticMesh;			//var StaticMesh* SFBoonieStaticMesh;
	UPROPERTY()		UStaticMesh*	GuerrillaHelmetMesh;		//var StaticMesh* GuerrillaHelmetMesh;

	UStaticMesh* GetStaticMesh(bool bFriendly);
};
