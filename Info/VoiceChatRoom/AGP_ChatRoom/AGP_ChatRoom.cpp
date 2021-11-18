// All the original content belonged to the US Army


#include "AA29/Info/VoiceChatRoom/AGP_ChatRoom/AGP_ChatRoom.h"

AAGP_ChatRoom::AAGP_ChatRoom()
{

}

void AAGP_ChatRoom::SetGRI(AGameReplicationInfo* InGRI)
{
	//GRI = InGRI;
}

void AAGP_ChatRoom::Timer()
{
	/*
	if (Owner == None)
	{
		if (VoiceChatManager != None)
		{
			VoiceChatManager.bRefresh = true;
		}
		Destroy();
		Return;
	}
	*/
}
void AAGP_ChatRoom::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	if (GRI == None)
	{
		ForEach DynamicActors(Class'GameReplicationInfo', GRI)
		{
		}
	}
	SetTimer(1, True);
	*/
}

void AAGP_ChatRoom::GetMask()
{
	/*
	if (IsPrivateChannel())
	{
		Return PlayerReplicationInfo(Owner).VoiceMemberMask;
	}
	else
	{
		if (VoiceChatReplicationInfo(Owner) != None)
		{
			Return VoiceChatReplicationInfo(Owner).GetMask(Self);
		}
	}
	Return Super::GetMask();
	*/
}

void AAGP_ChatRoom::GetTitle()
{
	/*
	if (IsPrivateChannel())
	{
		Return PlayerReplicationInfo(Owner).PlayerName;
	}
	else
	{
		if (VoiceChatReplicationInfo(Owner) != None)
		{
			Return VoiceChatReplicationInfo(Owner).GetTitle(Self);
		}
	}
	Return Super::GetTitle();
	*/
}
void AAGP_ChatRoom::GetTeam()
{
	/*
	if (IsPrivateChannel())
	{
		if (PlayerReplicationInfo(Owner).Team == None)
		{
			Return GetTeam();
		}
		Return PlayerReplicationInfo(Owner).Team.TeamIndex;
	}
	else
	{
		if (VoiceChatReplicationInfo(Owner) != None)
		{
			Return GetTeam();
		}
	}
	*/
}

FString AAGP_ChatRoom::GetPassword()
{
	return Password;
}

TArray<AAA2_PlayerState*> AAGP_ChatRoom::GetMembers()
{
	TArray<AAA2_PlayerState*> PRIArray = {};
	/*
	local int i;
	if (GRI != None && ValidMask())
	{
		for (i = 0; i < GRI.PRIArray.Length; i++)
		{
			if (IsMember(GRI.PRIArray[i]))
			{
				PRIArray[PRIArray.Length] = GRI.PRIArray[i];
			}
		}
	}
	*/
	return PRIArray;
}

bool AAGP_ChatRoom::IsPublicChannel()
{
	//Return ChannelIndex != Default.ChannelIndex && ChannelIndex < 2;
	return false;    //FAKE   /ELiZ
}

bool AAGP_ChatRoom::IsPrivateChannel()
{
	//Return PlayerReplicationInfo(Owner) != None;
	return false;    //FAKE   /ELiZ
}

int32 AAGP_ChatRoom::Count()
{
	int32 X=0;
	/*
	local int i;
	local int MemberMask;
	if (!ValidMask())
	{
		Return 0;
	}
	MemberMask = GetMask();
	for (i = 0; i < 32; i++)
	{
		if (MemberMask & 1 << i)
		{
			X++;
		}
	}
	*/
	return X;
}

bool AAGP_ChatRoom::IsFull()
{
	//Return GetMaxChatters() > 0 && Count() >= GetMaxChatters();
	return false;    //FAKE   /ELiZ
}
bool AAGP_ChatRoom::IsMember(AAA2_PlayerState* PRI, bool bNoCascade)
{
	/*
	if (IsMember(PRI, bNoCascade))
	{
		Return True;
	}
	if (!ValidMask())
	{
		Return False;
	}
	if (PRI == None || PRI.VoiceID == 255)
	{
		Return False;
	}
	Return GetMask() & 1 << PRI.VoiceID;
	*/
	return false;    //FAKE   /ELiZ
}
void AAGP_ChatRoom::CanJoinChannel(AAA2_PlayerState* PRI)
{
	/*
	if (PRI == None)
	{
		Log(GetTitle() @ "CanJoinChannel PRI: None returning false", 'VoiceChat');
		Return False;
	}
	if (Owner == None)
	{
		Log(GetTitle() @ "CanJoinChannel PRI:" $ PRI.PlayerName @ "Owner: None returning false", 'VoiceChat');
		Return False;
	}
	if (IsPrivateChannel())
	{
		Return PlayerReplicationInfo(Owner).bOnlySpectator == PRI.bOnlySpectator;
	}
	else
	{
		if (PRI.bOnlySpectator)
		{
			Return False;
		}
	}
	Return CanJoinChannel(PRI);
	*/
}

