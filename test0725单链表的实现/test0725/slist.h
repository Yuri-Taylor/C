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
SListNode* SListFind(SListNode* pList, SLTDataType x);//����
void SListInsertAfter(SListNode* pos, SLTDataType x);//�ڵ�ǰλ�ú����
void SListEraseAfter(SListNode* pos);//�ڵ�ǰλ�ú�ɾ��