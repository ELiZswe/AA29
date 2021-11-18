// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Contact/Contact.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AContact::AContact()
{

}

void AContact::BeginPlay()
{
	staticIL = 0;
	dynamicIL = 0;
	lastPerc = 0;
	perfect = false;
	//SetTimer(3, false);
}
bool AContact::setMM(AMentalModel* pmm)
{
	mm = pmm;
	return true;
}
void AContact::checkMyActor(AActor* contactTarget)
{
	//Return Target.Source == contactTarget;
}
void AContact::queryEnum(FString statName, int32& noInfo)
{
	/*
	local byte Response;
	if (Target == None)
	{
		mm.removeContact(Target.Source);
	}
	Response = Target.getEnumStat(statName, dynamicIL, staticIL, noInfo);
	Return Response;
	*/
}
void AContact::queryVector(FString statName, int32& noInfo)
{
	/*
	local Object.Vector Response;
	if (Target == None)
	{
		mm.removeContact(Target.Source);
	}
	Response = Target.getVecStat(statName, dynamicIL, staticIL, noInfo);
	Return Response;
	*/
}
void AContact::queryFloat(FString statName, int32& noInfo)
{
	/*
	local float Response;
	Response = Target.getFloatStat(statName, dynamicIL, staticIL, noInfo);
	Return Response;
	*/
}
void AContact::rangeToTarget(FVector myPosit)
{
	/*
	local float dist;
	local Object.Vector hisPosit;
	local int noInfo;
	hisPosit = queryVector("position", noInfo);
	if (noInfo == 1)
	{
		Return 4321;
	}
	else
	{
		dist = VSize(hisPosit - myPosit);
	}
	Return dist / 16;
	*/
}
void AContact::lineOfSightToMe(APawn* me, bool alt, FVector altLoc)
{
	/*
	local Pawn badGuy;
	local Object.Vector hisOffset;
	local Object.Vector myOffset;
	local Object.Vector MyLoc;
	local Object.Vector hisHead;
	local Object.Vector myHead;
	local Object.Vector myBody;
	local Object.Vector myFeet;
	local float SIGHT;
	local float Vertical;
	SIGHT = 0;
	if (Target.Source.IsA('Pawn'))
	{
		badGuy = Pawn(Target.Source);
		if (badGuy.bIsProne)
		{
			Vertical = badGuy.ProneEyeHeight;
		}
		else
		{
			if (badGuy.bIsCrouched)
			{
				Vertical = badGuy.CrouchEyeHeight;
			}
			else
			{
				Vertical = badGuy.EyeHeight;
			}
		}
		hisOffset = MakeVect(0, 0, Vertical);
	}
	else
	{
		hisOffset = MakeVect(0, 0, 0);
	}
	if (me.bIsProne)
	{
		Vertical = me.ProneHeight * 0.95;
	}
	else
	{
		if (me.bIsCrouched)
		{
			Vertical = me.CrouchHeight * 0.95;
		}
		else
		{
			Vertical = me.CollisionHeight * 0.95;
		}
	}
	myOffset = MakeVect(0, 0, Vertical);
	if (alt)
	{
		MyLoc = altLoc;
	}
	else
	{
		MyLoc = me.Location;
	}
	hisHead = Target.Source.Location + hisOffset;
	myHead = MyLoc + myOffset;
	myBody = MyLoc;
	myFeet = MyLoc - myOffset;
	if (FastTrace(hisHead, myHead))
	{
		SIGHT += 0.34;
	}
	if (FastTrace(hisHead, myBody))
	{
		SIGHT += 0.33;
	}
	if (FastTrace(hisHead, myFeet))
	{
		SIGHT += 0.33;
	}
	Return SIGHT;
	*/
}
void AContact::lineOfSightToHim(APawn* me, bool alt, FVector altLoc)
{
	/*
	local Pawn badGuy;
	local Object.Vector myOffset;
	local Object.Vector MyLoc;
	local Object.Vector hisOffset;
	local Object.Vector myHead;
	local Object.Vector hisHead;
	local Object.Vector hisBody;
	local Object.Vector hisFeet;
	local float SIGHT;
	local float Vertical;
	SIGHT = 0;
	if (Target.Source.IsA('Pawn'))
	{
		badGuy = Pawn(Target.Source);
		if (badGuy.bIsProne)
		{
			Vertical = badGuy.ProneHeight * 0.95;
		}
		else
		{
			if (badGuy.bIsCrouched)
			{
				Vertical = badGuy.CrouchHeight * 0.95;
			}
			else
			{
				Vertical = badGuy.CollisionHeight * 0.95;
			}
		}
		hisOffset = MakeVect(0, 0, Vertical);
	}
	else
	{
		hisOffset = MakeVect(0, 0, 0);
	}
	if (me.bIsProne)
	{
		Vertical = me.ProneEyeHeight;
	}
	else
	{
		if (me.bIsCrouched)
		{
			Vertical = me.CrouchEyeHeight;
		}
		else
		{
			Vertical = me.EyeHeight;
		}
	}
	myOffset = MakeVect(0, 0, Vertical);
	if (alt)
	{
		MyLoc = altLoc;
	}
	else
	{
		MyLoc = me.Location;
	}
	myHead = MyLoc + myOffset;
	hisHead = Target.Source.Location + hisOffset;
	hisBody = Target.Source.Location;
	hisFeet = Target.Source.Location - hisOffset;
	if (FastTrace(myHead, hisHead))
	{
		SIGHT += 0.34;
	}
	if (FastTrace(myHead, hisBody))
	{
		SIGHT += 0.33;
	}
	if (FastTrace(myHead, hisFeet))
	{
		SIGHT += 0.33;
	}
	Return SIGHT;
	*/
}
void AContact::lineOfFireToMe(APawn* me, bool alt, FVector altLoc)
{
	/*
	local Pawn badGuy;
	local Object.Vector myOffset;
	local Object.Vector MyLoc;
	local Object.Vector hisHead;
	local Object.Vector myHead;
	local Object.Vector myBody;
	local Object.Vector myFeet;
	local float Fire;
	local float Vertical;
	Fire = 0;
	badGuy = Pawn(Target.Source);
	hisHead = badGuy.EyePosition();
	if (me.bIsProne)
	{
		Vertical = me.ProneHeight * 0.95;
	}
	else
	{
		if (me.bIsCrouched)
		{
			Vertical = me.CrouchHeight * 0.95;
		}
		else
		{
			Vertical = me.CollisionHeight * 0.95;
		}
	}
	myOffset = MakeVect(0, 0, Vertical);
	if (alt)
	{
		MyLoc = altLoc;
	}
	else
	{
		MyLoc = me.Location;
	}
	myHead = MyLoc + myOffset;
	myBody = MyLoc;
	myFeet = MyLoc - myOffset;
	if (FastTrace(hisHead, myHead))
	{
		Fire += 0.34;
	}
	if (FastTrace(hisHead, myBody))
	{
		Fire += 0.33;
	}
	if (FastTrace(hisHead, myFeet))
	{
		Fire += 0.33;
	}
	DebugLog(DEBUG_AI, "dnback:: Contact.lineOffireToMe(); los from " $ badGuy $ " to " $ me $ " = " $ Fire);
	Return Fire;
	*/
}
void AContact::lineOfFireToHim(APawn* me, bool alt, FVector altLoc)
{
	/*
	local Pawn badGuy;
	local Object.Vector hisOffset;
	local Object.Vector myHead;
	local Object.Vector hisHead;
	local Object.Vector hisBody;
	local Object.Vector hisFeet;
	local float Fire;
	local float Vertical;
	local Actor Other;
	local Object.Vector junk1;
	local Object.Vector junk2;
	Fire = 0;
	badGuy = Pawn(Target.Source);
	if (badGuy.bIsProne)
	{
		Vertical = badGuy.ProneHeight * 0.95;
	}
	else
	{
		if (badGuy.bIsCrouched)
		{
			Vertical = badGuy.CrouchHeight * 0.95;
		}
		else
		{
			Vertical = badGuy.CollisionHeight * 0.95;
		}
	}
	hisOffset = MakeVect(0, 0, Vertical);
	myHead = me.Location;
	Other = Trace(junk1, junk2, badGuy.Location, me.Location, True);
	if (Other != badGuy)
	{
		Return 0;
	}
	hisHead = badGuy.Location + hisOffset;
	hisBody = badGuy.Location;
	hisFeet = badGuy.Location - hisOffset;
	if (FastTrace(myHead, hisHead))
	{
		Fire += 0.34;
		DebugLog(DEBUG_AI, "dnback:: Contact.lineOfFireToHim()	head");
	}
	if (FastTrace(myHead, hisBody))
	{
		Fire += 0.33;
		DebugLog(DEBUG_AI, "dnback:: Contact.lineOfFireToHim()	body");
	}
	if (FastTrace(myHead, hisFeet))
	{
		Fire += 0.33;
		DebugLog(DEBUG_AI, "dnback:: Contact.lineOfFireToHim()	feet");
	}
	Return Fire;
	*/
}
void AContact::update(FString Type, APawn* perceiver, float Intensity)
{
	/*
	local float Range;
	local float los;
	local float sightBonus;
	local float hearingBonus;
	local float percIncr;
	local bool respot;
	if (perfect)
	{
		Return False;
	}
	respot = False;
	percIncr = Level.TimeSeconds - lastPerc;
	lastPerc = Level.TimeSeconds;
	if (percIncr > 1)
	{
		respot = true;
		percIncr = 0.1;
	}
	Range = rangeToTarget(perceiver.Location);
	los = lineOfSightToHim(perceiver);
	if (Type == "sight")
	{
		sightBonus = 0.2 * percIncr * 10 / Range * los;
		dynamicIL += sightBonus;
		staticIL += sightBonus;
	}
	else
	{
		if (Type == "sound")
		{
			hearingBonus = 0.2 * percIncr * 10 / Range * Intensity;
			dynamicIL += hearingBonus;
			staticIL += hearingBonus;
		}
		else
		{
			if (Type == "comms")
			{
			}
		}
	}
	dynamicIL = FClamp(dynamicIL, 0, 1);
	staticIL = FClamp(staticIL, 0, 1);
	Return respot;
	*/
}
void AContact::threatAssessment(APawn* me, FString situation, FVector altLoc, float& cover)
{
	/*
	local float Threat;
	local float Range;
	local float rangeFactor;
	local float arms;
	local float lof;
	local float hostile;
	local float Goal;
	local Goal goaltype;
	local int noInfo;
	local byte weapType;
	local Object.Vector loc;
	if (Target == None)
	{
		Return 0;
	}
	if (Target.Source == None)
	{
		Return 0;
	}
	if (!Target.Source.IsA('Pawn'))
	{
		Return 0;
	}
	if (Pawn(Target.Source).Controller == None)
	{
		Return 0;
	}
	if (me == None)
	{
		Return 0;
	}
	if (me == Target.Source)
	{
		Return 0;
	}
	Threat = 0;
	weapType = queryEnum("weapon", noInfo);
	if (noInfo == 1)
	{
		arms = 0.5;
	}
	else
	{
		Switch(queryEnum("weapon", noInfo))
		{
			case 1:
				arms = 0.1;
				break;
			case 2:
				arms = 1;
				break;
			case 3:
				arms = 2;
				break;
			case 0:
				arms = 0.5;
				break;
			default:
				arms = 0;
				DebugLog(DEBUG_AI, "dnback:: Contact.threatAssessment(); unknown weapon type ");
		}
	}
	if (isMyFriend(AGP_Pawn(me)) == 0)
	{
		hostile = 1;
	}
	else
	{
		hostile = 0;
	}
	if (AGP_Pawn(Target.Source).Controller.IsA('HumanController'))
	{
		Goal = 1;
	}
	else
	{
		goaltype = AgentController(AGP_Pawn(Target.Source).Controller).ActiveGoal;
		if (goaltype.IsA('GoalAttrit'))
		{
			Goal = 1;
		}
		else
		{
			if (goaltype.IsA('GoalSurvive'))
			{
				Goal = 0.25;
			}
			else
			{
				Goal = 0.75;
			}
		}
	}
	if (situation == "notional")
	{
		Range = rangeToTarget(altLoc);
		lof = lineOfFireToMe(me, True, altLoc);
		cover = 1 - lof;
		lof = FClamp(lof, 0.1, 1);
		loc = altLoc;
	}
	else
	{
		if (situation == "max")
		{
			Range = 1;
			lof = 1;
			hostile = 1;
			Goal = 1;
			loc = me.Location;
		}
		else
		{
			situation = "current";
			lof = lineOfFireToMe(me);
			cover = 1 - lof;
			lof = FClamp(lof, 0.1, 1);
			loc = me.Location;
		}
	}
	Range = rangeToTarget(loc);
	Range = FClamp(Range, 1, 100000000);
	rangeFactor = FClamp(3600 / Range * Range, 0, 1);
	Threat = rangeFactor * arms * lof * hostile * Goal;
	Return Threat;
	*/
}
void AContact::vulnerability(APawn* Threat, FString situation, FVector altLoc)
{
	/*
	local float Score;
	local float Range;
	local float rangeFactor;
	local float los;
	local float hostile;
	local float Goal;
	local Goal goaltype;
	local AGP_Pawn threatPawn;
	Score = 0;
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); beginning vulnerability assessment of " $ Target.Source.Name);
	if (Threat == Target.Source)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " $ Threat.Name $ " is no threat to himself");
		Return 0;
	}
	if (Target == None)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); AI_Stats for " $ Self.Name $ " is dead");
		Return 0;
	}
	else
	{
		if (Target.Source == None)
		{
			DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); Actor for " $ Target.Name $ " is dead");
			Return 0;
		}
	}
	if (!Target.Source.IsA('Pawn'))
	{
		Return 0;
	}
	threatPawn = AGP_Pawn(Threat);
	if (threatPawn.Controller == None)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); Controller for " $ Pawn(Target.Source).Name $ " is dead");
		Return 0;
	}
	else
	{
		if (threatPawn == None)
		{
			DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " $ Threat.Name $ " is dead and calling this function");
			Return 0;
		}
	}
	if (threatPawn.getBestAmmoFromWeapon(threatPawn.Weapon) < 1)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " $ Threat.Name $ " is out of ammo doesn't present a threat to " $ Target.Source.Name);
		Return 0;
	}
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); queried weapon type");
	los = lineOfFireToHim(Threat);
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); queried los " $ los);
	if (isMyFriend(threatPawn) == 0)
	{
		hostile = 1;
	}
	else
	{
		hostile = 0;
	}
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); queried friendliness");
	Range = rangeToTarget(Threat.Location);
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); queried range");
	if (AGP_Pawn(Target.Source).Controller.IsA('HumanController'))
	{
		Goal = 1;
	}
	else
	{
		goaltype = AgentController(AGP_Pawn(Target.Source).Controller).ActiveGoal;
		if (goaltype.IsA('GoalSurvive'))
		{
			Goal = 1.5;
		}
		else
		{
			Goal = 1;
		}
	}
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); queried controller and goal");
	if (situation == "notional")
	{
		Range = rangeToTarget(altLoc);
	}
	else
	{
		if (situation == "max")
		{
			Range = 1;
			los = 1;
			hostile = 1;
			Goal = 1;
		}
		else
		{
			situation = "current";
		}
	}
	Range = FClamp(Range, 1, 100000000);
	rangeFactor = FClamp(3600 / Range * Range, 0, 1);
	Score = rangeFactor * los * hostile * Goal;
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " $ Threat $ " presents a" @ situation @ "threat of " $ Score $ " to " $ Target.Source);
	DebugLog(DEBUG_AI, "	range = " $ Range $ ", range factor = " $ rangeFactor);
	DebugLog(DEBUG_AI, "	los = " $ los);
	DebugLog(DEBUG_AI, "	hostile = " $ hostile);
	DebugLog(DEBUG_AI, "	goal = " $ Goal);
	DebugLog(DEBUG_AI, "		Total Threat = " $ Threat);
	Return Score;
	*/
}
void AContact::getPawn()
{
	//Return AGP_Pawn(Target.Source);
}
void AContact::isInvisible()
{
	//Return Target.bInvisible;
}
void AContact::isMyFriend(AAGP_Pawn* me)
{
	/*
	local int retval;
	local byte hisTeam;
	local byte MyTeam;
	local int noInfo;
	Return 0;
	MyTeam = me.Stats.getEnumStat("team", 1, 1, noInfo);
	hisTeam = queryEnum("team", noInfo);
	if (noInfo == 1)
	{
		Return - 1;
	}
	if (MyTeam == 0 || MyTeam == 4 || hisTeam == 0 || hisTeam == 4)
	{
		retval = -1;
	}
	else
	{
		if (MyTeam == 1 || MyTeam == 2)
		{
			if (hisTeam == 1 || hisTeam == 2)
			{
				retval = 1;
			}
			else
			{
				if (hisTeam == 3)
				{
					retval = -1;
				}
				else
				{
					retval = 0;
				}
			}
		}
		else
		{
			if (MyTeam == 3)
			{
				if (hisTeam == 3)
				{
					retval = 1;
				}
				else
				{
					retval = -1;
				}
			}
			else
			{
				if (hisTeam == 5 || hisTeam == 6)
				{
					retval = 1;
				}
				else
				{
					if (hisTeam == 3)
					{
						retval = -1;
					}
					else
					{
						retval = 0;
					}
				}
			}
		}
	}
	Return retval;
	*/
}
void AContact::Timer()
{
	/*
	if (perfect)
	{
		Return;
	}
	if (Level.TimeSeconds > lastPerc + 1)
	{
		dynamicIL -= 0.05 * TimerRate;
	}
	if (dynamicIL < 0)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.Timer(); I have completely forgotten about " $ Target.Source.Name);
		dynamicIL = 0;
	}
	else
	{
		SetTimer(1, False);
	}
	*/
}