// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Contact/Contact.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Stats/AI_Stats.h"
#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/GoalAttrit/GoalAttrit.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/GoalSurvive/GoalSurvive.h"
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

bool AContact::checkMyActor(AActor* contactTarget)
{
	return Target->Source == contactTarget;
}

uint8 AContact::queryEnum(FString statName, int32& noInfo)
{
	uint8 Response = 0;
	if (Target == nullptr)
	{
		mm->removeContact(Target->Source);
	}
	Response = Target->getEnumStat(statName, dynamicIL, staticIL, noInfo);
	return Response;
}

FVector AContact::queryVector(FString statName, int32& noInfo)
{
	FVector Response = FVector(0,0,0);
	if (Target == nullptr)
	{
		mm->removeContact(Target->Source);
	}
	Response = Target->getVecStat(statName, dynamicIL, staticIL, noInfo);
	return Response;
}

float AContact::queryFloat(FString statName, int32& noInfo)
{
	float Response = 0;
	//Response = Target.getFloatStat(statName, dynamicIL, staticIL, noInfo);
	return Response;
}

float AContact::rangeToTarget(FVector myPosit)
{
	float dist = 0;
	FVector hisPosit = FVector(0,0,0);
	int32 noInfo = 0;
	/*
	hisPosit = queryVector("position", noInfo);
	if (noInfo == 1)
	{
		return 4321;
	}
	else
	{
		dist = VSize(hisPosit - myPosit);
	}
	*/
	return dist / 16;
}

float AContact::lineOfSightToMe(APawn* me, bool alt, FVector altLoc)
{
	APawn* badGuy = nullptr;
	FVector hisOffset = FVector(0,0,0);
	FVector myOffset = FVector(0, 0, 0);
	FVector MyLoc = FVector(0, 0, 0);
	FVector hisHead = FVector(0, 0, 0);
	FVector myHead = FVector(0, 0, 0);
	FVector myBody = FVector(0, 0, 0);
	FVector myFeet = FVector(0, 0, 0);
	float SIGHT = 0;
	float Vertical = 0;
	SIGHT = 0;
	/*
	if (Target.Source->IsA(APawn::StaticClass()))
	{
		badGuy = Cast<APawn>(Target.Source);
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
		hisOffset = FVector(0, 0, Vertical);
	}
	else
	{
		hisOffset = FVector(0, 0, 0);
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
	myOffset = FVector(0, 0, Vertical);
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
	*/
	return SIGHT;
}

float AContact::lineOfSightToHim(APawn* me, bool alt, FVector altLoc)
{
	APawn* badGuy = nullptr;
	FVector myOffset = FVector(0, 0, 0);
	FVector MyLoc = FVector(0, 0, 0);
	FVector hisOffset = FVector(0, 0, 0);
	FVector myHead = FVector(0, 0, 0);
	FVector hisHead = FVector(0, 0, 0);
	FVector hisBody = FVector(0, 0, 0);
	FVector hisFeet = FVector(0, 0, 0);
	float SIGHT = 0;
	float Vertical = 0;
	SIGHT = 0;
	/*
	if (Target.Source->IsA(APawn::StaticClass()))
	{
		badGuy = Cast<APawn>(Target.Source);
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
		hisOffset = FVector(0, 0, Vertical);
	}
	else
	{
		hisOffset = FVector(0, 0, 0);
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
	myOffset = FVector(0, 0, Vertical);
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
	*/
	return SIGHT;
}

float AContact::lineOfFireToMe(APawn* me, bool alt, FVector altLoc)
{
	APawn* badGuy = nullptr;
	FVector myOffset = FVector(0, 0, 0);
	FVector MyLoc = FVector(0, 0, 0);
	FVector hisHead = FVector(0, 0, 0);
	FVector myHead = FVector(0, 0, 0);
	FVector myBody = FVector(0, 0, 0);
	FVector myFeet = FVector(0, 0, 0);
	float Fire = 0;
	float Vertical = 0;
	Fire = 0;
	/*
	badGuy = Cast<APawn>(Target.Source);
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
	myOffset = FVector(0, 0, Vertical);
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
	DebugLog(DEBUG_AI, "dnback:: Contact.lineOffireToMe(); los from " + badGuy + " to " + me + " = " + Fire);
	*/
	return Fire;
}

