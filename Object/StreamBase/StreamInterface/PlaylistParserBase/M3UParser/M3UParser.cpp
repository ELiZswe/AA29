// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/M3UParser/M3UParser.h"

UM3UParser::UM3UParser()
{

}

bool UM3UParser::Import(int32 PlaylistIndex, int32 InsertPosition, FString Path)
{
	/*
	if (Outer.FileManager.LoadPlaylist(Path, Lines) && ParsePath(Path, ParsedPath))
	{
		ImportedPlaylist(PlaylistIndex, InsertPosition);
		return true;
	}
	*/
	return false;
}

void UM3UParser::ParseLines()
{
	int32 i = 0;
	FString str;
	Super::ParseLines();
	if (Lines.Num() == 0)
	{
		return;
	}
	/*
	for (i = 0; i < Lines.Num(); i++)
	{
		if (Left(Lines[i], 1) == "#" || Lines[i] == "")
		{
		}
		str = Lines[i];
		if (Left(str, 1) == GetPathSeparator())
		{
			str = Mid(str, 1);
		}
		Paths[Paths.Num()] = MatchPath(str);
	}
	*/
}

FString UM3UParser::MatchPath(FString str)
{
	FString Result="";
	int32 i = 0;
	TArray<FString> Parts = {};
	/*
	Split(str, GetPathSeparator(), Parts);
	for (i = 0; i < ParsedPath.DirectoryParts.Num(); i++)
	{
		if (CompareNames(ParsedPath.DirectoryParts[i], Parts[0]))
		{
		}
		if (Result != "")
		{
			Result += GetPathSeparator();
		}
		Result += ParsedPath.DirectoryParts[i];
	}
	if (i == ParsedPath.DirectoryParts.Num())
	{
		Result = "";
	}
	for (i = 0; i < Parts.Num(); i++)
	{
		if (Result != "")
		{
			Result += GetPathSeparator();
		}
		Result += Parts[i];
	}
	*/
	return Result;
}
