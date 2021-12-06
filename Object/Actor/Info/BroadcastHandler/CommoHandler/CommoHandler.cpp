// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/BroadcastHandler/CommoHandler/CommoHandler.h"

ACommoHandler::ACommoHandler()
{
	iShoutDistance = 3200;
	iWhisperDistance = 320;
}

void ACommoHandler::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	agpgame = AGP_GameInfo(Level.Game);
	*/
}

void ACommoHandler::UpdateSentText()
{
	/*
	local Controller C;
	SentText = 0;
	_numTextUpdates++;
	if (_numTextUpdates < 10)
	{
		return;
	}
	_numTextUpdates = 0;
	C = Level.ControllerList;
	if (C != None)
	{
		if (C.IsA('HumanController'))
		{
			HumanController(C).CommoSentText = 0;
			HumanController(C).iTour = 0;
		}
		C = C.nextController;
	}
	*/
}

bool ACommoHandler::AllowsBroadcast(AActor* broadcaster, int32 Len)
{
	/*
	local HumanController HC;
	if (broadcaster == None)
	{
		return false;
	}
	HC = HumanController(broadcaster);
	if (HC != None)
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
				(HC.CommoSentText += Max(20, Len));
				return (HC.CommoSentText < 200);
			}
		}
	}
	else
	{
		if (broadcaster.IsA('GameInfo'))
		{
			return true;
		}
		else
		{
			(SentText += Len);
			DebugLog(DEBUG_Warn, "CommoHandler::AllowsBroadcast()	Unknown broadcaster! " $ string(broadcaster) @ string(SentText));
			return (SentText < 260);
		}
	}
	*/
	return false;   //FAKE   /EliZ
}

