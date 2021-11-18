// All the original content belonged to the US Army


#include "AA29/Info/ReplicationInfo/PersonnelJacket/PersonnelJacket.h"
#include "Net/UnrealNetwork.h"

APersonnelJacket::APersonnelJacket()
{

}

void APersonnelJacket::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APersonnelJacket, Experience);
	DOREPLIFETIME(APersonnelJacket, Honor);
	DOREPLIFETIME(APersonnelJacket, bQualifiedSniper);
	DOREPLIFETIME(APersonnelJacket, bQualifiedAirborne);
	DOREPLIFETIME(APersonnelJacket, bQualifiedRanger);
	DOREPLIFETIME(APersonnelJacket, bQualifiedMedic);
	DOREPLIFETIME(APersonnelJacket, bQualifiedSF);
	DOREPLIFETIME(APersonnelJacket, bQualifiedJavelin);
	DOREPLIFETIME(APersonnelJacket, bQualifiedES2);
}


int32 APersonnelJacket::GetExperience()
{
	return Experience;
}
int32 APersonnelJacket::GetHonor()
{
	return Honor;
}
int32 APersonnelJacket::CalculateHonor(int32 CurrentExperience)
{
	if (CurrentExperience < 500)		{	return 0;	}
	if (CurrentExperience < 1000)		{	return 1;	}
	if (CurrentExperience < 1500)		{	return 2;	}
	if (CurrentExperience < 2000)		{	return 3;	}
	if (CurrentExperience < 2500)		{	return 4;	}
	if (CurrentExperience < 3000)		{	return 5;	}
	if (CurrentExperience < 3500)		{	return 6;	}
	if (CurrentExperience < 4000)		{	return 7;	}
	if (CurrentExperience < 4500)		{	return 8;	}
	if (CurrentExperience < 5000)		{	return 9;	}
	if (CurrentExperience < 6000)		{	return 10;	}
	if (CurrentExperience < 7000)		{	return 11;	}
	if (CurrentExperience < 8000)		{	return 12;	}
	if (CurrentExperience < 9000)		{	return 13;	}
	if (CurrentExperience < 10000)		{	return 14;	}
	if (CurrentExperience < 11000)		{	return 15;	}
	if (CurrentExperience < 12000)		{	return 16;	}
	if (CurrentExperience < 12000)		{	return 17;	}
	if (CurrentExperience < 14000)		{	return 18;	}
	if (CurrentExperience < 15000)		{	return 19;	}
	if (CurrentExperience < 17500)		{	return 20;	}
	if (CurrentExperience < 20000)		{	return 21;	}
	if (CurrentExperience < 22500)		{	return 22;	}
	if (CurrentExperience < 25000)		{	return 23;	}
	if (CurrentExperience < 27500)		{	return 24;	}
	if (CurrentExperience < 30000)		{	return 25;	}
	if (CurrentExperience < 32500)		{	return 26;	}
	if (CurrentExperience < 35000)		{	return 27;	}
	if (CurrentExperience < 37500)		{	return 28;	}
	if (CurrentExperience < 40000)		{	return 29;	}
	if (CurrentExperience < 44000)		{	return 30;	}
	if (CurrentExperience < 48000)		{	return 31;	}
	if (CurrentExperience < 52000)		{	return 32;	}
	if (CurrentExperience < 56000)		{	return 33;	}
	if (CurrentExperience < 60000)		{	return 34;	}
	if (CurrentExperience < 64000)		{	return 35;	}
	if (CurrentExperience < 68000)		{	return 36;	}
	if (CurrentExperience < 72000)		{	return 37;	}
	if (CurrentExperience < 76000)		{	return 38;	}
	if (CurrentExperience < 80000)		{	return 39;	}
	if (CurrentExperience < 86000)		{	return 40;	}
	if (CurrentExperience < 92000)		{	return 41;	}
	if (CurrentExperience < 98000)		{	return 42;	}
	if (CurrentExperience < 104000)		{	return 43;	}
	if (CurrentExperience < 110000)		{	return 44;	}
	if (CurrentExperience < 116000)		{	return 45;	}
	if (CurrentExperience < 122000)		{	return 46;	}
	if (CurrentExperience < 128000)		{	return 47;	}
	if (CurrentExperience < 134000)		{	return 48;	}
	if (CurrentExperience < 140000)		{	return 49;	}
	if (CurrentExperience < 149000)		{	return 50;	}
	if (CurrentExperience < 158000)		{	return 51;	}
	if (CurrentExperience < 167000)		{	return 52;	}
	if (CurrentExperience < 176000)		{	return 53;	}
	if (CurrentExperience < 185000)		{	return 54;	}
	if (CurrentExperience < 194000)		{	return 55;	}
	if (CurrentExperience < 203000)		{	return 56;	}
	if (CurrentExperience < 212000)		{	return 57;	}
	if (CurrentExperience < 221000)		{	return 58;	}
	if (CurrentExperience < 230000)		{	return 59;	}
	if (CurrentExperience < 243000)		{	return 60;	}
	if (CurrentExperience < 256000)		{	return 61;	}
	if (CurrentExperience < 268999)		{	return 62;	}
	if (CurrentExperience < 282000)		{	return 63;	}
	if (CurrentExperience < 295000)		{	return 64;	}
	if (CurrentExperience < 308000)		{	return 65;	}
	if (CurrentExperience < 321000)		{	return 66;	}
	if (CurrentExperience < 334000)		{	return 67;	}
	if (CurrentExperience < 347000)		{	return 68;	}
	if (CurrentExperience < 360000)		{	return 69;	}
	if (CurrentExperience < 383000)		{	return 70;	}
	if (CurrentExperience < 406000)		{	return 71;	}
	if (CurrentExperience < 429000)		{	return 72;	}
	if (CurrentExperience < 452000)		{	return 73;	}
	if (CurrentExperience < 475000)		{	return 74;	}
	if (CurrentExperience < 498000)		{	return 75;	}
	if (CurrentExperience < 521000)		{	return 76;	}
	if (CurrentExperience < 544000)		{	return 77;	}
	if (CurrentExperience < 567000)		{	return 78;	}
	if (CurrentExperience < 590000)		{	return 79;	}
	if (CurrentExperience < 633000)		{	return 80;	}
	if (CurrentExperience < 676000)		{	return 81;	}
	if (CurrentExperience < 719000)		{	return 82;	}
	if (CurrentExperience < 762000)		{	return 83;	}
	if (CurrentExperience < 805000)		{	return 84;	}
	if (CurrentExperience < 848000)		{	return 85;	}
	if (CurrentExperience < 891000)		{	return 86;	}
	if (CurrentExperience < 934000)		{	return 87;	}
	if (CurrentExperience < 977000)		{	return 88;	}
	if (CurrentExperience < 1020000)	{	return 89;	}
	if (CurrentExperience < 1103000)	{	return 90;	}
	if (CurrentExperience < 1186000)	{	return 91;	}
	if (CurrentExperience < 1269000)	{	return 92;	}
	if (CurrentExperience < 1352000)	{	return 93;	}
	if (CurrentExperience < 1435000)	{	return 94;	}
	if (CurrentExperience < 1518000)	{	return 95;	}
	if (CurrentExperience < 1601000)	{	return 96;	}
	if (CurrentExperience < 1684000)	{	return 97;	}
	if (CurrentExperience < 1767000)	{	return 98;	}
	if (CurrentExperience < 1850000)	{	return 99;	}
	return 100;
}
int32 APersonnelJacket::CalculateExperience(int32 CurrentHonor)
{
	switch (CurrentHonor)
	{
	case 0:		return 0;
	case 1:		return 500;
	case 2:		return 1000;
	case 3:		return 1500;
	case 4:		return 2000;
	case 5:		return 2500;
	case 6:		return 3000;
	case 7:		return 3500;
	case 8:		return 4000;
	case 9:		return 4500;
	case 10:	return 5000;
	case 11:	return 6000;
	case 12:	return 7000;
	case 13:	return 8000;
	case 14:	return 9000;
	case 15:	return 10000;
	case 16:	return 11000;
	case 17:	return 12000;
	case 18:	return 13000;
	case 19:	return 14000;
	case 20:	return 15000;
	case 21:	return 17500;
	case 22:	return 20000;
	case 23:	return 22500;
	case 24:	return 25000;
	case 25:	return 27500;
	case 26:	return 30000;
	case 27:	return 32500;
	case 28:	return 35000;
	case 29:	return 37500;
	case 30:	return 40000;
	case 31:	return 44000;
	case 32:	return 48000;
	case 33:	return 52000;
	case 34:	return 56000;
	case 35:	return 60000;
	case 36:	return 64000;
	case 37:	return 68000;
	case 38:	return 72000;
	case 39:	return 76000;
	case 40:	return 80000;
	case 41:	return 86000;
	case 42:	return 92000;
	case 43:	return 98000;
	case 44:	return 104000;
	case 45:	return 110000;
	case 46:	return 116000;
	case 47:	return 122000;
	case 48:	return 128000;
	case 49:	return 134000;
	case 50:	return 140000;
	case 51:	return 149000;
	case 52:	return 158000;
	case 53:	return 167000;
	case 54:	return 176000;
	case 55:	return 185000;
	case 56:	return 194000;
	case 57:	return 203000;
	case 58:	return 212000;
	case 59:	return 221000;
	case 60:	return 230000;
	case 61:	return 243000;
	case 62:	return 256000;
	case 63:	return 269000;
	case 64:	return 282000;
	case 65:	return 295000;
	case 66:	return 308000;
	case 67:	return 321000;
	case 68:	return 334000;
	case 69:	return 347000;
	case 70:	return 360000;
	case 71:	return 383000;
	case 72:	return 406000;
	case 73:	return 429000;
	case 74:	return 452000;
	case 75:	return 475000;
	case 76:	return 498000;
	case 77:	return 521000;
	case 78:	return 544000;
	case 79:	return 567000;
	case 80:	return 590000;
	case 81:	return 633000;
	case 82:	return 676000;
	case 83:	return 719000;
	case 84:	return 762000;
	case 85:	return 805000;
	case 86:	return 848000;
	case 87:	return 891000;
	case 88:	return 934000;
	case 89:	return 977000;
	case 90:	return 1020000;
	case 91:	return 1103000;
	case 92:	return 1186000;
	case 93:	return 1269000;
	case 94:	return 1352000;
	case 95:	return 1435000;
	case 96:	return 1518000;
	case 97:	return 1601000;
	case 98:	return 1684000;
	case 99:	return 1767000;
	case 100:	return 1850000;

	default:
		return 0;
	}

}
int32 APersonnelJacket::CalculateExperienceNeeded(int32 CurrentExperience, int32 CurrentHonor)
{
	return CalculateExperience(CurrentHonor + 1) - CurrentExperience;
}
