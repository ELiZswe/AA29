// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AA2_Pawn.generated.h"

class UKarmaParamsCollision;
class AEventlab;
class AAnimManager;

UCLASS(Config = Game)
class AAA2_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAA2_Pawn();

	//From Actor+Pawn

	UPROPERTY()												bool					InVal;
	UPROPERTY()												USkeletalMesh*			Mesh;
	UPROPERTY(EditAnywhere, Category = "Collision")			uint8					ValidJavelinTarget;			//var(Collision) byte ValidJavelinTarget;


	UPROPERTY()												float					GroundSpeed;				//var float GroundSpeed;
	UPROPERTY()												float					WaterSpeed;					//var float WaterSpeed;
	UPROPERTY()												float					AirSpeed;					//var float AirSpeed;
	UPROPERTY()												float					LadderSpeed;				//var float LadderSpeed;
	UPROPERTY()												float					AccelRate;					//var float AccelRate;
	UPROPERTY()												float					JumpZ;						//var float JumpZ;
	UPROPERTY()												float					AirControl;					//var float AirControl;
	UPROPERTY()												float					WalkingPct;					//var float WalkingPct;
	UPROPERTY()												float					CrouchedPct;				//var float CrouchedPct;
	UPROPERTY()												float					MaxFallSpeed;				//var float MaxFallSpeed;

	UPROPERTY()												float					HealthMax;					//var float HealthMax;
	UPROPERTY()												float					SuperHealthMax;				//var float SuperHealthMax;
	UPROPERTY()												int32					Health;						//var travel int32 Health;

	UPROPERTY(globalconfig)									float					Bob;							//var globalconfig float Bob;
	UPROPERTY()												bool					bJumpCapable;					//var bool bJumpCapable;
	UPROPERTY()												bool					bCanJump;						//var bool bCanJump;
	UPROPERTY()												bool					HebAbortMoveIfGoalOccupiedalth;	//var bool bAbortMoveIfGoalOccupied;
	UPROPERTY()												bool					bCanWalk;						//var bool bCanWalk;
	UPROPERTY()												bool					bCanSwim;						//var bool bCanSwim;
	UPROPERTY()												bool					bCanFly;						//var bool bCanFly;
	UPROPERTY()												bool					bCanClimbLadders;				//var bool bCanClimbLadders;
	UPROPERTY()												bool					bCanStrafe;						//var bool bCanStrafe;
	UPROPERTY()												bool					bCanDoubleJump;					//var bool bCanDoubleJump;
	UPROPERTY()												bool					bCanWallDodge;					//var bool bCanWallDodge;
	UPROPERTY()												bool					bAvoidLedges;					//var bool bAvoidLedges;
	UPROPERTY()												bool					bStopAtLedges;					//var bool bStopAtLedges;
	UPROPERTY()												bool					bNoJumpAdjust;					//var bool bNoJumpAdjust;
	UPROPERTY()												bool					bCountJumps;					//var bool bCountJumps;
	UPROPERTY()												bool					bSimulateGravity;				//var const bool bSimulateGravity;
	UPROPERTY()												bool					bUpdateEyeheight;				//var bool bUpdateEyeheight;
	UPROPERTY()												bool					bIgnoreForces;					//var bool bIgnoreForces;
	UPROPERTY()												AAnimManager*			AnimManager;					//var AAnimManager* AnimManager;
	//From Actor
	UPROPERTY()												USceneComponent*			Root;
	UPROPERTY()												TArray<UMaterialInstance*>	Skins;
	UPROPERTY()												AEventlab*					EventLab;					//var Actor EventLab;
	UPROPERTY(EditAnywhere, Category = "Movement")			FVector						Velocity;					//var(Movement) FVector Velocity;
	UPROPERTY(EditAnywhere, Category = "Karma")				UKarmaParamsCollision*		KParams;					//var(Karma) KarmaParamsCollision KParams;
	UPROPERTY(EditAnywhere)									USkeletalMeshComponent*		Mesh_3P;
	UPROPERTY(EditAnywhere)									UAnimationAsset*			Anim_1P;
	UPROPERTY(EditAnywhere)									UAnimationAsset*			Anim_3P;
	UPROPERTY(EditAnywhere)									FVector						PrePivot;
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void LoadMesh();
};
