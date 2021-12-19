// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_ItemList.generated.h"

class AInventory;

UCLASS()
class AA29_API AAGP_ItemList : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_ItemList();

	UPROPERTY()								TArray<int32> ItemArray;									//var array<int> ItemArray;
	UPROPERTY()								int32 _iQuantity;											//var int _iQuantity;
	UPROPERTY()								int32 _iPosition;											//var int _iPosition;
	UPROPERTY(EditAnywhere)					int32 weap_M16A2Trainer_Qty;								//var() int weap_M16A2Trainer_Qty;
	UPROPERTY(EditAnywhere)					int32 ammo_556_20_Qty;										//var() int ammo_556_20_Qty;
	UPROPERTY(EditAnywhere)					int32 ammo_556_200_Qty;										//var() int ammo_556_200_Qty;
	UPROPERTY(EditAnywhere)					int32 ammo_556_30_Qty;										//var() int ammo_556_30_Qty;
	UPROPERTY(EditAnywhere)					int32 weap_M249_Qty;										//var() int weap_M249_Qty;
	UPROPERTY(EditAnywhere)					int32 weap_M16A2_Qty;										//var() int weap_M16A2_Qty;

	UPROPERTY()																USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;

	void PreBeginPlay();
	int32 GetNumItems();
	AInventory* GetItem(int32 Index);
	FString GetItemString(int32 Index);
	int32 GetItemQuantity(int32 Index);
	AInventory* MakeItem(FString ClassName);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
