// All the original content belonged to the US Army


#include "AA29/Info/AGP_ServerInfo/AGP_ServerInfo.h"

AAGP_ServerInfo::AAGP_ServerInfo()
{
	bAlwaysRelevant = true;
	//RemoteRole = 2;
	NetUpdateFrequency = 5;
}


void AAGP_ServerInfo::PreBeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT(" ServerInfo Created... "));
}
int32 AAGP_ServerInfo::GetSettingsCount()
{
	UE_LOG(LogTemp, Log, TEXT("GetSettingsCount() - returning %d"), numCurrentServerSettings);
	return 0;
}
FString AAGP_ServerInfo::GetKey(int32 Index)
{
	UE_LOG(LogTemp, Log, TEXT(" GetKey() - returning %s"), *CurrentServerSettings[Index].Key);
	return "";
}
void AAGP_ServerInfo::SetKey(int32 Index, FString Key)
{
}
FString AAGP_ServerInfo::GetKeyValue(int32 Index)
{
	return "";
}
void AAGP_ServerInfo::SetKeyValue(int32 Index, FString Value)
{
}
void AAGP_ServerInfo::UpdateServerKey(int32 Index, FString Key)
{
}
void AAGP_ServerInfo::UpdateServerKeyValue(int32 Index, FString Value)
{
}
void AAGP_ServerInfo::RefreshServerSettings()
{
}
void AAGP_ServerInfo::ServerRequestServerInfo(bool bUpdate=false)
{
}
void AAGP_ServerInfo::ClientReceiveServerInfo(int32 Index, FString Key, FString Value, bool bUpdate=false)
{
}