float AContact::lineOfFireToHim(APawn* me, bool alt, FVector altLoc)
{
	APawn* badGuy = nullptr;
	FVector hisOffset = FVector(0, 0, 0);
	FVector myHead = FVector(0, 0, 0);
	FVector hisHead = FVector(0, 0, 0);
	FVector hisBody = FVector(0, 0, 0);
	FVector hisFeet = FVector(0, 0, 0);
	float Fire = 0;
	float Vertical = 0;
	AActor* Other = nullptr;
	FVector junk1 = FVector(0, 0, 0);
	FVector junk2 = FVector(0, 0, 0);
	Fire = 0;
	/*
	badGuy = Cast<APawn>(Target.Source);
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
	hisOffset = FVector(0, 0, Vertical);
	myHead = me.Location;
	Other = Trace(junk1, junk2, badGuy->GetActorLocation(), me->GetActorLocation(), true);
	if (Other != badGuy)
	{
		return 0;
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
	*/
	return Fire;
}

bool AContact::update(FString Type, APawn* perceiver, float Intensity)
{
	float Range = 0;
	float los = 0;
	float sightBonus = 0;
	float hearingBonus = 0;
	float percIncr = 0;
	bool respot = false;
	if (perfect)
	{
		return false;
	}
	respot = false;
	/*
	percIncr = GetWorld()->GetTimeSeconds() - lastPerc;
	lastPerc = GetWorld()->GetTimeSeconds();
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
	dynamicIL =FMath::Clamp(dynamicIL, 0, 1);
	staticIL =FMath::Clamp(staticIL, 0, 1);
	*/
	return respot;
}

float AContact::threatAssessment(APawn* me, FString situation, FVector altLoc, float& cover)
{
	float Threat = 0;
	float Range = 0;
	float rangeFactor = 0;
	float arms = 0;
	float lof = 0;
	float hostile = 0;
	float Goal = 0;
	AGoal* goaltype = nullptr;
	int noInfo = 0;
	uint8 weapType = 0;
	FVector loc = FVector(0,0,0);
	/*
	if (Target == nullptr)
	{
		return 0;
	}
	if (Target.Source == nullptr)
	{
		return 0;
	}
	if (!Target.Source->IsA(APawn::StaticClass()))
	{
		return 0;
	}
	if (Cast<APawn>(Target.Source).Controller == nullptr)
	{
		return 0;
	}
	if (me == nullptr)
	{
		return 0;
	}
	if (me == Target.Source)
	{
		return 0;
	}
	Threat = 0;
	weapType = queryEnum("weapon", noInfo);
	if (noInfo == 1)
	{
		arms = 0.5;
	}
	else
	{
		switch(queryEnum("weapon", noInfo))
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
	if (isMyFriend(Cast<AAGP_Pawn>(me)) == 0)
	{
		hostile = 1;
	}
	else
	{
		hostile = 0;
	}
	if (Cast<AAGP_Pawn>(Target.Source).Controller->IsA(AHumanController::StaticClass()))
	{
		Goal = 1;
	}
	else
	{
		goaltype = AgentController(Cast<AAGP_Pawn>(Target.Source).Controller).ActiveGoal;
		if (goaltype->IsA(AGoalAttrit::StaticClass()))
		{
			Goal = 1;
		}
		else
		{
			if (goaltype->IsA(AGoalSurvive::StaticClass()))
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
		lof = lineOfFireToMe(me, true, altLoc);
		cover = 1 - lof;
		lof =FMath::Clamp(lof, 0.1, 1);
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
			lof =FMath::Clamp(lof, 0.1, 1);
			loc = me.Location;
		}
	}
	Range = rangeToTarget(loc);
	Range =FMath::Clamp(Range, 1, 100000000);
	rangeFactor =FMath::Clamp(3600 / Range * Range, 0, 1);
	Threat = rangeFactor * arms * lof * hostile * Goal;
	*/
	return Threat;
}

