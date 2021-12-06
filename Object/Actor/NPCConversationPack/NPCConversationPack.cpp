// All the original content belonged to the US Army


#include "AA29/Object/Actor/NPCConversationPack/NPCConversationPack.h"

// Sets default values
ANPCConversationPack::ANPCConversationPack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseLipSynch = true;
	Volume = 1;
	Radius = 64;
	Pitch = 1;
	bLoopConversation = true;
	fpMaxRangeBeforeTermination = 250;
	//bHidden = true;
}

// Called when the game starts or when spawned
void ANPCConversationPack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCConversationPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



/*
State PlayConversationEntry
{
	Function BeginState()
	{
		Log("Initializing conversation pack");
		CachePawnsForConversationEntry();
		SignalPawnsStartOfConversation();
		PlayEntry();
	}
	Function SignalPawnsStartOfConversation()
	{
		int32 iPawnIndex = 0;
		for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Length; iPawnIndex++)
		{
			NPCBaseController(apawnConversationMembers[iPawnIndex].Controller).NotifyConversationPackStart(Self);
		}
	}
	Function PlayEntry()
	{
		Log("Conversation - PlayEntry() entered with " $ string(acsSpeechEntries.Length) $ " entries to play, index: " $ string(iConvEntryIndex));
		if (iConvEntryIndex < acsSpeechEntries.Length)
		{
			if (bUseLipSynch)
			{
				pawnNPCTalking = FindCachedPawnByTagName(acsSpeechEntries[iConvEntryIndex].sMemberName);
				if (pawnNPCTalking != None)
				{
					pawnNPCTalking.PlayLIPSincAnim(acsSpeechEntries[iConvEntryIndex].nameLipSynchAudio,Volume,Radius,Pitch);
					if (acsSpeechEntries[iConvEntryIndex].nameAnimation != 'None')
					{
						pawnNPCTalking.EnableChannelNotify(15,1);
						pawnNPCTalking.AnimBlendParams(15,1,pawnNPCTalking.BlendChangeTime,pawnNPCTalking.BlendChangeTime,'Spine02');
						pawnNPCTalking.LoopAnim(acsSpeechEntries[iConvEntryIndex].nameAnimation,1,0.05,15);
						if (Level.NetMode == NM_DedicatedServer)
						{
							pawnNPCTalking.SetAnimAction(acsSpeechEntries[iConvEntryIndex].nameAnimation);
						}
					}
				}
				else
				{
					Log("Failure finding pawn for speech entry, pawn: " $ acsSpeechEntries[iConvEntryIndex].sMemberName);
				}
			}
			else
			{
				pawnNPCTalking = FindCachedPawnByTagName(acsSpeechEntries[iConvEntryIndex].sMemberName);
				NPCBaseController(pawnNPCTalking.Controller).PlayCustomSound(acsSpeechEntries[iConvEntryIndex].sndNonLSAudio);
				if (acsSpeechEntries[iConvEntryIndex].nameAnimation != 'None')
				{
					pawnNPCTalking.SetAnimAction(acsSpeechEntries[iConvEntryIndex].nameAnimation);
				}
			}
			SetTimer(1,true);
		}
		else
		{
			if (bLoopConversation)
			{
				if (acsSpeechEntries.Length > 0)
				{
					iConvEntryIndex = 0;
					PlayEntry();
				}
			}
			else
			{
				SetTimer(0,false);
				GotoState('EndingConversation');
			}
		}
	}
	Function Timer()
	{
		int32 iPawn = 0;
		for (iPawn = 0; iPawn < apawnConversationMembers.Length; iPawn++)
		{
			if (apawnConversationMembers[iPawn].Health < 100)
			{
				Log("Conversation being ended due to injury of particpant");
				GotoState('EndingConversation');
				return;
			}
		}
		if (pawnNPCTalking != None)
		{
			if (!pawnNPCTalking.IsPlayingLIPSincAnim())
			{
				pawnNPCTalking = None;
				iConvEntryIndex++;
				PlayEntry();
			}
		}
	}
}

State EndingConversation
{
	Function BeginState()
	{
		EndConversation();
	}
}

*/

