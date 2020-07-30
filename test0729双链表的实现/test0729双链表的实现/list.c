#include"list.h"

ListNode* ListCreate()//创建返回链表的头节点
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

void ListDestory(ListNode* phead)//销毁
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

void ListPrint(ListNode* phead)//打印
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d  ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushBack(ListNode* phead, LTDataType x)//尾插
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void ListPushFront(ListNode* phead, LTDataType x)//头插
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* first = phead->next;
	newnode->data = x;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}
void ListPopBack(ListNode* phead)//尾删
{
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	free(tail);
	prev->next = phead;
	phead->prev = prev;
}
void ListPopFront(ListNode* phead)//头删
{
	assert(phead->next != phead);
	ListNode* node = phead->next;
	ListNode* next = node->next;
	free(node);
	phead->next = next;
	next->prev = phead;
}
ListNode* ListFind(ListNode* phead, LTDataType x)//查找
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)//在pos位置前面插入
{
	ListNode* prev = pos->prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;

	newnode->prev = prev;
	prev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(ListNode* pos)//删除pos位置的节点
{
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}