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
	TArray<APlayerController*> Arr = {};
	int32 i = 0;
	if (!bDebug)
	{
		ToggleChatDebug();
	}
	/*
	Level.Game.GetPlayerControllerList(Arr);
	Log("Controller list length:" + FString::FromInt(Arr.Num()), 'ChatManager');
	for (i = 0; i < Arr.Num(); i++)
	{
		if (Arr[i].ChatManager == nullptr)
		{
			Log(string(Arr[i].Name) @ "PC[" + FString::FromInt(i) + "].ChatManager None (" + Arr[i].PlayerReplicationInfo.PlayerName + ")", 'ChatManager');
			Log("");
		}
		else
		{
			Log(string(Arr[i].Name) @ "PC[" + FString::FromInt(i) + "] (" + Arr[i].PlayerReplicationInfo.PlayerName + ") Chat Handler Information", 'ChatManager');
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
	if ((Receiver != nullptr) && (Receiver.ChatManager != nullptr))
	{
		Result = Receiver.ChatManager.AcceptText(SenderPRI, Msg, Type);
		if (bDebug)
		{
			Log("AcceptBroadcastText() Receiver:" + FString::FromInt(Receiver.Name) @ "Sender:" + SenderPRI.PlayerName @ "Allowed:" + FString::FromInt(Result), 'ChatManager');
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
			Log("AcceptBroadcastText() Receiver:" + FString::FromInt(Receiver.Name) @ "Receiver.ChatManager:" + FString::FromInt(Receiver.ChatManager), 'ChatManager');
		}
	}
	return Super::AcceptBroadcastText(Receiver, SenderPRI, Msg, Type);
	*/
	return false;   //FAKE   /ELiZ}
}

bool AAGP_ChatHandler::AcceptBroadcastLocalized(APlayerController* Receiver, AActor* Sender, ALocalMessage*  Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* obj)
{
	/*
	if ((Receiver != nullptr) && (Receiver.ChatManager != nullptr))
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
	if ((Receiver != nullptr) && (Receiver.ChatManager != nullptr))
	{
		bResult = Receiver.ChatManager.AcceptSpeech(SenderPRI);
		if (bDebug)
		{
			Log("AcceptBroadcastSpeech() Receiver:" + FString::FromInt(Receiver.Name) @ "Sender:" + SenderPRI.PlayerName @ "Allowed:" + FString::FromInt(bResult), 'ChatManager');
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
			Log("AcceptBroadcastSpeech() Receiver:" + FString::FromInt(Receiver.Name) @ "Receiver.ChatManager:" + FString::FromInt(Receiver.ChatManager), 'ChatManager');
		}
	}
	return Super::AcceptBroadcastSpeech(Receiver, SenderPRI);
	*/
	return false;   //FAKE   /ELiZ
}

bool AAGP_ChatHandler::AcceptBroadcastVoice(APlayerController* Receiver, AAA2_PlayerState* Sender)
{
	/*
	if ((Receiver != nullptr) && (Receiver.ChatManager != nullptr))
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

