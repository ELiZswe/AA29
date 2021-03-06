// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/BufferedTCPLink.h"
#include "IRCLink.generated.h"

class UIRC_System;

UCLASS()
class AIRCLink : public ABufferedTCPLink
{
	GENERATED_BODY()
public:
	AIRCLink();

	UPROPERTY()			float SinceLastLevCheck;							//var transient float SinceLastLevCheck;
	UPROPERTY()			FString VersionString;								//var string VersionString;
	UPROPERTY()			FString DisconnectReason;							//var string DisconnectReason;
	UPROPERTY()			UIRC_System* SystemPage;							//var IRC_System SystemPage;
	UPROPERTY()			FString NickInvalidText;							//var localized string NickInvalidText;
	UPROPERTY()			FString NickInUseText;								//var localized string NickInUseText;
	UPROPERTY()			FString InviteString;								//var localized string InviteString;
	UPROPERTY()			FString TimeOutError;								//var localized string TimeOutError;
	UPROPERTY()			FString ConnectingToText;							//var localized string ConnectingToText;
	UPROPERTY()			FString ConnectedText;								//var localized string ConnectedText;
	UPROPERTY()			FString ResolveFailedText;							//var localized string ResolveFailedText;
	UPROPERTY()			FString ErrorBindingText;							//var localized string ErrorBindingText;
	UPROPERTY()			FString InvalidAddressText;							//var localized string InvalidAddressText;
	UPROPERTY()			FString DefaultChannel;								//var string DefaultChannel;
	UPROPERTY()			FString FullName;									//var string FullName;
	UPROPERTY()			FString UserIdent;									//var string UserIdent;
	UPROPERTY()			FString NickName;									//var string NickName;
	UPROPERTY()			int32 ServerPort;									//var int ServerPort;
	UPROPERTY()			FString ServerAddress;								//var string ServerAddress;
	UPROPERTY()			FIpAddr ServerIpAddr;								//var InternetLink.IpAddr ServerIpAddr;

	void PostBeginPlay();
	void Connect(UIRC_System* InSystemPage, FString InServer, FString InNickName, FString InUserIdent, FString InFullName, FString InDefaultChannel);
	FString ChopLeft(FString Text);
	FString RemoveNickPrefix(FString Nick);
	FString Chop(FString Text);
	void Resolved(FIpAddr Addr);
	void Closed();
	void ResolveFailed();
	void Timer();
	void Opened();
	void Tick(float DeltaTime);
	void SendCommandText(FString Text);
	void SendChannelText(FString Channel, FString Text);
	void SendChannelAction(FString Channel, FString Text);
	void ProcessInput(FString Line);
	void JoinChannel(FString Channel);
	void PartChannel(FString Channel);
	void SetNick(FString NewNick);
	void SetAway(FString AwayText);
	void DestroyLink();
};
