// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"

ACommoLocalMessage::ACommoLocalMessage()
{
	Punctuation = ".";
		Messaged = "said";
		_iMaxMessages = 32;
		_messagename = "Default";
		_fSoundVolume = 0.5;
		_fTravelDistance = -1;
		_fEnemyTravelDistance = -1;
		_commotype = ECommoType::COMMOTYPE_Shout;
		bFadeMessage = true;
		bBeep = true;
		Lifetime = 4;
}



void ACommoLocalMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	local float Volume;
	local float Distance;
	local float fallOff;
	local float TravelDistance;
	local Sound MySound;
	local Actor SoundTarget;
	local string ConsoleMsg;
	if (p == None || p.bIgnoreRadioMessages && Default.Class == 'CommoRadio' || Default.Class == 'CommoSquad' || Default.Class == 'CommoEventRadio')
	{
		Return;
	}
	MySound = GetSound(Switch, RelatedPRI_1, p.PlayerReplicationInfo);
	if (!p.MyHUD.bMessageBeep || !Default.bBeep && IsBeepSound(MySound))
	{
		MySound = None;
	}
	if (MySound != None)
	{
		if (p.Pawn != None)
		{
			SoundTarget = p.Pawn;
		}
		else
		{
			if (p.ViewTarget != None)
			{
				SoundTarget = p.ViewTarget;
			}
			else
			{
				SoundTarget = p;
			}
		}
		Volume = Default._fSoundVolume;
		TravelDistance = GetTravelDistance(RelatedPRI_1, p.PlayerReplicationInfo);
		if (TravelDistance > -1)
		{
			Distance = VSize(SoundTarget.Location - RelatedPRI_1.GetPawnLocation());
			if (Distance < TravelDistance)
			{
				fallOff = TravelDistance - Distance / TravelDistance;
				Volume *= fallOff;
				if (!SoundTarget.FastTrace(SoundTarget.Location, RelatedPRI_1.GetPawnLocation()))
				{
					Volume *= 0.5;
				}
			}
			else
			{
				SoundTarget = None;
			}
		}
		if (SoundTarget != None)
		{
			SoundTarget.PlayOwnedSound(MySound, 5, Volume, , , , False, Default.bNo3D);
		}
	}
	p.MyHUD.LocalizedMessage(Default.Class, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (Default.bIsConsoleMessage && p.Player != None && p.Player.Console != None && p.PlayerReplicationInfo.IsFriend(RelatedPRI_1))
	{
		ConsoleMsg = GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, ExtraText);
		if (ConsoleMsg != "")
		{
			p.Player.Console.Message(ConsoleMsg, Default.Lifetime);
		}
	}
	*/
}
void ACommoLocalMessage::GetTravelDistance(AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI)
{
	/*
	if (SenderPRI == None || LocalPRI == None)
	{
		Return - 1;
	}
	else
	{
		if (SenderPRI.IsEnemy(LocalPRI))
		{
			Return Default._fEnemyTravelDistance;
		}
		else
		{
			Return Default._fTravelDistance;
		}
	}
	*/
}
void ACommoLocalMessage::GetNumMessages()
{
	/*
	Return _iNumMessages;
	*/
}
void ACommoLocalMessage::GetMessage(int32 Index)
{
	/*
	if (Index < 0 || Index >= Default._iMaxMessages)
	{
		Return "";
	}
	else
	{
		Return Default._Messages[Index];
	}
	*/
}
void ACommoLocalMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	local string retval;
	retval = GetMessage(Switch);
	if (retval != "")
	{
		if (Switch == 31 && retval ~= "Medic!")
		{
			if (RelatedPRI_1 != None && Len(RelatedPRI_1.GetLocationName()) > 0)
			{
				retval = retval $ " Help needed at " $ RelatedPRI_1.GetLocationName();
			}
			else
			{
				if (Len(ExtraText) > 0)
				{
					retval = retval $ " Help needed at " $ ExtraText;
				}
			}
		}
		if (Switch == 29 && retval ~= "Medic on the way!")
		{
			if (RelatedPRI_1 != None && Len(RelatedPRI_1.GetLocationName()) > 0)
			{
				retval = retval $ "  I am at " $ RelatedPRI_1.GetLocationName();
			}
			else
			{
				if (Len(ExtraText) > 0)
				{
					retval = retval $ "  I am at " $ ExtraText;
				}
			}
		}
		retval = retval $ Default.Punctuation;
		if (RelatedPRI_1 != None)
		{
			retval = RelatedPRI_1.PlayerName @ Default.Messaged $ ": """ $ retval $ """";
		}
		else
		{
			retval = Default.Messaged $ ": """ $ retval $ """";
		}
		if (ExtraText != "")
		{
			retval = retval @ "[" $ ExtraText $ "]";
		}
	}
	Return retval;
	*/
}
void ACommoLocalMessage::IsBeepSound(USoundBase* SoundToTest)
{
	/*
	Return SoundToTest == Sound'commo_keymicrophone';
	*/
}
void ACommoLocalMessage::GetSound(int32 Switch, AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI)
{
	/*
	if (Switch < 0 || Switch >= Default._iMaxMessages)
	{
		Return None;
	}
	else
	{
		if (SenderPRI != None)
		{
			if (SenderPRI.IsEnemy(LocalPRI) && !SenderPRI.Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
			{
				Return Default._Sounds3[Switch];
			}
			else
			{
				if (SenderPRI.IsSquadLeader())
				{
					Return Default._Sounds1[Switch];
				}
				else
				{
					Return Default._Sounds2[Switch];
				}
			}
		}
		else
		{
			Return Default._Sounds2[Switch];
		}
	}
	*/
}
void ACommoLocalMessage::GetAnim(int32 Switch)
{
	/*
	if (Switch < 0 || Switch >= Default._iNumMessages)
	{
		Return 'None';
	}
	Return Default._Animations[Switch];
	*/
}
void ACommoLocalMessage::GetMessageTypeName()
{
	//Return Default._messagename;
}
void ACommoLocalMessage::GetType()
{
	//Return Default._commotype;
}
