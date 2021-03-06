// All the original content belonged to the US Army
//=============================================================================
// UdpGameSpyQuery
//
// Version: 1.5
//
// This query server is compliant with the GameSpy Uplink Specification.
// The specification is available at http://www.gamespy.com/developer
// and might be of use to progammers who are writing or maintaining
// their own stat gathering/game querying software.
//
// Note: Currently, SendText returns false if successful.
//
// Full documentation on this class is available at http://unreal.epicgames.com/
//
//=============================================================================

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpLink.h"
#include "UdpGamespyQuery.generated.h"

UCLASS()
class AUdpGamespyQuery : public AUdpLink
{
	GENERATED_BODY()
public:
	AUdpGamespyQuery();
	// Game Server Config.
	UPROPERTY(EditAnyWhere)			FName QueryName;								//var() name QueryName;
	UPROPERTY()						int32 CurrentQueryNum;							//var int CurrentQueryNum;
	//crt
	UPROPERTY()						FString ReplyData;								//var string ReplyData;
	UPROPERTY(Globalconfig)			int32 MinNetVer;								//var globalconfig int MinNetVer;
	//!! Hack to prevent port swapping
	UPROPERTY(Globalconfig)			int32 OldQueryPortNumber;						//var globalconfig int OldQueryPortNumber;
	UPROPERTY(Globalconfig)			bool bRestartServerOnPortSwap;					//var globalconfig bool bRestartServerOnPortSwap;
	UPROPERTY(Globalconfig)			bool bDebugPortSwaps;							//var globalconfig bool bDebugPortSwaps;

	void PreBeginPlay();
	void DebugPortSwap(AActor* Ref);
	FString GetFullName(UObject* obj);
	void ReceivedText(FIpAddr Addr, FString Text);
	bool ParseNextQuery(FString Query, FString &QueryType, FString &QueryValue, FString &QueryRest, int32 &bFinalPacket);
	FString ParseQuery(FIpAddr Addr, FString Query, int32 QueryNum, int32 &PacketNum);
	bool SendAPacket(FIpAddr Addr, int32 QueryNum, int32 &PacketNum, int32 bFinalPacket);
	bool SendQueryPacket(FIpAddr Addr, FString SendString, int32 QueryNum, int32 &PacketNum, int32 &bFinalPacket);
	FString GetBasic();
	FString GetInfo();
	FString GetRules();
	FString GetPlayer(APlayerController* p, int32 PlayerNum);
	bool SendPlayers(FIpAddr Addr, int32 QueryNum, int32 &PacketNum, int32 bFinalPacket);
	FString GetLevelProperty(FString Prop);
	FString GetGameProperty(FString Prop);
	FString GetPlayerProperty(FString Prop);
};
