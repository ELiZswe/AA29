// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/AGP_VoiceChatReplicationInfo/AGP_VoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/BroadcastHandler/AGP_ChatHandler/AGP_ChatHandler.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/AGP_ChatRoom/AGP_ChatRoom.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "Engine/Canvas.h"

AAGP_VoiceChatReplicationInfo::AAGP_VoiceChatReplicationInfo()
{
	//ChatBroadcastClass = AAGP_ChatHandler::StaticClass();
	//ChatRoomClass = AAGP_ChatRoom::StaticClass();
	DefaultChannel = 1;
}

void AAGP_VoiceChatReplicationInfo::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	int32 i = 0;
	int32 j = 0;
	TArray<AVoiceChatRoom*> Rooms ={};
	TArray<AAA2_PlayerState*> Members = {};
	FString teamstring = "";
	/*
	Canvas.SetDrawColor(255, 220, 100, 230);
	Canvas.DrawText("VOICECHAT | bPrivateChat:" + FString::FromInt(bPrivateChat));
	Rooms = GetChannels();
	for (i = 0; i < Rooms.Num(); i++)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		if (Rooms[i] != nullptr)
		{
			Members = Rooms[i].GetMembers();
			Canvas.DrawText(" Name:" @ Rooms[i].GetTitle() @ "Members:" + FString::FromInt(Members.Num()) @ "  Index:" + FString::FromInt(Rooms[i].ChannelIndex) @ " Team:" + ATeamInfo::StaticClass().Default.ColorNames[Rooms[i].GetTeam()] @ " Mask:" + FString::FromInt(Rooms[i].GetMask()) @ " P:" + FString::FromInt(Rooms[i].IsPublicChannel()) @ " T:" + FString::FromInt(Rooms[i].IsTeamChannel()));
			for (j = 0; j < Members.Num(); j++)
			{
				YPos += YL;
				Canvas.SetPos(4, YPos);
				if (Members[j].Team == nullptr)
				{
					teamstring = "None";
				}
				else
				{
					teamstring = ATeamInfo::StaticClass().Default.ColorNames[Members[j].Team.TeamIndex];
				}
				Canvas.DrawText("          " + Members[j].PlayerName @ "ID:" + FString::FromInt(Members[j].PlayerID) @ "Mask:" + FString::FromInt(Members[j].VoiceID) @ "Team:" + teamstring);
			}
		}
		else
		{
			Canvas.DrawText("CHANNEL" @ FString::FromInt(i) @ "IS NONE!");
		}
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	*/
}

void AAGP_VoiceChatReplicationInfo::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (ChatBroadcastClass != nullptr)
	{
		ChatBroadcastHandler = Spawn(ChatBroadcastClass);
	}
	else
	{
		ChatBroadcastHandler = Spawn(AAGP_ChatHandler::StaticClass());
	}
	if (Level.Game.BroadcastHandler != nullptr)
	{
		Level.Game.BroadcastHandler.RegisterBroadcastHandler(ChatBroadcastHandler);
	}
	*/
}

void AAGP_VoiceChatReplicationInfo::PostNetBeginPlay()
{
	AAA2_PlayerState* PRI = nullptr;
	/*
	Log(string(Name) @ "___________________PostNetBeginPlay", "VoiceChat");
	Super::PostNetBeginPlay();
	ForEach DynamicActors(APlayerReplicationInfo::StaticClass(), PRI)
	{
		PRI.VoiceInfo = this;
	}
	*/
}

void AAGP_VoiceChatReplicationInfo::SetGRI(AGameReplicationInfo* NewGRI)
{
	GRI = NewGRI;
	//GRI.VoiceReplicationInfo = this;
}

void AAGP_VoiceChatReplicationInfo::InitChannels()
{
	AVoiceChatRoom* VCR = nullptr;
	/*
	Super::InitChannels();
	AddVoiceChannel();
	if (bAllowLocalBroadcast)
	{
		VCR = AddVoiceChannel();
		VCR.bLocal = true;
	}
	*/
}

