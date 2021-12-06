// All the original content belonged to the US Army


#include "AA29/Object/CheatManager/Cheater/Cheater.h"

UCheater::UCheater()
{

}

void UCheater::PlayerLock(bool B)
{
	//Outer.LockPlayer(B, B);
}

void UCheater::Entropy()
{
	/*
	Outer.bGodMode = (!Outer.bGodMode);
	if (Outer.bGodMode)
	{
		Outer.ClientMessage("Entropy Says: I'm yer huckleberry -- God Mode On");
	}
	else
	{
		Outer.ClientMessage("Entropy Says: Go practice, then come back -- God Mode Off");
	}
	*/
}

void UCheater::Deathstalker()
{
	/*
	Outer.bUnlimitedAmmo = (!Outer.bUnlimitedAmmo);
	if (Outer.bUnlimitedAmmo)
	{
		Outer.ClientMessage("Deathstalker Says: Make up for your lack in accuracy with lots of lead! -- Unlimited Ammo On");
	}
	else
	{
		Outer.ClientMessage("Deathstalker Says: So you decided to play with the big boys after all?  -- Unlimited Ammo Off");
	}
	*/
}

void UCheater::Judas()
{
	/*
	Outer.bPerfectAccuracy = (!Outer.bPerfectAccuracy);
	if (Outer.bPerfectAccuracy)
	{
		Outer.ClientMessage("Judas Says: You're not me and I know it! Spread my teachings -- Perfect Accuracy On");
	}
	else
	{
		Outer.ClientMessage("Judas Says: Practice and someday, maybe... just maybe you won't have to cheat -- Perfect Accuracy Off");
	}
	*/
}

void UCheater::PatVaccine()
{
	/*
	Outer.bFriendlyFireOff = (!Outer.bFriendlyFireOff);
	if (Outer.bFriendlyFireOff)
	{
		Outer.ClientMessage("Finally, I can walk near friends safely!");
	}
	else
	{
		Outer.ClientMessage("Uh - oh! Danger around every corner!");
	}
	*/
}

void UCheater::Spook()
{
	/*
	Outer.bInvisible = (!Outer.bInvisible);
	AGP_Pawn(Outer.Pawn).Stats.bInvisible = Outer.bInvisible;
	if (Outer.bInvisible)
	{
		Outer.ClientMessage("Oh no! Where'd you go? Now the AI can't see you!");
	}
	else
	{
		Outer.ClientMessage("Better stay hidden, you're visible now");
	}
	*/
}

void UCheater::FOV(float F)
{
	/*
	if ((F >= 80) || (Outer.Level.NetMode == NM_Standalone))
	{
		Outer.DesiredFOV = FClamp(F, 1, 170);
	}
	*/
}

void UCheater::LowRes()
{
	/*
	if (Outer.Pawn.ResolutionSwap == 0)
	{
		Outer.ClientMessage("LOD deactivated");
		Outer.Pawn.ResolutionSwap = 1;
	}
	else
	{
		Outer.ClientMessage("LOD activated");
		Outer.Pawn.ResolutionSwap = 0;
	}
	*/
}

void UCheater::newTeamClass(ASoldierClass*  sclass)
{
	/*
	local SoldierClass LastClass;
	if (sclass == None)
	{
		Outer.DebugLog(1, "AGP:Cheater::newTeamClass received null class.");
		return;
	}
	LastClass = AGP_Pawn(Outer.Pawn).TeamClass;
	AGP_Pawn(Outer.Pawn).TeamClass = Outer.Spawn(sclass, AGP_Pawn(Outer.Pawn));
	AGP_Pawn(Outer.Pawn).TeamClass.adjustAttributes(LastClass);
	AGP_Pawn(Outer.Pawn).EmptyInventory(true);
	AGP_Pawn(Outer.Pawn).TeamClass.addClassInventory();
	Outer.Pawn.Controller.TeamClassClass = sclass;
	LastClass.Destroy();
	*/
}

