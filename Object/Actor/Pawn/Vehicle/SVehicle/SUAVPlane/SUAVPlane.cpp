// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SUAVPlane/SUAVPlane.h"

ASUAVPlane::ASUAVPlane()
{
	MPHMeterMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxD_Mat.BorderBoxD_Mat'"), NULL, LOAD_None, NULL);
	MPHMeterPosX = 0.01;
	MPHMeterPosY = 0.9;
	MPHMeterScale = 70;
	MPHMeterSizeY = 0.05;
	bZeroPCRotOnEntry = false;
	//bSpecialHUD = true;
	//bProp = true;
	//bCollideWorld = true;
}

/*
replication
{
	reliable if ((Role == ROLE_Authority))
		uavsUAVState;
}
*/

bool ASUAVPlane::KUpdateState(FKRigidBodyState& NewState)
{
	/*
	if ((GetRemoteRole() == ENetRole::ROLE_MAX) || (!bNewUAVState))
	{
		return false;
	}
	NewState = ChassisState;
	bNewUAVState = false;
	*/
	return true;
}

void ASUAVPlane::SVehicleUpdateParams()
{
	/*
	Super::SVehicleUpdateParams();
	KSetStayUprightParams(UprightStiffness, UprightDamping);
	*/
}

bool ASUAVPlane::SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation)
{
	/*
	FVector CamLookAt = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector OffsetVector = FVector(0, 0, 0);
	APlayerController* PC = nullptr;
	PC = Cast<APlayerController>(Controller);
	if ((PC == nullptr) || (PC.ViewTarget != Self))
	{
		return false;
	}
	if (PC.bBehindView)
	{
		ViewActor = this;
		CamLookAt = (Location + (TPCamLookat >> Rotation));
		OffsetVector = FVector(0, 0, 0);
		OffsetVector.X = (-1 * TPCamDistance);
		CameraLocation = (CamLookAt + (OffsetVector >> CameraRotation));
		if (Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, false, FVector(10, 10, 10)) != nullptr)
		{
			CameraLocation = HitLocation;
		}
		bOwnerNoSee = false;
		if (bDrawDriverInTP)
		{
			Driver.bOwnerNoSee = false;
		}
		else
		{
			Driver.bOwnerNoSee = true;
		}
	}
	else
	{
		ViewActor = this;
		CameraLocation = (Location + (FPCamPos >> Rotation));
		if (bDrawMeshInFP)
		{
			bOwnerNoSee = false;
		}
		else
		{
			bOwnerNoSee = true;
		}
		Driver.bOwnerNoSee = true;
	}
	*/
	return true;
}

void ASUAVPlane::DrawHUD(UCanvas* Canvas)
{
	FColor WhiteColor = FColor(0, 0, 0, 0);
	float XL = 0;
	float YL = 0;
	/*
	Super::DrawHUD(Canvas);
	WhiteColor = Class'Canvas'.MakeColor(255, 255, 255);
	Canvas.DrawColor = WhiteColor;
	Canvas.Style = ERenderStyle.STY_Normal;
	Canvas.StrLen("TEST", XL, YL);
	Canvas.SetPos((MPHMeterPosX * Canvas.ClipX), (((MPHMeterSizeY + MPHMeterPosY) * Canvas.ClipY) + YL));
	Canvas.Font = Class'HUD'.GetConsoleFont(Canvas);
	Canvas.DrawText(string(CopterMPH));
	*/
}
