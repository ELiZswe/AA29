// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projector/DynamicProjector/DynamicProjector.h"

ADynamicProjector::ADynamicProjector()
{
	bDynamicAttach = true;
	//bStatic = false;
}

void ADynamicProjector::Tick(float DeltaTime)
{
	DetachProjector(false);
	AttachProjector(false);
}
