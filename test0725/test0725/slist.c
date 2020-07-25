#include"slist.h"

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPrint(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void SListPushBack(SListNode** ppList, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else
	{
		SListNode* cur = *ppList;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void SListPushFront(SListNode** ppList, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}


void SListPopBack(SListNode** ppList)
{
	//1.链表为空
	if (*ppList == NULL)
	{
		return;
	}
	//2.链表只有一个节点
	else if ((*ppList)->next==NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	//3.链表有多个节点
	else
	{
		SListNode* cur = *ppList;
		SListNode* prev = NULL;
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}

		free(cur);
		prev->next = NULL;
	}
}

void SListPopFront(SListNode** ppList)
{
	//1.链表为空
	if (*ppList == NULL)
	{
		return;
	}
	//2.链表只有一个节点
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	//3.链表有多个节点
	else
	{
		SListNode* cur = *ppList;
		*ppList = (*ppList)->next;
		free(cur);
	}
}