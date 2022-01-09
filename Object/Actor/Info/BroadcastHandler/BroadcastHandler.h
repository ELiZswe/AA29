// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "BroadcastHandler.generated.h"

class APlayInfo;
class AAA2_PlayerState;
class AInternetInfo;
class ALocalMessage;

UCLASS()
class ABroadcastHandler : public AAA2_Info
{
	GENERATED_BODY()
public:
	ABroadcastHandler();

	UPROPERTY()										ABroadcastHandler*		NextBroadcastHandler;			//var BroadcastHandler NextBroadcastHandler;
	UPROPERTY()										ABroadcastHandler*		NextBroadcastHandlerClass;		//var class<BroadcastHandler> NextBroadcastHandlerClass;
	UPROPERTY()										int32					SentText;						//var int32 SentText;
	UPROPERTY(globalconfig)							bool					bMuteSpectators;				//var globalconfig bool bMuteSpectators;
	UPROPERTY(globalconfig)							bool					bPartitionSpectators;			//var globalconfig bool bPartitionSpectators;
	UPROPERTY(globalconfig)							bool					bLogChats;						//var globalconfig bool bLogChats;
	UPROPERTY(globalconfig)							int32					iLogChatLevel;					//var globalconfig int32 iLogChatLevel;
	UPROPERTY()										TArray<FString>			BHDisplayText;					//var localized FString BHDisplayText[2];
	UPROPERTY()										TArray<FString>			BHDescText;						//var localized FString BHDescText[2];
	UPROPERTY()										AInternetInfo*			_LogTarget;						//var InternetInfo _LogTarget;

	void WriteChatLog(FString sChatText);
	void UpdateSentText();
	void FillPlayInfo(APlayInfo* PlayInfo);
	FString GetDescriptionText(FString PropName);
	bool AllowsBroadcast(AActor* broadcaster, int32 Len);
	bool HandlerAllowsBroadcast(AActor* broadcaster, int32 SentTextNum);
	void BroadcastText(AAA2_PlayerState* SenderPRI, APlayerController* Receiver, FString Msg, FName Type);
	void BroadcastLocalized(AActor* Sender, APlayerController* Receiver, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void Broadcast(AActor* Sender, FString Msg, FName Type);
	void WritePRIChatLog(AAA2_PlayerState* priSender, FString sMsg, FName Type);
	void BroadcastTeam(AController* Sender, FString Msg, FName Type);
	void BroadcastTeamByIndex(uint8 TeamIndex, FString Msg, FName Type);
	void BroadcastLocalizedTeamByIndex(uint8 TeamIndex, AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject);
	void AllowBroadcastLocalized(AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject);
	void RegisterBroadcastHandler(ABroadcastHandler* NewBH);
	bool AcceptBroadcastText(APlayerController* Receiver, AAA2_PlayerState* SenderPRI, FString& Msg, FName Type);
	bool AcceptBroadcastLocalized(APlayerController* Receiver, AActor* Sender, ALocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* obj);
	bool AcceptBroadcastSpeech(APlayerController* Receiver, AAA2_PlayerState* SenderPRI);
	bool AcceptBroadcastVoice(APlayerController* Receiver, AAA2_PlayerState* SenderPRI);
	void Destroyed();
	void SetLogTarget(AInternetInfo* iinfo);
};
