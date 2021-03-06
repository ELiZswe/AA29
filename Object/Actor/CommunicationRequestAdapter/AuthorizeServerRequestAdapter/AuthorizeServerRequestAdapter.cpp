// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/AuthorizeServerRequestAdapter/AuthorizeServerRequestAdapter.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"

AAuthorizeServerRequestAdapter::AAuthorizeServerRequestAdapter()
{

}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		if (Cast<AGameInfo>(GetOwner()) != nullptr)
		{
			DebugLog(DEBUG_Auth,"AuthorizeServerRequestAdapter() sending to gameinfo" @ FString::FromInt(ServerModeId) @ "-" @ ServerModeName);
			GameInfo(GetOwner())->AuthAuthenticateServerCallback(ResultCode,ServerModeId,ServerModeName);
		}
	}
	Function CommunicationFailureCallback()
	{
		FString Reason = "";
		FString ShortReason = "";
		GetFailureReasons(Reason,ShortReason);
		GameInfo(GetOwner())->AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	}
}
*/

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
	FString Reason;
	FString ShortReason;
	GetFailureReasons(Reason,ShortReason);
	GameInfo(GetOwner())->AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AAuthorizeServerRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (Cast<AGameInfo>(GetOwner()) != nullptr)
	{
		DebugLog(DEBUG_Auth,"AuthorizeServerRequestAdapter() sending to gameinfo" @ ServerModeId @ "-" @ ServerModeName);
		GameInfo(GetOwner())->AuthAuthenticateServerCallback(ResultCode,ServerModeId,ServerModeName);
	}
	*/
}

FString AAuthorizeServerRequestAdapter::GetServerAuthIP()
{
	/*
	FString IP;
	if ('DBAuth'.Default.GameServerIP != "")
	{
		IP = 'DBAuth'.Default.GameServerIP;
	}
	else
	{
		IP = GetLegacyServerAuthIP();
		if (IP == "")
		{
			IP = AInternetLink::StaticClass().GetLocalIPAsString();
		}
	}
	return AGameInfo::StaticClass().GetPossibleCommandlineOverride("ServerAuthIP=", IP);
	*/
	return "FAKE";     //FAKE   /ELiZ
}

void AAuthorizeServerRequestAdapter::SetServerAuthUsername(FString UserName)
{
	//Default.ServerAuthUsername = UserName;
}
void AAuthorizeServerRequestAdapter::SetServerAuthPassword(FString Password)
{
	//Default.ServerAuthPassword = Password;
}
