// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/AAGameplay.h"
#include "MarksmanTarget.generated.h"

class AMarksmanTarget_Base;
class AMarksmanTarget_Part;
class ADynamicMover;

UCLASS()
class AMarksmanTarget : public AAAGameplay
{
	GENERATED_BODY()
public:
	AMarksmanTarget();

	UPROPERTY()																		FTarget MyTarget;								//var MarksmanTarget.Target MyTarget;
	UPROPERTY(EditAnywhere)										TArray<FTarget> MeshesBlueFor;					//var() array<Target> MeshesBlueFor;
	UPROPERTY(EditAnywhere)										TArray<FTarget> MeshesCiv;						//var() array<Target> MeshesCiv;
	UPROPERTY(EditAnywhere)										TArray<FTarget> MeshesIndig;					//var() array<Target> MeshesIndig;
	UPROPERTY(EditAnywhere)										TArray<FTarget> MeshesOpFor;					//var() array<Target> MeshesOpFor;
	UPROPERTY(EditAnywhere)										bool bCreateBase;								//var() bool bCreateBase;
	UPROPERTY(EditAnywhere)										bool bRandomizeType;							//var() bool bRandomizeType;
	UPROPERTY(EditAnywhere)										bool bRandomizeMesh;							//var() bool bRandomizeMesh;
	UPROPERTY(EditAnywhere)										bool bShootToTrigger;							//var() bool bShootToTrigger;
	UPROPERTY(EditAnywhere)										bool bTriggerOnce;								//var() bool bTriggerOnce;
	UPROPERTY(EditAnywhere)										int32 DefaultMeshIndex;							//var() int DefaultMeshIndex;
	UPROPERTY(EditAnywhere)										ETargetType TargetType;							//var() ETargetType TargetType;
	UPROPERTY(EditAnywhere, Category = "Zones")					bool bCreateZones;								//var(Zones) bool bCreateZones;
	UPROPERTY(EditAnywhere, Category = "Zones")					bool bShowZoneA;								//var(Zones) bool bShowZoneA;
	UPROPERTY(EditAnywhere, Category = "Zones")					bool bShowZoneB;								//var(Zones) bool bShowZoneB;
	UPROPERTY(EditAnywhere, Category = "Zones")					bool bDoubleSidedZones;							//var(Zones) bool bDoubleSidedZones;
	UPROPERTY(EditAnywhere, Category = "Zones")					FString ZoneID;									//var(Zones) string ZoneID;
	UPROPERTY(EditAnywhere, Category = "RandomLocation")		bool bRandomizeLocation;						//var(RandomLocation) bool bRandomizeLocation;
	UPROPERTY(EditAnywhere, Category = "RandomLocation")		FName RandomLocationTag;						//var(RandomLocation) name RandomLocationTag;
	UPROPERTY(EditAnywhere, Category = "TriggerMovement")		bool bMoveOnTrigger;							//var(TriggerMovement) bool bMoveOnTrigger;
	UPROPERTY(EditAnywhere, Category = "TriggerMovement")		FVector LocationOffset;							//var(TriggerMovement) FVector LocationOffset;
	UPROPERTY(EditAnywhere, Category = "TriggerMovement")		FName MoverState;								//var(TriggerMovement) name MoverState;
	UPROPERTY(EditAnywhere, Category = "TriggerMovement")		float MoveTime;									//var(TriggerMovement) float MoveTime;
	UPROPERTY(EditAnywhere, Category = "TriggerMovement")		FRotator RotationOffset;						//var(TriggerMovement) Object.Rotator RotationOffset;
	UPROPERTY()																		AMarksmanTarget_Part* Zone1;					//var MarksmanTarget_Part Zone1;
	UPROPERTY()																		AMarksmanTarget_Part* Zone2;					//var MarksmanTarget_Part Zone2;
	UPROPERTY()																		AMarksmanTarget_Part* Zone3;					//var MarksmanTarget_Part Zone3;
	UPROPERTY()																		AMarksmanTarget_Part* Zone4;					//var MarksmanTarget_Part Zone4;
	UPROPERTY()																		AMarksmanTarget_Base* MagicBox;					//var MarksmanTarget_Base MagicBox;
	UPROPERTY()																		ADynamicMover* MoveActor;						//var DynamicMover MoveActor;
	UPROPERTY(EditAnywhere)										bool bTriggered;								//var bool bTriggered;


	void PreBeginPlay();
	void BeginPlay();
	void PostBeginPlay();
	void InitMover();
	void InitBase();
	void RandomizeLocation();
	bool LocationIsTaken(TArray<AMarksmanTarget*> Targets, AActor* L);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void TriggerSelf();
	void TriggerMover();
	void ResetTarget(bool bResetMover);
	void CreateZones();
	void SetTargetType(ETargetType Type);
	void SetNewTarget(ETargetType Type);
	void SetRandomTarget();
	void SetRandomType();
	void SetRandomMesh();
	void SetMesh(int32 Index);
	//void TakeDamage(int32 Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
	//void NotifyDamaged(int32 Damage, Pawn EventInstigator, class<DamageType>  DamageType, string Id);


};