void ACommoHandler::AllowBroadcastLocalized(AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_playerState* RelatedPRI_1, AAA2_playerState* RelatedPRI_2, UObject* OptionalObject)
{
	/*
	local PlayerController p;
	local Pawn SenderPawn;
	local Pawn IteratedPawn;
	local Pawn.ECommoType CType;
	local PlayerReplicationInfo PRI;
	float CommoDistance = 0;
	FString report_location = "";
	if (Sender == None)
	{
		return;
	}
	if (!AllowsBroadcast(Sender, Len(Message.GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject))))
	{
		return;
	}
	SenderPawn = None;
	if (Sender.IsA('Pawn'))
	{
		PRI = Pawn(Sender).PlayerReplicationInfo;
		SenderPawn = Pawn(Sender);
	}
	else
	{
		if (Sender.IsA('PlayerController'))
		{
			PRI = PlayerController(Sender).PlayerReplicationInfo;
			if ((Controller(Sender) != None) && (Controller(Sender).Pawn != None))
			{
				SenderPawn = Controller(Sender).Pawn;
			}
		}
		else
		{
			if (_LogTarget != None)
			{
				_LogTarget.WriteLog("System message: " @ Message.GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject));
			}
			Super::AllowBroadcastLocalized(Sender, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
			return;
		}
	}
	if (PRI == None)
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
	if ((Message != None) && (class<CommoLocalMessage>(Message) != None))
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
		if (SenderPawn != None)
		{
			ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, CommoDistance)
			{
				if ((IteratedPawn.Controller != None) && (!IteratedPawn.Controller.IsA('PlayerController')))
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
			if ((IteratedPawn != None) && ((IteratedPawn.IsA('AGP_Pawn') && (!IteratedPawn.bIsDead)) || ((((Vehicle(IteratedPawn) != None) && (Vehicle(IteratedPawn).Driver != None)) && Vehicle(IteratedPawn).Driver.IsA('AGP_Pawn')) && (!Vehicle(IteratedPawn).Driver.bIsDead))))
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
	/*
	local PlayerController p;
	local PlayerReplicationInfo PRI;
	local Pawn SenderPawn;
	local Pawn IteratedPawn;
	if (Sender == None)
	{
		Sender = Level.Game;
	}
	if (!AllowsBroadcast(Sender, Len(Msg)))
	{
		return;
	}
	SenderPawn = None;
	if (Sender.IsA('Pawn'))
	{
		PRI = Pawn(Sender).PlayerReplicationInfo;
		SenderPawn = Pawn(Sender);
	}
	else
	{
		if (Sender.IsA('PlayerController'))
		{
			PRI = PlayerController(Sender).PlayerReplicationInfo;
			if (Controller(Sender).Pawn != None)
			{
				SenderPawn = PlayerController(Sender).Pawn;
			}
		}
		else
		{
			if (Sender.IsA('GameInfo'))
			{
				if (_LogTarget != None)
				{
					_LogTarget.WriteLog("System message: " @ Msg);
				}
				Super::Broadcast(Sender, Msg, Type);
				return;
			}
			else
			{
				DebugLog(DEBUG_Warn, "CommoHandler::Broadcast()	Received message from unknown Sender(" @ string(Sender) @ ") Message(" @ Msg @ ") Type(" @ string(Type) @ ")");
			}
		}
	}
	if (_LogTarget != None)
	{
		_LogTarget.WriteLog(PRI.PlayerName @ "said:" @ Msg);
	}
	if ((Type == 'Center') || (Type == 'Event'))
	{
		if ((PRI != None) && (!PRI.SuperUser()))
		{
			Type = 'Say';
		}
	}
	else
	{
		if (Type == 'AdminSay')
		{
			if ((PRI != None) && (!PRI.Administrator()))
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
			if ((PRI != None) && (!PRI.SuperUser()))
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
		if (((PRI != None) && PRI.isDead()) || ((!Level.Game.IsInState('MatchInProgress')) && (!Level.Game.IsInState('DelayedMatchInProgress'))))
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
			if (SenderPawn != None)
			{
				if (agpgame.IsTeamGame())
				{
					ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, float(iWhisperDistance))
					{
						if (IteratedPawn.bIsDead || (!IteratedPawn.Controller.IsA('PlayerController')))
						{
							continue;
						}
						if ((IteratedPawn.PlayerReplicationInfo != None) && IteratedPawn.PlayerReplicationInfo.IsFriend(PRI))
						{
							BroadcastText(PRI, PlayerController(IteratedPawn.Controller), Msg, Type);
						}
						BroadcastLocalized(SenderPawn, PlayerController(IteratedPawn.Controller), class'AGP.CommoWhisper', class'AGP.CommoWhisper'.Default.MsgStatic, PRI, None, None);
					}
				}
				else
				{
					ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, float(iWhisperDistance))
					{
						if (!IteratedPawn.Controller.IsA('PlayerController'))
						{
							continue;
						}
						BroadcastText(PRI, PlayerController(IteratedPawn.Controller), Msg, Type);
						BroadcastLocalized(SenderPawn, PlayerController(IteratedPawn.Controller), class'AGP.CommoWhisper', class'AGP.CommoWhisper'.Default.MsgStatic, PRI, None, None);
					}
				}
			}
			else
			{
				if (agpgame.IsTeamGame())
				{
					ForEach DynamicActors(Class'PlayerController', p)
					{
						if ((p.PlayerReplicationInfo != None) && p.PlayerReplicationInfo.IsFriend(PRI))
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
			if (SenderPawn != None)
			{
				ForEach SenderPawn.RadiusActors(Class'Pawn', IteratedPawn, float(iShoutDistance))
				{
					if (IteratedPawn.Controller == None)
					{
						continue;
					}
					if (!IteratedPawn.Controller.IsA('PlayerController'))
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
						if ((IteratedPawn != None) && (IteratedPawn.IsA('AGP_Pawn') || (((Vehicle(IteratedPawn) != None) && (Vehicle(IteratedPawn).Driver != None)) && Vehicle(IteratedPawn).Driver.IsA('AGP_Pawn'))))
						{
							if (p.PlayerReplicationInfo.IsFriend(PRI))
							{
								BroadcastText(PRI, p, Msg, Type);
							}
							BroadcastLocalized(SenderPawn, p, class'AGP.CommoEventRadio', class'AGP.CommoEventRadio'.Default.MsgStatic, PRI, None, None);
						}
					}
				}
				else
				{
					ForEach DynamicActors(Class'PlayerController', p)
					{
						IteratedPawn = p.Pawn;
						if ((IteratedPawn != None) && (IteratedPawn.IsA('AGP_Pawn') || (((Vehicle(IteratedPawn) != None) && (Vehicle(IteratedPawn).Driver != None)) && Vehicle(IteratedPawn).Driver.IsA('AGP_Pawn'))))
						{
							BroadcastText(PRI, p, Msg, Type);
							BroadcastLocalized(SenderPawn, p, class'AGP.CommoEventRadio', class'AGP.CommoEventRadio'.Default.MsgStatic, PRI, None, None);
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
	/*
	local PlayerController p;
	ForEach DynamicActors(Class'PlayerController', p)
	{
		if (p.PlayerReplicationInfo.Team.TeamIndex == TeamIndex)
		{
			BroadcastText(None, p, Msg, Type);
		}
	}
	if (_LogTarget != None)
	{
		_LogTarget.WriteLog(Msg);
	}
	*/
}

void ACommoHandler::BroadcastLocalizedTeamByIndex(uint8 TeamIndex, AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_playerState* RelatedPRI_1, AAA2_playerState* RelatedPRI_2, UObject* OptionalObject)
{
	/*
	local PlayerController p;
	ForEach DynamicActors(Class'PlayerController', p)
	{
		if (p.PlayerReplicationInfo.Team.TeamIndex == TeamIndex)
		{
			BroadcastLocalized(Sender, p, Message, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
		}
	}
	*/
}