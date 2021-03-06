// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_CheckParachute/Dir_CheckParachute.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "AA29/Object/Actor/AGP_IntVar/AGP_IntVar.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_CheckParachute::UDir_CheckParachute()
{
	_nNumParamsDefined = 1;
}

void UDir_CheckParachute::Destroyed()
{
	Super::Destroyed();
	_IntVar = nullptr;
	_HumanController = nullptr;
}

void UDir_CheckParachute::DirectionStart()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Dir_CheckParachute::DirectionStart()"));
	}
	if (_HumanController != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("DIR_CheckParachute::setting value."));
		//_IntVar->SetValue(Rand(3));
	}
}

bool UDir_CheckParachute::ProcessParams()
{
	//_IntVar = Cast<AAGP_IntVar>(_ParentScreenplay->GetActorByTag(GetParam(0)));
	if (_IntVar == nullptr)
	{
		if (_bDebug)
		{
			//Log("Dir_CheckParachute::ProcessParams() - could not find AGP_IntVar with tag " + GetParam(0));
		}
		return false;
	}
	_HumanController = Cast<AHumanController>(_ParentScreenplay->GetHumanController());
	return true;
}
