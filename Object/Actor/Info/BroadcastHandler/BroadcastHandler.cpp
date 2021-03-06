// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/BroadcastHandler/BroadcastHandler.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetInfo.h"

ABroadcastHandler::ABroadcastHandler()
{
	BHDescText.SetNum(2);
	BHDisplayText.SetNum(2);
	BHDisplayText = { "Mute Spectators","Partition Spectators" };
	BHDescText = { "Check this option to prevent spectators from chatting during the game.","Check this option to separate spectator chat from player chat." };
}

//const CHATLOGLEVEL_DISABLED = 0;
//const CHATLOGLEVEL_CHATONLY = 1;
//const CHATLOGLEVEL_ADMINACTION = 2;
//const CHATLOGLEVEL_SYSTEM = 3;
//const BHPROPNUM = 2;

//native Function WriteChatLog(FString sChatText);
void ABroadcastHandler::WriteChatLog(FString sChatText)
{

}

void ABroadcastHandler::UpdateSentText()
{
	SentText = 0;
}

void ABroadcastHandler::FillPlayInfo(APlayInfo* PlayInfo)
{
	/*
	Super::FillPlayInfo(PlayInfo);
	PlayInfo.AddSetting(Default.ChatGroup, "bMuteSpectators", Default.BHDisplayText[0], 0, 1, "Check", , , true, true);
	PlayInfo.AddSetting(Default.ChatGroup, "bPartitionSpectators", Default.BHDisplayText[1], 1, 1, "Check", , , true, true);
	if (Default.NextBroadcastHandlerClass != nullptr)
	{
		Default.NextBroadcastHandlerClass.FillPlayInfo(PlayInfo);
		PlayInfo.PopClass();
	}
	*/
}

FString ABroadcastHandler::GetDescriptionText(FString PropName)
{
	/*
	switch (PropName)
	{
	case "bMuteSpectators":
		return Default.BHDescText[0];
	case "bPartitionSpectators":
		return Default.BHDescText[1];
	default:
		return Super::GetDescriptionText(PropName);
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

bool ABroadcastHandler::AllowsBroadcast(AActor* broadcaster, int32 Len)
{
	/*
	if (((bMuteSpectators && (Cast<APlayerController>(broadcaster) != nullptr)) && (!PlayerController(broadcaster).PlayerReplicationInfo.bAdmin)) && (Cast<APlayerController>(broadcaster).PlayerReplicationInfo.bOnlySpectator || PlayerController(broadcaster).PlayerReplicationInfo.bOutOfLives))
	{
		return false;
	}
	(SentText += Len);
	if ((NextBroadcastHandler != nullptr) && (!NextBroadcastHandler.HandlerAllowsBroadcast(broadcaster, SentText)))
	{
		return false;
	}
	return ((Level.Pauser != nullptr) || (SentText < 200));
	*/
	return false;    //FAKE   /ELiZ
}

bool ABroadcastHandler::HandlerAllowsBroadcast(AActor* broadcaster, int32 SentTextNum)
{
	/*
	if (NextBroadcastHandler != nullptr)
	{
		return NextBroadcastHandler.HandlerAllowsBroadcast(broadcaster, SentTextNum);
	}
	*/
	return true;
}

void ABroadcastHandler::BroadcastText(AAA2_PlayerState* SenderPRI, APlayerController* Receiver, FString Msg, FName Type)
{
	/*
	if (!AcceptBroadcastText(Receiver, SenderPRI, Msg, Type))
	{
		return;
	}
	if (NextBroadcastHandler != nullptr)
	{
		NextBroadcastHandler.BroadcastText(SenderPRI, Receiver, Msg, Type);
	}
	else
	{
		Receiver.TeamMessage(SenderPRI, Msg, Type);
	}
	*/
}

