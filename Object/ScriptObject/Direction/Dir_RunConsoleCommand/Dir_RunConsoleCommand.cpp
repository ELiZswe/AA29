// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_RunConsoleCommand/Dir_RunConsoleCommand.h"

UDir_RunConsoleCommand::UDir_RunConsoleCommand()
{
	_nNumParamsDefined = 1;
}

void UDir_RunConsoleCommand::Destroyed()
{
	//Log("Dir_RunConsoleCommand::Destroyed() entered " $ _sCommand);
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
	Log("Dir_RunConsoleCommand::DirectionStart(): " $ _sCommand);
	Log("Dir_RunConsoleCommand::DirectionStart(): " $ string(_HumanController));
	if ((_HumanController != None) && (Len(_sCommand) > 0))
	{
		_HumanController.ConsoleCommand(_sCommand);
	}
	*/
}

bool UDir_RunConsoleCommand::ProcessParams()
{
	/*
	_sCommand = GetParam(0);
	Log("Dir_RunConsoleCommand::ProcessParams() entered " $ _sCommand);
	if (_ParentScreenplay != None)
	{
		_HumanController = HumanController(_ParentScreenplay.GetHumanController());
		Log("Dir_RunConsoleCommand::ProcessParams() Got HC of " $ string(_HumanController));
	}
	else
	{
		Log("Dir_RunConsoleCommand::ProcessParams() - _ParentScreenplay is NONE!");
		_HumanController = nullptr;
	}
	*/
	return true;
}
