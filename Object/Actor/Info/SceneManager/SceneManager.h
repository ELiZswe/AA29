// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "AA29/Object/MatObject/MatAction/MatAction.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "SceneManager.generated.h"

UCLASS()
class AA29_API ASceneManager : public AAA2_Info
{
	GENERATED_BODY()
public:
	ASceneManager(); 

private:
	UPROPERTY()										bool							bEndSceneNow;			//var bool bEndSceneNow;
	UPROPERTY()										bool							bAbortCinematic;		//var transient bool bAbortCinematic;
	UPROPERTY()										FVector							DollyOffset;			//var transient FVector DollyOffset;
	UPROPERTY()										FVector							CameraShake;			//var transient FVector CameraShake;
	UPROPERTY()										FInterpolator					RotInterpolator;		//var transient Interpolator RotInterpolator;
	UPROPERTY()										FOrientation					PrevOrientation;		//var transient Orientation PrevOrientation;
	UPROPERTY()										FOrientation					CamOrientation;			//var transient Orientation CamOrientation;
	UPROPERTY()										TArray<UMatSubAction*>			SubActions;				//var transient array<MatSubAction> SubActions;
	UPROPERTY()										TArray<FVector>					SampleLocations;		//var transient array<Vector> SampleLocations;
	UPROPERTY()										float							CurrentTime;			//var transient float CurrentTime;
	UPROPERTY()										bool							bIsSceneStarted;		//var transient bool bIsSceneStarted;
	UPROPERTY()										bool							bIsRunning;				//var transient bool bIsRunning;
	UPROPERTY()										APawn*							OldPawn;				//var transient Pawn OldPawn;
	UPROPERTY()										AActor*							Viewer;					//var transient Actor Viewer;
	UPROPERTY()										float							TotalSceneTime;			//var transient float TotalSceneTime;
	UPROPERTY()										float							SceneSpeed;				//var transient float SceneSpeed;
	UPROPERTY()										bool							CurrentAction;			//var transient MatAction CurrentAction;
	UPROPERTY()										float							PctSceneComplete;		//var transient float PctSceneComplete;

public:
	UPROPERTY(EditAnywhere)							bool							bHideHUD;				//var() bool bHideHUD;
	UPROPERTY(EditAnywhere)							FName							EventEnd;				//var() name EventEnd;
	UPROPERTY(EditAnywhere)							FName							EventStart;				//var() name EventStart;
	UPROPERTY(EditAnywhere)							FName							NextSceneTag;			//var() name NextSceneTag;
	UPROPERTY(EditAnywhere)							FName							PlayerScriptTag;		//var() name PlayerScriptTag;
	UPROPERTY(EditAnywhere)							bool							bCinematicView;			//var() bool bCinematicView;
	UPROPERTY(EditAnywhere)							bool							bLooping;				//var() bool bLooping;
	UPROPERTY(EditAnywhere)							AActor*							AffectedActor;			//var() Actor AffectedActor;
	UPROPERTY(EditAnywhere, Config)					EAffect							Affect;					//var() config EAffect Affect;
	UPROPERTY(EditAnywhere)							TArray<TSubclassOf<UMatAction>>	Actions;				//var() array<MatAction> Actions;
};
