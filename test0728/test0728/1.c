#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int STDataType;
typedef struct ListNode
{
	STDataType data;
	struct ListNode* next;
}ListNode;


//1.ɾ�������е��ڸ���ֵdata�����нڵ�
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



//2.��ת������  1->2->3->4->5->NULL��תΪ5->4->3->2->1->NULL
//����һ:
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
//��������
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



//3. ����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м�ڵ�
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

//4.����һ����������������е�����k�����
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

//5.��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
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


//6. ��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ 
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


//7.��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ��



//8.����Ļ��Ľṹ


//9.�������������ҳ����ǵĵ�һ���������



//10. ����һ�������ж��������Ƿ��л���


//11. ����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣?��������޻����򷵻�?NULL



//12.����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣 Ҫ�󷵻�����������ȿ���



