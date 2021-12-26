// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/AGP_ObjectiveAttachment/AGP_ObjectiveAttachment.h"

AAGP_ObjectiveAttachment::AAGP_ObjectiveAttachment()
{
	AttachBone = "RuckSack";
	//DisableOtherAttachment(0) = Attch_MedicRuck
	//DisableOtherAttachment(1) = Attch_RPGBackpack
	
	DisableOtherAttachment = { "Attch_MedicRuck","Attch_RPGBackpack" };
}
/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		PlacedPickup;
}
*/

void AAGP_ObjectiveAttachment::SetPlacedPickup(AAGP_ObjectivePickup* new_placed_pickup)
{
	PlacedPickup = new_placed_pickup;
}

bool AAGP_ObjectiveAttachment::IsReplicationComplete()
{
	//return ((PlacedPickup != None) && (Pawn(Base) != None));
	return false;    //FAKE  /EliZ
}

void AAGP_ObjectiveAttachment::NotifyReplicationComplete()
{
	SetMesh();
}

void AAGP_ObjectiveAttachment::SetMesh()
{
	/*
	if (!IsReplicationComplete())
	{
		return;
	}
	FriendlyStaticMesh = PlacedPickup.AttachmentFriendlyStaticMesh;
	EnemyStaticMesh = PlacedPickup.AttachmentEnemyStaticMesh;
	Super::SetMesh();
	*/
}
