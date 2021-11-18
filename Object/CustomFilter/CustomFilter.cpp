// All the original content belonged to the US Army


#include "AA29/Object/CustomFilter/CustomFilter.h"

UCustomFilter::UCustomFilter()
{

}


void UCustomFilter::Created()
{
	//CancelChanges();
}

void UCustomFilter::CancelChanges()
{
	/*
	Title = DefaultTitle;
	bEnabled = Active;
	InitializeRules();
	bDirty = False;
	*/
}

void UCustomFilter::InitializeRules()
{
	/*
	local int32 i;
	if (AllRules.Length > 0)
	{
		AllRules.remove(0, AllRules.Length);
	}
	for (i = 0; i < Rules.Length; i++)
	{
		AddRule(Rules[i].ItemName, Rules[i].FilterItem.Key, Rules[i].FilterItem.Value, Rules[i].FilterItem.QueryType, Rules[i].FilterType);
	}
	*/
}

bool UCustomFilter::SetTitle(FString NewTitle)
{
	/*
	bDirty = bDirty || NewTitle != Title;
	Title = NewTitle;
	*/
	return true;
}

bool UCustomFilter::SetActive(bool NewActive)
{
	/*
	bDirty = bDirty || NewActive != bEnabled;
	bEnabled = NewActive;
	*/
	return true;
}

void UCustomFilter::SetRules(TArray<FCurrentFilter> NewRules)
{
	/*
	AllRules = NewRules;
	bDirty = True;
	*/
}

FString UCustomFilter::GetTitle()
{
	return Title;
}

bool UCustomFilter::IsActive()
{
	return bEnabled;
}

void UCustomFilter::GetQueryRules(TArray<FAFilterRule>& OutRules)
{
	/*
	Save();
	OutRules = Rules;
	*/
}

void UCustomFilter::GetRules(TArray<FAFilterRule>& OutRules)
{
	//OutRules = AllRules;
}

void UCustomFilter::Save(bool bForceSave)
{
	/*
	local int32 i;
	if (bDirty || bForceSave)
	{
		DefaultTitle = Title;
		Active = bEnabled;
		if (Rules.Length > 0)
		{
			Rules.remove(0, Rules.Length);
		}
		for (i = 0; i < AllRules.Length; i++)
		{
			Rules[Rules.Length] = AllRules[i].Item;
		}
		SaveConfig();
	}
	bDirty = False;
	*/
}

void UCustomFilter::Count()
{
	//Return AllRules.Length;
}

void UCustomFilter::FindRule(FAFilterRule& Rule, FString ItemName, FString Value)
{
	/*
	local int32 i;
	i = FindRuleIndex(ItemName, Value);
	Return GetRule(i, Rule);
	*/
}

bool UCustomFilter::GetRule(int32 Index, FAFilterRule& Rule)
{
	/*
	if (ValidIndex(Index))
	{
		Rule = AllRules[Index].Item;
		return true;
	}
	*/
	return false;
}

int32 UCustomFilter::FindRuleIndex(FString ItemName, FString Value)
{
	/*
	local int32 i;
	local int32 j;
	j = InStr(ItemName, ".");
	if (j != -1)
	{
		ItemName = Mid(ItemName, j + 1);
	}
	for (i = 0; i < AllRules.Length; i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName)
		{
			if (Value == "" || Value != "" && Value ~= AllRules[i].Item.FilterItem.Value)
			{
				Return i;
			}
		}
	}
	*/
	return -1;
}

int32 UCustomFilter::FindItemIndex(FString ItemName, int32 ItemIndex)
{
	/*
	local int32 i;
	for (i = 0; i < AllRules.Length; i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName && AllRules[i].ItemIndex == ItemIndex)
		{
			Return i;
		}
	}
	*/
	return -1;
}

int32 UCustomFilter::FindLastIndex(FString ItemName)
{
	int32 i=0;
	int32 j=0;
	j = -1;
	/*
	for (i = 0; i < AllRules.Length; i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName && AllRules[i].ItemIndex > j)
		{
			j = AllRules[i].ItemIndex;
		}
	}
	*/
	return j;
}

