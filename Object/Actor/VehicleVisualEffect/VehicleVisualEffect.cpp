// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleVisualEffect/VehicleVisualEffect.h"

// Sets default values
AVehicleVisualEffect::AVehicleVisualEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_None;
	//RemoteRole = ROLE_None;
}


void AVehicleVisualEffect::BeginPlay()
{
	Super::BeginPlay();
	
}


void AVehicleVisualEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehicleVisualEffect::StartEmitter(AEmitter* Emitter, AActor* AttachActor, FName AttachBone)
{
	/*
	if (EffectEmitter != nullptr)
	{
		EffectEmitter.Kill();
	}
	EffectEmitter = Spawn(Emitter, this);
	if (AttachActor == nullptr)
	{
		Log("VehicleVisualEffect: Attempted to attach emitter to non-existant Actor");
		return;
	}
	AttachActor.AttachToBone(EffectEmitter, AttachBone);
	*/
}

void AVehicleVisualEffect::StopEmitter()
{
	/*
	if (EffectEmitter != nullptr)
	{
		EffectEmitter.Kill();
	}
	*/
}
