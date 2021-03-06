// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/VoiceChatRoom/AGP_ChatRoom/AGP_ChatRoom.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"

AAGP_ChatRoom::AAGP_ChatRoom()
{

}

void AAGP_ChatRoom::SetGRI(AGameReplicationInfo* InGRI)
{
	//GRI = InGRI;
}

void AAGP_ChatRoom::Timer()
{
	if (GetOwner() == nullptr)
	{
		if (VoiceChatManager != nullptr)
		{
			VoiceChatManager->bRefresh = true;
		}
		Destroy();
		return;
	}
}
void AAGP_ChatRoom::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	if (GRI == nullptr)
	{
		ForEach DynamicActors(AGameReplicationInfo::StaticClass(), GRI)
		{
		}
	}
	SetTimer(1, true);
	*/
}

int32 AAGP_ChatRoom::GetMask()
{
	if (IsPrivateChannel())
	{
		return Cast<AAA2_PlayerState>(GetOwner())->VoiceMemberMask;
	}
	else
	{
		if (Cast<AVoiceChatReplicationInfo>(GetOwner()) != nullptr)
		{
			return Cast<AVoiceChatReplicationInfo>(GetOwner())->GetMask(this);
		}
	}
	return Super::GetMask();
}

FString AAGP_ChatRoom::GetTitle()
{
	if (IsPrivateChannel())
	{
		return Cast<AAA2_PlayerState>(GetOwner())->PlayerName;
	}
	else
	{
		if (Cast<AVoiceChatReplicationInfo>(GetOwner()) != nullptr)
		{
			return Cast<AVoiceChatReplicationInfo>(GetOwner())->GetTitle(this);
		}
	}
	return Super::GetTitle();
}

int32 AAGP_ChatRoom::GetTeam()
{
	if (IsPrivateChannel())
	{
		if (Cast<AAA2_PlayerState>(GetOwner())->Team == nullptr)
		{
			return GetTeam();
		}
		return Cast<AAA2_PlayerState>(GetOwner())->Team->TeamIndex;
	}
	else
	{
		if (Cast<AVoiceChatReplicationInfo>(GetOwner()) != nullptr)
		{
			return GetTeam();
		}
	}
	return 0;    //FAKE   /EliZ
}

FString AAGP_ChatRoom::GetPassword()
{
	return Password;
}

TArray<AAA2_PlayerState*> AAGP_ChatRoom::GetMembers()
{
	TArray<AAA2_PlayerState*> PRIArray = {};
	/*
	int32 i = 0;
	if (GRI != nullptr && ValidMask())
	{
		for (i = 0; i < GRI.PRIArray.Num(); i++)
		{
			if (IsMember(GRI.PRIArray[i]))
			{
				PRIArray[PRIArray.Num()] = GRI.PRIArray[i];
			}
		}
	}
	*/
	return PRIArray;
}

bool AAGP_ChatRoom::IsPublicChannel()
{
	//return ChannelIndex != Default.ChannelIndex && ChannelIndex < 2;
	return false;    //FAKE   /ELiZ
}

bool AAGP_ChatRoom::IsPrivateChannel()
{
	//returnCast<AAA2_PlayerState>(GetOwner()) != nullptr;
	return false;    //FAKE   /ELiZ
}

int32 AAGP_ChatRoom::Count()
{
	int32 X=0;
	/*
	int32 i = 0;
	int32 MemberMask;
	if (!ValidMask())
	{
		return 0;
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
	//return GetMaxChatters() > 0 && Count() >= GetMaxChatters();
	return false;    //FAKE   /ELiZ
}
bool AAGP_ChatRoom::IsMember(AAA2_PlayerState* PRI, bool bNoCascade)
{
	/*
	if (IsMember(PRI, bNoCascade))
	{
		return true;
	}
	if (!ValidMask())
	{
		return false;
	}
	if (PRI == nullptr || PRI.VoiceID == 255)
	{
		return false;
	}
	return GetMask() & 1 << PRI.VoiceID;
	*/
	return false;    //FAKE   /ELiZ
}

bool AAGP_ChatRoom::CanJoinChannel(AAA2_PlayerState* PRI)
{
	if (PRI == nullptr)
	{
		//Log(GetTitle() @ "CanJoinChannel PRI: nullptr returning false", "VoiceChat");
		return false;
	}
	if (GetOwner() == nullptr)
	{
		//Log(GetTitle() @ "CanJoinChannel PRI:" + PRI.PlayerName @ "Owner: nullptr returning false", "VoiceChat");
		return false;
	}
	if (IsPrivateChannel())
	{
		return (Cast<AAA2_PlayerState>(GetOwner())->IsOnlyASpectator() == PRI->IsOnlyASpectator());
	}
	else
	{
		if (PRI->IsOnlyASpectator())
		{
			return false;
		}
	}
	return Super::CanJoinChannel(PRI);
}

