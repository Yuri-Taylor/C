#pragma once

#include<stdio.h>
#include<malloc.h>
#include<memory.h>
#include<string.h>

typedef int HpDataType;

typedef struct Heap
{
	HpDataType* _a;
	size_t _size;
	size_t _capapcity;
}Heap;

void HeapCreate(Heap* hp, HpDataType* a, size_t n);//������
void HeapDestory(Heap* hp);//����
void HeapPush(Heap* hp, HpDataType x);//����
void HeapPop(Heap* hp);//ɾ��
HpDataType HeapTop(Heap* hp);//ȡ�Ѷ�������
int HeapSize(Heap* hp);//�ѵ����ݸ���
int HeapEmpty(Heap* hp);//�п�
void HeapSort(HpDataType* a, size_t n);//�Զ�����
void HeapPrint(Heap* hp);