#include<stdio.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity); //��ʼ��
void SeqListDestory(SeqList* psl);//����

void CheckCapacity(SeqList* psl);//�鿴������С
void SeqListPushBack(SeqList* psl, SLDataType x);//
void SeqListPopBack(SeqList* psl);//
void SeqListPushFront(SeqList* psl, SLDataType x);//
void SeqListPopFront(SeqList* psl);//

int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

void SeqListBubbleSort(SeqList* psl);


int SeqListBinaryFind(SeqList* psl, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);