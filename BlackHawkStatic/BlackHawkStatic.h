// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "Components/PoseableMeshComponent.h"
#include "BlackHawkStatic.generated.h"


//class AGP_Objective;

UCLASS()
class AA29_API ABlackHawkStatic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHawkStatic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()																		float fpDesiredRotorSpeed;					//var float fpDesiredRotorSpeed;
	UPROPERTY()																		float fpRotorSpeed;							//var float fpRotorSpeed;
	UPROPERTY()																		float fpTailRotorRotation;					//var float fpTailRotorRotation;
	UPROPERTY()																		float fpMainRotorRotation;					//var float fpMainRotorRotation;
	UPROPERTY()																		AActor* aRearwardWounded;					//var Actor aRearwardWounded;
	UPROPERTY()																		AActor* aForwardWounded;					//var Actor aForwardWounded;
	UPROPERTY()																		APawn* pForwardWounded;						//var Pawn pForwardWounded;
	UPROPERTY()																		APawn* pRearwardWounded;					//var Pawn pRearwardWounded;
	UPROPERTY()																		APawn* pPilot;								//var Pawn pPilot;
	UPROPERTY()																		APawn* pCoPilot;							//var Pawn pCoPilot;
	UPROPERTY()																		APawn* pCrewLoadMaster;						//var Pawn pCrewLoadMaster;
	UPROPERTY()																		APawn* pCrewChief;							//var Pawn pCrewChief;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterCrew")		bool bIncludeForwardWounded;				//var(HelicopterCrew) bool bIncludeForwardWounded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterCrew")		bool bIncludeRearwardWounded;				//var(HelicopterCrew) bool bIncludeRearwardWounded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterCrew")		bool bIncludeLoadMaster;					//var(HelicopterCrew) bool bIncludeLoadMaster;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterCrew")		bool bIncludeCrewchief;						//var(HelicopterCrew) bool bIncludeCrewchief;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterCrew")		bool bIncludeCoPilot;						//var(HelicopterCrew) bool bIncludeCoPilot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HelicopterCrew")		bool bIncludePilot;							//var(HelicopterCrew) bool bIncludePilot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				UTexture2D* CivilianBHSkin;					//var(blackhawk) Texture CivilianBHSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				bool bIsCivilian;							//var(blackhawk) bool bIsCivilian;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				float fpRotorDustSpeed;						//var(blackhawk) float fpRotorDustSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				float fpRotorAcceleration;					//var(blackhawk) float fpRotorAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				float fpRotorActivatedSpeed;				//var(blackhawk) float fpRotorActivatedSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				bool bUseToStartRotor;						//var(blackhawk) bool bUseToStartRotor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				FName nameTailRotorBone;					//var(blackhawk) name nameTailRotorBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				FName nameMainRotorBone;					//var(blackhawk) name nameMainRotorBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				FName namePlayerUsedEvent;					//var(blackhawk) name namePlayerUsedEvent;
	UPROPERTY()																		int32 InitialKillHealth;					//var int InitialKillHealth;
	UPROPERTY(BlueprintReadWrite			)										AAGP_Objective* DamageObjective;			//var AGP.AGP_Objective DamageObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "blackhawk")				USoundBase* sndHover;						//var(blackhawk) Sound sndHover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			int32 KillHealth;							//var(LinkDamage) int KillHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			FName KillEvent;							//var(LinkDamage) name KillEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			FName DamageTag;							//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			FName DamageEvent;							//var(LinkDamage) name DamageEvent;
	//UPROPERTY()																	AHelicopterDustCloudEffect* emitDust;		//var HelicopterDustCloudEffect emitDust;

	//Mine
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)										USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UPoseableMeshComponent * PoseableMesh;

	//from Actor
	UPROPERTY()										bool bProp;			//var bool bProp;

	//void BeginPlay();
	void ConfigureLinkDamage();
	//void TakeDamage(int Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
	void InitializeCrew();
	void Timer();
	//void Tick(float DeltaTime);
	void DustCloudTimer();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UsedBy(APawn* User);
	void AttachCrewChief();
	void AttachCrewLoadMaster();
	void AttachCoPilot();
	void AttachPilot();
	void AttachRearwardWounded();
	void AttachForwardWounded();
	void AttachHelmet(APawn* pawnCrewMember);

};
