// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_T62_115MM_HE/Proj_T62_115MM_HE.h"
#include "Proj_BMP_Auto_Cannon.generated.h"

UCLASS()
class AProj_BMP_Auto_Cannon : public AProj_T62_115MM_HE
{
	GENERATED_BODY()
public:
	AProj_BMP_Auto_Cannon(const FObjectInitializer& ObjectInitializer);
};
