// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DBAuth.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UDBAuth : public UObject
{
	GENERATED_BODY()
public:
	UDBAuth();

	UPROPERTY(globalconfig)								FString GameServerIP;							//var globalconfig string GameServerIP;

	void SetAuthServer(FString hostname);
	void GetAuthServer();
	void SetKeyFilename(FString KeyFilename);
	void GetKeyFilename();
	void Sleep(float Seconds);
};
