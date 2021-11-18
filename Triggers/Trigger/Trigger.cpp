// All the original content belonged to the US Army


#include "Trigger.h"

ATrigger::ATrigger()
{
	bInitiallyActive = true;
	InitialState = "NormalTrigger";
	//Texture = Texture'Engine.S_Trigger';
}



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
			OnlyAffectPawns(True);
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
			bHidden=False;
			bProjTarget=True;
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
void ATrigger::SpecialHandling(APawn* Other)
{
	/*
		local Actor A;
		if(bTriggerOnceOnly && ! bCollideActors)
		{
			Return None;
		}
		if(TriggerType == 5 && ! Other.IsHumanControlled())
		{
			Return None;
		}
		if(TriggerType == 0 && ! Other.IsPlayerPawn())
		{
			Return None;
		}
		if(! bInitiallyActive)
		{
			if(TriggerActor == None)
			{
				FindTriggerActor();
			}
			if(TriggerActor == None)
			{
				Return None;
			}
			if(TriggerActor2 != None && VSize(TriggerActor2.Location - Other.Location) < VSize(TriggerActor.Location - Other.Location))
			{
				Return TriggerActor2;
			}
			else
			{
				Return TriggerActor;
			}
		}
		if(TriggerType == 4)
		{
			Return Self;
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
			Return Self;
		}
		Return Self;
	*/
}
void ATrigger::CheckTouchList()
{
	/*
		local Actor A;
		ForEach TouchingActors('Actor',A)
		{
			Touch(A);
		}
	*/
}
void ATrigger::IsRelevant(AActor* Other)
{
	/*
		local Actor Inst;
		Inst=FindInstigator(Other);
		if(! bInitiallyActive)
		{
			Return False;
		}
		Switch(TriggerType)
		{
			case 5:
			Return Pawn(Other) != None && Pawn(Other).IsHumanControlled();
			case 0:
			Return Pawn(Other) != None && Pawn(Other).IsPlayerPawn() || Pawn(Other).WasPlayerPawn();
			case 6:
			Return Pawn(Other) != None && Pawn(Other).IsPlayerPawn();
			case 1:
			Return Pawn(Other) != None && Pawn(Other).CanTrigger(Self);
			case 2:
			Return ClassIsChildOf(Other.Class,ClassProximityType) && ! ClassIsChildOf(ClassProximityType,'Vehicle') || Pawn(Inst).IsPlayerPawn();
			case 3:
			Return True;
			case 4:
			Return Projectile(Other) != None && Projectile(Other).Damage >= DamageThreshold;
			default:
	*/
}
void ATrigger::FindInstigator(AActor* Other)
{
	/*
		if(Vehicle(Other) != None && Vehicle(Other).Controller == None)
		{
			Return Vehicle(Other).GetInstigator();
		}
		Return Other;
	*/
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
		local int i;
		Other=FindInstigator(Other);
		if(ReTriggerDelay > 0)
		{
			if(GetWorld()->GetTimeSeconds() - TriggerTime < ReTriggerDelay)
			{
				Return;
			}
			TriggerTime=GetWorld()->GetTimeSeconds();
		}
		TriggerEvent(Event,Self,Other.Instigator);
		if(Pawn(Other) != None && Pawn(Other).Controller != None)
		{
			i=0;
			if(i < 4)
			{
				if(Pawn(Other).Controller.GoalList[i] == Self)
				{
					Pawn(Other).Controller.GoalList[i]=None;
				}
				else
				{
					i ++;
				}
			}
		}
		if(Message != "" && Other.Instigator != None)
		{
			Other.Instigator.ClientMessage(Message);
		}
		if(bTriggerOnceOnly)
		{
			SetCollision(False);
		}
		else
		{
			if(RepeatTriggerTime > 0)
			{
				SetTimer(RepeatTriggerTime,False);
			}
		}
	*/
}
void ATrigger::Timer()
{
	/*
		local bool bKeepTiming;
		local Actor A;
		bKeepTiming=False;
		ForEach TouchingActors('Actor',A)
		{
			if(IsRelevant(A))
			{
				bKeepTiming=True;
				Touch(A);
			}
		}
		if(bKeepTiming)
		{
			SetTimer(RepeatTriggerTime,False);
		}
	*/
}
/*
void ATrigger::TakeDamage(int Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if(bInitiallyActive && TriggerType == 4 && Damage >= DamageThreshold && instigatedBy != None)
	{
		if(ReTriggerDelay > 0)
		{
			if(GetWorld()->GetTimeSeconds() - TriggerTime < ReTriggerDelay)
			{
				Return;
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
			SetCollision(False);
		}
		if(AIController(instigatedBy.Controller) != None && instigatedBy.Controller.Target == Self)
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
	/*
		bInitiallyActive=Active;
		if(bInitiallyActive)
		{
			CheckTouchList();
		}
	*/
}