void AAGP_VoiceChatReplicationInfo::AddVoiceChatter(AAA2_PlayerState* NewPRI)
{
	if (NewPRI == nullptr)
	{
		//Log("AddVoiceChatter() not executing: NewPRI is NONE!", "VoiceChat");
		return;
	}
	/*
	if ((((!bEnableVoiceChat) || NewPRI.bOnlySpectator) || NewPRI.bBot) || ((NewPRI.Owner != nullptr) && (Cast<AHumanController>(NewPRI.Owner) == nullptr)))
	{
		return;
	}
	Log("AddVoiceChatter:" + FString::FromInt(NewPRI) @ NewPRI.PlayerName @ FString::FromInt(NewPRI.VoiceID), "VoiceChat");
	AddVoiceChannel(NewPRI);
	*/
}

void AAGP_VoiceChatReplicationInfo::RemoveVoiceChatter(AAA2_PlayerState* PRI)
{
	APlayerController* PC = nullptr;
	if (PRI == nullptr)
	{
		return;
	}
	/*
	Log("RemoveVoiceChatter:" + FString::FromInt(PRI) @ PRI.PlayerName, "VoiceChat");
	if (Role < 4)
	{
		PC = Level.GetLocalPlayerController();
		if ((PC != nullptr) && (PC.ChatManager != nullptr))
		{
			PC.ChatManager.UnTrackPlayer(PRI.PlayerID);
		}
	}
	*/
	RemoveVoiceChannel(PRI);
}

bool AAGP_VoiceChatReplicationInfo::CanJoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 i = 0;
	/*
	if ((PRI != nullptr) && (PRI.Team != nullptr))
	{
		i = PRI.Team.TeamIndex;
	}
	VCR = GetChannel(ChannelTitle, i);
	if (VCR == nullptr)
	{
		return false;
	}
	return VCR.CanJoinChannel(PRI);
	*/
	return false;    //FAKE  /ELiZ
}

uint8 AAGP_VoiceChatReplicationInfo::JoinChannel(FString ChannelTitle, AAA2_PlayerState* PRI, FString Password)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 i = 0;
	/*
	if ((PRI != nullptr) && (PRI.Team != nullptr))
	{
		i = PRI.Team.TeamIndex;
	}
	VCR = GetChannel(ChannelTitle, i);
	if (VCR == nullptr)
	{
		return 0;
	}
	return VCR.JoinChannel(PRI, Password);
	*/
	return 0;     //FAKE   /ELiZ
}

uint8 AAGP_VoiceChatReplicationInfo::JoinChannelAt(int32 ChannelIndex, AAA2_PlayerState* PRI, FString Password)
{
	AVoiceChatRoom* VCR = nullptr;
	VCR = GetChannelAt(ChannelIndex);
	if (VCR == nullptr)
	{
		return 0;
	}
	//return VCR.JoinChannel(PRI, Password);
	return 0;     //FAKE   /ELiZ
}

bool AAGP_VoiceChatReplicationInfo::LeaveChannel(FString ChannelTitle, AAA2_PlayerState* PRI)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 i = 0;
	/*
	if ((PRI != nullptr) && (PRI.Team != nullptr))
	{
		i = PRI.Team.TeamIndex;
	}
	VCR = GetChannel(ChannelTitle, i);
	return VCR.LeaveChannel(PRI);
	*/
	return false;     //FAKE   /ELiZ
}

