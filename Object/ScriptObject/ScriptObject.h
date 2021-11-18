// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScriptObject.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UScriptObject : public UObject
{
	GENERATED_BODY()
public:
	UScriptObject();

	UPROPERTY()										int32 _nNumParamsDefined;					//var int _nNumParamsDefined;
	UPROPERTY()										TArray<FString> _sParameters;				//var array<String> _sParameters;
	UPROPERTY()										bool bSupportsMP;							//var bool bSupportsMP;
	UPROPERTY()										bool _bDebug;								//var bool _bDebug;





	void Destroyed();
	void Notify();
	void update();
	void SetDebug(bool Debug);
	int32 GetNumParams();
	int32 GetNumParamsDefined();
	FString GetParam(int32 Index);
	void SetParamString(FString szParams);

};
