// All the original content belonged to the US Army

#include "AA29/Object/LogEntry/LogEntry.h"

ULogEntry::ULogEntry()
{
	DateTime = "No Date/Time specified.";
	Entry = "No Data.";
}

void ULogEntry::Insert(ULogEntry* newLE)
{
	/*
	local LogEntry cur;
	if (Next == None)
	{
		Next = newLE;
	}
	else
	{
		cur = Next;
		if (cur.Next != None)
		{
			cur = cur.Next;
		}
		cur.Next = newLE;
	}
	*/
}

ULogEntry* ULogEntry::Delete(ULogEntry* delLE)
{
	ULogEntry* head = nullptr;
	ULogEntry* Prev = nullptr;
	ULogEntry* cur = nullptr;
	head = this;
	/*
	if (Self == delLE)
	{
		head = Next;
	}
	else
	{
		Prev = Self;
		cur = Next;
		if (cur != delLE)
		{
			Prev = cur;
			cur = cur.Next;
		}
		Prev.Next = cur.Next;
	}
	*/
	return head;
}

int32 ULogEntry::Count()
{
	int32 Num = 0;
	/*
	local LogEntry le;
	le = Self;
	Num = 0;
	if (le != None)
	{
		Num++;
		le = le.Next;
	}
	*/
	return Num;
}