AVoiceChatRoom* AAGP_VoiceChatReplicationInfo::AddVoiceChannel(AAA2_PlayerState* PRI)
{
	int32 i = 0;
	int32 cnt = 0;
	AVoiceChatRoom* VCR = nullptr;
	/*
	Log(string(Name) @ "AddVoiceChannel PRI:" + FString::FromInt(PRI), "VoiceChat");
	VCR = CreateNewVoiceChannel(PRI);
	if (VCR != nullptr)
	{
		VCR.VoiceChatManager = this;
		i = Channels.Num();
		cnt = GetPublicChannelCount();
		if (PRI == nullptr)
		{
			VCR.ChannelIndex = i;
		}
		else
		{
			VCR.ChannelIndex = (cnt + PRI.PlayerID);
			PRI.PrivateChatRoom = VCR;
			VCR.AddMember(PRI);
		}
		for (i = 0; i < Channels.Num(); i++)
		{
			if ((Channels[i] != nullptr) && (Channels[i].ChannelIndex > VCR.ChannelIndex))
			{
			}
		}
		Channels.insert(i, 1);
		Channels[i] = VCR;
	}
	*/
	return VCR;
}

bool AAGP_VoiceChatReplicationInfo::RemoveVoiceChannel(AAA2_PlayerState* PRI)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 i = 0;
	/*
	if ((PRI != nullptr) && (GetRemoteRole() == ENetRole::ROLE_MAX))
	{
		PRI.ActiveChannel = -1;
	}
	for (i = (Channels.Num() - 1); i >= 0; i--)
	{
		if (Channels[i] != nullptr)
		{
			if (Channels[i].Owner == PRI)
			{
				VCR = Channels[i];
				Channels.RemoveAt(i, 1);
			}
			else
			{
				Channels[i].RemoveMember(PRI);
			}
		}
		else
		{
			Channels.RemoveAt(i, 1);
		}
	}
	if (VCR == nullptr)
	{
		return Super::RemoveVoiceChannel(PRI);
	}
	DestroyVoiceChannel(VCR);
	return Super::RemoveVoiceChannel(PRI);
	*/
	return false;     //FAKE   /ELiZ
}

AVoiceChatRoom* AAGP_VoiceChatReplicationInfo::GetChannel(FString ChatRoomName, int32 TeamIndex)
{
	int32 i = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if (((Channels[i] != nullptr) && (Channels[i].GetTitle() ~= ChatRoomName)) && (Channels[i].Owner != nullptr))
		{
			return Channels[i];
		}
	}
	return Super::GetChannel(ChatRoomName, TeamIndex);
	*/
	return nullptr;     //FAKE   /ELiZ
}

AVoiceChatRoom* AAGP_VoiceChatReplicationInfo::GetChannelAt(int32 Index)
{
	int32 i = 0;
	if (Index < 0)
	{
		return nullptr;
	}
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if (((Channels[i] != nullptr) && (Channels[i].ChannelIndex == Index)) && (Channels[i].Owner != nullptr))
		{
			return Channels[i];
		}
	}
	return Super::GetChannelAt(Index);
	*/
	return nullptr;     //FAKE   /ELiZ
}

TArray<int32> AAGP_VoiceChatReplicationInfo::GetChannelMembers(FString ChatRoomName, int32 TeamIndex)
{
	AVoiceChatRoom* Room = nullptr;
	TArray<AAA2_PlayerState*> Members = {};
	TArray<int32> MemberIds = {};
	int32 i = 0;
	Room = GetChannel(ChatRoomName, TeamIndex);
	if (Room != nullptr)
	{
		Members = Room->GetMembers();
		/*
		MemberIds.Num() = Members.Num();
		for (i = 0; i < Members.Num(); i++)
		{
			if (Members[i] != nullptr)
			{
				MemberIds[i] = Members[i].PlayerID;
			}
		}
		*/
	}
	return MemberIds;
}

TArray<int32> AAGP_VoiceChatReplicationInfo::GetChannelMembersAt(int32 Index)
{
	AVoiceChatRoom* Room = nullptr;
	TArray<AAA2_PlayerState*> Members;
	TArray<int32> MemberIds;
	int32 i = 0;
	Room = GetChannelAt(Index);
	if (Room != nullptr)
	{
		Members = Room->GetMembers();
		/*
		MemberIds.Num() = Members.Num();
		for (i = 0; i < Members.Num(); i++)
		{
			if (Members[i] != nullptr)
			{
				MemberIds[i] = Members[i].PlayerID;
			}
		}
		*/
	}
	return MemberIds;
}

