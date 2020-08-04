#include"Heap.h"

//小堆向下调整
void AdjustDown(HpDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		//找出小的孩子
		if (a[child + 1] < a[child])
		{
			++child;
		}
		//如果孩子比父亲小
		if (a[parent] > a[child])
		{
			HpDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
Heap* HeapCreate(HpDataType* a, size_t n)//创建堆
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	hp->_a = (HpDataType)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_capapcity = n;
	hp->_size = n;
	//建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
	return hp;
}
void HeapDestory(Heap* hp)//销毁
{

}
void HeapPush(Heap* hp, HpDataType x)//插入
{

}
void HeapPop(Heap* hp)//删除
{

}
HpDataType HeapTop(Heap* hp)//取堆顶的数据
{

}
int HeapSize(Heap* hp)//堆的数据个数
{

}
int HeapEmpty(Heap* hp)//判空
{

}
void HeapSort(HpDataType* a, size_t n)//对堆排序
{

}