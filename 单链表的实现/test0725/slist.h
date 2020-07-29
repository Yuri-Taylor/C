#pragma once
#include<stdio.h>
#include<malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pList);//打印
void SListPushBack(SListNode** ppList, SLTDataType x);//尾插
void SListPushFront(SListNode** ppList, SLTDataType x);//头插
void SListPopBack(SListNode** ppList);//尾删
void SListPopFront(SListNode** ppList);//头删
SListNode* SListFind(SListNode* pList, SLTDataType x);//查找
void SListInsertAfter(SListNode* pos, SLTDataType x);//在当前位置后插入
void SListEraseAfter(SListNode* pos);//在当前位置后删除