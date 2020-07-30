#include"list.h"

void Test()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);
	ListPushFront(list, 20);
	ListPrint(list);
	ListNode* find = ListFind(list, 7);
	printf("%p\n", find);
	ListInsert(list->prev, 44);
	ListPrint(list);
	ListErase(list->next);
	ListPrint(list);
}

int main()
{
	Test();
	return 0;
}