void UCheater::newTeamRole(ASoldierRole* srole)
{
	
	/*
	local SoldierRole LastRole;
	if (srole == None)
	{
		Outer.DebugLog(1, "AGP:Cheater::newTeamRole received null class.");
		return;
	}
	LastRole = AGP_Pawn(Outer.Pawn).TeamRole;
	AGP_Pawn(Outer.Pawn).TeamRole = Outer.Spawn(srole);
	LastRole.Destroy();
	*/
}

void UCheater::Class(FString ClassName)
{
	/*
	local ASoldierClass*  sclass;
	FString sclass_name = "";
	if ((Outer.Level.Title == "Virtual Recruiting Station") || Outer.Level.GetTourIsTraining(Outer.Level.iTour))
	{
		Log("Cheating disabled for Class command in training");
		Outer.ClientMessage("Cheating is not allowed");
		return;
	}
	PlayerLock(false);
	Outer.CleanUp();
	switch (ClassName)
	{
	case "":
		Outer.ScreenPrint("Type \"Class X\" where classes are R, AR, G, S, RCT, AK, SL, S24, SVD, AK74, M4A1, M4A1Auto, GP, RPK, MOS, D, PSO");
		return;
	case "AR":
	case "AutomaticRifleman":
		sclass_name = "AGP_Characters.ClassAutomaticRifleman";
		break;
	case "R":
	case "Rifleman":
		sclass_name = "AGP_Characters.ClassRifleman";
		break;
	case "RCT":
	case "Recruit":
		sclass_name = "AGP_Characters.ClassRecruit";
		break;
	case "AK":
	case "RiflemanAK":
		sclass_name = "AGP_Characters.ClassRiflemanAK";
		break;
	case "G":
	case "Grenadier":
		sclass_name = "AGP_Characters.ClassGrenadier";
		break;
	case "S":
	case "Sniper":
		sclass_name = "AGP_Characters.ClassSniper";
		break;
	case "S24":
	case "Sniper24":
		sclass_name = "AGP_Characters.ClassSniper24_US";
		break;
	case "SVD":
	case "SniperSVD":
		sclass_name = "AGP_Characters.ClassSniperSVD";
		break;
	case "AK74":
	case "AK74su":
		sclass_name = "AGP_Characters.ClassRiflemanAK74su";
		break;
	case "AK74suReflex":
		sclass_name = "AGP_Characters.ClassGuerrillaAK74suReflex";
		break;
	case "M":
	case "M4A1":
		sclass_name = "AGP_Characters.ClassRiflemanM4A1AutoIron";
		break;
	case "MA":
	case "M4A1Auto":
		sclass_name = "AGP_Characters.ClassRiflemanM4A1Auto";
		break;
	case "GP":
		sclass_name = "AGP_Characters.ClassGrenadierGP30_Op";
		break;
	case "RPK":
		sclass_name = "AGP_Characters.ClassAutomaticRiflemanRPK";
		break;
	case "Mos":
		sclass_name = "AGP_Characters.ClassSniperMos";
		break;
	case "RPG":
		sclass_name = "AGP_Characters.ClassRPG";
		break;
	case "AT4":
		sclass_name = "AGP_Characters.ClassAT4Rocket";
		break;
	case "M4M":
		sclass_name = "AGP_Characters.ClassRiflemanM4A1Mod";
		break;
	case "SF":
		sclass_name = "AGP_Characters.ClassSF";
		break;
	case "M9":
		sclass_name = "AGP_Characters.ClassPistol";
		break;
	case "SPR":
		sclass_name = "AGP_Characters.ClassSFSniper";
		break;
	case "V":
		sclass_name = "AGP_Characters.ClassGuerrillaSniper";
		break;
	case "D":
		sclass_name = "AGP_Characters.ClassDemolitions";
		break;
	case "PSO":
		sclass_name = "AGP_Characters.ClassGuerrillaPSO";
		break;
	case "BDM":
		sclass_name = "AGP_Characters.ClassBDMRocket";
		break;
	case "J":
		sclass_name = "AGP_Characters.ClassJavelin";
		break;
	case "JT":
		sclass_name = "AGP_Characters.ClassJavelinTube";
		break;
	case "RPG9":
		sclass_name = "AGP_Characters.ClassGuerrillaRPGNine";
		break;
	default:
		Outer.ScreenPrint("Unrecognized class " $ ClassName);
		Outer.ScreenPrint("Type \"Class X\" where classes are R, AR, G, S, RCT, AK, SL, S24, SVD, AK74, M4A1, M4A1Auto, GP, RPK, MOS, D, PSO, BDM, J");
		return;
	}
	AGP_Pawn(Outer.Pawn).bForcedWeaponChange = true;
	sclass = ASoldierClass*(DynamicLoadObject(sclass_name, Class'Class'));
	newTeamClass(sclass);
	*/
}