float AContact::vulnerability(APawn* Threat, FString situation, FVector altLoc)
{
	float Score = 0;
	float Range = 0;
	float rangeFactor = 0;
	float los = 0;
	float hostile = 0;
	float Goal = 0;
	AGoal* goaltype = nullptr;
	AAGP_Pawn* threatPawn = nullptr;
	Score = 0;
	/*
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); beginning vulnerability assessment of " + Target.Source.Name);
	if (Threat == Target.Source)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " + Threat.Name + " is no threat to himself");
		return 0;
	}
	if (Target == nullptr)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); AI_Stats for " + Self.Name + " is dead");
		return 0;
	}
	else
	{
		if (Target.Source == nullptr)
		{
			DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); Actor for " + Target.Name + " is dead");
			return 0;
		}
	}
	if (!Target.Source->IsA(APawn::StaticClass()))
	{
		return 0;
	}
	threatPawn = Cast<AAGP_Pawn>(Threat);
	if (threatPawn.Controller == nullptr)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); Controller for " + Pawn(Target.Source).Name + " is dead");
		return 0;
	}
	else
	{
		if (threatPawn == nullptr)
		{
			DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " + Threat.Name + " is dead and calling this function");
			return 0;
		}
	}
	if (threatPawn.getBestAmmoFromWeapon(threatPawn.Weapon) < 1)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " + Threat.Name + " is out of ammo doesn't present a threat to " + Target.Source.Name);
		return 0;
	}
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); queried weapon type");
	los = lineOfFireToHim(Threat);
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); queried los " + los);
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
	if (Cast<AAGP_Pawn>(Target.Source).Controller->IsA(AHumanController::StaticClass()))
	{
		Goal = 1;
	}
	else
	{
		goaltype = AgentController(Cast<AAGP_Pawn>(Target.Source).Controller).ActiveGoal;
		if (goaltype->IsA(AGoalSurvive::StaticClass()))
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
	Range =FMath::Clamp(Range, 1, 100000000);
	rangeFactor =FMath::Clamp(3600 / Range * Range, 0, 1);
	Score = rangeFactor * los * hostile * Goal;
	DebugLog(DEBUG_AI, "dnback:: Contact.vulnerability(); " + Threat + " presents a" @ situation @ "threat of " + Score + " to " + Target.Source);
	DebugLog(DEBUG_AI, "	range = " + Range + ", range factor = " + rangeFactor);
	DebugLog(DEBUG_AI, "	los = " + los);
	DebugLog(DEBUG_AI, "	hostile = " + hostile);
	DebugLog(DEBUG_AI, "	goal = " + Goal);
	DebugLog(DEBUG_AI, "		Total Threat = " + Threat);
	*/
	return Score;
}

AAGP_Pawn* AContact::getPawn()
{
	return Cast<AAGP_Pawn>(Target->Source);
}

bool AContact::isInvisible()
{
	return Target->bInvisible;
}

int32 AContact::isMyFriend(AAGP_Pawn* me)
{
	int32 retval = 0;
	uint8 hisTeam = 0;
	uint8 MyTeam = 0;
	int32 noInfo = 0;
	return 0;
	/*
	MyTeam = me.Stats.getEnumStat("team", 1, 1, noInfo);
	hisTeam = queryEnum("team", noInfo);
	if (noInfo == 1)
	{
		return - 1;
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
	*/
	return retval;
}
void AContact::Timer()
{
	/*
	if (perfect)
	{
		return;
	}
	if (GetWorld()->GetTimeSeconds() > lastPerc + 1)
	{
		dynamicIL -= 0.05 * TimerRate;
	}
	if (dynamicIL < 0)
	{
		DebugLog(DEBUG_AI, "dnback:: Contact.Timer(); I have completely forgotten about " + Target.Source.Name);
		dynamicIL = 0;
	}
	else
	{
		SetTimer(1, false);
	}
	*/
}
