// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_RunConsoleCommand/Dir_RunConsoleCommand.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_RunConsoleCommand::UDir_RunConsoleCommand()
{
	_nNumParamsDefined = 1;
}

void UDir_RunConsoleCommand::Destroyed()
{
	//Log("Dir_RunConsoleCommand::Destroyed() entered " + _sCommand);
	_sCommand = "";
	_HumanController = nullptr;
	Super::Destroyed();
}

void UDir_RunConsoleCommand::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_RunConsoleCommand::DirectionStart()");
	}
	Log("Dir_RunConsoleCommand::DirectionStart(): " + _sCommand);
	Log("Dir_RunConsoleCommand::DirectionStart(): " + FString::FromInt(_HumanController));
	if ((_HumanController != nullptr) && (Len(_sCommand) > 0))
	{
		_HumanController.ConsoleCommand(_sCommand);
	}
	*/
}

bool UDir_RunConsoleCommand::ProcessParams()
{
	/*
	_sCommand = GetParam(0);
	Log("Dir_RunConsoleCommand::ProcessParams() entered " + _sCommand);
	if (_ParentScreenplay != nullptr)
	{
		_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
		Log("Dir_RunConsoleCommand::ProcessParams() Got HC of " + FString::FromInt(_HumanController));
	}
	else
	{
		Log("Dir_RunConsoleCommand::ProcessParams() - _ParentScreenplay is NONE!");
		_HumanController = nullptr;
	}
	*/
	return true;
}
