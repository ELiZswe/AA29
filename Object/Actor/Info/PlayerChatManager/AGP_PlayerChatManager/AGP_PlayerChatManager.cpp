// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/PlayerChatManager/AGP_PlayerChatManager/AGP_PlayerChatManager.h"

AAGP_PlayerChatManager::AAGP_PlayerChatManager()
{

}

static const int32 NOTEXT = 1;
static const int32 NOSPEECH = 2;
static const int32 NOVOICE = 4;
static const int32 BANNED = 8;

void AAGP_PlayerChatManager::ChatDebug()
{
	int32 i = 0;
	/*
	for (i = 0; i < StoredChatRestrictions.Length; i++)
	{
		Log("   StoredChatRestrictions[" $ string(i) $ "] Hash:" $ StoredChatRestrictions[i].PlayerHash @ "Restriction:" $ string(StoredChatRestrictions[i].Restriction));
	}
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		LogChatRestriction(i);
	}
	*/
}

void AAGP_PlayerChatManager::LogChatRestriction(int32 i)
{
	//Log("   ChatRestrictions[" $ string(i) $ "] PlayerID:" $ string(ChatRestrictions[i].PlayerID) @ "Hash:" $ ChatRestrictions[i].PlayerHash @ "Address:" $ ChatRestrictions[i].PlayerAddress @ "Mask:" $ string(ChatRestrictions[i].PlayerVoiceMask) @ "Restriction:" $ string(ChatRestrictions[i].Restriction));
}

bool AAGP_PlayerChatManager::LoadChatBan(FString PlayerHash, uint8& OutRestriction)
{
	int32 i = 0;
	/*
	for (i = 0; i < StoredChatRestrictions.Length; i++)
	{
		if (StoredChatRestrictions[i].PlayerHash == PlayerHash)
		{
			OutRestriction = StoredChatRestrictions[i].Restriction;
			return true;
		}
	}
	*/
	return false;
}

void AAGP_PlayerChatManager::StoreChatBan(FString PlayerHash, uint8 Restriction)
{
	int32 i = 0;
	/*
	for (i = 0; i < StoredChatRestrictions.Length; i++)
	{
		if (StoredChatRestrictions[i].PlayerHash == PlayerHash)
		{
		}
	}
	if (i == StoredChatRestrictions.Length)
	{
		if (Restriction == 0)
		{
			return;
		}
		StoredChatRestrictions.Length = (i + 1);
	}
	else
	{
		if (Restriction == 0)
		{
			StoredChatRestrictions.remove(i, 1);
			return;
		}
	}
	Log("StoreChatBan PlayerHash:" $ PlayerHash @ "Restriction:" $ string(Restriction), "ChatManager");
	StoredChatRestrictions[i].PlayerHash = PlayerHash;
	StoredChatRestrictions[i].Restriction = Restriction;
	*/
}

void AAGP_PlayerChatManager::ReceiveBanInfo(FString S)
{
	TArray<FString> Arr = {};
	int32 PlayerID = 0;
	FString PlayerHash = "";
	FString PlayerAddress = "";
	/*
	Log(string(Name) @ "ReceiveBanInfo S:" $ S, "ChatManager");
	Split(S, Chr(27), Arr);
	if (Arr.Length < 3)
	{
		Log("Error receiving ban info Arr.Length:" $ string(Arr.Length) @ S, "ChatManager");
		return;
	}
	PlayerID = int(Arr[0]);
	*/
	PlayerHash = Arr[1];
	PlayerAddress = Arr[2];
	TrackNewPlayer(PlayerID, PlayerHash, PlayerAddress);
}

void AAGP_PlayerChatManager::TrackNewPlayer(int32 PlayerID, FString PlayerHash, FString PlayerAddress)
{
	int32 i = 0;
	AAA2_PlayerState* PRI = nullptr;
	uint8 NewRestriction = 0;
	/*
	if (PlayerOwner == nullptr)
	{
		Log(string(Name) @ "Couldn't update server tracking - No PlayerOwner!", "ChatManager");
		return;
	}
	Log(string(Name) @ "___________________TrackNewPlayer PlayerID:" $ string(PlayerID) @ "PlayerHash:" $ PlayerHash @ "PlayerAddress:" $ PlayerAddress, "ChatManager");
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		if (ChatRestrictions[i].PlayerID == PlayerID)
		{
		}
	}
	if (i == ChatRestrictions.Length)
	{
		ChatRestrictions.Length = (ChatRestrictions.Length + 1);
	}
	if ((Role < 4) && LoadChatBan(PlayerHash, NewRestriction))
	{
		PlayerOwner.ServerChatRestriction(PlayerID, NewRestriction);
	}
	else
	{
		if ((Level.NetMode == NM_ListenServer) && (PlayerOwner == Level.GetLocalPlayerController()))
		{
			LoadChatBan(PlayerHash, NewRestriction);
		}
	}
	ChatRestrictions[i].PlayerID = PlayerID;
	ChatRestrictions[i].PlayerHash = PlayerHash;
	ChatRestrictions[i].PlayerAddress = PlayerAddress;
	ChatRestrictions[i].Restriction = NewRestriction;
	PRI = PlayerOwner.GameReplicationInfo.FindPlayerByID(PlayerID);
	if (PRI != nullptr)
	{
		ChatRestrictions[i].PlayerVoiceMask = PRI.VoiceID;
	}
	*/
}

