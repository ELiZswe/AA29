// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/BroadcastHandler/CommoHandler/CommoHandler.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoEventRadio/CommoEventRadio.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoWhisper/CommoWhisper.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

ACommoHandler::ACommoHandler()
{
	iShoutDistance = 3200;
	iWhisperDistance = 320;
}

void ACommoHandler::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	agpgame = Cast<AAGP_GameInfo>(GetGameMode());
	*/
}

void ACommoHandler::UpdateSentText()
{
	/*
	AController* C = nullptr;
	SentText=0;
	_numTextUpdates ++;
	if (_numTextUpdates < 10)
	{
		return;
	}
	_numTextUpdates=0;
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if (C->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(C).CommoSentText=0;
			Cast<AHumanController>(C).iTour=0;
		}

	*/
}

bool ACommoHandler::AllowsBroadcast(AActor* broadcaster, int32 Len)
{
	/*
	AHumanController* HC = nullptr;
	if (broadcaster == nullptr)
	{
		return false;
	}
	HC = Cast<AHumanController>(broadcaster);
	if (HC != nullptr)
	{
		if (HC.PlayerReplicationInfo.bAdmin || HC.PlayerReplicationInfo.SuperUser())
		{
			return true;
		}
		else
		{
			if (bMuteSpectators && HC.PlayerReplicationInfo.bOnlySpectator)
			{
				return false;
			}
			else
			{
				if (Len == 0)
				{
					HC.iTour++;
					if (HC.iTour > 20)
					{
						Level.Game.AccessControl.Kick(HC.GetHumanReadableName(), "ROE");
						return false;
					}
				}
				(HC.CommoSentText += FMath::Max(20, Len));
				return (HC.CommoSentText < 200);
			}
		}
	}
	else
	{
		if (broadcaster->IsA(AGameInfo::StaticClass()))
		{
			return true;
		}
		else
		{
			(SentText += Len);
			DebugLog(DEBUG_Warn, "CommoHandler::AllowsBroadcast()	Unknown broadcaster! " + FString::FromInt(broadcaster) @ FString::FromInt(SentText));
			return (SentText < 260);
		}
	}
	*/
	return false;   //FAKE   /EliZ
}

void ACommoHandler::AllowBroadcastLocalized(AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_playerState* RelatedPRI_1, AAA2_playerState* RelatedPRI_2, UObject* OptionalObject)
{
	APlayerController* p = nullptr;
	APawn* SenderPawn = nullptr;
	APawn* IteratedPawn = nullptr;
	ECommoType CType = ECommoType::COMMOTYPE_Hand;
	AAA2_PlayerState* PRI = nullptr;
	float CommoDistance = 0;
	FString report_location = "";
	/*
	if (Sender == nullptr)
	{
		return;
	}
	if (!AllowsBroadcast(Sender, Len(Message.GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject))))
	{
		return;
	}
	SenderPawn = nullptr;
	if (Sender->IsA(APawn::StaticClass()))
	{
		PRI = Cast<APawn>(Sender).PlayerReplicationInfo;
		SenderPawn = Cast<APawn>(Sender);
	}
	else
	{
		if (Sender->IsA(APlayerController::StaticClass()))
		{
			PRI = Cast<APlayerController>(Sender).PlayerReplicationInfo;
			if ((Cast<AController>(Sender) != nullptr) && (Cast<AController>(Sender).Pawn != nullptr))
			{
				SenderPawn = Cast<AController>(Sender).Pawn;
			}
		}
		else
		{
			if (_LogTarget != nullptr)
			{
				_LogTarget.WriteLog("System message: " @ Message.GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject));
			}
			Super::AllowBroadcastLocalized(Sender, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
			return;
		}
	}
	if (PRI == nullptr)
	{
		return;
	}
	if (PRI.isDead())
	{
		return;
	}
	if (Message.ReportLocation(Switch))
	{
		report_location = PRI.GetLocationName();
	}
	if ((Message != nullptr) && (class<CommoLocalMessage>(Message) != nullptr))
	{
		CType = class<CommoLocalMessage>(Message).GetType();
	}
	else
	{
		return;
	}
	switch (CType)
	{
	case 0:
		break;
	case 1:
	case 2:
		if (CType == 1)
		{
			CommoDistance = float(iWhisperDistance);
		}
		else
		{
			CommoDistance = float(iShoutDistance);
		}
		if (SenderPawn != nullptr)
		{
			ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, CommoDistance)
			{
				if ((IteratedPawn.Controller != nullptr) && (!IteratedPawn.Controller->IsA(APlayerController::StaticClass())))
				{
					continue;
				}
				BroadcastLocalized(Sender, PlayerController(IteratedPawn.Controller), Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, report_location);
			}
		}
		else
		{
			ForEach DynamicActors(Class'PlayerController', p)
			{
				BroadcastLocalized(Sender, p, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, report_location);
			}
		}
		GOTO JL0483;
	case 3:
	case 4:
		ForEach DynamicActors(Class'PlayerController', p)
		{
			IteratedPawn = p.Pawn;
			if ((IteratedPawn != nullptr) && ((IteratedPawn->IsA(AAGP_Pawn::StaticClass()) && (!IteratedPawn.bIsDead)) || ((((Cast<AVehicle>(IteratedPawn) != nullptr) && (Cast<AVehicle>(IteratedPawn).Driver != nullptr)) && Vehicle(IteratedPawn).Driver->IsA(AAGP_Pawn::StaticClass())) && (!Vehicle(IteratedPawn).Driver.bIsDead))))
			{
				BroadcastLocalized(Sender, p, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, report_location);
			}
		}
		GOTO JL0483;
	case 5:
	default:
		ForEach DynamicActors(Class'PlayerController', p)
		{
			BroadcastLocalized(Sender, p, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, report_location);
		}
		GOTO JL0483;
	JL0483:
	}
	*/
}