uint8 AAGP_ChatRoom::JoinChannel(AAA2_PlayerState* NewPRI, FString InPassword)
{
	/*
	FString str;
	if (NewPRI != nullptr)
	{
		if (NewPRI.Team != nullptr)
		{
			str = NewPRI.Team.TeamIndex;
		}
		else
		{
			str = "No Team";
		}
		Log(NewPRI.PlayerName + "(" + str + ") joined channel" @ GetTitle() + "(" + GetTeam() + ")", 'VoiceChat');
	}
	else
	{
		Log("Invalid player joined" @ GetTitle(), 'VoiceChat');
	}
	if (NewPRI == Owner)
	{
		return 1;
	}
	if (IsMember(NewPRI))
	{
		return 1;
	}
	str = GetPassword();
	if (str != "")
	{
		if (InPassword == "")
		{
			return 2;
		}
		if (InPassword != str)
		{
			return 3;
		}
	}
	if (IsBanned(NewPRI))
	{
		return 4;
	}
	if (IsFull())
	{
		return 5;
	}
	if (NewPRI.bOnlySpectator && !IsPrivateChannel() || !PlayerReplicationInfo(GetOwner())->bOnlySpectator)
	{
		return 6;
	}
	return JoinChannel(NewPRI, Password);
	*/

	return 0;    //FAKE   /ELiZ
}

bool AAGP_ChatRoom::LeaveChannel(AAA2_PlayerState* LeavingPRI)
{
	if (LeavingPRI == GetOwner())
	{
		return false;
	}
	if (!IsMember(LeavingPRI, true))
	{
		return false;
	}
	if (LeavingPRI != nullptr)
	{
		//Log(LeavingPRI.PlayerName @ "left channel" @ GetTitle(), "VoiceChat");
	}
	else
	{
		//Log("Invalid player left channel" @ GetTitle(), "VoiceChat");
	}
	return Super::LeaveChannel(LeavingPRI);
}

void AAGP_ChatRoom::AddMember(AAA2_PlayerState* PRI)
{
	int32 i = 0;
	TArray<AAA2_PlayerState*> Members = {};
	if (IsMember(PRI,false))
	{
		return;
	}
	/*
	if (PRI == nullptr || PRI.VoiceID == 255)
	{
		return;
	}
	if (PRI.Team != nullptr)
	{
		Log("Adding member" @ PRI.PlayerName @ "(" + PRI.Team.TeamIndex + ")" @ "to" @ GetTitle() @ "(" + GetTeam() + ")", 'VoiceChat');
	}
	else
	{
		Log("Adding member" @ PRI.PlayerName @ "( No Team ) to" @ GetTitle() @ "(" + GetTeam() + ")", 'VoiceChat');
	}
	if (GetNetMode() != ENetMode::NM_Client)
	{
		Members = GetMembers();
		for (i = 0; i < Members.Num(); i++)
		{
			if (Members[i] != nullptr && PlayerController(Members[i].Owner) != nullptr)
			{
				Cast<APlayerController>(Members[i].Owner).ChatRoomMessage(11, ChannelIndex, PRI);
			}
		}
	}
	SetMask(GetMask() | 1 << PRI.VoiceID);
	AddMember(PRI);
	*/
}

void AAGP_ChatRoom::RemoveMember(AAA2_PlayerState* PRI)
{
	TArray<AAA2_PlayerState*> Members = {};
	int32 i = 0;
	/*
	if (PRI != nullptr && PRI.VoiceID != 255 && IsMember(PRI, True))
	{
		SetMask(GetMask() & ~1 << PRI.VoiceID);
		if (GetNetMode() != ENetMode::NM_Client)
		{
			Members = GetMembers();
			for (i = 0; i < Members.Num(); i++)
			{
				Log(Name @ "RemoveMember Members[" + i + "]:" + Members[i].PlayerName, 'VoiceChat');
				if (Members[i] != nullptr && PlayerController(Members[i].Owner) != nullptr)
				{
					Cast<APlayerController>(Members[i].Owner).ChatRoomMessage(12, ChannelIndex, PRI);
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
	if (PRI == nullptr ||Cast<AAA2_PlayerState>(GetOwner()) == nullptr || PlayerController(Owner.Owner) == nullptr || PlayerController(Owner.Owner).ChatManager == nullptr)
	{
		return false;
	}
	return PlayerController(Owner.Owner).ChatManager.IsBanned(PRI);
	*/
	return false;    //FAKE   /ELiZ
}
void AAGP_ChatRoom::SetTeam(int32 NewTeam)
{
	/*
	if (Cast<AVoiceChatReplicationInfo>(GetOwner()) == nullptr)
	{
		return;
	}
	SetTeam(NewTeam);
	*/
}

void AAGP_ChatRoom::SetMask(int32 NewMask)
{
	/*
	if (Owner == nullptr)
	{
		return;
	}
	if (IsPrivateChannel())
	{
		PlayerReplicationInfo(GetOwner())->SetVoiceMemberMask(NewMask);
	}
	else
	{
		VoiceChatReplicationInfo(GetOwner())->SetMask(this, NewMask);
	}
	*/
}

bool AAGP_ChatRoom::AddChild(AVoiceChatRoom* NewChild)
{
	int32 i = 0;
	if (NewChild == nullptr)
	{
		return false;
	}
	for (i = 0; i < Children.Num(); i++)
	{
		if (Children[i] == NewChild)
		{
			return false;
		}
	}
	NewChild->Parent = this;
	Children.Add(NewChild);
	return Super::AddChild(NewChild);
}

bool AAGP_ChatRoom::RemoveChild(AVoiceChatRoom* Child)
{
	int32 i = 0;
	for (i = (Children.Num() - 1); i >= 0; i--)
	{
		if (Children[i] == nullptr)
		{
			Children.RemoveAt(i, 1);
		}
		else
		{
			if (Children[i] == Child)
			{
				Children.RemoveAt(i, 1);
				return true;
			}
		}
	}
	return Super::RemoveChild(Child);
}
