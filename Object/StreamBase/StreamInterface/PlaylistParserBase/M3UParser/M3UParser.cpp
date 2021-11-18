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
		Return True;
	}
	*/
	return false;
}

void UM3UParser::ParseLines()
{
	/*
	local int i;
	local string str;
	ParseLines();
	if (Lines.Length == 0)
	{
		Return;
	}
	for (i = 0; i < Lines.Length; i++)
	{
		if (Left(Lines[i], 1) == "#" || Lines[i] == "")
		{
		}
		str = Lines[i];
		if (Left(str, 1) == GetPathSeparator())
		{
			str = Mid(str, 1);
		}
		Paths[Paths.Length] = MatchPath(str);
	}
	*/
}

FString UM3UParser::MatchPath(FString str)
{
	FString Result="";
	/*
	local int i;
	local array<String> Parts;
	
	Split(str, GetPathSeparator(), Parts);
	for (i = 0; i < ParsedPath.DirectoryParts.Length; i++)
	{
		if (CompareNames(ParsedPath.DirectoryParts[i], Parts[0]))
		{
		}
		if (Result != "")
		{
			Result $ = GetPathSeparator();
		}
		Result $ = ParsedPath.DirectoryParts[i];
	}
	if (i == ParsedPath.DirectoryParts.Length)
	{
		Result = "";
	}
	for (i = 0; i < Parts.Length; i++)
	{
		if (Result != "")
		{
			Result $ = GetPathSeparator();
		}
		Result $ = Parts[i];
	}
	*/
	return Result;
}
