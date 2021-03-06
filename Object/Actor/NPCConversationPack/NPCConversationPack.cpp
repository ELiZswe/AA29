// All the original content belonged to the US Army

#include "AA29/Object/Actor/NPCConversationPack/NPCConversationPack.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

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
		for (iPawnIndex=0; iPawnIndex<apawnConversationMembers.Num(); iPawnIndex++)
		{
			NPCBaseController(apawnConversationMembers[iPawnIndex].Controller).NotifyConversationPackStart(this);
		}
	}
	Function PlayEntry()
	{
		Log("Conversation - PlayEntry() entered with " + FString::FromInt(acsSpeechEntries.Num()) + " entries to play, index: " + FString::FromInt(iConvEntryIndex));
		if (iConvEntryIndex < acsSpeechEntries.Num())
		{
			if (bUseLipSynch)
			{
				pawnNPCTalking=FindCachedPawnByTagName(acsSpeechEntries[iConvEntryIndex].sMemberName);
				if (pawnNPCTalking != nullptr)
				{
					pawnNPCTalking.PlayLIPSincAnim(acsSpeechEntries[iConvEntryIndex].nameLipSynchAudio,Volume,Radius,Pitch);
					if (acsSpeechEntries[iConvEntryIndex].nameAnimation != "None")
					{
						pawnNPCTalking.EnableChannelNotify(15,1);
						pawnNPCTalking.AnimBlendParams(15,1,pawnNPCTalking.BlendChangeTime,pawnNPCTalking.BlendChangeTime,"Spine02");
						pawnNPCTalking.LoopAnim(acsSpeechEntries[iConvEntryIndex].nameAnimation,1,0.05,15);
						if (GetWorld()->GetNetMode() == NM_DedicatedServer)
						{
							pawnNPCTalking.SetAnimAction(acsSpeechEntries[iConvEntryIndex].nameAnimation);
						}
					}
				}
				else
				{
					Log("Failure finding pawn for speech entry, pawn: " + acsSpeechEntries[iConvEntryIndex].sMemberName);
				}
			}
			else
			{
				pawnNPCTalking=FindCachedPawnByTagName(acsSpeechEntries[iConvEntryIndex].sMemberName);
				NPCBaseController(pawnNPCTalking.Controller).PlayCustomSound(acsSpeechEntries[iConvEntryIndex].sndNonLSAudio);
				if (acsSpeechEntries[iConvEntryIndex].nameAnimation != "None")
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
				if (acsSpeechEntries.Num() > 0)
				{
					iConvEntryIndex=0;
					PlayEntry();
				}
			}
			else
			{
				SetTimer(0,false);
				GotoState("EndingConversation");
			}
		}
	}
	Function Timer()
	{
		int32 iPawn = 0;
		for (iPawn=0; iPawn<apawnConversationMembers.Num(); iPawn++)
		{
			if (apawnConversationMembers[iPawn].Health < 100)
			{
				Log("Conversation being ended due to injury of particpant");
				GotoState("EndingConversation");
				return;
			}
		}
		if (pawnNPCTalking != nullptr)
		{
			if (! pawnNPCTalking.IsPlayingLIPSincAnim())
			{
				pawnNPCTalking=nullptr;
				iConvEntryIndex ++;
				PlayEntry();
			}
		}
	}
}
*/

/*
State EndingConversation
{
	Function BeginState()
	{
		EndConversation();
	}
}
*/


void ANPCConversationPack::BeginPlay()
{
	Super::BeginPlay();
	
}


void ANPCConversationPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

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
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Num(); iPawnIndex++)
	{
		if (apawnConversationMembers[iPawnIndex] == pawnToCheck)
		{
			return true;
		}
	}
	return false;
}

bool ANPCConversationPack::IsPawnNameMemberOfConversation(FString sPawnName)
{
	int32 iPawnIndex = 0;
	/*
	Log("Testing conversation members " + FString::FromInt(acsSpeechEntries.Num()) + " entries for \"" + sPawnName + "\"");
	for (iPawnIndex = 0; iPawnIndex < acsSpeechEntries.Num(); iPawnIndex++)
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
	apawnConversationMembers.Num() = 0;
	for (iSpeechEntry = 0; iSpeechEntry < acsSpeechEntries.Num(); iSpeechEntry++)
	{
		AddPawnToMemberList(acsSpeechEntries[iSpeechEntry].sMemberName);
	}
	*/
}

void ANPCConversationPack::AddPawnToMemberList(FString sTagNameOfPawnToAdd)
{
	int32 iPawnIndex = 0;
	ANPCBaseController* npcbcIterator = nullptr;
	/*
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Num(); iPawnIndex++)
	{
		if (sTagNameOfPawnToAdd ~= FString::FromInt(apawnConversationMembers[iPawnIndex].Tag))
		{
			return;
		}
	}
	ForEach AllActors(ANPCBaseController::StaticClass(), npcbcIterator)
	{
		if (string(npcbcIterator.Tag) ~= sTagNameOfPawnToAdd)
		{
			apawnConversationMembers.insert(apawnConversationMembers.Num(), 1);
			apawnConversationMembers[(apawnConversationMembers.Num() - 1)] = npcbcIterator.Pawn;
		}
	}
	*/
}

APawn* ANPCConversationPack::FindCachedPawnByTagName(FString sTagName)
{
	int32 iPawnIndex = 0;
	/*
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Num(); iPawnIndex++)
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
	if (pawnNPCTalking != nullptr)
	{
		if (pawnNPCTalking.IsPlayingLIPSincAnim())
		{
			Log("Stopping pawn " + FString::FromInt(pawnNPCTalking) + " from lipsynching");
			pawnNPCTalking->StopLIPSincAnim();
		}
	}
	for (iPawnIndex = 0; iPawnIndex < apawnConversationMembers.Num(); iPawnIndex++)
	{
		Log("Signalling pawn " + FString::FromInt(apawnConversationMembers[iPawnIndex].Controller.Tag) + " conversation is over");
		NPCBaseController(apawnConversationMembers[iPawnIndex].Controller).NotifyConversationPackEnded(this);
	}
	GotoState("None");
	*/
}

