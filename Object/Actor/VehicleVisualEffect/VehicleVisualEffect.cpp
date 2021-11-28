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

// Called when the game starts or when spawned
void AVehicleVisualEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicleVisualEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehicleVisualEffect::StartEmitter(AEmitter* Emitter, AActor* AttachActor, FName AttachBone)
{
	/*
	if (EffectEmitter != None)
	{
		EffectEmitter.Kill();
	}
	EffectEmitter = Spawn(Emitter, Self);
	if (AttachActor == None)
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
	if (EffectEmitter != None)
	{
		EffectEmitter.Kill();
	}
	*/
}