// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/MidGamePanel/MidGamePanel.h"

UMidGamePanel::UMidGamePanel()
{

}

void UMidGamePanel::ModifiedChatRestriction(UMidGamePanel* Sender, int32 PlayerID)
{
}

void UMidGamePanel::UpdateChatRestriction(int32 PlayerID)
{
	//Log(string(Name) @ "UpdateChatRestriction PlayerID:" $ string(PlayerID), 'ChatManager');
}

bool UMidGamePanel::PlayerIDIsMine(int32 idx)
{
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	if (((PC != None) && (PC.PlayerReplicationInfo != None)) && (PC.PlayerReplicationInfo.PlayerID == idx))
	{
		return true;
	}
	*/
	return false;
}

void UMidGamePanel::Free()
{
	bLocked = true;
	//Super::Free();
}

void UMidGamePanel::LevelChanged()
{
	bLocked = true;
	//Free();
}