void AAGP_PlayerChatManager::UnTrackPlayer(int32 PlayerID)
{
	int32 i = 0;
	/*
	Log("Untrack player:" $ string(PlayerID), "ChatManager");
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		if (ChatRestrictions[i].PlayerID == PlayerID)
		{
			ChatRestrictions.remove(i, 1);
			return;
		}
	}
	Log("Untrack player couldn't find restriction for PlayerID:" $ string(PlayerID), "ChatManager");
	*/
}

bool AAGP_PlayerChatManager::AcceptText(AAA2_PlayerState* Sender, FString& Msg, FName Type)
{
	int32 i = 0;
	/*
	if (Sender == nullptr)
	{
		return Super::AcceptText(Sender, Msg, Type);
	}
	i = GetIDIndex(Sender.PlayerID);
	if (!IsValid(i))
	{
		return true;
	}
	Log(string(Name) @ "Owner:" $ PlayerOwner.PlayerReplicationInfo.PlayerName @ "Restriction for Index " $ string(i) $ ":" $ string(ChatRestrictions[i].Restriction), "ChatManager");
	return (!bool((ChatRestrictions[i].Restriction & 1)));
	*/
	return false;     //FAKE   /ELiZ
}

bool AAGP_PlayerChatManager::AcceptSpeech(AAA2_PlayerState* SenderPRI)
{
	int32 i = 0;
	if (SenderPRI == nullptr)
	{
		//return Super::AcceptSpeech(SenderPRI);
	}
	//i = GetIDIndex(SenderPRI.PlayerID);
	if (!IsValid(i))
	{
		return true;
	}
	//return (!bool((ChatRestrictions[i].Restriction & 2)));
	return false;     //FAKE   /ELiZ
}

bool AAGP_PlayerChatManager::AcceptVoice(AAA2_PlayerState* SenderPRI)
{
	int32 i = 0;
	if (SenderPRI == nullptr)
	{
		//return Super::AcceptVoice(SenderPRI);
	}
	//i = GetIDIndex(SenderPRI.PlayerID);
	if (!IsValid(i))
	{
		return true;
	}
	//return (!bool((ChatRestrictions[i].Restriction & 4)));
	return false;     //FAKE   /ELiZ
}

bool AAGP_PlayerChatManager::IsBanned(AAA2_PlayerState* PRI)
{
	int32 i = 0;
	FString PlayerHash = "";
	/*
	PlayerHash = PlayerController(PRI.Owner).GetPlayerIDHash();
	Log(string(Name) @ "IsBanned() PRI:" $ string(PRI.Name), "ChatManager");
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		if (ChatRestrictions[i].PlayerHash == PlayerHash)
		{
			Log(string(Name) @ "IsBanned() found matching PlayerHash for" @ PlayerHash $ ":" $ string(i) @ "Restriction:" $ string(ChatRestrictions[i].Restriction), "ChatManager");
			return bool((ChatRestrictions[i].Restriction & 8));
		}
	}
	return Super::IsBanned(PRI);
	*/
	return false;     //FAKE   /ELiZ
}

bool AAGP_PlayerChatManager::SetRestriction(FString PlayerHash, uint8 Type)
{
	int32 i = 0;
	i = GetHashIndex(PlayerHash);
	/*
	Log(string(Name) @ "SetRestriction PlayerHash:" $ PlayerHash @ "i:" $ string(i) @ "Type:" $ string(Type), "ChatManager");
	if (!IsValid(i))
	{
		if (Type == 0)
		{
			return false;
		}
		i = ChatRestrictions.Length;
		ChatRestrictions.Length = (i + 1);
	}
	else
	{
		if (ChatRestrictions[i].Restriction == Type)
		{
			return false;
		}
	}
	ChatRestrictions[i].Restriction = Type;
	if (IsLocal())
	{
		StoreChatBan(PlayerHash, Type);
		SaveConfig();
	}
	*/
	return true;
}

bool AAGP_PlayerChatManager::SetRestrictionID(int32 PlayerID, uint8 Type)
{
	FString PlayerHash = "";
	//Log(string(Name) @ "SetRestrictionID PlayerID:" $ string(PlayerID) @ "Type:" $ string(Type), "ChatManager");
	PlayerHash = GetPlayerHash(PlayerID);
	if (PlayerHash == "")
	{
		return false;
	}
	return SetRestriction(PlayerHash, Type);
}

