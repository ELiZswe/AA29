// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/PlaylistParserBase.h"
#include "M3UParser.generated.h"


UCLASS()
class AA29_API UM3UParser : public UPlaylistParserBase
{
	GENERATED_BODY()
public:
	UM3UParser();
	UPROPERTY()									FFilePath ParsedPath;									//var StreamBase.FilePath ParsedPath;



	bool Import(int32 PlaylistIndex, int32 InsertPosition, FString Path);
	void ParseLines();
	FString MatchPath(FString str);
};
