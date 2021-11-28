// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/AA29.h"
#include "MasterServerLink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMasterServerLink : public AAA2_Info
{
	GENERATED_BODY()
public:
	AMasterServerLink();

	UPROPERTY()					int32 LastMSIndex;												//var int LastMSIndex;
	UPROPERTY()					TArray<FtMasterServerEntry> ActiveMasterServerList;				//var array<tMasterServerEntry> ActiveMasterServerList;
	UPROPERTY(Globalconfig)		TArray<FtMasterServerEntry> MasterServerList;					//var globalconfig array<tMasterServerEntry> MasterServerList;
	UPROPERTY(Globalconfig)		int32 LANServerPort;											//var globalconfig int LANServerPort;
	UPROPERTY(Globalconfig)		int32 LANPort;													//var globalconfig int LANPort;
	//UPROPERTY()				pointer LinkPtr;												//var const native transient pointer LinkPtr;

	void Poll(int32 WaitTime);
	void GetMasterServer(FString& OutAddress, int32& OutPort);
	void Tick(float DeltaTime);

};
