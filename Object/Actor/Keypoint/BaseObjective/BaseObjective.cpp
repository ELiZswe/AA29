// All the original content belonged to the US Army


#include "BaseObjective.h"

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




void ABaseObjective::GetCompassLocation()
{
}
void ABaseObjective::IsOnCompass(AController* ctrlRequesting)
{
}
bool ABaseObjective::IsEnabled()
{
	return true;   //FAKE  /ELiZ
}
void ABaseObjective::IsInstantWin()
{
}
void ABaseObjective::IsSquadTarget(int iTeamIndex)
{
}
void ABaseObjective::GetPercentComplete()
{
}
void ABaseObjective::GetAccomplishMessageByTeam(uint8 Accomplisher, uint8 listener)
{
	//return "";
}
void ABaseObjective::GetDescriptionByTeam(uint8 listener)
{
	//return "";
}
void ABaseObjective::GetDescriptionByPawn(APawn* listener)
{
	//return "";
}
void ABaseObjective::GetDescriptionByController(AController* listener)
{
	//return "";
}
void ABaseObjective::GetHUDPosition()
{
	//return 0;
}
void ABaseObjective::CanTeamAttack(uint8 B)
{
}

void ABaseObjective::CanTeamInfoAttack(ATeamInfo* t)
{
}

bool ABaseObjective::CanAccomplish(APawn* p)
{
	return false;   //FAKE  /ELiZ
}
void ABaseObjective::IsHigherPriorityThan(ABaseObjective* Other)
{
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