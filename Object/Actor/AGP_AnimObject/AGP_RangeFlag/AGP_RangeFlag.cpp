// All the original content belonged to the US Army


#include "AGP_RangeFlag.h"


AAGP_RangeFlag::AAGP_RangeFlag()
{
	//Mesh=SkeletalMesh'A_AA2_Objects.RangeFlag'

}

// Called when the game starts or when spawned
void AAGP_RangeFlag::BeginPlay()
{
	Super::BeginPlay();
	if (SkeletalMesh)
	{

		SetMesh();
	}
}

// Called every frame
void AAGP_RangeFlag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}