// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/AAGameplay.h"
#include "MarksmanTarget.generated.h"

class AMarksmanTarget_Base;
class AMarksmanTarget_Part;
class ADynamicMover;

UCLASS()
class AA29_API AMarksmanTarget : public AAAGameplay
{
	GENERATED_BODY()
public:
	AMarksmanTarget();

	UPROPERTY()																		FTarget MyTarget;								//var MarksmanTarget.Target MyTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										TArray<FTarget> MeshesBlueFor;					//var() array<Target> MeshesBlueFor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										TArray<FTarget> MeshesCiv;						//var() array<Target> MeshesCiv;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										TArray<FTarget> MeshesIndig;					//var() array<Target> MeshesIndig;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										TArray<FTarget> MeshesOpFor;					//var() array<Target> MeshesOpFor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bCreateBase;								//var() bool bCreateBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bRandomizeType;							//var() bool bRandomizeType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bRandomizeMesh;							//var() bool bRandomizeMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bShootToTrigger;							//var() bool bShootToTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bTriggerOnce;								//var() bool bTriggerOnce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										int32 DefaultMeshIndex;							//var() int DefaultMeshIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										ETargetType TargetType;							//var() ETargetType TargetType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zones")					bool bCreateZones;								//var(Zones) bool bCreateZones;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zones")					bool bShowZoneA;								//var(Zones) bool bShowZoneA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zones")					bool bShowZoneB;								//var(Zones) bool bShowZoneB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zones")					bool bDoubleSidedZones;							//var(Zones) bool bDoubleSidedZones;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zones")					FString ZoneID;									//var(Zones) string ZoneID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomLocation")		bool bRandomizeLocation;						//var(RandomLocation) bool bRandomizeLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomLocation")		FName RandomLocationTag;						//var(RandomLocation) name RandomLocationTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TriggerMovement")		bool bMoveOnTrigger;							//var(TriggerMovement) bool bMoveOnTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TriggerMovement")		FVector LocationOffset;							//var(TriggerMovement) FVector LocationOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TriggerMovement")		FName MoverState;								//var(TriggerMovement) name MoverState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TriggerMovement")		float MoveTime;									//var(TriggerMovement) float MoveTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TriggerMovement")		FRotator RotationOffset;						//var(TriggerMovement) Object.Rotator RotationOffset;
	UPROPERTY()																		AMarksmanTarget_Part* Zone1;					//var MarksmanTarget_Part Zone1;
	UPROPERTY()																		AMarksmanTarget_Part* Zone2;					//var MarksmanTarget_Part Zone2;
	UPROPERTY()																		AMarksmanTarget_Part* Zone3;					//var MarksmanTarget_Part Zone3;
	UPROPERTY()																		AMarksmanTarget_Part* Zone4;					//var MarksmanTarget_Part Zone4;
	UPROPERTY()																		AMarksmanTarget_Base* MagicBox;					//var MarksmanTarget_Base MagicBox;
	UPROPERTY()																		ADynamicMover* MoveActor;						//var DynamicMover MoveActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bTriggered;								//var bool bTriggered;


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
	//void TakeDamage(int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
	//void NotifyDamaged(int Damage, Pawn EventInstigator, class<DamageType>  DamageType, string Id);


};
