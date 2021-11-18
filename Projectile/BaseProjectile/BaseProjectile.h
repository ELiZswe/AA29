// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/Projectile.h"
#include "BaseProjectile.generated.h"

UCLASS()
class AA29_API ABaseProjectile : public AProjectile
{
	GENERATED_BODY()
public:
	ABaseProjectile(const FObjectInitializer& ObjectInitializer);

		
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 idTeamOwner;											//var byte idTeamOwner;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class ABaseProjectile> EnemyProjectileClass;	//var class<BaseProjectile> EnemyProjectileClass;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase* ExplosionSound;									//var Sound ExplosionSound;
		//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* TrailEmitter;									//var Emitter TrailEmitter;
		//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* cTrailEmitterClass;							//var class<Emitter> cTrailEmitterClass;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		float fAtmoFactor;											//var float fAtmoFactor;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		float fWindFactor;											//var float fWindFactor;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		float fKillRadius;											//var float fKillRadius;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<AActor*> DamageClasses;								//var array<class<Actor> > DamageClasses;

};
