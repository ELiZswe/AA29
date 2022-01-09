// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine/Console.h"
#include "AA29/AA29.h"
#include "ExtendedConsole.generated.h"

class UGUIPage;
class AVoiceChatRoom;
class UUT2MusicManager;

UCLASS(Config = Game)
class UExtendedConsole : public UConsole
{
	GENERATED_BODY()
public:
	UExtendedConsole();

	UPROPERTY(globalconfig)								int32				MaxScrollbackSize;						//var globalconfig int32 MaxScrollbackSize;
	UPROPERTY()											TArray<FString>		Scrollback;								//var TArray<FString> Scrollback;
	UPROPERTY()											int32				SBHead;									//var int32 SBHead;
	UPROPERTY()											int32				SBPos;									//var int32 SBPos;
	UPROPERTY()											bool				bCtrl;									//var bool bCtrl;
	UPROPERTY()											bool				bAlt;									//var bool bAlt;
	UPROPERTY()											bool				bShift;									//var bool bShift;
	UPROPERTY()											bool				bConsoleHotKey;							//var bool bConsoleHotKey;
	UPROPERTY()											float				ConsoleSoundVol;						//var float ConsoleSoundVol;
	UPROPERTY()											FString				AddedCurrentHead;						//var localized FString AddedCurrentHead;
	UPROPERTY()											FString				AddedCurrentTail;						//var localized FString AddedCurrentTail;
	UPROPERTY()											FString				ServerFullMsg;							//var localized FString ServerFullMsg;
	UPROPERTY()											float				SMLineSpace;							//var float SMLineSpace;
	UPROPERTY()											FName				SMType;									//var FName SMType;
	UPROPERTY()											int32				SMIndex;								//var int32 SMIndex;
	UPROPERTY()											FString				SMCallsign;								//var FString SMCallsign;
	UPROPERTY()											int32				SMOffset;								//var int32 SMOffset;
	UPROPERTY()											TArray<FString>		SMNameArray;							//var FString SMNameArray[48];
	UPROPERTY()											TArray<int32>		SMIndexArray;							//var int32 SMIndexArray[48];
	UPROPERTY()											int32				SMArraySize;							//var int32 SMArraySize;
	UPROPERTY(config)									float				SMOriginX;								//var config float SMOriginX;
	UPROPERTY(config)									float				SMOriginY;								//var config float SMOriginY;
	UPROPERTY()											float				SMMargin;								//var float SMMargin;
	UPROPERTY()											float				SMTab;									//var float SMTab;
	UPROPERTY()											TArray<FString>		SMStateName;							//var localized FString SMStateName[10];
	UPROPERTY()											TArray<FString>		SMChannelOptions;						//var localized FString SMChannelOptions[3];
	UPROPERTY()											TArray<AVoiceChatRoom*> VoiceChannels;						//var TArray<VoiceChatRoom> VoiceChannels;
	UPROPERTY()											FString				SMAllString;							//var localized FString SMAllString;
	UPROPERTY()											FString				SMMoreString;							//var localized FString SMMoreString;
	UPROPERTY()											USoundBase*			SMOpenSound;							//var Sound SMOpenSound;
	UPROPERTY()											USoundBase*			SMAcceptSound;							//var Sound SMAcceptSound;
	UPROPERTY()											USoundBase*			SMDenySound;							//var Sound SMDenySound;
	UPROPERTY()											TArray<EInputKey>	LetterKeys;								//var config Interactions.EInputKey LetterKeys[10];
	UPROPERTY()											TArray<EInputKey>	NumberKeys;								//var Interactions.EInputKey NumberKeys[10];
	UPROPERTY(config)									bool				bSpeechMenuUseLetters;					//var config bool bSpeechMenuUseLetters;
	UPROPERTY(config)									bool				bSpeechMenuUseMouseWheel;				//var config bool bSpeechMenuUseMouseWheel;
	UPROPERTY()											bool				bSpeechMenuLocked;						//var bool bSpeechMenuLocked;
	UPROPERTY()											int32				HighlightRow;							//var int32 HighlightRow;
	UPROPERTY()											TArray<FServerFavorite> Favorites;							//var() config TArray<ServerFavorite> Favorites;
	UPROPERTY(config)									TArray<FStoredPassword> SavedPasswords;						//var config TArray<StoredPassword> SavedPasswords;
	UPROPERTY(config)									FString				PasswordPromptMenu;						//var config FString PasswordPromptMenu;
	UPROPERTY()											FString				LastConnectedServer;					//var FString LastConnectedServer;
	UPROPERTY()											FString				LastURL;								//var FString LastURL;
	UPROPERTY()											TArray<FChatStruct> ChatMessages;							//var TArray<ChatStruct> ChatMessages;
	UPROPERTY(config)									FString				ChatMenuClass;							//var config FString ChatMenuClass;
	UPROPERTY()											UGUIPage*			ChatMenu;								//var transient GUIPage ChatMenu;
	UPROPERTY()											bool				bTeamChatOnly;							//var bool bTeamChatOnly;
	UPROPERTY()											UUT2MusicManager*	MusicManager;							//var transient UT2MusicManager MusicManager;
	UPROPERTY(config)									FString				StatsPromptMenuClass;					//var config FString StatsPromptMenuClass;
	UPROPERTY(config)									FString				MusicManagerClassName;					//var config FString MusicManagerClassName;
	UPROPERTY(config)									FString				WaitingGameClassName;					//var config FString WaitingGameClassName;
	UPROPERTY(config)									FString				NeedPasswordMenuClass;					//var config FString NeedPasswordMenuClass;
	UPROPERTY(config)									FString				ServerInfoMenu;							//var config FString ServerInfoMenu;

	void OnChat(FString Msg, int32 TeamIndex);
	void OnStatsClosed(bool bCancelled);
	void OnStatsConfigured();
	void ConnectFailure(FString FailCode, FString URL);
	void NotifyLevelChange();
	void Cls();
	void PostRender(UCanvas* Canvas);
	void Chat(FString Msg, float MsgLife, AAA2_PlayerState* PRI);
	void OnChatMessage(FString Msg);
	void Message(FString Msg, float MsgLife, FColor Color);
	bool KeyEvent(EInputKey Key, EInputAction Action, float Delta);
	void PlayConsoleSound(USoundBase* S);
	void NativeConsoleOpen();
	void ConsoleOpen();
	void ConsoleClose();
	void ConsoleToggle();
	void OnExecAddFavorite(FServerFavorite Fav);
	void AddCurrentToFavorites();
	bool InFavorites(FServerFavorite Fav);
	bool AddFavorite(FServerFavorite NewFav);
	bool RemoveFavorite(FString IP, int32 Port, int32 QueryPort);
	void GetFavorites(TArray<FServerFavorite>& List);
	void SaveFavorites();
	void SpeechMenuToggle();
	void IngameChat();
	void ServerInfo();
	void TeamChatOnly();
	void PlayWaitingGame();
	void MusicMenu();
	void DumpPlayInfo(FString Group);
	void DumpRecords(FString Type);
	void AddMessage(FString Mesg);
	void DumpCacheRecords(FString CacheType);
	bool VoiceChatAllowed();
	void DLO(FString ClassName, FString ClassType);
	void DumpLoadingHints(FString Param);
	void DebugTabOrder();

};
