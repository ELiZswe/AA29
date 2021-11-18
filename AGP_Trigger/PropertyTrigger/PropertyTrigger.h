// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "AA29/AA29.h"
#include "PropertyTrigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APropertyTrigger : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	APropertyTrigger();

	UPROPERTY(EditAnywhere)				AActor* _TargetActor;						//var Actor _TargetActor;
	UPROPERTY(EditAnywhere)				bool bSet;									//var bool bSet;
	UPROPERTY(EditAnywhere)				bool bTouchTriggered;						//var() bool bTouchTriggered;
	UPROPERTY(EditAnywhere)				bool bToggle;								//var() bool bToggle;
	UPROPERTY(EditAnywhere)				TArray<FTargetActor> TargetActors;			//var() array<TargetActor> TargetActors;
	UPROPERTY(EditAnywhere)				EStartType StartType;					//var() EStartType StartType;

	void BeginPlay();
	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
	void SetProperties();
	void UnSetProperties();
	void Set_bHidden(FTargetActor TargetActor);
	void UnSet_bHidden(FTargetActor TargetActor);
	void Set_bBlockActors(FTargetActor TargetActor);
	void UnSet_bBlockActors(FTargetActor TargetActor);
	void Set_bBlockPlayers(FTargetActor TargetActor);
	void UnSet_bBlockPlayers(FTargetActor TargetActor);
	void Set_bBlockZeroExtentTraces(FTargetActor TargetActor);
	void UnSet_bBlockZeroExtentTraces(FTargetActor TargetActor);
	void Set_bBlockNonZeroExtentTraces(FTargetActor TargetActor);
	void UnSet_bBlockNonZeroExtentTraces(FTargetActor TargetActor);
	void Set_AmbientGlow(FTargetActor TargetActor);
	void UnSet_AmbientGlow(FTargetActor TargetActor);
	void Set_DrawScale(FTargetActor TargetActor);
	void UnSet_DrawScale(FTargetActor TargetActor);

};
