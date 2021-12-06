// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/BroadcastHandler/AGP_ChatHandler/AGP_ChatHandler.h"

AAGP_ChatHandler::AAGP_ChatHandler()
{

}

void AAGP_ChatHandler::ToggleChatDebug()
{
	bDebug = !bDebug;
}

void AAGP_ChatHandler::DoChatDebug()
{
	/*
	local TArray<PlayerController> Arr;
	int32 i = 0;
	if (!bDebug)
	{
		ToggleChatDebug();
	}
	Level.Game.GetPlayerControllerList(Arr);
	Log("Controller list length:" $ string(Arr.Length), 'ChatManager');
	for (i = 0; i < Arr.Length; i++)
	{
		if (Arr[i].ChatManager == None)
		{
			Log(string(Arr[i].Name) @ "PC[" $ string(i) $ "].ChatManager None (" $ Arr[i].PlayerReplicationInfo.PlayerName $ ")", 'ChatManager');
			Log("");
		}
		else
		{
			Log(string(Arr[i].Name) @ "PC[" $ string(i) $ "] (" $ Arr[i].PlayerReplicationInfo.PlayerName $ ") Chat Handler Information", 'ChatManager');
			Arr[i].ChatManager.ChatDebug();
			Log("");
		}
	}
	*/
}

bool AAGP_ChatHandler::AcceptBroadcastText(APlayerController* Receiver, AAA2_PlayerState* SenderPRI, FString& Msg, FName Type)
{
	/*
	bool Result = false;
	if ((Receiver != None) && (Receiver.ChatManager != None))
	{
		Result = Receiver.ChatManager.AcceptText(SenderPRI, Msg, Type);
		if (bDebug)
		{
			Log("AcceptBroadcastText() Receiver:" $ string(Receiver.Name) @ "Sender:" $ SenderPRI.PlayerName @ "Allowed:" $ string(Result), 'ChatManager');
			if (!Result)
			{
				return false;
			}
		}
		else
		{
			if (!Receiver.ChatManager.AcceptText(SenderPRI, Msg, Type))
			{
				return false;
			}
		}
	}
	else
	{
		if (bDebug)
		{
			Log("AcceptBroadcastText() Receiver:" $ string(Receiver.Name) @ "Receiver.ChatManager:" $ string(Receiver.ChatManager), 'ChatManager');
		}
	}
	return Super::AcceptBroadcastText(Receiver, SenderPRI, Msg, Type);
	*/
	return false;   //FAKE   /ELiZ}
}

bool AAGP_ChatHandler::AcceptBroadcastLocalized(APlayerController* Receiver, AActor* Sender, ALocalMessage*  Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* obj)
{
	/*
	if ((Receiver != None) && (Receiver.ChatManager != None))
	{
		if (!Receiver.ChatManager.AcceptLocalized(Sender, Message, Switch, RelatedPRI_1, RelatedPRI_2, obj))
		{
			return false;
		}
	}
	return Super::AcceptBroadcastLocalized(Receiver, Sender, Message, Switch, RelatedPRI_1, RelatedPRI_2, obj);
	*/
	return false;   //FAKE   /ELiZ
}

bool AAGP_ChatHandler::AcceptBroadcastSpeech(APlayerController* Receiver, AAA2_PlayerState* SenderPRI)
{
	/*
	bool bResult = false;
	if ((Receiver != None) && (Receiver.ChatManager != None))
	{
		bResult = Receiver.ChatManager.AcceptSpeech(SenderPRI);
		if (bDebug)
		{
			Log("AcceptBroadcastSpeech() Receiver:" $ string(Receiver.Name) @ "Sender:" $ SenderPRI.PlayerName @ "Allowed:" $ string(bResult), 'ChatManager');
			if (!bResult)
			{
				return false;
			}
		}
		else
		{
			if (!Receiver.ChatManager.AcceptSpeech(SenderPRI))
			{
				return false;
			}
		}
	}
	else
	{
		if (bDebug)
		{
			Log("AcceptBroadcastSpeech() Receiver:" $ string(Receiver.Name) @ "Receiver.ChatManager:" $ string(Receiver.ChatManager), 'ChatManager');
		}
	}
	return Super::AcceptBroadcastSpeech(Receiver, SenderPRI);
	*/
	return false;   //FAKE   /ELiZ
}

bool AAGP_ChatHandler::AcceptBroadcastVoice(APlayerController* Receiver, AAA2_PlayerState* Sender)
{
	/*
	if ((Receiver != None) && (Receiver.ChatManager != None))
	{
		if (!Receiver.ChatManager.AcceptVoice(Sender))
		{
			return false;
		}
	}
	return Super::AcceptBroadcastVoice(Receiver, Sender);
	*/
	return false;   //FAKE   /ELiZ
}


