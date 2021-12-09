// All the original content belonged to the US Army


#include "AA29/Object/Actor/AI_Primitive/InfoSource/InfoSource.h"

AInfoSource::AInfoSource()
{

}

void AInfoSource::setMentalModel(AMentalModel* pmm)
{
	_mm = pmm;
}
void AInfoSource::see(AActor* Seen, APawn* me)
{
	//_mm->receiveInfo(Seen, "sight", me);
}
void AInfoSource::HEAR(AActor* heard, APawn* me, float Loudness, bool surprised)
{
	/*
	if (me != Pawn(heard))
	{
		_mm.receiveInfo(heard, "sound", me, Loudness);
		if (surprised)
		{
			me.ShouldCrouch(False);
		}
	}
	*/
}
void AInfoSource::comm(AActor* told, APawn* me)
{
	/*
	Log("dnback:: InfoSource.see(); " $ me.Name $ " was told about " $ told.Name);
	_mm.receiveInfo(told, "comms", me);
	*/
}