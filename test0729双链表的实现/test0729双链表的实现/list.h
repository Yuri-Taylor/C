#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListCreate();//�������������ͷ�ڵ�

void ListDestory(ListNode* phead);//����

void ListPrint(ListNode* phead);//��ӡ

void ListPushBack(ListNode* phead, LTDataType x);//β��

void ListPushFront(ListNode* phead, LTDataType x);//ͷ��

void ListPopBack(ListNode* phead);//βɾ

void ListPopFront(ListNode* phead);//ͷɾ

ListNode* ListFind(ListNode* phead, LTDataType x);//����

void ListInsert(ListNode* pos, LTDataType x);//��posλ��ǰ�����

void ListErase(ListNode* pos);//ɾ��posλ�õĽڵ�
