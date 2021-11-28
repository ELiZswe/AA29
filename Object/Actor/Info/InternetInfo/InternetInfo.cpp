// All the original content belonged to the US Army
//=============================================================================
// InternetInfo: Parent class for Internet connection classes
//=============================================================================

#include "AA29/Object/Actor/Info/InternetInfo/InternetInfo.h"

AInternetInfo::AInternetInfo()
{

}

int32 AInternetInfo::GetBeaconCount()
{
	return 0;
}
FString AInternetInfo::GetBeaconAddress(int32 i)
{
	return "";
}
FString AInternetInfo::GetBeaconText(int32 i)
{
	return "";
}
void AInternetInfo::WriteLog(FString Text)
{
}