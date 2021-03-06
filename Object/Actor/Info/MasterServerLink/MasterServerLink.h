// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/AA29.h"
#include "MasterServerLink.generated.h"

UCLASS()
class AMasterServerLink : public AAA2_Info
{
	GENERATED_BODY()
public:
	AMasterServerLink();

	UPROPERTY()					int32							LastMSIndex;						//var int LastMSIndex;
	UPROPERTY()					TArray<FtMasterServerEntry>		ActiveMasterServerList;				//var array<tMasterServerEntry> ActiveMasterServerList;
	UPROPERTY(globalconfig)		TArray<FtMasterServerEntry>		MasterServerList;					//var globalconfig array<tMasterServerEntry> MasterServerList;
	UPROPERTY(globalconfig)		int32							LANServerPort;						//var globalconfig int LANServerPort;
	UPROPERTY(globalconfig)		int32							LANPort;							//var globalconfig int LANPort;
	UPROPERTY()					Fpointer						LinkPtr;							//var const native transient pointer LinkPtr;

	bool Poll(int32 WaitTime);
	void GetMasterServer(FString& OutAddress, int32& OutPort);
	void Tick(float DeltaTime);
};
