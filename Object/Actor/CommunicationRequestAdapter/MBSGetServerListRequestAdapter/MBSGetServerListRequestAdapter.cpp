// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSGetServerListRequestAdapter/MBSGetServerListRequestAdapter.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"

AMBSGetServerListRequestAdapter::AMBSGetServerListRequestAdapter()
{
	RetryCountMax = 0;
	HighPriority = true; 
}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		if (nullptr != ServerBrowserDBMBS(GetOwner()))
		{
			ServerBrowserDBMBS(GetOwner())->SetServerList(serverList);
		}
		else
		{
			DebugLog(DEBUG_Auth,string(this) @ "CommunicationCompleteCallback called with owner" @ FString::FromInt(GetOwner()));
		}
	}
	Function CommunicationFailureCallback()
	{
		Log("Failed to obtain server list from MBS server. Result Code:" @ FString::FromInt(ResultCode));
		if (nullptr != ServerBrowserDBMBS(GetOwner()))
		{
			ServerBrowserDBMBS(GetOwner())->UpdateServerListFailed(ResultCode);
		}
	}
}
*/

void AMBSGetServerListRequestAdapter::CommunicationFailureCallback()
{
	/*
	Log("Failed to obtain server list from MBS server. Result Code:" @ ResultCode);
	if (None != ServerBrowserDBMBS(GetOwner()))
	{
		ServerBrowserDBMBS(GetOwner())->UpdateServerListFailed(ResultCode);
	}
	*/
}
void AMBSGetServerListRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (None != ServerBrowserDBMBS(GetOwner()))
	{
		ServerBrowserDBMBS(GetOwner())->SetServerList(serverList);
	}
	else
	{
		DebugLog(DEBUG_Auth,Self @ "CommunicationCompleteCallback called with owner" @ Owner);
	}
	*/
}

void AMBSGetServerListRequestAdapter::SetFilterList(TArray<FFilterItem> List)
{
	int32 Index = 0;
	FKeyValuePair Item = FKeyValuePair({});
	/*
	if (Level.debugThis(20))
	{
		AServerBrowserBase::StaticClass().DebugDumpFilterList(List);
	}
	FilterList.Num() = 0;
	for (Index = 0; Index < List.Num(); Index++)
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
