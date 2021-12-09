// All the original content belonged to the US Army


#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"

AMentalModel::AMentalModel()
{
	StartUp = true;
}

void AMentalModel::PostBeginPlay()
{
	/*
	DebugLog(DEBUG_AI, "dnback:: MentalModel.PostBeginPlay()");
	Tension = 0;
	SetTimer(1, True);
	*/
}
void AMentalModel::Timer()
{
	/*
	local AI_Stats Stats;
	if (StartUp)
	{
		DebugLog(DEBUG_AI, "dnback:: MentalModel.Timer(); first time through, " $ Self $ " polling for autodiscovery");
		ForEach AllActors(Class'AI_Stats', Stats)
		{
			if (Stats.bAutoDiscoverMe)
			{
				DebugLog(DEBUG_AI, "			found " $ Stats $ ", adding to " $ Self);
				addContact(Stats, 1, 1);
			}
		}
		StartUp = False;
	}
	Tension -= 1;
	Tension = FClamp(Tension, 0, 10);
	*/
}
int32 AMentalModel::getNumContacts()
{
	return numContacts;
}
int32 AMentalModel::getNumFriends(AAGP_Pawn* this_pawn)
{
	int32 friends=0;
	/*
	local int i;
	local byte contact_team;
	local byte this_team;
	friends = 0;
	this_team = this_pawn.idTeam;
	for (i = 0; i < numContacts; i++)
	{
		contact_team = allContacts[i].Target.GetTeam();
		if (contact_team == this_team)
		{
			friends++;
		}
	}
	*/
	return friends;
}
int32 AMentalModel::getNumEnemies(AAGP_Pawn* this_pawn)
{
	int32 enemies=0;
	/*
	local int i;
	local byte contact_team;
	local byte this_team;
	enemies = 0;
	this_team = this_pawn.idTeam;
	for (i = 0; i < numContacts; i++)
	{
		contact_team = allContacts[i].Target.GetTeam();
		if (contact_team != this_team)
		{
			if (contact_team != 0)
			{
				enemies++;
			}
		}
	}
	*/
	return enemies;
}
void AMentalModel::logDump()
{
	/*
	local int i;
	Log("dnback:: MentalModel.logDump(); printing contents of mental model " $ Self.Name $ " numContacts " $ numContacts);
	for (i = 0; i < numContacts; i++)
	{
		Log("	" $ allContacts[i].Target.Source.Name $ " at index" $ i);
	}
	*/
}
int32 AMentalModel::findActorIdx(AActor* findThis)
{
	/*
	local int i;
	for (i = 0; i < numContacts; i++)
	{
		if (allContacts[i].Target.Source == findThis)
		{
			Return i;
		}
	}
	*/
	return - 1;
}
void AMentalModel::findContact(AActor* findThis)
{
	/*
	local int i;
	for (i = 0; i < numContacts; i++)
	{
		if (allContacts[i].Target.Source == findThis)
		{
			Return allContacts[i];
		}
	}
	Return None;
	*/
}
void AMentalModel::getBestPickup(APawn* me, APickup* &out_pickup)
{
	/*
	local Pickup a_pickup;
	local Pickup best_pickup;
	local float a_score;
	local float best_score;
	best_score = 0;
	a_pickup = Level.PickupList;
	if (a_pickup != None)
	{
		a_score = a_pickup.BotDesireability(me);
		DebugLog(DEBUG_InvAI, "MentalModel::getBestPickup()	Evaluated " $ a_pickup @ a_score);
		if (a_score > best_score)
		{
			best_pickup = a_pickup;
			best_score = a_score;
		}
		a_pickup = a_pickup.Next;
	}
	out_pickup = best_pickup;
	Return best_score;
	*/
}
void AMentalModel::getBiggestThreat(APawn* me, FString situation, FVector altLoc)
{
	/*
	local int i;
	local float highThreat;
	local float thisThreat;
	local int highIndex;
	highIndex = -1;
	highThreat = 0.01;
	for (i = 0; i < numContacts; i++)
	{
		if (me == None)
		{
			Log("dnback:: MentalModel.getBiggestThreat(); 'me' is dead");
			Return None;
		}
		if (allContacts[i].Target.Source != None)
		{
			thisThreat = allContacts[i].threatAssessment(me, situation, altLoc);
			if (thisThreat > highThreat)
			{
				highThreat = thisThreat;
				highIndex = i;
			}
		}
	}
	if (highIndex != -1)
	{
		Return allContacts[highIndex];
	}
	else
	{
		Return None;
	}
	*/
}
void AMentalModel::totalThreatAssessment(APawn* me, FString situation, FVector altLoc, float &cover)
{
	/*
	local int i;
	local Contact tempCont;
	local float Threat;
	local float Gain;
	local int friendly;
	local int moreTargets;
	local int moreHostiles;
	local int noInfo;
	local float cond;
	local float friendRange;
	local float coverAdd;
	Threat = 0;
	moreTargets = 0;
	moreHostiles = 0;
	cover = 0;
	for (i = 0; i < numContacts; i++)
	{
		tempCont = allContacts[i];
		friendly = tempCont.isMyFriend(AGP_Pawn(me));
		if (friendly == 1)
		{
			cond = tempCont.queryFloat("condition", noInfo);
			if (noInfo == 1)
			{
				moreTargets += 0.5;
			}
			else
			{
				friendRange = tempCont.rangeToTarget(me.Location);
				if (tempCont.rangeToTarget(me.Location) < 20 && cond > 0)
				{
					moreTargets++;
				}
			}
		}
		else
		{
			if (friendly == 0)
			{
				moreHostiles++;
				Gain = tempCont.threatAssessment(me, situation, altLoc, coverAdd);
				cover += coverAdd;
				Threat += Gain;
				coverAdd = 0;
			}
		}
	}
	if (moreTargets > 0)
	{
		Tension = moreHostiles / moreTargets;
	}
	else
	{
		Tension = 0;
	}
	if (moreTargets > 0)
	{
		Threat /= moreTargets;
	}
	if (moreHostiles > 0)
	{
		cover /= moreHostiles;
	}
	else
	{
		cover = 0;
	}
	if (me.Health > 0)
	{
		Threat *= 100 / me.Health;
	}
	Return Threat;
	*/
}
void AMentalModel::attackAssessment(APawn* me, FString situation, FVector altLoc)
{
	/*
	local Contact tempCont;
	local float assessment;
	if (AGP_Weapon(me.Weapon).WeaponDisabled() == True)
	{
		assessment = 0;
	}
	else
	{
		tempCont = getMostVulnerable(me, assessment, situation, altLoc);
		if (tempCont == None)
		{
			DebugLog(DEBUG_AI, "dnback:: MentalModel.attackAssessment(); " $ me $ " knows of no targets");
		}
	}
	Return assessment;
	*/
}
void AMentalModel::getMostVulnerable(APawn* me, float &vuln, FString situation, FVector altLoc)
{
	/*
	local int i;
	local float highVuln;
	local float thisVuln;
	local int highIndex;
	highIndex = -1;
	highVuln = 0.01;
	for (i = 0; i < numContacts; i++)
	{
		if (me == None)
		{
			DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); 'me' is dead");
			Return None;
		}
		if (allContacts[i].Target.Source != None)
		{
			thisVuln = allContacts[i].vulnerability(me);
			DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); I see " $ allContacts[i] @ thisVuln $ allContacts[i].Target.Source);
			if (thisVuln > highVuln)
			{
				highVuln = thisVuln;
				highIndex = i;
			}
		}
	}
	if (highIndex != -1)
	{
		DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); biggest turkey for " $ me.Name $ " is " $ allContacts[highIndex].Target.Source.Name);
		vuln = highVuln;
		Return allContacts[highIndex];
	}
	else
	{
		DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); there are no targets for " $ me.Name);
		vuln = -1;
		Return None;
	}
	*/
}
void AMentalModel::addContact(AAI_Stats* contactInfo, float staticInfo, float dynInfo)
{
	/*
	local Contact tempCont;
	if (contactInfo.bInvisible == True)
	{
		Return None;
	}
	DebugLog(DEBUG_AI, "dnback:: MentalModel.addContact(); adding " $ contactInfo.Source.Name $ " at index " $ numContacts);
	allContacts[numContacts] = Spawn('Contact');
	tempCont = allContacts[numContacts];
	numContacts++;
	tempCont.Target = contactInfo;
	tempCont.staticIL = staticInfo;
	tempCont.dynamicIL = dynInfo;
	if (staticInfo == 1 && dynInfo == 1)
	{
		tempCont.perfect = true;
	}
	else
	{
		DebugLog(DEBUG_AI, "dnback:: MentalModel.addContact(); new contact " $ tempCont.Target.Source $ " forced reweight");
		membersForceReweight();
	}
	tempCont.setMM(Self);
	Return tempCont;
	*/
}
void AMentalModel::removeContact(AActor* Contact)
{
	/*
	local int Index;
	local int i;
	local Contact remContact;
	Tension = 0;
	Index = findActorIdx(Contact);
	if (Index == -1)
	{
		remContact = None;
	}
	else
	{
		remContact = allContacts[Index];
		for (i = Index; i < numContacts; i++)
		{
			allContacts[i] = allContacts[i + 1];
		}
		numContacts--;
		DebugLog(DEBUG_AI, "dnback:: MentalModel.removeContact(); forcing reweight due to loss of " $ Contact);
		membersForceReweight();
	}
	Return remContact;
	*/
}
void AMentalModel::receiveInfo(AActor* Source, FString recptType, APawn* Receiver, float Intensity)
{
	/*
	local int Index;
	local Contact tempCont;
	local float bonus;
	Index = -1;
	bonus = 0.2;
	Index = findActorIdx(Source);
	if (Index == -1)
	{
		if (Source.IsA('AGP_Pawn'))
		{
			if (AGP_Pawn(Source).Stats.bInvisible == True)
			{
				Return;
			}
			tempCont = addContact(AGP_Pawn(Source).Stats, bonus, bonus);
			Index = numContacts - 1;
		}
		else
		{
			if (Source.IsA('AGP_WeaponPickup'))
			{
				DebugLog(DEBUG_AI, "MentalModel::receiveInfo()	Saw " $ Source @ Source.Name);
			}
			else
			{
				DebugLog(DEBUG_AI, "dnback:: MentalModel.receiveInfo(); " $ Source.Name $ " is not a contact");
				Return;
			}
		}
		DebugLog(DEBUG_AI, "dnback:: MentalModel.receiveInfo(); " $ Source.Name $ " is a new contact");
	}
	else
	{
		tempCont = allContacts[Index];
		if (!tempCont.isInvisible())
		{
			if (tempCont.update(recptType, Receiver, Intensity))
			{
				DebugLog(DEBUG_AI, "dnback:: MentalModel.receiveInfo(); forcing reweight, respot of contact " $ Source);
				membersForceReweight();
			}
		}
	}
	*/
}
float AMentalModel::getTension()
{
	return Tension;
}
void AMentalModel::membersForceReweight()
{
	/*
	local int i;
	for (i = 0; i < numContacts; i++)
	{
		if (allContacts[i].perfect && allContacts[i].Target.Source.IsA('Pawn'))
		{
			AgentController(AGP_Pawn(allContacts[i].Target.Source).Controller).my_goal_decider.reweightGoals();
		}
	}
	*/
}