int32 UCustomFilter::FindInnerIndex(FString ItemName, FString Value)
{
	/*
	local int32 i;
	local int32 j;
	j = InStr(ItemName, ".");
	if (j != -1)
	{
		ItemName = Mid(ItemName, j + 1);
	}
	for (i = 0; i < AllRules.Length; i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName && AllRules[i].Item.FilterItem.Value ~= Value)
		{
			Return AllRules[i].ItemIndex;
		}
	}
	*/
	return -1;
}

FString UCustomFilter::GetRuleKey(int32 Index)
{
	/*
	if (ValidIndex(Index))
	{
		Return AllRules[Index].Item.FilterItem.Key;
	}
	*/
	return "";
}

FString UCustomFilter::GetRuleType(int32 Index)
{
	/*
	if (ValidIndex(Index))
	{
		Return GetDataTypeString(AllRules[Index].Item.FilterType);
	}
	*/
	return "";
}

FString UCustomFilter::GetRuleQueryType(int32 Index)
{
	/*
	if (ValidIndex(Index))
	{
		Return GetEnum(Enum'EQueryType', AllRules[Index].Item.FilterItem.QueryType);
	}
	*/
	return "";
}

TArray<FString> UCustomFilter::GetRuleValues(int32 Index)
{
	int32 i=0;
	TArray<FString> Ar = {};
	TArray<FCurrentFilter> Subset = {};
	/*
	Subset = GetRuleSetAt(Index);
	for (i = 0; i < Subset.Length; i++)
	{
		Ar[i] = Subset[i].Item.FilterItem.Value;
	}
	*/
	return Ar;
}

TArray<FCurrentFilter> UCustomFilter::GetRuleSet(FString ItemName)
{
	int32 i=0;
	TArray<FCurrentFilter> RuleAr = {};
	/*
	ChopClass(ItemName);
	for (i = 0; i < AllRules.Length; i++)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName)
		{
			RuleAr[RuleAr.Length] = AllRules[i];
		}
	}
	*/
	return RuleAr;
}

TArray<FCurrentFilter> UCustomFilter::GetRuleSetAt(int32 Index)
{
	TArray<FCurrentFilter> RuleAr = {};
	/*
	if (ValidIndex(Index))
	{
		RuleAr = GetRuleSet(AllRules[Index].Item.FilterItem.Key);
	}
	*/
	return RuleAr;
}

void UCustomFilter::PostEdit(FString NewTitle, TArray<FAFilterRule> NewRules)
{
	/*
	local int32 i;
	AllRules.remove(0, AllRules.Length);
	Title = NewTitle;
	for (i = 0; i < NewRules.Length; i++)
	{
		AddRule(NewRules[i].ItemName, NewRules[i].FilterItem.Key, NewRules[i].FilterItem.Value, NewRules[i].FilterItem.QueryType, NewRules[i].FilterType);
	}
	bDirty = True;
	Save();
	*/
}

int32 UCustomFilter::AddRule(FString NewName, FString NewKey, FString NewValue, EQueryType QType, EDataType DType)
{
	int32 i=0;
	int32 j=0;
	/*
	local CustomFilter.CurrentFilter NewRule;
	local CustomFilter.AFilterRule NewItem;
	local MasterServerClient.QueryData KeyPair;
	j = FindLastIndex(NewKey);
	NewRule.ItemIndex = j + 1;
	i = AllRules.Length;
	KeyPair.Key = NewKey;
	KeyPair.Value = NewValue;
	KeyPair.QueryType = QType;
	NewItem.ItemName = NewName;
	NewItem.FilterItem = KeyPair;
	NewItem.FilterType = DType;
	NewRule.Item = NewItem;
	AllRules[i] = NewRule;
	bDirty = True;
	*/
	return i;
}

bool UCustomFilter::RemoveRule(FString ItemName)
{
	bool bSuccess=false;
	int32 i=0;
	/*
	for (i = AllRules.Length - 1; i >= 0; i--)
	{
		if (AllRules[i].Item.FilterItem.Key ~= ItemName)
		{
			bDirty = True;
			bSuccess = True;
			AllRules.remove(i--, 1);
		}
	}
	*/
	return bSuccess;
}

