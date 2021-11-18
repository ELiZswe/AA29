// All the original content belonged to the US Army


#include "AA29/Info/ReplicationInfo/VehicleReplicationInfo/VehicleReplicationInfo.h"
#include "Net/UnrealNetwork.h"

AVehicleReplicationInfo::AVehicleReplicationInfo()
{
	MyVehicleNumber = -1;
}



/*
void AVehicleReplicationInfo::SetVehicle(Vehicle V)
{
	MyVehicle = V;
}
*/

void AVehicleReplicationInfo::SetVehicleNumber(int32 VehicleNumber)
{
	MyVehicleNumber = VehicleNumber;
}
void AVehicleReplicationInfo::PostNetBeginPlay()
{
	/*
		local GameReplicationInfo GRI;
		SetCustomTimer(LocationUpdateFrequency,True,'UpdateLocation');
		SetCustomTimer(RotationUpdateFrequency,True,'UpdateRotation');
		if (Level.GRI != None)
		{
			Level.GRI.AddVRI(Self);
		}
		else
		{
			ForEach DynamicActors('GameReplicationInfo',GRI)
			{
				GRI.AddVRI(Self);
			}
		}
	*/
}
void AVehicleReplicationInfo::Destroyed()
{
	/*
		local GameReplicationInfo GRI;
		MyVehicle=None;
		if (Level.GRI != None)
		{
			Level.GRI.RemoveVRI(Self);
		}
		else
		{
			ForEach DynamicActors('GameReplicationInfo',GRI)
			{
				GRI.RemoveVRI(Self);
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
void AVehicleReplicationInfo::IsVehicleDisabled()
{
}
void AVehicleReplicationInfo::GetVehiclePosition()
{
	/*
		local FVector VehiclePosition;
		if (MyVehicle != None)
		{
			Return MyVehicle.Location;
		}
		else
		{
			VehiclePosition.X=LocationX;
			VehiclePosition.Y=LocationY;
			VehiclePosition.Z=LocationZ;
			Return VehiclePosition;
		}
	*/
}
void AVehicleReplicationInfo::GetVehicleRotation()
{
	/*
		local Object.Rotator VehicleRotation;
		if (MyVehicle != None)
		{
			Return MyVehicle.Rotation;
		}
		else
		{
			VehicleRotation.Pitch=RotationPitch;
			VehicleRotation.Yaw=RotationYaw;
			VehicleRotation.Roll=RotationRoll;
			Return VehicleRotation;
		}
	*/
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