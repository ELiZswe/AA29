// All the original content belonged to the US Army


#include "AA29/NavigationPoint/BlockedPath/BlockedPath.h"

ABlockedPath::ABlockedPath()
{
	bBlocked = true;
	bBlockable = true;
}

void ABlockedPath::PostBeginPlay()
{
	bStartBlocked = bBlocked;
	//Super::PostBeginPlay();
}
void ABlockedPath::Reset()
{
	//Super::Reset();
	bBlocked = bStartBlocked;
}
void ABlockedPath::Trigger(AActor* Other, APawn* EventInstigator)
{
	bBlocked = !bBlocked;
}