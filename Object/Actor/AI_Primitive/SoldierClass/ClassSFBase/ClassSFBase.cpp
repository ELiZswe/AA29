// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSFBase/ClassSFBase.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaAK74su/ClassGuerrillaAK74su.h"

AClassSFBase::AClassSFBase()
{

}

TSubclassOf<ASoldierClass> AClassSFBase::GetAlternateClass()
{
	return AClassGuerrillaAK74su::StaticClass();
}
