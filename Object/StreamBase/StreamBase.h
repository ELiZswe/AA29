// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyStructs.h"
#include "StreamBase.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UStreamBase : public UObject
{
	GENERATED_BODY()
public:
	UStreamBase();




	void GetPathSeparator();
	bool IsCaseSensitive();
	FString GetPathRoot(FString& InPath);
	bool HasExtension(FString Test);
	bool ParsePath(FString InPath, FFilePath &ParsedPath);
	FString ParseExtension(FString &FileNameWithExtension);
	TArray<FString>  ParseDirectories(FString &InPath);
	void RevInStr(FString Src, FString Match);
	void FormatTimeDisplay(float Seconds);
	FString ConvertToFileExtension(EFileType aType);
	uint8 ConvertToFileType(FString Extension);
	bool CompareNames(FString NameA, FString NameB);
	bool HandleDebugExec(FString Command, FString Param);

};
