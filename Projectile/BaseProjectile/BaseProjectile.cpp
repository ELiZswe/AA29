// All the original content belonged to the US Army


#include "BaseProjectile.h"

ABaseProjectile::ABaseProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	fWindFactor    = 1;
	fAtmoFactor    = 1;
	idTeamOwner    = 255;
	Speed          = 7000;
	MaxSpeed       = 100000;
	DrawType       = EDrawType::DT_None;
	LifeSpan       = 10;
	//bUseCollisionStaticMesh = true;
}