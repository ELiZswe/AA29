// All the original content belonged to the US Army

#include "AA29/Object/LogEntry/LogEntry.h"

ULogEntry::ULogEntry()
{
	DateTime = "No Date/Time specified.";
	Entry = "No Data.";
}

void ULogEntry::Insert(ULogEntry* newLE)
{
	ULogEntry* cur = nullptr;
	if (Next == nullptr)
	{
		Next = newLE;
	}
	else
	{
		cur = Next;
		if (cur->Next != nullptr)
		{
			cur = cur->Next;
		}
		cur->Next = newLE;
	}
}

ULogEntry* ULogEntry::Delete(ULogEntry* delLE)
{
	ULogEntry* head = nullptr;
	ULogEntry* Prev = nullptr;
	ULogEntry* cur = nullptr;
	head = this;
	if (this == delLE)
	{
		head = Next;
	}
	else
	{
		Prev = this;
		for (cur = Next; cur != delLE; cur = cur->Next)
		{
			Prev = cur;
		}
		Prev->Next = cur->Next;
	}
	return head;
}

int32 ULogEntry::Count()
{
	int32 Num = 0;
	ULogEntry* le = nullptr;
	le = this;
	Num = 0;
	if (le != nullptr)
	{
		Num++;
		le = le->Next;
	}
	return Num;
}