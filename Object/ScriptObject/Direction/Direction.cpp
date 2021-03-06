// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"

UDirection::UDirection()
{

}

void UDirection::Destroyed()
{
	Super::Destroyed();
	_ParentScreenplay = nullptr;
}

void UDirection::DirectionStart()
{
}

void UDirection::DirectionFinish()
{
}

bool UDirection::ProcessParams()
{
	return false;
}

void UDirection::Start()
{
	DirectionStart();
}

void UDirection::Finish()
{
	DirectionFinish();
}

void UDirection::SetParentScreenplay(AScreenplay* Parent)
{
	_ParentScreenplay = Parent;
}
