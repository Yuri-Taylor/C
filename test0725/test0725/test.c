#include"slist.h"

void TestSList()
{
	SListNode* pList=NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushFront(&pList, 5);
	SListPopFront(&pList);
	SListPrint(pList);
}
//
//int main()
//{
//	TestSList();
//	return 0;
//}
