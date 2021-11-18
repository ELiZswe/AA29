// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/AuthorizeServerRequestAdapter/AuthorizeServerRequestAdapter.h"

AAuthorizeServerRequestAdapter::AAuthorizeServerRequestAdapter()
{

}


//native static Function GetServerAuthUsername();
void AAuthorizeServerRequestAdapter::GetServerAuthUsername()
{
}

//native static Function GetServerAuthPassword();
void AAuthorizeServerRequestAdapter::GetServerAuthPassword()
{
}

//native static Function GetLegacyServerAuthIP();
void AAuthorizeServerRequestAdapter::GetLegacyServerAuthIP()
{
}

//native Function Request(string IPAddress, int Port, int Tour, int Mission, int MaxPlayers, string ServerPassword, string sAuthMapData);
void AAuthorizeServerRequestAdapter::Request(FString IPAddress, int32 Port, int32 Tour, int32 Mission, int32 MaxPlayers, FString ServerPassword, FString sAuthMapData)
{
}

//native Function AdaptResults();
void AAuthorizeServerRequestAdapter::AdaptResults()
{
}

void AAuthorizeServerRequestAdapter::CommunicationFailureCallback()
{
	/*
	local string Reason;
	local string ShortReason;
	GetFailureReasons(Reason,ShortReason);
	GameInfo(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AAuthorizeServerRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (GameInfo(Owner) != None)
	{
		DebugLog(DEBUG_Auth,"AuthorizeServerRequestAdapter() sending to gameinfo" @ ServerModeId @ "-" @ ServerModeName);
		GameInfo(Owner).AuthAuthenticateServerCallback(ResultCode,ServerModeId,ServerModeName);
	}
	*/
}
void AAuthorizeServerRequestAdapter::GetServerAuthIP()
{
	/*
	local string IP;
	if ('DBAuth'.Default.GameServerIP != "")
	{
		IP = 'DBAuth'.Default.GameServerIP;
	}
	else
	{
		IP = GetLegacyServerAuthIP();
		if (IP == "")
		{
			IP = Class'InternetLink'.GetLocalIPAsString();
		}
	}
	Return Class'GameInfo'.GetPossibleCommandlineOverride("ServerAuthIP=", IP);
	*/
}
void AAuthorizeServerRequestAdapter::SetServerAuthUsername(FString UserName)
{
	//Default.ServerAuthUsername = UserName;
}
void AAuthorizeServerRequestAdapter::SetServerAuthPassword(FString Password)
{
	//Default.ServerAuthPassword = Password;
}
