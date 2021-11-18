// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/BufferedTCPLink.h"
#include "AAIRCLink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAAIRCLink : public ABufferedTCPLink
{
	GENERATED_BODY()
public:
	AAAIRCLink();
	UPROPERTY()			float SinceLastLevCheck;							//var transient float SinceLastLevCheck;
	UPROPERTY(config)	TArray<FCommandAlias> Shortcuts;					//var config array<CommandAlias> Shortcuts;
	UPROPERTY()			FString VersionString;								//var string VersionString;
	UPROPERTY()			FString DisconnectReason;							//var string DisconnectReason;
	//UPROPERTY()			AAIRC_System SystemPage;									//var AAIRC_System SystemPage;
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

	void ProcessInput(FString Line);
	void PostBeginPlay();
	void CloseMe();
	//void Connect(AAIRC_System InSystemPage, FString InServer, FString InNickName, FString InUserIdent, FString InFullName, FString InDefaultChannel);
	void ChopLeft(FString Text);
	void RemoveNickPrefix(FString Nick);
	void Chop(FString Text);
	void Resolved(FIpAddr Addr);
	void Closed();
	void ResolveFailed();
	void Timer();
	void Opened();
	void Tick(float DeltaTime);
	void ChopLeftSpaces(FString Text);
	void SendCommandText(FString Cmd);
	void ReplaceCommandAlias(FString& Text);
	void SendBufferedData(FString Text);
	void SendChannelText(FString Channel, FString Text);
	void SendChannelAction(FString Channel, FString Text);
	
	void JoinChannel(FString Channel);
	void PartChannel(FString Channel);
	void SetNick(FString NewNick);
	void SetAway(FString AwayText);
	void DestroyLink();


};
