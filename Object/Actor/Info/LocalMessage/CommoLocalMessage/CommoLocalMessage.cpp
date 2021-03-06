// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "AA29/AA2_PlayerState.h"

ACommoLocalMessage::ACommoLocalMessage()
{
	_Animations.SetNum(32);
	_Sounds3.SetNum(32);
	_Sounds2.SetNum(32);
	_Sounds1.SetNum(32);
	_Messages.SetNum(32);
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
	float Volume = 0;
	float Distance = 0;
	float fallOff = 0;
	float TravelDistance = 0;
	USoundBase* MySound = nullptr;
	AActor* SoundTarget = nullptr;
	FString ConsoleMsg;
	/*
	if (p == nullptr || p.bIgnoreRadioMessages && Default.Class == 'CommoRadio' || Default.Class == 'CommoSquad' || Default.Class == 'CommoEventRadio')
	{
		return;
	}
	MySound = GetSound(Switch, RelatedPRI_1, p.PlayerReplicationInfo);
	if (!p.MyHUD.bMessageBeep || !Default.bBeep && IsBeepSound(MySound))
	{
		MySound = nullptr;
	}
	if (MySound != nullptr)
	{
		if (p.Pawn != nullptr)
		{
			SoundTarget = p.Pawn;
		}
		else
		{
			if (p.ViewTarget != nullptr)
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
				if (!SoundTarget.FastTrace(SoundTarget->GetActorLocation(), RelatedPRI_1.GetPawnLocation()))
				{
					Volume *= 0.5;
				}
			}
			else
			{
				SoundTarget = nullptr;
			}
		}
		if (SoundTarget != nullptr)
		{
			SoundTarget.PlayOwnedSound(MySound, 5, Volume, , , , false, Default.bNo3D);
		}
	}
	p.MyHUD.LocalizedMessage(Default.Class, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (Default.bIsConsoleMessage && p.Player != nullptr && p.Player.Console != nullptr && p.PlayerReplicationInfo.IsFriend(RelatedPRI_1))
	{
		ConsoleMsg = GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, ExtraText);
		if (ConsoleMsg != "")
		{
			p.Player.Console.Message(ConsoleMsg, Default.Lifetime);
		}
	}
	*/
}

float ACommoLocalMessage::GetTravelDistance(AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI)
{
	if (SenderPRI == nullptr || LocalPRI == nullptr)
	{
		return - 1;
	}
	else
	{
		if (SenderPRI->IsEnemy(LocalPRI,nullptr))
		{
			return GetDefault<ACommoLocalMessage>()->_fEnemyTravelDistance;
		}
		else
		{
			return GetDefault<ACommoLocalMessage>()->_fTravelDistance;
		}
	}
}

int32 ACommoLocalMessage::GetNumMessages()
{
	return _iNumMessages;
}

FString ACommoLocalMessage::GetMessage(int32 Index)
{
	/*
	if (Index < 0 || Index >= Default._iMaxMessages)
	{
		return "";
	}
	else
	{
		return Default._Messages[Index];
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString ACommoLocalMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	FString retval = "";
	/*
	retval = GetMessage(Switch);
	if (retval != "")
	{
		if (Switch == 31 && retval ~= "Medic!")
		{
			if (RelatedPRI_1 != nullptr && Len(RelatedPRI_1.GetLocationName()) > 0)
			{
				retval = retval + " Help needed at " + RelatedPRI_1.GetLocationName();
			}
			else
			{
				if (Len(ExtraText) > 0)
				{
					retval = retval + " Help needed at " + ExtraText;
				}
			}
		}
		if (Switch == 29 && retval ~= "Medic on the way!")
		{
			if (RelatedPRI_1 != nullptr && Len(RelatedPRI_1.GetLocationName()) > 0)
			{
				retval = retval + "  I am at " + RelatedPRI_1.GetLocationName();
			}
			else
			{
				if (Len(ExtraText) > 0)
				{
					retval = retval + "  I am at " + ExtraText;
				}
			}
		}
		retval = retval + Default.Punctuation;
		if (RelatedPRI_1 != nullptr)
		{
			retval = RelatedPRI_1.PlayerName @ Default.Messaged + ": """ + retval + """";
		}
		else
		{
			retval = Default.Messaged + ": """ + retval + """";
		}
		if (ExtraText != "")
		{
			retval = retval @ "[" + ExtraText + "]";
		}
	}
	*/
	return retval;
}

bool ACommoLocalMessage::IsBeepSound(USoundBase* SoundToTest)
{
	//return SoundToTest == Sound'commo_keymicrophone';
	return false;    //FAKE   /ELiZ
}

USoundBase* ACommoLocalMessage::GetSound(int32 Switch, AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI)
{
	/*
	if (Switch < 0 || Switch >= Default._iMaxMessages)
	{
		return nullptr;
	}
	else
	{
		if (SenderPRI != nullptr)
		{
			if (SenderPRI.IsEnemy(LocalPRI) && !SenderPRI.Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
			{
				return Default._Sounds3[Switch];
			}
			else
			{
				if (SenderPRI.IsSquadLeader())
				{
					return Default._Sounds1[Switch];
				}
				else
				{
					return Default._Sounds2[Switch];
				}
			}
		}
		else
		{
			return Default._Sounds2[Switch];
		}
	}
	*/
	return nullptr;    //FAKE  /ELiZ
}

FName ACommoLocalMessage::GetAnim(int32 Switch)
{
	if (Switch < 0 || Switch >= GetDefault<ACommoLocalMessage>()->_iNumMessages)
	{
		return "None";
	}
	return GetDefault<ACommoLocalMessage>()->_Animations[Switch];
}

FString ACommoLocalMessage::GetMessageTypeName()
{
	return GetDefault<ACommoLocalMessage>()->_messagename;
}

ECommoType ACommoLocalMessage::GetType()
{
	return GetDefault<ACommoLocalMessage>()->_commotype;
}
