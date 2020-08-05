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

void HeapCreate(Heap* hp, HpDataType* a, size_t n);//创建堆
void HeapDestory(Heap* hp);//销毁
void HeapPush(Heap* hp, HpDataType x);//插入
void HeapPop(Heap* hp);//删除
HpDataType HeapTop(Heap* hp);//取堆顶的数据
int HeapSize(Heap* hp);//堆的数据个数
int HeapEmpty(Heap* hp);//判空
void HeapSort(HpDataType* a, size_t n);//对堆排序
void HeapPrint(Heap* hp);