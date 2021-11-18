// All the original content belonged to the US Army


#include "AA29/Info/Security/AGP_MD5Dumper/AGP_MD5Dumper.h"

AAGP_MD5Dumper::AAGP_MD5Dumper()
{

}

/*
State StartUp
{
	Function BeginState()
	{
		if (bPerformDump)
		{
			PerformDump();
		}
	}
}
*/

void AAGP_MD5Dumper::PerformDump()
{
	/*
	for (iIndex = 0; iIndex < Checks.Length; iIndex++)
	{
		GetMD5(MD5Type[iIndex], Checks[iIndex]);
	}
	*/
}

void AAGP_MD5Dumper::GetMD5(int Type, FString Check)
{
	//NativePerform(Type, Check, "");
}

void AAGP_MD5Dumper::ServerCallback(int SecType, FString Data)
{
	//Log("[" $ iIndex $ "] Checking [" $ Checks[iIndex] $ "] type [" $ MD5Type[iIndex] $ "] MD5: " $ Data);
}