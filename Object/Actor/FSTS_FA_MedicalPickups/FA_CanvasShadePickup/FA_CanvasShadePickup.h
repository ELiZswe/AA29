// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FSTS_FA_MedicalPickups.h"
#include "FA_CanvasShadePickup.generated.h"

UCLASS()
class AFA_CanvasShadePickup : public AFSTS_FA_MedicalPickups
{
	GENERATED_BODY()
public:
	AFA_CanvasShadePickup();

	UPROPERTY()		UStaticMesh*		AltStaticMesh;			//var StaticMesh AltStaticMesh;
	UPROPERTY()		UMaterialInstance*	ShadowProjector;		//var Projector ShadowProjector;

	void PostBeginPlay();
	void SwitchToAltStaticMesh();
	void SwitchToOriginalStaticMesh();
	void DisablePickup();
	void ActivatePickup();
};