void ANPCConversationPack::PostBeginPlay()
{
	//Super::PostBeginPlay();
}

void ANPCConversationPack::AttachPrimaryToTag()
{
}

void ANPCConversationPack::StartConversation()
{
	/*
	iConvEntryIndex = 0;
	if (!bConversationPackOwnedByNPC)
	{
		GotoState('PlayConversationEntry');
	}
	*/
}

void ANPCConversationPack::NPCStartConversation(ANPCBaseController* npcbc)
{
	/*
	iConvEntryIndex = 0;
	npcbcConversationOwner = npcbc;
	GotoState('PlayConversationEntry');
	*/
}

bool ANPCConversationPack::IsPawnMemberOfConversation(APawn* pawnToCheck)
{
	int32 iPawnIndex = 0;
	/*
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Length; iPawnIndex++)
	{
		if (apawnConversationMembers[iPawnIndex] == pawnToCheck)
		{
			return true;
		}
	}
	*/
	return false;
}

bool ANPCConversationPack::IsPawnNameMemberOfConversation(FString sPawnName)
{
	int32 iPawnIndex = 0;
	/*
	Log("Testing conversation members " $ string(acsSpeechEntries.Length) $ " entries for \"" $ sPawnName $ "\"");
	for (iPawnIndex = 0; iPawnIndex < acsSpeechEntries.Length; iPawnIndex++)
	{
		if (acsSpeechEntries[iPawnIndex].sMemberName ~= sPawnName)
		{
			return true;
		}
	}
	*/
	return false;
}

void ANPCConversationPack::CachePawnsForConversationEntry()
{
	/*
	int32 iSpeechEntry = 0;
	apawnConversationMembers.Length = 0;
	for (iSpeechEntry = 0; iSpeechEntry < acsSpeechEntries.Length; iSpeechEntry++)
	{
		AddPawnToMemberList(acsSpeechEntries[iSpeechEntry].sMemberName);
	}
	*/
}

void ANPCConversationPack::AddPawnToMemberList(FString sTagNameOfPawnToAdd)
{
	int32 iPawnIndex = 0;
	/*
	local NPCBaseController npcbcIterator;
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Length; iPawnIndex++)
	{
		if (sTagNameOfPawnToAdd ~= string(apawnConversationMembers[iPawnIndex].Tag))
		{
			return;
		}
	}
	ForEach AllActors(class'AGP.NPCBaseController', npcbcIterator)
	{
		if (string(npcbcIterator.Tag) ~= sTagNameOfPawnToAdd)
		{
			apawnConversationMembers.insert(apawnConversationMembers.Length, 1);
			apawnConversationMembers[(apawnConversationMembers.Length - 1)] = npcbcIterator.Pawn;
		}
	}
	*/
}

APawn* ANPCConversationPack::FindCachedPawnByTagName(FString sTagName)
{
	int32 iPawnIndex = 0;
	/*
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Length; iPawnIndex++)
	{
		if (string(apawnConversationMembers[iPawnIndex].Tag) ~= sTagName)
		{
			return apawnConversationMembers[iPawnIndex];
		}
	}
	*/
	return nullptr;
}

void ANPCConversationPack::EndConversation()
{
	/*
	int32 iPawnIndex = 0;
	if (pawnNPCTalking != None)
	{
		if (pawnNPCTalking.IsPlayingLIPSincAnim())
		{
			Log("Stopping pawn " $ string(pawnNPCTalking) $ " from lipsynching");
			pawnNPCTalking.StopLIPSincAnim();
		}
	}
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Length; iPawnIndex++)
	{
		Log("Signalling pawn " $ string(apawnConversationMembers[iPawnIndex].Controller.Tag) $ " conversation is over");
		NPCBaseController(apawnConversationMembers[iPawnIndex].Controller).NotifyConversationPackEnded(Self);
	}
	GotoState('None');
	*/
}

