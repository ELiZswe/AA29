// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_LocationList.generated.h"

class AAGP_Location;

UCLASS()
class AAGP_LocationList : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_LocationList();

	UPROPERTY()					TArray<AAGP_Location*> LocationList;				//var array<AGP_Location> LocationList;
	UPROPERTY(EditAnywhere)		TArray<FName> Locations;							//var() array<name> Locations;

	UPROPERTY()				USceneComponent* Root;
	UPROPERTY()				UTexture2D* Texture;
	UPROPERTY()				UBillboardComponent* SpriteComponent;

	void PreBeginPlay();
	AAGP_Location* GetRandomLocation();
	AAGP_Location* GetLocationByTag(FName Tag);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
