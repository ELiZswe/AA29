// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/CheatManager/AA2_CheatManager.h"
#include "Cheater.generated.h"

class ASoldierClass;
class ASoldierRole;

UCLASS()
class AA29_API UCheater : public UAA2_CheatManager
{
	GENERATED_BODY()
public:
	UCheater();

	void PlayerLock(bool B);
	void Entropy();
	void Deathstalker();
	void Judas();
	void PatVaccine();
	void Spook();
	void FOV(float F);
	void LowRes();
	void newTeamClass(ASoldierClass* sclass);
	void newTeamRole(ASoldierRole* srole);
	void Class(FString ClassName);
	void Role(FString rolename);
	void m4a1();
	void svd();
	void AK74su();
	void M16A2();
	void AMMO_556_30();
	void M249();
	void AK47();
	void AT4();
	void AMMO_556_200();
	void M67Frag();
	void RGD5();
	void M83Smoke();
	void FlashBang();
	void M82Barrett();
	void FillAmmo();
	void FixRuined();
	void NoJam();
	void WpnRecoil();
	void WpnAccuracy();
	void TestWeapon();
	void btr60();
	void SFHumvee();
	void HMMWV();
	void HMMWV_mk19();
	void Technical();
	void ChevySuburban();
	void USTechnical();
	void BMP1();
	void T62A();
	void HEMTTC();
	void HEMTTF();
	void FMTV();
	void ASV();
	void JavCheat(FString javobject);

};
