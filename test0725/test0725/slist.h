#pragma once
#include<stdio.h>
#include<malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pList);//��ӡ
void SListPushBack(SListNode** ppList, SLTDataType x);//β��
void SListPushFront(SListNode** ppList, SLTDataType x);//ͷ��
void SListPopBack(SListNode** ppList);//βɾ
void SListPopFront(SListNode** ppList);//ͷɾ
void SListInit(SListNode* pList);