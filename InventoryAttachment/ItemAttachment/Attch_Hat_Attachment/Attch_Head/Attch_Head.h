// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Hat_Attachment.h"
#include "Attch_Head.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttch_Head : public AAttch_Hat_Attachment
{
	GENERATED_BODY()
public:
	AAttch_Head();

	UPROPERTY()		UStaticMesh* ArcticMichHelmet;			//var StaticMesh ArcticMichHelmet;
	UPROPERTY()		UStaticMesh* ACUHelmet;					//var StaticMesh ACUHelmet;
	UPROPERTY()		UStaticMesh* GuerrillaHelmetMesh;		//var StaticMesh GuerrillaHelmetMesh;
	UPROPERTY()		UStaticMesh* CapStaticMesh;				//var StaticMesh CapStaticMesh;
	UPROPERTY()		UStaticMesh* ScarfStaticMesh;			//var StaticMesh ScarfStaticMesh;
	UPROPERTY()		UStaticMesh* MILESStaticMesh;			//var StaticMesh MILESStaticMesh;
	UPROPERTY()		UStaticMesh* SFStaticMesh;				//var StaticMesh SFStaticMesh;
	UPROPERTY()		UStaticMesh* SFBoonieStaticMesh;		//var StaticMesh SFBoonieStaticMesh;
	UPROPERTY()		UStaticMesh* SFBDUStaticMesh;			//var StaticMesh SFBDUStaticMesh;

};
