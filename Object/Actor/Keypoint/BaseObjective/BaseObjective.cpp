// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"

ABaseObjective::ABaseObjective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	//bAlwaysRelevant = true;
	//bOnlyDirtyReplication = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	if (StaticMesh)
	{
		StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}

}

FVector ABaseObjective::GetCompassLocation()
{
	return FVector(0, 0, 0);    //FAKE   /EliZ
}

bool ABaseObjective::IsOnCompass(AController* ctrlRequesting)
{
	return false;    //FAKE   /EliZ
}

bool ABaseObjective::IsEnabled()
{
	return true;   //FAKE  /ELiZ
}

bool ABaseObjective::IsInstantWin()
{
	return false;    //FAKE   /EliZ
}

bool ABaseObjective::IsSquadTarget(int32 iTeamIndex)
{
	return false;    //FAKE   /EliZ
}

float ABaseObjective::GetPercentComplete()
{
	return 0;    //FAKE   /EliZ
}

FString ABaseObjective::GetAccomplishMessageByTeam(uint8 Accomplisher, uint8 listener)
{
	return "";
}

FString ABaseObjective::GetDescriptionByTeam(uint8 listener)
{
	return "";
}

FString ABaseObjective::GetDescriptionByPawn(APawn* listener)
{
	return "";
}

FString ABaseObjective::GetDescriptionByController(AController* listener)
{
	return "";
}

uint8 ABaseObjective::GetHUDPosition()
{
	return 0;
}

bool ABaseObjective::CanTeamAttack(uint8 B)
{
	return false;    //FAKE   /EliZ
}

bool ABaseObjective::CanTeamInfoAttack(ATeamInfo* t)
{
	return false;    //FAKE   /EliZ
}

bool ABaseObjective::CanAccomplish(APawn* p)
{
	return false;   //FAKE  /ELiZ
}

bool ABaseObjective::IsHigherPriorityThan(ABaseObjective* Other)
{
	return false;   //FAKE  /ELiZ
}
void ABaseObjective::NotifyLinkDamage(APawn* instigatedBy, int32 Damage)
{
}

void ABaseObjective::NotifyLinkKill(APawn* instigatedBy)
{
}

void ABaseObjective::NotifyLinkDecoDamage(APawn* instigatedBy, int32 DestroyPoints)
{
}

bool ABaseObjective::HandleGrenadeDamage()
{
	return true;
}

void ABaseObjective::BeginPlay()
{
	Super::BeginPlay();
}