bool UCustomFilter::RemoveRuleAt(int32 Index)
{
	/*
	if (ValidIndex(Index))
	{
		Return RemoveRule(AllRules[Index].Item.FilterItem.Key);
	}
	*/
	return false;
}

void UCustomFilter::ImportFilter(UCustomFilter* ImportFrom)
{
	/*
	SetTitle(ImportFrom.GetTitle());
	SetActive(ImportFrom.IsActive());
	ImportFrom.GetRules(AllRules);
	bDirty = True;
	*/
}

void UCustomFilter::ResetRules()
{
	//CancelChanges();
}

bool UCustomFilter::ChangeRule(int32 Index, FString NewTag, FString NewValue, EQueryType NewType)
{
	/*
	if (!ValidIndex(Index))
	{
		return false;
	}
	AllRules[Index].Item.ItemName = NewTag;
	AllRules[Index].Item.FilterItem.Value = NewValue;
	AllRules[Index].Item.FilterItem.QueryType = NewType;
	bDirty = True;
	*/
	return true;
}

void UCustomFilter::ValidIndex(int32 Index)
{
	//Return Index >= 0 && Index < AllRules.Length;
}

void UCustomFilter::GetDataType(FString dt)
{
	/*
	Switch(dt)
	{
			case "DT_Multiple":
				Return 2;
			case "DT_Ranged":
				Return 1;
			default:
				Return 0;
	}
	*/
}
FString UCustomFilter::GetDataTypeString(EDataType Type)
{
	/*
	if (Type == 0)
	{
		Return "DT_Unique";
	}
	if (Type == 1)
	{
		Return "DT_Ranged";
	}
	if (Type == 2)
	{
		Return "DT_Multiple";
	}
	*/
	return "";
}
void UCustomFilter::GetQueryString(EQueryType QT)
{
	/*
	Switch(QT)
	{
		case 0:
			Return "QT_Equals";
		case 1:
			Return "QT_NotEquals";
		case 2:
			Return "QT_LessThan";
		case 3:
			Return "QT_LessThanEquals";
		case 4:
			Return "QT_GreaterThan";
		case 5:
			Return "QT_GreaterThanEquals";
		default:
			Return "QT_Disabled";
			Return "";
	}
	*/
}
void UCustomFilter::GetQueryType(FString QT)
{
	/*
	Switch(QT)
	{
	case "QT_Equals":
		Return 0;
	case "QT_NotEquals":
		Return 1;
	case "QT_LessThan":
		Return 2;
	case "QT_LessThanEquals":
		Return 3;
	case "QT_GreaterThan":
		Return 4;
	case "QT_GreaterThanEquals":
		Return 5;
	default:
		Return 6;
	}
	*/
}

void UCustomFilter::StaticGenerateRule(FString FriendlyName, FString ItemName, FString ItemVal, EDataType ItemDataType, EQueryType ItemQueryType)
{
	/*
	local CustomFilter.AFilterRule NewItem;
	local MasterServerClient.QueryData KeyPair;
	KeyPair.Key = ItemName;
	KeyPair.Value = ItemVal;
	KeyPair.QueryType = ItemQueryType;
	NewItem.ItemName = FriendlyName;
	NewItem.FilterItem = KeyPair;
	NewItem.FilterType = ItemDataType;
	Return NewItem;
	*/
}

void UCustomFilter::GetUniqueName(FString Test, int32 Index)
{
	/*
	local int32 i;
	local int32 j;
	local FString S;
	for (i = 0; i < AllRules.Length; i++)
	{
		if (AllRules[i].ItemIndex == Index && AllRules[i].Item.ItemName ~= Test $ S)
		{
			S = " " $ ++ j;
			i = -1;
		}
	}
	Return Test $ S;
	*/
}

void UCustomFilter::ChopClass(FString& FullName)
{
	/*
	local int32 i;
	i = InStr(FullName, ".");
	if (i >= 0)
	{
		FullName = Mid(FullName, i + 1);
		i = InStr(FullName, ".");
	}
	*/
}