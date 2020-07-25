#pragma once
#include<stdio.h>
#include<malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pList);//¥Ú”°
void SListPushBack(SListNode** ppList, SLTDataType x);//Œ≤≤Â
void SListPushFront(SListNode** ppList, SLTDataType x);//Õ∑≤Â
void SListPopBack(SListNode** ppList);//Œ≤…æ
void SListPopFront(SListNode** ppList);//Õ∑…æ
void SListInit(SListNode* pList);