void UCheater::Role(FString rolename)
{
	/*
	local class<SoldierRole>  srole;
	FString srole_name = "";
	switch (rolename)
	{
	case "":
		Outer.ScreenPrint("Type \"Role X\" where roles are SL, FL, FM");
		return;
	case "SL":
	case "SquadLeader":
		srole_name = "AGP_AI.SquadLeaderRole";
		break;
	case "FL":
	case "FTL":
	case "FTLeader":
		srole_name = "AGP_AI.FTLeaderRole";
		break;
	case "FM":
	case "FTM":
	case "FTMember":
		srole_name = "AGP_AI.FTMemberRole";
		break;
	default:
		Outer.ScreenPrint("Unrecognized role " $ rolename);
		Outer.ScreenPrint("Type \"Role X\" where roles are SL, FL, FM");
		return;
	}
	srole = class<SoldierRole>(DynamicLoadObject(srole_name, Class'Class'));
	newTeamRole(srole);
	*/
}

void UCheater::m4a1()
{
	//Summon("AGP_Inventory.PickupW_M4A1_Rifle_Mod");
}

void UCheater::svd()
{
	//Summon("AGP_Inventory.PickupW_SVD_Sniper");
}

void UCheater::AK74su()
{
	//Summon("AGP_Inventory.PickupW_AK74su_Rifle");
}

void UCheater::M16A2()
{
	//Summon("AGP_Inventory.PickupW_M16A2_Rifle");
}

void UCheater::AMMO_556_30()
{
	//Summon("AGP_Inventory.PickupAmmo_556mm_30_Mag");
}

void UCheater::M249()
{
	//Summon("AGP_Inventory.PickupW_M249_SAW");
}

void UCheater::AK47()
{
	//Summon("AGP_Inventory.PickupW_AK47_Rifle");
}

void UCheater::AT4()
{
	//Summon("AGP_Inventory.PickupW_AT4_Rocket");
}

void UCheater::AMMO_556_200()
{
	//Summon("AGP_Inventory.PickupAmmo_556mm_200_Belt");
}

void UCheater::M67Frag()
{
	//Summon("AGP_Inventory.PickupT_M67_Frag");
}

void UCheater::RGD5()
{
	//Summon("AGP_Inventory.AGP_RGD5");
}

void UCheater::M83Smoke()
{
	//Summon("AGP_Inventory.AGP_M83Smoke");
}

void UCheater::FlashBang()
{
	//Summon("AGP_Inventory.AGP_FlashBang");
}

void UCheater::M82Barrett()
{
	//Summon("AGP_Inventory.AGP_M82Barrett");
}

void UCheater::FillAmmo()
{
	/*
	local Inventory Inv;
	if (true)
	{
		Inv = Outer.Spawn(Outer.Pawn.Weapon.GetCurrentAmmoName(), Outer.Pawn);
		if (!Outer.Pawn.AddInventory(Inv))
		{
		}
	}
	if (Inv != None)
	{
		Inv.Destroy();
		Inv = None;
	}
	*/
}

