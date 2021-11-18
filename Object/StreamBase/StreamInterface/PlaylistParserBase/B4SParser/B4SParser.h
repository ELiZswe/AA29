// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/PlaylistParserBase.h"
#include "B4SParser.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UB4SParser : public UPlaylistParserBase
{
	GENERATED_BODY()
public:
	UB4SParser();


	void ParseLines();
};