void ACommoHandler::Broadcast(AActor* Sender, FString Msg, FName Type)
{
	APlayerController* p = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	APawn* SenderPawn = nullptr;
	APawn* IteratedPawn = nullptr;
	/*
	if (Sender == nullptr)
	{
		Sender = Level.Game;
	}
	if (!AllowsBroadcast(Sender, Len(Msg)))
	{
		return;
	}
	SenderPawn = nullptr;
	if (Sender->IsA(APawn::StaticClass()))
	{
		PRI = Cast<APawn>(Sender).PlayerReplicationInfo;
		SenderPawn = Cast<APawn>(Sender);
	}
	else
	{
		if (Sender->IsA(APlayerController::StaticClass()))
		{
			PRI = Cast<APlayerController>(Sender).PlayerReplicationInfo;
			if (Cast<AController>(Sender).Pawn != nullptr)
			{
				SenderPawn = Cast<APlayerController>(Sender).Pawn;
			}
		}
		else
		{
			if (Sender->IsA(AGameInfo::StaticClass()))
			{
				if (_LogTarget != nullptr)
				{
					_LogTarget.WriteLog("System message: " @ Msg);
				}
				Super::Broadcast(Sender, Msg, Type);
				return;
			}
			else
			{
				DebugLog(DEBUG_Warn, "CommoHandler::Broadcast()	Received message from unknown Sender(" @ FString::FromInt(Sender) @ ") Message(" @ Msg @ ") Type(" @ FString::FromInt(Type) @ ")");
			}
		}
	}
	if (_LogTarget != nullptr)
	{
		_LogTarget.WriteLog(PRI.PlayerName @ "said:" @ Msg);
	}
	if ((Type == 'Center') || (Type == 'Event'))
	{
		if ((PRI != nullptr) && (!PRI.SuperUser()))
		{
			Type = 'Say';
		}
	}
	else
	{
		if (Type == 'AdminSay')
		{
			if ((PRI != nullptr) && (!PRI.Administrator()))
			{
				Type = 'Say';
			}
			else
			{
			}
		}
		else
		{
	else
	{
		if (Type == 'DevSay')
		{
			if ((PRI != nullptr) && (!PRI.SuperUser()))
			{
				Type = 'Say';
			}
			else
			{
				Type = 'AdminSay';
			}
		}
	}
		}
	else
	{
		WritePRIChatLog(PRI, Msg, Type);
		if (((PRI != nullptr) && PRI.isDead()) || ((!Level.Game.IsInState('MatchInProgress')) && (!Level.Game.IsInState('DelayedMatchInProgress'))))
		{
			if (Type != 'TeamSay')
			{
				Type = 'Say';
			}
			ForEach DynamicActors(Class'PlayerController', p)
			{
				if (p.PlayerReplicationInfo.isDead() || (!Level.Game.IsInState('MatchInProgress')))
				{
					if ((Type != 'TeamSay') || p.PlayerReplicationInfo.IsFriend(PRI))
					{
						BroadcastText(PRI, p, Msg, Type);
					}
				}
			}
			return;
		}
		if (Type == 'TeamSay')
		{
			Type = 'Radio';
		}
		if (Type == 'Whisper')
		{
			if (SenderPawn != nullptr)
			{
				if (agpgame.IsTeamGame())
				{
					ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, float(iWhisperDistance))
					{
						if (IteratedPawn.bIsDead || (!IteratedPawn.Controller->IsA(APlayerController::StaticClass())))
						{
							continue;
						}
						if ((IteratedPawn.PlayerReplicationInfo != nullptr) && IteratedPawn.PlayerReplicationInfo.IsFriend(PRI))
						{
							BroadcastText(PRI, PlayerController(IteratedPawn.Controller), Msg, Type);
						}
						BroadcastLocalized(SenderPawn, PlayerController(IteratedPawn.Controller), ACommoWhisper::StaticClass(), ACommoWhisper::StaticClass().Default.MsgStatic, PRI, None, None);
					}
				}
				else
				{
					ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, float(iWhisperDistance))
					{
						if (!IteratedPawn.Controller->IsA(APlayerController::StaticClass()))
						{
							continue;
						}
						BroadcastText(PRI, PlayerController(IteratedPawn.Controller), Msg, Type);
						BroadcastLocalized(SenderPawn, PlayerController(IteratedPawn.Controller), ACommoWhisper::StaticClass(), ACommoWhisper::StaticClass().Default.MsgStatic, PRI, None, None);
					}
				}
			}
			else
			{
				if (agpgame.IsTeamGame())
				{
					ForEach DynamicActors(Class'PlayerController', p)
					{
						if ((p.PlayerReplicationInfo != nullptr) && p.PlayerReplicationInfo.IsFriend(PRI))
						{
							BroadcastText(PRI, p, Msg, Type);
						}
					}
				}
				else
				{
				}
			}
		else
		{
			return;
		}
		if (Type == 'shout')
		{
			if (SenderPawn != nullptr)
			{
				ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, float(iShoutDistance))
				{
					if (IteratedPawn.Controller == nullptr)
					{
						continue;
					}
					if (!IteratedPawn.Controller->IsA(APlayerController::StaticClass()))
					{
						continue;
					}
					BroadcastText(PRI, PlayerController(IteratedPawn.Controller), Msg, Type);
				}
			}
			else
			{
			}
			return;
		}
		else
		{
			if (((Type == 'Radio') || (Type == 'Squad')) || (Type == 'ReportIn'))
			{
				if (agpgame.IsTeamGame())
				{
					ForEach DynamicActors(Class'PlayerController', p)
					{
						IteratedPawn = p.Pawn;
						if ((IteratedPawn != nullptr) && (IteratedPawn->IsA(AAGP_Pawn::StaticClass()) || (((Cast<AVehicle>(IteratedPawn) != nullptr) && (Cast<AVehicle>(IteratedPawn).Driver != nullptr)) && Vehicle(IteratedPawn).Driver->IsA(AAGP_Pawn::StaticClass()))))
						{
							if (p.PlayerReplicationInfo.IsFriend(PRI))
							{
								BroadcastText(PRI, p, Msg, Type);
							}
							BroadcastLocalized(SenderPawn, p, ACommoEventRadio::StaticClass(), ACommoEventRadio::StaticClass().Default.MsgStatic, PRI, None, None);
						}
					}
				}
				else
				{
					ForEach DynamicActors(Class'PlayerController', p)
					{
						IteratedPawn = p.Pawn;
						if ((IteratedPawn != nullptr) && (IteratedPawn->IsA(AAGP_Pawn::StaticClass()) || (((Cast<AVehicle>(IteratedPawn) != nullptr) && (Cast<AVehicle>(IteratedPawn).Driver != nullptr)) && Vehicle(IteratedPawn).Driver->IsA(AAGP_Pawn::StaticClass()))))
						{
							BroadcastText(PRI, p, Msg, Type);
							BroadcastLocalized(SenderPawn, p, ACommoEventRadio::StaticClass(), ACommoEventRadio::StaticClass().Default.MsgStatic, PRI, None, None);
						}
					}
				}
				return;
			}
		}
		}
	}
	}
	ForEach DynamicActors(Class'PlayerController', p)
	{
		BroadcastText(PRI, p, Msg, Type);
	}
	WritePRIChatLog(PRI, Msg, Type);
	*/
}

void ACommoHandler::BroadcastTeamByIndex(uint8 TeamIndex, FString Msg, FName Type)
{
	APlayerController* p = nullptr;
	/*
	ForEach DynamicActors(Class'PlayerController', p)
	{
		if (p.PlayerReplicationInfo.Team.TeamIndex == TeamIndex)
		{
			BroadcastText(None, p, Msg, Type);
		}
	}
	if (_LogTarget != nullptr)
	{
		_LogTarget.WriteLog(Msg);
	}
	*/
}

void ACommoHandler::BroadcastLocalizedTeamByIndex(uint8 TeamIndex, AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_playerState* RelatedPRI_1, AAA2_playerState* RelatedPRI_2, UObject* OptionalObject)
{
	APlayerController* p = nullptr;
	/*
	ForEach DynamicActors(Class'PlayerController', p)
	{
		if (p.PlayerReplicationInfo.Team.TeamIndex == TeamIndex)
		{
			BroadcastLocalized(Sender, p, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
		}
	}
	*/
}
