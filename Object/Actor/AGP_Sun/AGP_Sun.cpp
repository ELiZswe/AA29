// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Sun/AGP_Sun.h"

// Sets default values
AAGP_Sun::AAGP_Sun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WhiteOutColorAndAlpha = FColor(255, 255, 255, 255);
	WhiteOutRampFactor = 1;
	AngleToStartWhiteOut = 20;
	AngleToStartLensFlares = 55;
	SunIntensityColorScalar = FColor(128, 128, 128, 255);
	bLensFlaresInEditor = true;
	//bStatic = true;
	//bSkipActorPropertyReplication = true;
	//RemoteRole = ROLE_None;
}


void AAGP_Sun::BeginPlay()
{
	Super::BeginPlay();
}


void AAGP_Sun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//native Function TestGlowCaps();
void AAGP_Sun::TestGlowCaps()
{
}

void AAGP_Sun::PostBeginPlay()
{
	//Super::PostBeginPlay();
	TestGlowCaps();
}
