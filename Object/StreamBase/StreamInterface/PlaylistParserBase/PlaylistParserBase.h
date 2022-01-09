// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"
#include "AA29/AA29.h"
#include "PlaylistParserBase.generated.h"


UCLASS()
class UPlaylistParserBase : public UStreamInterface
{
	GENERATED_BODY()
public:
	UPlaylistParserBase();

	UPROPERTY()									TArray<FHtmlChar>	SpecialChars;				//var array<HtmlChar> SpecialChars;
	UPROPERTY()									TArray<FString>		Lines;						//var array<String> Lines;
	UPROPERTY()									TArray<FString>		Paths;						//var array<String> Paths;
	UPROPERTY()									FString				PlaylistName;				//var string PlaylistName;
	UPROPERTY()									EStreamPlaylistType Type;						//var StreamBase.EStreamPlaylistType Type;


	EStreamPlaylistType GetType();
	void SetType(EStreamPlaylistType InType);
	bool Import(int32 PlaylistIndex, int32 InsertPosition, FString Path);
	void ImportedPlaylist(int32 PlaylistIndex, int32 InsertPosition);
	void ParseLines();
	FString GetValue(FString KeyValuePair, bool bAllowSpaces);
	FString GetTagged(FString& Text);
	FString HtmlDecode(FString Src);

};
