// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_ConsoleCommand/ACTION_ConsoleCommand.h"

UACTION_ConsoleCommand::UACTION_ConsoleCommand()
{
	ActionString = "console command";
}

bool UACTION_ConsoleCommand::InitActionFor(UScriptedController* C)
{
	/*
	if (CommandStr != "")
	{
		C.ConsoleCommand(CommandStr);
	}
	*/
	return false;
}
FString UACTION_ConsoleCommand::GetActionString()
{
	//return ActionString @ CommandStr;
	return "";    //FAKE   /ELiZ
}