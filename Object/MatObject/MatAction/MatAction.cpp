// All the original content belonged to the US Army

#include "AA29/Object/MatObject/MatAction/MatAction.h"
#include "AA29/Object/Actor/Keypoint/InterpolationPoint/InterpolationPoint.h"

UMatAction::UMatAction()
{
	bSmoothCorner = true;
	StartControlPoint = FVector (800, 800, 0);
	EndControlPoint = FVector(-800, -800, 0);
}
