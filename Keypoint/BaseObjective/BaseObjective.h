// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ReplicationInfo/TeamInfo/TeamInfo.h"

#include "AA29/Keypoint/Keypoint.h"
#include "BaseObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABaseObjective : public AKeypoint
{
	GENERATED_BODY()
public:

	ABaseObjective(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")		FName DamageTag;				//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomObjective")	FName RandomTag;				//var(RandomObjective) name RandomTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMeshComponent* StaticMesh;

	virtual void BeginPlay() override;

	void GetCompassLocation();
	void IsOnCompass(AController* ctrlRequesting);
	bool IsEnabled();
	void IsInstantWin();
	void IsSquadTarget(int iTeamIndex);
	void GetPercentComplete();
	void GetAccomplishMessageByTeam(uint8 Accomplisher, uint8 listener);
	void GetDescriptionByTeam(uint8 listener);
	void GetDescriptionByPawn(APawn* listener);
	void GetDescriptionByController(AController* listener);
	void GetHUDPosition();
	void CanTeamAttack(uint8 B);
	void CanTeamInfoAttack(ATeamInfo* t);
	bool CanAccomplish(APawn* p);
	void IsHigherPriorityThan(ABaseObjective* Other);
	void NotifyLinkDamage(APawn* instigatedBy, int32 Damage);
	void NotifyLinkKill(APawn* instigatedBy);
	void NotifyLinkDecoDamage(APawn* instigatedBy, int32 DestroyPoints);
	bool HandleGrenadeDamage();

};
