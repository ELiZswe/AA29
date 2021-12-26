// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "VotingHandler.generated.h"

class APlayInfo;

UCLASS()
class AVotingHandler : public AAA2_Info
{
	GENERATED_BODY()
public:
	AVotingHandler();

	void PlayerJoin(APlayerController* Player);
	void PlayerExit(AController* Exiting);
	bool HandleRestartGame();
	FString GetConfigArrayData(FString ConfigArrayName, int32 RowIndex, int32 ColumnIndex);
	FString GetConfigArrayColumnTitle(FString ConfigArrayName, int32 ColumnIndex);
	void DeleteConfigArrayItem(FString ConfigArrayName, int32 RowIndex);
	int32 AddConfigArrayItem(FString ConfigArrayName);
	void UpdateConfigArrayItem(FString ConfigArrayName, int32 RowIndex, int32 ColumnIndex, FString NewValue);
	int32 GetConfigArrayItemCount(FString ConfigArrayName);
	void FillPlayInfo(APlayInfo* PlayInfo);
	bool IsEnabled();
	void ReloadAll(bool bParam);
	void GetServerDetails(FServerResponseLine &ServerState);
};