void ABroadcastHandler::BroadcastLocalized(AActor* Sender, APlayerController* Receiver, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	if (!AcceptBroadcastLocalized(Receiver, Sender, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject))
	{
		return;
	}
	if (NextBroadcastHandler != nullptr)
	{
		NextBroadcastHandler.BroadcastLocalized(Sender, Receiver, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	}
	else
	{
		if (Receiver != nullptr)
		{
			Receiver.ReceiveLocalizedMessage(Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, ExtraText);
		}
	}
	*/
}

void ABroadcastHandler::Broadcast(AActor* Sender, FString Msg, FName Type)
{
	AController* C = nullptr;
	APlayerController* p = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	/*
	if (! AllowsBroadcast(Sender,Len(Msg)))
	{
		return;
	}
	if (Cast<APawn>(Sender) != nullptr)
	{
		PRI=Pawn(Sender).PlayerReplicationInfo;
	}
	else
	{
		if (Cast<AController>(Sender) != nullptr)
		{
			PRI=Controller(Sender).PlayerReplicationInfo;
		}
	}
	if ((((bPartitionSpectators && (! Level.Game.bGameEnded)) && (PRI != nullptr)) && (! PRI.bAdmin)) && (PRI.bOnlySpectator || PRI.bOutOfLives))
	{
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			p=Cast<APlayerController>(C);
			if ((p != nullptr) && (p.PlayerReplicationInfo.bOnlySpectator || p.PlayerReplicationInfo.bOutOfLives))
			{
				BroadcastText(PRI,p,Msg,Type);
			}
		}
	}
	else
	{
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			p=Cast<APlayerController>(C);
			if (p != nullptr)
			{
				BroadcastText(PRI,p,Msg,Type);
			}
		}
	}
	if (iLogChatLevel >= 3)
	{
		WriteChatLog("System (System): " + Msg);
	}
	if (_LogTarget != nullptr)
	{
		_LogTarget.WriteLog("TEXT:" + Msg);
	}
	*/
}

void ABroadcastHandler::WritePRIChatLog(AAA2_PlayerState* priSender, FString sMsg, FName Type)
{
	/*
	if (bLogChats && (iLogChatLevel >= 1))
	{
		if (priSender != nullptr)
		{
			if (Type != "None")
			{
				if (priSender.bAdmin)
				{
					WriteChatLog(priSender.PlayerName + " (Admin/Team:" + FString::FromInt(priSender.TeamID) + ") (" + FString::FromInt(Type) + "): " + sMsg);
				}
				else
				{
					WriteChatLog(priSender.PlayerName + " (Team:" + FString::FromInt(priSender.TeamID) + ") (" + FString::FromInt(Type) + "): " + sMsg);
				}
			}
			else
			{
				WriteChatLog(priSender.PlayerName + ": " + sMsg);
			}
		}
		else
		{
			WriteChatLog("System (" + FString::FromInt(Type) + "):" + sMsg);
		}
	}
	*/
}

void ABroadcastHandler::BroadcastTeam(AController* Sender, FString Msg, FName Type)
{
	AController* C = nullptr;
	APlayerController* p = nullptr;
	/*
	if (! AllowsBroadcast(Sender,Len(Msg)))
	{
		return;
	}
	if ((((bPartitionSpectators && (! Level.Game.bGameEnded)) && (Sender != nullptr)) && (! Sender.PlayerReplicationInfo.bAdmin)) && (Sender.PlayerReplicationInfo.bOnlySpectator || Sender.PlayerReplicationInfo.bOutOfLives))
	{
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			p=Cast<APlayerController>(C);
			if (((p != nullptr) && (p.PlayerReplicationInfo.Team == Sender.PlayerReplicationInfo.Team)) && (p.PlayerReplicationInfo.bOnlySpectator || p.PlayerReplicationInfo.bOutOfLives))
			{
				BroadcastText(Sender.PlayerReplicationInfo,p,Msg,Type);
			}
		}
	}
	else
	{
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			p=Cast<APlayerController>(C);
			if ((p != nullptr) && (p.PlayerReplicationInfo.Team == Sender.PlayerReplicationInfo.Team))
			{
				BroadcastText(Sender.PlayerReplicationInfo,p,Msg,Type);
			}
		}
	}
	if (iLogChatLevel >= 3)
	{
		WriteChatLog(Msg);
	}
	if (_LogTarget != nullptr)
	{
		_LogTarget.WriteLog("TEAMTEXT:" + Msg);
	}
	*/
}

void ABroadcastHandler::BroadcastTeamByIndex(uint8 TeamIndex, FString Msg, FName Type)
{
}

void ABroadcastHandler::BroadcastLocalizedTeamByIndex(uint8 TeamIndex, AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
}

void ABroadcastHandler::AllowBroadcastLocalized(AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
	AController* C = nullptr;
	APlayerController* p = nullptr;
	/*
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		p=Cast<APlayerController>(C);
		if (p != nullptr)
		{
			BroadcastLocalized(Sender,p,Message,Switch,RelatedPRI_1,RelatedPRI_2,OptionalObject);
		}
	}
	*/
}

void ABroadcastHandler::RegisterBroadcastHandler(ABroadcastHandler* NewBH)
{
	/*
	if (NextBroadcastHandler == nullptr)
	{
		NextBroadcastHandler = NewBH;
		Default.NextBroadcastHandlerClass = NewBH.Class;
	}
	else
	{
		NextBroadcastHandler.RegisterBroadcastHandler(NewBH);
	}
	*/
}

bool ABroadcastHandler::AcceptBroadcastText(APlayerController* Receiver, AAA2_PlayerState* SenderPRI, FString& Msg, FName Type)
{
	/*
	if (NextBroadcastHandler != nullptr)
	{
		return NextBroadcastHandler.AcceptBroadcastText(Receiver, SenderPRI, Msg, Type);
	}
	*/
	return true;
}

bool ABroadcastHandler::AcceptBroadcastLocalized(APlayerController* Receiver, AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* obj)
{
	/*
	if (NextBroadcastHandler != nullptr)
	{
		return NextBroadcastHandler.AcceptBroadcastLocalized(Receiver, Sender, Message, Switch, RelatedPRI_1, RelatedPRI_2, obj);
	}
	*/
	return true;
}

bool ABroadcastHandler::AcceptBroadcastSpeech(APlayerController* Receiver, AAA2_PlayerState* SenderPRI)
{
	/*
	if (NextBroadcastHandler != nullptr)
	{
		return NextBroadcastHandler.AcceptBroadcastSpeech(Receiver, SenderPRI);
	}
	*/
	return true;
}

bool ABroadcastHandler::AcceptBroadcastVoice(APlayerController* Receiver, AAA2_PlayerState* SenderPRI)
{
	/*
	if (NextBroadcastHandler != nullptr)
	{
		return NextBroadcastHandler.AcceptBroadcastVoice(Receiver, SenderPRI);
	}
	*/
	return true;
}

void ABroadcastHandler::Destroyed()
{
	/*
	Default.NextBroadcastHandlerClass = nullptr;
	Super::Destroyed();
	*/
}

void ABroadcastHandler::SetLogTarget(AInternetInfo* iinfo)
{
	/*
	Log("BroadcastHander::SetLogTarget(" + FString::FromInt(iinfo) + ")");
	_LogTarget = iinfo;
	*/
}
