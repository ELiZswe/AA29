// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Marker/Marker.h"
#include "CubeMapMaker.generated.h"

class AHumanController;
class AAGP_Pawn;
class AMultiTimer;

UCLASS()
class ACubeMapMaker : public AMarker
{
	GENERATED_BODY()
public:
	ACubeMapMaker(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere)			bool bInit;							//var bool bInit;
	UPROPERTY(EditAnywhere)			bool bDestroy;						//var bool bDestroy;
	UPROPERTY(EditAnywhere)			AMultiTimer* mT;					//var MultiTimer mT;
	UPROPERTY(EditAnywhere)			int32 RotIndex;						//var int RotIndex;
	UPROPERTY(EditAnywhere)			AHumanController* Controller;		//var HumanController Controller;
	UPROPERTY(EditAnywhere)			AAGP_Pawn* Player;					//var AGP_Pawn Player;
	UPROPERTY(EditAnywhere)			int32 Resolution;					//var() int Resolution;

	void BeginPlay();
	void Begin(uint8 Index);
	FRotator GetRotationFromIndex(uint8 Index);
	void DestroyOnFinish(bool bDoDestroy);
	void Destroyed();
	void TimerNotify(FName TimerName, AMultiTimer* NotifyTimer);
	void NextShot();
	void Tick(float DeltaTime);
};
