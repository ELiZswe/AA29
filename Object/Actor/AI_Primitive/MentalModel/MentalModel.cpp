// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"
#include "AA29/Object/Actor/AI_Primitive/Contact/Contact.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Stats/AI_Stats.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"

AMentalModel::AMentalModel()
{
	allContacts.SetNum(50);
	StartUp = true;
}

void AMentalModel::PostBeginPlay()
{
	/*
	DebugLog(DEBUG_AI, "dnback:: MentalModel.PostBeginPlay()");
	Tension = 0;
	SetTimer(1, true);
	*/
}

void AMentalModel::Timer()
{
	AAI_Stats* Stats = nullptr;
	/*
	if (StartUp)
	{
		DebugLog(DEBUG_AI, "dnback:: MentalModel.Timer(); first time through, " + this + " polling for autodiscovery");
		ForEach AllActors(AAI_Stats::StaticClass(), Stats)
		{
			if (Stats.bAutoDiscoverMe)
			{
				DebugLog(DEBUG_AI, "			found " + Stats + ", adding to " + Self);
				addContact(Stats, 1, 1);
			}
		}
		StartUp = false;
	}
	Tension -= 1;
	Tension =FMath::Clamp(Tension, 0, 10);
	*/
}

int32 AMentalModel::getNumContacts()
{
	return numContacts;
}

int32 AMentalModel::getNumFriends(AAGP_Pawn* this_pawn)
{
	int32 friends=0;
	int32 i = 0;
	uint8 contact_team = 0;
	uint8 this_team = 0;
	friends = 0;
	/*
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
	int32 i = 0;
	uint8 contact_team = 0;
	uint8 this_team = 0;
	enemies = 0;
	/*
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
	int32 i = 0;
	Log("dnback:: MentalModel.logDump(); printing contents of mental model " + Self.Name + " numContacts " + numContacts);
	for (i = 0; i < numContacts; i++)
	{
		Log("	" + allContacts[i].Target.Source.Name + " at index" + i);
	}
	*/
}

int32 AMentalModel::findActorIdx(AActor* findThis)
{
	/*
	int32 i = 0;
	for (i = 0; i < numContacts; i++)
	{
		if (allContacts[i].Target.Source == findThis)
		{
			return i;
		}
	}
	*/
	return - 1;
}

AContact* AMentalModel::findContact(AActor* findThis)
{
	int32 i = 0;
	/*
	for (i = 0; i < numContacts; i++)
	{
		if (allContacts[i].Target.Source == findThis)
		{
			return allContacts[i];
		}
	}
	*/
	return nullptr;
}

float AMentalModel::getBestPickup(APawn* me, APickup* &out_pickup)
{
	APickup* a_pickup = nullptr;
	APickup* best_pickup = nullptr;
	float a_score = 0;
	float best_score = 0;
	best_score = 0;
	/*
	for (a_pickup=Level.PickupList; a_pickup!=nullptr; a_pickup=a_pickup.Next)
	{
		a_score=a_pickup.BotDesireability(me);
		DebugLog(DEBUG_InvAI,"MentalModel::getBestPickup()	Evaluated " + FString::FromInt(a_pickup) @ FString::FromInt(a_score));
		if (a_score > best_score)
		{
			best_pickup=a_pickup;
			best_score=a_score;
		}
	}
	*/
	out_pickup = best_pickup;
	return best_score;
}

AContact* AMentalModel::getBiggestThreat(APawn* me, FString situation, FVector altLoc)
{
	int32 i = 0;
	float highThreat = 0;
	float thisThreat = 0;
	int32 highIndex = 0;
	highIndex = -1;
	highThreat = 0.01;
	/*
	for (i = 0; i < numContacts; i++)
	{
		if (me == nullptr)
		{
			Log("dnback:: MentalModel.getBiggestThreat(); 'me' is dead");
			return nullptr;
		}
		if (allContacts[i].Target.Source != nullptr)
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
		return allContacts[highIndex];
	}
	else
	{
		return nullptr;
	}
	*/
	return nullptr;    //FAKE   /EliZ
}

float AMentalModel::totalThreatAssessment(APawn* me, FString situation, FVector altLoc, float &cover)
{
	int32 i = 0;
	AContact* tempCont = nullptr;
	float Threat = 0;
	float Gain = 0;
	int32 friendly = 0;
	int32 moreTargets = 0;
	int32 moreHostiles = 0;
	int32 noInfo = 0;
	float cond = 0;
	float friendRange = 0;
	float coverAdd = 0;
	Threat = 0;
	moreTargets = 0;
	moreHostiles = 0;
	cover = 0;
	/*
	for (i = 0; i < numContacts; i++)
	{
		tempCont = allContacts[i];
		friendly = tempCont.isMyFriend(Cast<AAGP_Pawn>(me));
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
	*/
	return Threat;
}

