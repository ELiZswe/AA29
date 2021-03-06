// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/VehicleReplicationInfo.h"
#include "Net/UnrealNetwork.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"

AVehicleReplicationInfo::AVehicleReplicationInfo()
{
	MyVehicleNumber = -1;
}

void AVehicleReplicationInfo::SetVehicle(AVehicle* V)
{
	MyVehicle = V;
}

void AVehicleReplicationInfo::SetVehicleNumber(int32 VehicleNumber)
{
	MyVehicleNumber = VehicleNumber;
}

void AVehicleReplicationInfo::PostNetBeginPlay()
{
	/*
		AGameReplicationInfo* GRI = nullptr;
		SetCustomTimer(LocationUpdateFrequency,True,'UpdateLocation');
		SetCustomTimer(RotationUpdateFrequency,True,'UpdateRotation');
		if (Level.GRI != nullptr)
		{
			Level.GRI.AddVRI(this);
		}
		else
		{
			ForEach DynamicActors('GameReplicationInfo',GRI)
			{
				GRI.AddVRI(this);
			}
		}
	*/
}
void AVehicleReplicationInfo::Destroyed()
{
	/*
		AGameReplicationInfo* GRI = nullptr;
		MyVehicle=nullptr;
		if (Level.GRI != nullptr)
		{
			Level.GRI.RemoveVRI(this);
		}
		else
		{
			ForEach DynamicActors('GameReplicationInfo',GRI)
			{
				GRI.RemoveVRI(this);
			}
		}
	*/
}
void AVehicleReplicationInfo::UpdateLocation()
{
	/*
		LocationX=MyVehicle.Location.X;
		LocationY=MyVehicle.Location.Y;
		LocationZ=MyVehicle.Location.Z;
	*/
}
void AVehicleReplicationInfo::UpdateRotation()
{
	/*
		RotationPitch=MyVehicle.Rotation.Pitch;
		RotationYaw=MyVehicle.Rotation.Yaw;
		RotationRoll=MyVehicle.Rotation.Roll;
	*/
}

bool AVehicleReplicationInfo::IsVehicleDisabled()
{
	return false;     //FAKE   /EliZ
}

FVector AVehicleReplicationInfo::GetVehiclePosition()
{
	FVector VehiclePosition = FVector(0,0,0);
	if (MyVehicle != nullptr)
	{
		//return MyVehicle.Location;
	}
	else
	{
		//VehiclePosition.X=LocationX;
		//VehiclePosition.Y=LocationY;
		//VehiclePosition.Z=LocationZ;
		return VehiclePosition;
	}
	return FVector(0,0,0);    //FAKE   /ELiZ
}

FRotator AVehicleReplicationInfo::GetVehicleRotation()
{
	FRotator VehicleRotation = FRotator(0,0,0);
	if (MyVehicle != nullptr)
	{
		//return MyVehicle.Rotation;
	}
	else
	{
		//VehicleRotation.Pitch=RotationPitch;
		//VehicleRotation.Yaw=RotationYaw;
		//VehicleRotation.Roll=RotationRoll;
		return VehicleRotation;
	}
	return FRotator(0, 0, 0);    //FAKE   /ELiZ
}

int32 AVehicleReplicationInfo::GetVehicleNumber()
{
	return MyVehicleNumber;
}

void AVehicleReplicationInfo::PlayerEntered(APlayerController* PC, int32 PositionIndex)
{
}

void AVehicleReplicationInfo::PlayerLeft(APlayerController* PC)
{
}

void AVehicleReplicationInfo::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AVehicleReplicationInfo, LocationUpdateFrequency);
	DOREPLIFETIME(AVehicleReplicationInfo, RotationUpdateFrequency);
	DOREPLIFETIME(AVehicleReplicationInfo, LocationX);
	DOREPLIFETIME(AVehicleReplicationInfo, LocationY);
	DOREPLIFETIME(AVehicleReplicationInfo, LocationZ);
	DOREPLIFETIME(AVehicleReplicationInfo, RotationPitch);
	DOREPLIFETIME(AVehicleReplicationInfo, RotationYaw);
	DOREPLIFETIME(AVehicleReplicationInfo, RotationRoll);
	DOREPLIFETIME(AVehicleReplicationInfo, MyVehicle);
	DOREPLIFETIME(AVehicleReplicationInfo, MyVehicleNumber);
}
