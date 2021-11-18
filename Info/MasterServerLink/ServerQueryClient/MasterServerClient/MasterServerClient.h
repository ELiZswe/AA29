// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/MasterServerLink/ServerQueryClient/ServerQueryClient.h"
#include "MasterServerClient.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMasterServerClient : public AServerQueryClient
{
	GENERATED_BODY()
public:
	AMasterServerClient();

	UPROPERTY()										Fpointer			MSLinkPtr;				//var const native transient Fpointer MSLinkPtr;
	UPROPERTY()										int32				OwnageLevel;			//var int32 OwnageLevel;
	UPROPERTY()										int32				ModRevLevel;			//var int32 ModRevLevel;
	UPROPERTY(EditAnywhere, Category = "Query")		TArray<FQueryData>	Query;					//var(Query) TArray<QueryData> Query;
	UPROPERTY(EditAnywhere, Category = "Query")		int32				ResultCount;			//var(Query) const int32 ResultCount;
	UPROPERTY()										FString				OptionalResult;			//var FString OptionalResult;

	void StartQuery(EClientToMaster Command);
	void Stop();
	void LaunchAutoUpdate();
	void OnQueryFinished(EResponseInfo ResponseInfo, int32 Info);
	void OnReceivedServer(FServerResponseLine S);
	void OnReceivedMOTDData(EMOTDResponse Command, FString Value);
	void OnReceivedModMOTDData(FString Value);
	void OnReceivedOwnageItem(int32 Level, FString ItemName, FString ItemDesc, FString ItemURL);
};
