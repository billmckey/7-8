#include <iostream>
#include "ProcessList.h"
using std::cout;
using std::endl;
ProcessList::ProcessList()
{
	head = nullptr;
}
ProcessList::~ProcessList()
{
	ListNode* current = head;
	while (current!=nullptr)
	{
		ListNode* nextN = current->next;
		delete current;
		current = nextN;
	}
}
void ProcessList::printList() const
{
	ListNode* current = head;
	if (head == nullptr)
	{
		cout << "Список пуст";
		return;
	}
	else
	{
		while (current != nullptr)
		{
			ListNode* nextN = current->next;
			cout << "ID: " << current->data.processID << endl;
			cout << "Name: " << current->data.processName << endl;
			cout << "Status: " << current->data.processStatus << endl;
			current = nextN;
		}
	}
	
}
bool ProcessList::insert(const PCB& newPCB)
{
	ListNode* current = head;
	while (current != nullptr)
	{
		if (current->data.processID == newPCB.processID)
		{
			return false;
		}
		current = current->next;
	}
	ListNode* newNode = new ListNode(newPCB);
	if (head == nullptr || newPCB.processID < head->data.processID)
	{
		newNode->next = head;
		head = newNode;
		return true;
	}
	ListNode* current2 = head;
	ListNode* previous = nullptr;
	while (current2 != nullptr && current2->data.processID < newPCB.processID)
	{
		previous = current2;
		current2 = current2->next;
	}
	newNode->next = current2;
	previous->next = newNode;
	return true;
}
bool ProcessList::remove(int pid)
{
	ListNode* current = head;
	ListNode* previous = nullptr;
	while (current != nullptr&& current->data.processID!=pid)
	{
		previous = current;
		current = current->next;
	}
	if (current == nullptr)
	{
		return false;
	}
	if (previous == nullptr)
	{
		head = current->next;
	}
	else
	{
		previous->next = current->next;
	}
	delete current;
	return true;
}