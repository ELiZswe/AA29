// All the original content belonged to the US Army


#include "ItemAttachment.h"

// Sets default values
AItemAttachment::AItemAttachment()
{
	DrawScale          = 1.13;
	DrawType           = EDrawType::DT_StaticMesh;
	RelativeRotation   = FRotator(0, 180, 90);
	Rotation           = FRotator(0, 180, 90);
}