bool AAGP_PlayerChatManager::AddRestriction(FString PlayerHash, uint8 Type)
{
	return MergeRestriction(GetHashIndex(PlayerHash), Type);
}

bool AAGP_PlayerChatManager::AddRestrictionID(int32 PlayerID, uint8 Type)
{
	return AddRestriction(GetPlayerHash(PlayerID), Type);
}

bool AAGP_PlayerChatManager::ClearRestriction(FString PlayerHash, uint8 Type)
{
	return UnMergeRestriction(GetHashIndex(PlayerHash), Type);
}

bool AAGP_PlayerChatManager::ClearRestrictionID(int32 PlayerID, uint8 Type)
{
	return ClearRestriction(GetPlayerHash(PlayerID), Type);
}

bool AAGP_PlayerChatManager::MergeRestriction(int32 Index, uint8 NewType)
{
	if (!IsValid(Index))
	{
		return false;
	}
	//ChatRestrictions[Index].Restriction = byte((ChatRestrictions[Index].Restriction & (~NewType)));
	//ChatRestrictions[Index].Restriction = byte((ChatRestrictions[Index].Restriction | NewType));
	if (IsLocal())
	{
		//StoreChatBan(ChatRestrictions[Index].PlayerHash, ChatRestrictions[Index].Restriction);
		//SaveConfig();
	}
	return true;
}

bool AAGP_PlayerChatManager::UnMergeRestriction(int32 Index, uint8 NewType)
{
	if (!IsValid(Index))
	{
		return false;
	}
	/*
	if (!bool((ChatRestrictions[Index].Restriction & NewType)))
	{
		return false;
	}
	ChatRestrictions[Index].Restriction = byte((ChatRestrictions[Index].Restriction & (~NewType)));
	if (IsLocal())
	{
		StoreChatBan(ChatRestrictions[Index].PlayerHash, ChatRestrictions[Index].Restriction);
		SaveConfig();
	}
	*/
	return true;
}

uint8 AAGP_PlayerChatManager::GetPlayerRestriction(int32 PlayerID)
{
	int32 i = 0;
	i = GetIDIndex(PlayerID);
	if (!IsValid(i))
	{
		//return Super::GetPlayerRestriction(PlayerID);
	}
	//return ChatRestrictions[i].Restriction;
	return 0;   //FAKE   /ELiZ
}

bool AAGP_PlayerChatManager::ClientIsBanned(FString PlayerHash)
{
	int32 i = 0;
	if (PlayerHash == "")
	{
		return true;
	}
	/*
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		if (ChatRestrictions[i].PlayerHash == PlayerHash)
		{
			return bool((ChatRestrictions[i].Restriction & 8));
		}
	}
	return Super::ClientIsBanned(PlayerHash);
	*/
	return false;   //FAKE   /ELiZ
}

FString AAGP_PlayerChatManager::GetPlayerHash(int32 PlayerID)
{
	int32 i = 0;
	if (PlayerID < 1)
	{
		return "";
	}
	/*
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		Log(string(Name) @ "GetPlayerHash Match:" $ string(PlayerID) @ "Test[" $ string(i) $ "]:" $ string(ChatRestrictions[i].PlayerID));
		if (ChatRestrictions[i].PlayerID == PlayerID)
		{
			return ChatRestrictions[i].PlayerHash;
		}
	}
	*/
	return "";
}

int32 AAGP_PlayerChatManager::GetIDIndex(int32 PlayerID)
{
	int32 i = 0;
	if (PlayerID < 1)
	{
		return -1;
	}
	/*
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		if (ChatRestrictions[i].PlayerID == PlayerID)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 AAGP_PlayerChatManager::GetHashIndex(FString PlayerHash)
{
	int32 i = 0;
	if (PlayerHash == "")
	{
		return -1;
	}
	/*
	for (i = 0; i < ChatRestrictions.Length; i++)
	{
		if (ChatRestrictions[i].PlayerHash == PlayerHash)
		{
			return i;
		}
	}
	*/
	return -1;
}

bool AAGP_PlayerChatManager::IsValid(int32 i)
{
	//return ((i >= 0) && (i < ChatRestrictions.Length));
	return false;    //FAKE   /ELiZ
}

bool AAGP_PlayerChatManager::IsLocal()
{
	//return ((Level.NetMode == NM_Client) || (((Level.NetMode == NM_ListenServer) && (PlayerOwner != nullptr)) && (PlayerOwner == Level.GetLocalPlayerController())));
	return false;    //FAKE   /ELiZ
}

int32 AAGP_PlayerChatManager::Count()
{
	return ChatRestrictions.Num();
}
