// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/ChatRoomMessage/ChatRoomMessage.h"

AChatRoomMessage::AChatRoomMessage()
{
	AnonText = "Someone";
	ChatRoomString = { "Invalid channel or channel couldn't be found: '%title%'",	"Already a member of channel '%title%'",	"Channel '%title%' requires a password!",	"Incorrect password specified for channel '%title%'",
	"You have been banned from channel '%title%'",	"Couldn't join channel '%title%'.  Channel full!",	"You are not allowed to join channel '%title%'",	"Successfully joined channel '%title%'",
	"You left channel '%title%'",	"Now speaking on channel '%title%'",	"No longer speaking on channel '%title%'",	"'%pri%' joined channel '%title%'",
	"'%pri%' left channel '%title%'",	"Successfully banned '%pri%' from your personal chat channel",	"Voice-chat ban action not successful.  No player with the specified ID was found",	"Voice chat is not enabled on this server" };
}


void AChatRoomMessage::AssembleMessage(int32 Index, FString ChannelTitle, AAA2_PlayerState* RelatedPRI)
{
	/*
	local string Text;
	if (RelatedPRI != None)
	{
		Text = Repl(Default.ChatRoomString[Index], "%pri%", RelatedPRI.PlayerName);
	}
	else
	{
		if (InStr(Default.ChatRoomString[Index], "%pri%") != -1)
		{
			Text = Repl(Default.ChatRoomString[Index], "%pri%", Default.AnonText);
		}
		else
		{
			Text = Default.ChatRoomString[Index];
		}
	}
	if (ChannelTitle != "")
	{
		Return Repl(Text, "%title%", ChannelTitle);
	}
	else
	{
		Return Text;
	}
	*/
}
bool AChatRoomMessage::IsConsoleMessage(int32 Index)
{
	switch (Index)
	{
	case 1:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		return false;
	default:
		return Super::IsConsoleMessage(Index);
	}
}