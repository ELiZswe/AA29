// All the original content belonged to the US Army


#include "AA29/Keypoint/Marker/NoiseMarker/NoiseMarker.h"

ANoiseMarker::ANoiseMarker(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{

}


void ANoiseMarker::SetDestroyTimer(float Life)
{
	//SetTimer(Life, false);
}
void ANoiseMarker::Timer()
{
	Destroy();
}
void ANoiseMarker::Destroyed()
{
}