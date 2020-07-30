#include<stdio.h>
#include<stdlib.h>

//1.


//2.反转单链表  1->2->3->4->5->NULL反转为5->4->3->2->1->NULL
//方法一:
//typedef struct ListNode
//{
//	int val;
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
//	n1->val = 1;
//	n2->val = 2;
//	n3->val = 3;
//	n4->val = 4;
//	n5->val = 5;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = NULL;
//	Node* cur = n1;
//	while (cur)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//
//	node = reverseList(n1);
//	cur = node;
//	while (cur)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//	return 0;
//}
//
//方法二：
//typedef struct ListNode
//{
//	int val;
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



//3.输入一个链表，输出该链表中倒数第k个结点