int32 AAGP_ChatRoom::JoinChannel(AAA2_PlayerState* NewPRI, FString InPassword)
{
	/*
	local string str;
	if (NewPRI != None)
	{
		if (NewPRI.Team != None)
		{
			str = NewPRI.Team.TeamIndex;
		}
		else
		{
			str = "No Team";
		}
		Log(NewPRI.PlayerName $ "(" $ str $ ") joined channel" @ GetTitle() $ "(" $ GetTeam() $ ")", 'VoiceChat');
	}
	else
	{
		Log("Invalid player joined" @ GetTitle(), 'VoiceChat');
	}
	if (NewPRI == Owner)
	{
		Return 1;
	}
	if (IsMember(NewPRI))
	{
		Return 1;
	}
	str = GetPassword();
	if (str != "")
	{
		if (InPassword == "")
		{
			Return 2;
		}
		if (InPassword != str)
		{
			Return 3;
		}
	}
	if (IsBanned(NewPRI))
	{
		Return 4;
	}
	if (IsFull())
	{
		Return 5;
	}
	if (NewPRI.bOnlySpectator && !IsPrivateChannel() || !PlayerReplicationInfo(Owner).bOnlySpectator)
	{
		Return 6;
	}
	Return JoinChannel(NewPRI, Password);
	*/

	return 0;    //FAKE   /ELiZ
}

void AAGP_ChatRoom::LeaveChannel(AAA2_PlayerState* LeavingPRI)
{
	/*
	if (LeavingPRI == Owner)
	{
		Return False;
	}
	if (!IsMember(LeavingPRI, True))
	{
		Return False;
	}
	if (LeavingPRI != None)
	{
		Log(LeavingPRI.PlayerName @ "left channel" @ GetTitle(), 'VoiceChat');
	}
	else
	{
		Log("Invalid player left channel" @ GetTitle(), 'VoiceChat');
	}
	Return LeaveChannel(LeavingPRI);
	*/
}

void AAGP_ChatRoom::AddMember(AAA2_PlayerState* PRI)
{
	/*
	local int i;
	local array<AAA2_PlayerState*> Members;
	if (IsMember(PRI))
	{
		Return;
	}
	if (PRI == None || PRI.VoiceID == 255)
	{
		Return;
	}
	if (PRI.Team != None)
	{
		Log("Adding member" @ PRI.PlayerName @ "(" $ PRI.Team.TeamIndex $ ")" @ "to" @ GetTitle() @ "(" $ GetTeam() $ ")", 'VoiceChat');
	}
	else
	{
		Log("Adding member" @ PRI.PlayerName @ "( No Team ) to" @ GetTitle() @ "(" $ GetTeam() $ ")", 'VoiceChat');
	}
	if (Level.NetMode != 3)
	{
		Members = GetMembers();
		for (i = 0; i < Members.Length; i++)
		{
			if (Members[i] != None && PlayerController(Members[i].Owner) != None)
			{
				PlayerController(Members[i].Owner).ChatRoomMessage(11, ChannelIndex, PRI);
			}
		}
	}
	SetMask(GetMask() | 1 << PRI.VoiceID);
	AddMember(PRI);
	*/
}

void AAGP_ChatRoom::RemoveMember(AAA2_PlayerState* PRI)
{
	/*
	local array<AAA2_PlayerState*> Members;
	local int i;
	if (PRI != None && PRI.VoiceID != 255 && IsMember(PRI, True))
	{
		SetMask(GetMask() & ~1 << PRI.VoiceID);
		if (Level.NetMode != 3)
		{
			Members = GetMembers();
			for (i = 0; i < Members.Length; i++)
			{
				Log(Name @ "RemoveMember Members[" $ i $ "]:" $ Members[i].PlayerName, 'VoiceChat');
				if (Members[i] != None && PlayerController(Members[i].Owner) != None)
				{
					PlayerController(Members[i].Owner).ChatRoomMessage(12, ChannelIndex, PRI);
				}
			}
		}
	}
	RemoveMember(PRI);
	*/
}

bool AAGP_ChatRoom::IsBanned(AAA2_PlayerState* PRI)
{
	/*
	if (PRI == None || PlayerReplicationInfo(Owner) == None || PlayerController(Owner.Owner) == None || PlayerController(Owner.Owner).ChatManager == None)
	{
		Return False;
	}
	Return PlayerController(Owner.Owner).ChatManager.IsBanned(PRI);
	*/
	return false;    //FAKE   /ELiZ
}
void AAGP_ChatRoom::SetTeam(int32 NewTeam)
{
	/*
	if (VoiceChatReplicationInfo(Owner) == None)
	{
		Return;
	}
	SetTeam(NewTeam);
	*/
}

void AAGP_ChatRoom::SetMask(int32 NewMask)
{
	/*
	if (Owner == None)
	{
		Return;
	}
	if (IsPrivateChannel())
	{
		PlayerReplicationInfo(Owner).SetVoiceMemberMask(NewMask);
	}
	else
	{
		VoiceChatReplicationInfo(Owner).SetMask(Self, NewMask);
	}
	*/
}

void AAGP_ChatRoom::AddChild(AVoiceChatRoom* NewChild)
{
	/*
	local int i;
	if (NewChild == None)
	{
		Return False;
	}
	for (i = 0; i < Children.Length; i++)
	{
		if (Children[i] == NewChild)
		{
			Return False;
		}
	}
	NewChild.Parent = Self;
	Children[Children.Length] = NewChild;
	Return AddChild(NewChild);
	*/
}

void AAGP_ChatRoom::RemoveChild(AVoiceChatRoom* Child)
{
	/*
	local int i;
	for (i = Children.Length - 1; i >= 0; i--)
	{
		if (Children[i] == None)
		{
			Children.remove(i, 1);
		}
		else
		{
			if (Children[i] == Child)
			{
				Children.remove(i, 1);
				Return True;
			}
		}
	}
	Return Super::RemoveChild(Child);
	*/
}