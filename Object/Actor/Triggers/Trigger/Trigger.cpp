// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

ATrigger::ATrigger()
{
	bInitiallyActive = true;
	InitialState = "NormalTrigger";
	//Texture = Texture'Engine.S_Trigger';
}

/*
State NormalTrigger
{
}
*/

/*
State OtherTriggerToggles
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		bInitiallyActive=(! bInitiallyActive);
		if (bInitiallyActive)
		{
			CheckTouchList();
		}
	}
}
*/

/*
State OtherTriggerTurnsOn
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		bool bWasActive = false;
		bWasActive=bInitiallyActive;
		bInitiallyActive=true;
		if (! bWasActive)
		{
			CheckTouchList();
		}
	}
}
*/

/*
State OtherTriggerTurnsOff
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		bInitiallyActive=false;
	}
}
*/

void ATrigger::PlayerToucherDied(APawn* p)
{
	/*
		if(bInitiallyActive && TriggerType == 6)
		{
			UntriggerEvent(Event,Self,p);
		}
	*/
}
bool ATrigger::SelfTriggered()
{
	return bInitiallyActive;
}
void ATrigger::PreBeginPlay()
{
	/*
		PreBeginPlay();
		if(TriggerType == 0 || TriggerType == 1 || TriggerType == 5 || TriggerType == 6 || TriggerType == 2 && ClassIsChildOf(ClassProximityType,'Pawn'))
		{
			OnlyAffectPawns(true);
		}
	*/
}
void ATrigger::PostBeginPlay()
{
	/*
		if(! bInitiallyActive)
		{
			FindTriggerActor();
		}
		if(TriggerType == 4)
		{
			bHidden=false;
			bProjTarget=true;
			SetDrawType(0);
		}
		bSavedInitialActive=bInitiallyActive;
		bSavedInitialCollision=bCollideActors;
		PostBeginPlay();
	*/
}
void ATrigger::Reset()
{
	Super::Reset();
	bInitiallyActive=bSavedInitialActive;
	
	//SetCollision(bSavedInitialCollision,bBlockActors);
	
}
void ATrigger::MatchStarting()
{
	if(bResetCollisionAtRoundEnd)
	{
		Reset();
	}
}
void ATrigger::FindTriggerActor()
{
	/*
		AActor* A;
		TriggerActor=nullptr;
		TriggerActor2=nullptr;

		ForEach AllActors('Actor',A)
		{
			if(A->Event == Tag)
			{
				if(TriggerActor == nullptr)
				{
					TriggerActor=A;
				}
				else
				{
					TriggerActor2=A;
					return;
				}
			}
		}
	*/
}

AActor* ATrigger::SpecialHandling(APawn* Other)
{
	AActor* A = nullptr;
	/*
	if(bTriggerOnceOnly && ! bCollideActors)
	{
		return nullptr;
	}
	if(TriggerType == 5 && ! Other.IsHumanControlled())
	{
		return nullptr;
	}
	if(TriggerType == 0 && ! Other.IsPlayerPawn())
	{
		return nullptr;
	}
	if(! bInitiallyActive)
	{
		if(TriggerActor == nullptr)
		{
			FindTriggerActor();
		}
		if(TriggerActor == nullptr)
		{
			return nullptr;
		}
		if(TriggerActor2 != nullptr && VSize(TriggerActor2.Location - Other.Location) < VSize(TriggerActor.Location - Other.Location))
		{
			return TriggerActor2;
		}
		else
		{
			return TriggerActor;
		}
	}
	if(TriggerType == 4)
	{
		return this;
	}
	if(IsRelevant(Other))
	{
		ForEach TouchingActors('Actor',A)
		{
			if(A == Other)
			{
				Touch(Other);
			}
		}
		return this;
	}
	*/
	return this;
}

void ATrigger::CheckTouchList()
{
	AActor* A = nullptr;
	/*
	ForEach TouchingActors('Actor',A)
	{
		Touch(A);
	}
	*/
}