TArray<int32> AAGP_VoiceChatReplicationInfo::GetMemberChannels(AAA2_PlayerState* PRI)
{
	TArray<int32> ChannelIndexArray;
	int32 i = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if ((Channels[i] != nullptr) && Channels[i].IsMember(PRI))
		{
			ChannelIndexArray[ChannelIndexArray.Num()] = Channels[i].ChannelIndex;
		}
	}
	*/
	return ChannelIndexArray;
}

TArray<AVoiceChatRoom*> AAGP_VoiceChatReplicationInfo::GetChannels()
{
	return Channels;
}

int32 AAGP_VoiceChatReplicationInfo::GetChannelCount()
{
	return Channels.Num();
}

int32 AAGP_VoiceChatReplicationInfo::GetChannelIndex(FString ChannelTitle, int32 TeamIndex)
{
	int32 i = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if ((Channels[i] != nullptr) && (Channels[i].GetTitle() ~= ChannelTitle))
		{
			return Channels[i].ChannelIndex;
		}
	}
	return Super::GetChannelIndex(ChannelTitle, TeamIndex);
	*/
	return 0;    //FAKE  /ELiZ
}

TArray<AVoiceChatRoom*> AAGP_VoiceChatReplicationInfo::GetPublicChannels()
{
	TArray<AVoiceChatRoom*> Rooms = {};
	int32 i = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if ((Channels[i] != nullptr) && (Channels[i].Owner == this))
		{
			Rooms[Rooms.Num()] = Channels[i];
		}
	}
	*/
	return Rooms;
}

TArray<AVoiceChatRoom*> AAGP_VoiceChatReplicationInfo::GetPlayerChannels()
{
	TArray<AVoiceChatRoom*> Rooms = {};
	int32 i = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if (((Channels[i] != nullptr) && (Channels[i].Owner != nullptr)) && (Channels[i].Owner != Self))
		{
			Rooms[Rooms.Num()] = Channels[i];
		}
	}
	*/
	return Rooms;
}

int32 AAGP_VoiceChatReplicationInfo::GetPublicChannelCount(bool bSingleTeam)
{
	int32 i = 0;
	int32 cnt = 0;
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if (((Channels[i] != nullptr) && (Channels[i].Owner == this)) && ((Channels[i].GetTeam() == 0) || (!bSingleTeam)))
		{
			cnt++;
		}
	}
	*/
	return cnt;
}

int32 AAGP_VoiceChatReplicationInfo::GetPlayerChannelCount()
{
	TArray<AVoiceChatRoom*> Arr = {};
	Arr = GetPlayerChannels();
	//return Arr.Num();
	return 0;    //FAKE   /ELiZ
}

bool AAGP_VoiceChatReplicationInfo::IsMember(AAA2_PlayerState* TestPRI, int32 ChannelIndex, bool bNoCascade)
{
	AVoiceChatRoom* VCR = nullptr;
	if (TestPRI == nullptr)
	{
		return false;
	}
	VCR = GetChannelAt(ChannelIndex);
	if (VCR == nullptr)
	{
		return false;
	}
	return VCR->IsMember(TestPRI, bNoCascade);
}

AVoiceChatRoom* AAGP_VoiceChatReplicationInfo::CreateNewVoiceChannel(AAA2_PlayerState* PRI)
{
	int32 i = 0;
	if (PRI == nullptr)
	{
		//return Spawn(ChatRoomClass, this);
	}
	/*
	for (i = 0; i < Channels.Num(); i++)
	{
		if (Channels[i].Owner == PRI)
		{
			return Super::CreateNewVoiceChannel(PRI);
		}
	}
	return Spawn(ChatRoomClass, PRI);
	*/
	return nullptr;  //FAKE   /EliZ
}

void AAGP_VoiceChatReplicationInfo::DestroyVoiceChannel(AVoiceChatRoom* Channel)
{
	if (Channel != nullptr)
	{
		Channel->Destroy();
		bRefresh = true;
	}
}
