#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int STDataType;
typedef struct ListNode
{
	STDataType data;
	struct ListNode* next;
}ListNode;


//1.删除链表中等于给定值data的所有节点
//ListNode* ListDelete(ListNode* list, STDataType x)
//{
//	if (list == NULL)
//		return NULL;
//	while (list != NULL && list->data == x)
//	{
//		list = list->next;
//	}
//	ListNode* prev = list;
//	ListNode* cur = list->next;
//	while (cur)
//	{
//		if (cur->data == x)
//		{
//			prev->next = cur->next;
//		}
//		else
//		{
//			prev = cur;
//		}
//		cur = cur->next;
//	}
//	return list;
//}



//2.反转单链表  1->2->3->4->5->NULL反转为5->4->3->2->1->NULL
//方法一:
//typedef struct ListNode
//{
//	int data;
//	struct ListNode* next;
//}Node;
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//	Node* n1, *n2, *n3;
//	if (head == NULL || head->next == NULL)
//		return NULL;
//	n1 = NULL;
//	n2 = head;
//	n3 = n2->next;
//
//	while (n2)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if(n3)
//			n3 = n3->next;
//	}
//	return n1;
//}
//int main()
//{
//	Node* n1 = (Node*)malloc(sizeof(Node));
//	Node* n2 = (Node*)malloc(sizeof(Node));
//	Node* n3 = (Node*)malloc(sizeof(Node));
//	Node* n4 = (Node*)malloc(sizeof(Node));
//	Node* n5 = (Node*)malloc(sizeof(Node));
//	Node* node = NULL;
//	n1->data = 1;
//	n2->data = 2;
//	n3->data = 3;
//	n4->data = 4;
//	n5->data = 5;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;
//	Node* cur = n1;
//	while (cur)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//
//	node = reverseList(n1);
//	cur = node;
//	while (cur)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//	return 0;
//}
//
//方法二：
//typedef struct ListNode
//{
//	int data;
//	struct ListNode* next;
//}Node;
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//	Node* cur = head;
//	Node* newhead = NULL;
//	while (cur)
//	{
//		Node* next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//	return newhead;
//}



//3. 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间节点
//ListNode* MiddleList(ListNode* head)
//{
//	if (head->next == NULL)
//		return NULL;
//	ListNode* fast = head;
//	ListNode* slow = head;
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	return slow;
//}
//int main()
//{
//	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
//	head->next = n1;
//	n1->data = 1;
//	n2->data = 2;
//	n3->data = 3;
//	n4->data = 4;
//	n5->data = 5;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;
//	ListNode* list=MiddleList(head);
//	printf("%d ", list->data);
//	return 0;
//}

//4.输入一个链表，输出该链表中倒数第k个结点
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//	if (pListHead == NULL || k < 0)
//		return NULL;
//	ListNode* fast = pListHead;
//	ListNode* slow = pListHead;
//	int i = 0;
//	while (fast)
//	{
//		if (i < k)
//		{
//			fast = fast->next;
//			i++;
//		}
//		else
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//	}
//	if (i < k)
//		return NULL;
//	return slow;
//}
//
//int main()
//{
//	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
//	n1->data = 1;
//	n2->data = 2;
//	n3->data = 3;
//	n4->data = 4;
//	n5->data = 5;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;
//	ListNode* list = FindKthToTail(n1, 1);
//	printf("%d ", list->data);
//	return 0;
//}

//5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//	if (l1 == NULL)
//	{
//		return l2;
//	}
//	if (l2 == NULL)
//	{
//		return l1;
//	}
//	ListNode* cur1 = l1;
//	ListNode* cur2 = l2;
//	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* cur = head;
//	while (cur1 && cur2)
//	{
//		if (cur1->data< cur2->data)
//		{
//			cur->next = cur1;
//			cur1 = cur1->next;
//			cur = cur->next;
//			cur->next = NULL;
//		}
//		else
//		{
//			cur->next = cur2;
//			cur2 = cur2->next;
//			cur = cur->next;
//			cur->next = NULL;
//		}
//	}
//	return head->next;
//}


//6. 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 
ListNode* partition(ListNode* pHead, int x) {
	ListNode* cur = pHead;
	ListNode* list = NULL;
	ListNode* head1, *head2, *tail1, *tail2;
	head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));
	head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));
	tail1->next = NULL;
	tail2->next = NULL;
	while (cur)
	{
		if (cur->val < x)
		{
			tail1->next = cur;
			tail1 = cur;
		}
		else {
			tail2->next = cur;
			tail2 = cur;
		}
		cur = cur->next;
	}
	tail1->next = head2->next;
	tail2->next = NULL;
	list = head1->next;
	free(head1);
	free(head2);
	return list;
}


//7.在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针



//8.链表的回文结构


//9.输入两个链表，找出它们的第一个公共结点



//10. 给定一个链表，判断链表中是否有环。


//11. 给定一个链表，返回链表开始入环的第一个节点。?如果链表无环，则返回?NULL



//12.给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。 要求返回这个链表的深度拷贝



