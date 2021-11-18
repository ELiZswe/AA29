// All the original content belonged to the US Army


#include "AA29/Info/AGP_TrustManager/AGP_TrustManager.h"

AAGP_TrustManager::AAGP_TrustManager()
{
	ExperienceLevel = { 0, 500,  1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 17000, 19000, 21000, 23000, 25000, 27000, 29000, 31000, 33000, 35000, 38500, 42000, 45500, 49000, 52500, 56000, 59500, 63000, 66500, 70000, 75500, 81000, 86500, 92000, 97500, 103000, 108500, 114000, 119500, 125000, 133000, 141000, 149000, 157000, 165000, 173000, 181000, 189000, 197000, 205000, 216000, 227000, 238000, 249000, 260000, 271000, 282000, 293000, 304000, 315000, 329500, 344000, 358500, 373000, 387500, 402000, 416500, 431000, 445500, 460000, 478500, 497000, 515500, 534000, 552500, 571000, 589500, 608000, 626500, 645000, 668000, 691000, 714000, 737000, 760000, 783000, 806000, 829000, 852000, 875000 };
}

int32 AAGP_TrustManager::CalculateTrust(int32 Experience)
{
	int32 retTrust;
	retTrust = LookupTrust(Experience);
	retTrust = FMath::Clamp(retTrust, 0, 101 - 1);
	return retTrust;
}
int32 AAGP_TrustManager::LookupTrust(int32 Experience)
{
	int32 i;
	for (i = 0; i < 101; i++)
	{
		if (Experience < GetTrust(i))
		{
			return i - 1;
		}
	}
	return 101;
}
int32 AAGP_TrustManager::GetTrust(int32 Level)
{
	return ExperienceLevel[Level] / 10;
}