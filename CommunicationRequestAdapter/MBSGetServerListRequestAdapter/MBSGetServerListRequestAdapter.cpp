// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/MBSGetServerListRequestAdapter/MBSGetServerListRequestAdapter.h"

AMBSGetServerListRequestAdapter::AMBSGetServerListRequestAdapter()
{
	RetryCountMax = 0;
	HighPriority = true; 
}


void AMBSGetServerListRequestAdapter::CommunicationFailureCallback()
{
	/*
	Log("Failed to obtain server list from MBS server. Result Code:" @ ResultCode);
	if (None != ServerBrowserDBMBS(Owner))
	{
		ServerBrowserDBMBS(Owner).UpdateServerListFailed(ResultCode);
	}
	*/
}
void AMBSGetServerListRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (None != ServerBrowserDBMBS(Owner))
	{
		ServerBrowserDBMBS(Owner).SetServerList(serverList);
	}
	else
	{
		DebugLog(DEBUG_Auth,Self @ "CommunicationCompleteCallback called with owner" @ Owner);
	}
	*/
}
void AMBSGetServerListRequestAdapter::SetFilterList(TArray<FFilterItem> List)
{
	/*
	local int Index;
	local GameInfo.KeyValuePair Item;
	if (Level.debugThis(20))
	{
		Class'ServerBrowserBase'.DebugDumpFilterList(List);
	}
	FilterList.Length = 0;
	for (Index = 0; Index < List.Length; Index++)
	{
		Item.Key = List[Index].Key;
		Item.Value = List[Index].Value;
		FilterList[Index] = Item;
	}
	*/
}
//native Function Request();
void AMBSGetServerListRequestAdapter::Request()
{
}

//native Function AdaptResults();
void AMBSGetServerListRequestAdapter::AdaptResults()
{
}

void AMBSGetServerListRequestAdapter::GetRequestedServerAttributes(TArray<FString> &RequestedAttributes)
{
	RequestedAttributes[RequestedAttributes.Max()] = "serverName";
	RequestedAttributes[RequestedAttributes.Max()] = "locale";
	RequestedAttributes[RequestedAttributes.Max()] = "requiresPassword";
	RequestedAttributes[RequestedAttributes.Max()] = "official";
	RequestedAttributes[RequestedAttributes.Max()] = "leased";
	RequestedAttributes[RequestedAttributes.Max()] = "miles";
	RequestedAttributes[RequestedAttributes.Max()] = "punkbuster";
	RequestedAttributes[RequestedAttributes.Max()] = "cheats";
	RequestedAttributes[RequestedAttributes.Max()] = "tournament";
	RequestedAttributes[RequestedAttributes.Max()] = "exploreTheArmy";
	RequestedAttributes[RequestedAttributes.Max()] = "mapName";
	RequestedAttributes[RequestedAttributes.Max()] = "tour";
	RequestedAttributes[RequestedAttributes.Max()] = "minHonor";
	RequestedAttributes[RequestedAttributes.Max()] = "maxHonor";
	RequestedAttributes[RequestedAttributes.Max()] = "groups";
	RequestedAttributes[RequestedAttributes.Max()] = "missionTimeRemaining";
	RequestedAttributes[RequestedAttributes.Max()] = "maxSpectators";
	RequestedAttributes[RequestedAttributes.Max()] = "numSpectators";
	RequestedAttributes[RequestedAttributes.Max()] = "averageHonor";
	RequestedAttributes[RequestedAttributes.Max()] = "currentRound";
	RequestedAttributes[RequestedAttributes.Max()] = "roundsPerMatch";
	RequestedAttributes[RequestedAttributes.Max()] = "operatingSystem";
	RequestedAttributes[RequestedAttributes.Max()] = "coop";
	RequestedAttributes[RequestedAttributes.Max()] = "serverNameDisplay";
}