bool ATrigger::IsRelevant(AActor* Other)
{
	AActor* Inst = nullptr;
	/*
	Inst=FindInstigator(Other);
	if(! bInitiallyActive)
	{
		return false;
	}
	switch(TriggerType)
	{
		case 5:
		return Pawn(Other) != nullptr && Pawn(Other).IsHumanControlled();
		case 0:
		return Pawn(Other) != nullptr && Pawn(Other).IsPlayerPawn() || Pawn(Other).WasPlayerPawn();
		case 6:
		return Pawn(Other) != nullptr && Pawn(Other).IsPlayerPawn();
		case 1:
		return Pawn(Other) != nullptr && Pawn(Other).CanTrigger(this);
		case 2:
		return ClassIsChildOf(Other.Class,ClassProximityType) && ! ClassIsChildOf(ClassProximityType,'Vehicle') || Pawn(Inst).IsPlayerPawn();
		case 3:
		return true;
		case 4:
		return Projectile(Other) != nullptr && Projectile(Other).Damage >= DamageThreshold;
		default:
	}
	*/
	return false;    //FAKE   /EliZ
}

AActor* ATrigger::FindInstigator(AActor* Other)
{
	/*
	if(Cast<AVehicle>(Other) != nullptr && Vehicle(Other).Controller == nullptr)
	{
		return Vehicle(Other).GetInstigator();
	}
	*/
	return Other;
}

void ATrigger::Touch(AActor* Other)
{
	/*
	if(IsRelevant(Other))
	{
		DoTouch(Other);
	}
	*/
}

void ATrigger::DoTouch(AActor* Other)
{
	/*
	int32 i = 0;
	Other=FindInstigator(Other);
	if(ReTriggerDelay > 0)
	{
		if(GetWorld()->GetTimeSeconds() - TriggerTime < ReTriggerDelay)
		{
			return;
		}
		TriggerTime=GetWorld()->GetTimeSeconds();
	}
	TriggerEvent(Event,Self,Other.Instigator);
	if(Cast<APawn>(Other) != nullptr && Pawn(Other).Controller != nullptr)
	{
		i=0;
		if(i < 4)
		{
			if(Cast<APawn>(Other).Controller.GoalList[i] == this)
			{
				Cast<APawn>(Other).Controller.GoalList[i]=nullptr;
			}
			else
			{
				i ++;
			}
		}
	}
	if(Message != "" && Other.Instigator != nullptr)
	{
		Other.Instigator.ClientMessage(Message);
	}
	if(bTriggerOnceOnly)
	{
		SetCollision(false);
	}
	else
	{
		if(RepeatTriggerTime > 0)
		{
			SetTimer(RepeatTriggerTime,false);
		}
	}
	*/
}

void ATrigger::Timer()
{
	bool bKeepTiming = false;
	AActor* A = nullptr;
	bKeepTiming = false;
	/*
	ForEach TouchingActors('Actor',A)
	{
		if(IsRelevant(A))
		{
			bKeepTiming=true;
			Touch(A);
		}
	}
	if(bKeepTiming)
	{
		SetTimer(RepeatTriggerTime,false);
	}
	*/
}

/*
void ATrigger::TakeDamage(int32 Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if(bInitiallyActive && TriggerType == 4 && Damage >= DamageThreshold && instigatedBy != nullptr)
	{
		if(ReTriggerDelay > 0)
		{
			if(GetWorld()->GetTimeSeconds() - TriggerTime < ReTriggerDelay)
			{
				return;
			}
			TriggerTime=GetWorld()->GetTimeSeconds();
		}
		TriggerEvent(Event,Self,instigatedBy);
		if(Message != "")
		{
			instigatedBy.Instigator.ClientMessage(Message);
		}
		if(bTriggerOnceOnly)
		{
			SetCollision(false);
		}
		if(Cast<AAIController>(instigatedBy.Controller) != nullptr && instigatedBy.Controller.Target == this)
		{
			instigatedBy.Controller.StopFiring();
		}
	}
}
*/

void ATrigger::UnTouch(AActor* Other)
{
	/*
	if(IsRelevant(Other))
	{
		UntriggerEvent(Event,Self,Other.Instigator);
	}
	*/
}

void ATrigger::SetActive(bool Active)
{
	bInitiallyActive=Active;
	if(bInitiallyActive)
	{
		CheckTouchList();
	}
}
