// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/PlaylistParserBase.h"
#include "PLSParser.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UPLSParser : public UPlaylistParserBase
{
	GENERATED_BODY()
public:
	UPLSParser();

	void ParseLines();
};
