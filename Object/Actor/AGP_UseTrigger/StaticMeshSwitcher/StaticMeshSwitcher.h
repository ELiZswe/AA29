// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "StaticMeshSwitcher.generated.h"

UCLASS()
class AStaticMeshSwitcher : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	AStaticMeshSwitcher();

	UPROPERTY()					int32					CurrentMesh;		//var int CurrentMesh;
	UPROPERTY(EditAnywhere)		int32					StartMesh;			//var() int StartMesh;
	UPROPERTY(EditAnywhere)		TArray<UStaticMesh*>	Meshes;				//var() array<StaticMesh> Meshes;

	void BeginPlay();
	bool UsedBy(APawn* User);
	bool SwitchMesh();
	void SetMesh(int32 Index);
};
