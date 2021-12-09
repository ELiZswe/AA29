// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_LocationList.generated.h"

class AAGP_Location;

UCLASS()
class AA29_API AAGP_LocationList : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_LocationList();

	UPROPERTY()				TArray<AAGP_Location*> LocationList;				//var array<AGP_Location> LocationList;
	UPROPERTY()				TArray<FName> Locations;							//var() array<name> Locations;

	UPROPERTY()				USceneComponent* Root;
	UPROPERTY()				UTexture2D* Texture;
	UPROPERTY()				UBillboardComponent* SpriteComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
