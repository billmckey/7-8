#pragma once
#include "PCB.h"
struct ListNode
{
	PCB data;
	ListNode* next;
	ListNode(const PCB& pcbData);
};