float AMentalModel::attackAssessment(APawn* me, FString situation, FVector altLoc)
{
	AContact* tempCont = nullptr;
	float assessment = 0;
	/*
	if (Cast<AAGP_Weapon>(me.Weapon).WeaponDisabled() == true)
	{
		assessment = 0;
	}
	else
	{
		tempCont = getMostVulnerable(me, assessment, situation, altLoc);
		if (tempCont == nullptr)
		{
			DebugLog(DEBUG_AI, "dnback:: MentalModel.attackAssessment(); " + me + " knows of no targets");
		}
	}
	*/
	return assessment;
}

AContact* AMentalModel::getMostVulnerable(APawn* me, float &vuln, FString situation, FVector altLoc)
{
	int32 i = 0;
	float highVuln = 0;
	float thisVuln = 0;
	int32 highIndex = 0;
	highIndex = -1;
	highVuln = 0.01;
	/*
	for (i = 0; i < numContacts; i++)
	{
		if (me == nullptr)
		{
			DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); 'me' is dead");
			return nullptr;
		}
		if (allContacts[i].Target.Source != nullptr)
		{
			thisVuln = allContacts[i].vulnerability(me);
			DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); I see " + allContacts[i] @ thisVuln + allContacts[i].Target.Source);
			if (thisVuln > highVuln)
			{
				highVuln = thisVuln;
				highIndex = i;
			}
		}
	}
	if (highIndex != -1)
	{
		DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); biggest turkey for " + me.Name + " is " + allContacts[highIndex].Target.Source.Name);
		vuln = highVuln;
		return allContacts[highIndex];
	}
	else
	{
		DebugLog(DEBUG_AI, "dnback:: MentalModel.getMostVulnerable(); there are no targets for " + me.Name);
		vuln = -1;
		return nullptr;
	}
	*/
	return nullptr;     //FAKE   /ELiZ
}

AContact* AMentalModel::addContact(AAI_Stats* contactInfo, float staticInfo, float dynInfo)
{
	AContact* tempCont = nullptr;
	/*
	if (contactInfo.bInvisible == true)
	{
		return nullptr;
	}
	DebugLog(DEBUG_AI, "dnback:: MentalModel.addContact(); adding " + contactInfo.Source.Name + " at index " + numContacts);
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
		DebugLog(DEBUG_AI, "dnback:: MentalModel.addContact(); new contact " + tempCont.Target.Source + " forced reweight");
		membersForceReweight();
	}
	tempCont.setMM(this);
	*/
	return tempCont;
}

AContact* AMentalModel::removeContact(AActor* Contact)
{
	int32 Index = 0;
	int32 i = 0;
	AContact* remContact = nullptr;
	Tension = 0;
	/*
	Index = findActorIdx(Contact);
	if (Index == -1)
	{
		remContact = nullptr;
	}
	else
	{
		remContact = allContacts[Index];
		for (i = Index; i < numContacts; i++)
		{
			allContacts[i] = allContacts[i + 1];
		}
		numContacts--;
		DebugLog(DEBUG_AI, "dnback:: MentalModel.removeContact(); forcing reweight due to loss of " + Contact);
		membersForceReweight();
	}
	*/
	return remContact;
}

void AMentalModel::receiveInfo(AActor* Source, FString recptType, APawn* Receiver, float Intensity)
{
	int32 Index = 0;
	AContact* tempCont = nullptr;
	float bonus = 0;
	Index = -1;
	bonus = 0.2;
	/*
	Index = findActorIdx(Source);
	if (Index == -1)
	{
		if (Source->IsA(AAGP_Pawn::StaticClass()))
		{
			if (Cast<AAGP_Pawn>(Source).Stats.bInvisible == true)
			{
				return;
			}
			tempCont = addContact(Cast<AAGP_Pawn>(Source).Stats, bonus, bonus);
			Index = numContacts - 1;
		}
		else
		{
			if (Source->IsA(AAGP_WeaponPickup::StaticClass()))
			{
				DebugLog(DEBUG_AI, "MentalModel::receiveInfo()	Saw " + Source @ Source.Name);
			}
			else
			{
				DebugLog(DEBUG_AI, "dnback:: MentalModel.receiveInfo(); " + Source.Name + " is not a contact");
				return;
			}
		}
		DebugLog(DEBUG_AI, "dnback:: MentalModel.receiveInfo(); " + Source.Name + " is a new contact");
	}
	else
	{
		tempCont = allContacts[Index];
		if (!tempCont.isInvisible())
		{
			if (tempCont.update(recptType, Receiver, Intensity))
			{
				DebugLog(DEBUG_AI, "dnback:: MentalModel.receiveInfo(); forcing reweight, respot of contact " + Source);
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
	int32 i = 0;
	for (i = 0; i < numContacts; i++)
	{
		if (allContacts[i].perfect && allContacts[i].Target.Source->IsA(APawn::StaticClass()))
		{
			AgentController(Cast<AAGP_Pawn>(allContacts[i].Target.Source).Controller).my_goal_decider.reweightGoals();
		}
	}
	*/
}
