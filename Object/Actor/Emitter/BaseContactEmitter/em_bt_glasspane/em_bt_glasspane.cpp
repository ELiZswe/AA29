// All the original content belonged to the US Army


#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_glasspane/em_bt_glasspane.h"

Aem_bt_glasspane::Aem_bt_glasspane()
{

}

/*
Function Trigger(Actor Other, Pawn EventInstigator)
{
    Spawn(class'AGP_Effects.aux_em_glasspane');
}
*/


void Aem_bt_glasspane::Trigger(AActor* Other, APawn* EventInstigator)
{

    static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/AmericasArmy/Emitters/aux_em_glasspane_BP.aux_em_glasspane_BP'"));

    if (ItemBlueprint.Object)
    {
        MyItemBlueprint = (UClass*)ItemBlueprint.Object->GeneratedClass;
    }

    UWorld* const World = GetWorld();
    if (World)
    {
        FActorSpawnParameters SpawnParams;
        //SpawnParams.Instigator = this;

        FVector Location = GetActorLocation();
        FRotator Rotation = GetActorRotation();
        AActor* GlassEmitter = World->SpawnActor<AActor>(MyItemBlueprint, Location, Rotation, SpawnParams);
        if (GlassEmitter)
        {
            //DroppedItem->DoTheThings();
        }
    }

	//Spawn('aux_em_glasspane');
}