void UCheater::FixRuined()
{
	//AGP_Weapon(Outer.Pawn.Weapon).FixRuinedJam();
}

void UCheater::NoJam()
{
	//AGP_Weapon(Outer.Pawn.Weapon).bMisFire = (!AGP_Weapon(Outer.Pawn.Weapon).bMisFire);
}

void UCheater::WpnRecoil()
{
	/*
	AGP_Weapon(Outer.Pawn.Weapon).bWpnRecoil = (!AGP_Weapon(Outer.Pawn.Weapon).bWpnRecoil);
	Outer.ScreenPrint("Weapon Recoil" @ string(AGP_Weapon(Outer.Pawn.Weapon).bWpnRecoil));
	*/
}

void UCheater::WpnAccuracy()
{
	/*
	AGP_Weapon(Outer.Pawn.Weapon).bWpnAccuracy = (!AGP_Weapon(Outer.Pawn.Weapon).bWpnAccuracy);
	Outer.ScreenPrint("Weapon Accuracy" @ string(AGP_Weapon(Outer.Pawn.Weapon).bWpnAccuracy));
	*/
}

void UCheater::TestWeapon()
{
	//Summon("AGP_Inventory.AGP_TestWeapon");
}

void UCheater::btr60()
{
	//Summon("AGP_Vehicles.BTR60P");
}

void UCheater::SFHumvee()
{
	//Summon("AGP_Vehicles.SFHumvee");
}

void UCheater::HMMWV()
{
	//Summon("AGP_Vehicles.M1114_HMMWV");
}

void UCheater::HMMWV_mk19()
{
	//Summon("AGP_Vehicles.M1114_mk19_HMMWV");
}

void UCheater::Technical()
{
	//Summon("AGP_Vehicles.Technical");
}

void UCheater::ChevySuburban()
{
	//Summon("AGP_Vehicles.ChevySuburban");
}

void UCheater::USTechnical()
{
	//Summon("AGP_Vehicles.US_Technical");
}

void UCheater::BMP1()
{
	//Summon("AGP_Vehicles.BMP1_APC");
}

void UCheater::T62A()
{
	//Summon("AGP_Vehicles.T62A");
}

void UCheater::HEMTTC()
{
	//Summon("AGP_Vehicles.M985_HEMTT");
}

void UCheater::HEMTTF()
{
	//Summon("AGP_Vehicles.M978_HEMTT");
}

void UCheater::FMTV()
{
	//Summon("AGP_Vehicles.M1083_FMTV");
}

void UCheater::ASV()
{
	//Summon("AGP_Vehicles.M1117_ASV");
}

void UCheater::JavCheat(FString javobject)
{
	/*
	local class<Actor>  NewClass;
	FVector SpawnLoc = FVector(0, 0, 0);
	FString ClassName = "";
	int32 offset = 0;
	offset = 75;
	switch (javobject)
	{
	case "clu":
		ClassName = "AGP_Armory.PickupW_Javelin";
		break;
	case "tube":
		ClassName = "AGP_Armory.Pickup_Javelin_Tube";
		break;
	case "tank":
		ClassName = "AGP_Vehicles.T62A";
		offset = 300;
		break;
	case "tech":
		ClassName = "AGP_Vehicles.Technical";
		offset = 300;
		break;
	default:
		Log("JavCheat: Illegal Object");
	}
	if (ClassName != "")
	{
		Log("JavCheat Fabricate " $ ClassName);
		NewClass = class<Actor>(DynamicLoadObject(ClassName, Class'Class'));
		if (NewClass != None)
		{
			if (Outer.Pawn != None)
			{
				SpawnLoc = Outer.Pawn.Location;
			}
			else
			{
				SpawnLoc = Outer.Location;
			}
			Outer.Spawn(NewClass, , , ((SpawnLoc + (float(offset) * Vector(Outer.Rotation))) + (vect(0, 0, 1) * float(15))));
		}
	}
	*/
}

