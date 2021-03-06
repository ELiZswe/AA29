// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"

#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "BaseObjective.generated.h"

class ATeamInfo;
UCLASS()
class ABaseObjective : public AKeypoint
{
	GENERATED_BODY()
public:

	ABaseObjective(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere, Category = "LinkDamage")		FName DamageTag;				//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, Category = "RandomObjective")	FName RandomTag;				//var(RandomObjective) name RandomTag;

	UPROPERTY(EditAnywhere)		UStaticMeshComponent* StaticMesh;

	virtual void BeginPlay() override;

	FVector GetCompassLocation();
	bool IsOnCompass(AController* ctrlRequesting);
	bool IsEnabled();
	bool IsInstantWin();
	bool IsSquadTarget(int32 iTeamIndex);
	float GetPercentComplete();
	FString GetAccomplishMessageByTeam(uint8 Accomplisher, uint8 listener);
	FString GetDescriptionByTeam(uint8 listener);
	FString GetDescriptionByPawn(APawn* listener);
	FString GetDescriptionByController(AController* listener);
	uint8 GetHUDPosition();
	bool CanTeamAttack(uint8 B);
	bool CanTeamInfoAttack(ATeamInfo* t);
	bool CanAccomplish(APawn* p);
	bool IsHigherPriorityThan(ABaseObjective* Other);
	void NotifyLinkDamage(APawn* instigatedBy, int32 Damage);
	void NotifyLinkKill(APawn* instigatedBy);
	void NotifyLinkDecoDamage(APawn* instigatedBy, int32 DestroyPoints);
	bool HandleGrenadeDamage();
};
