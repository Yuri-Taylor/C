#include"Heap.h"

//С�����µ���
void AdjustDown(HpDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		//�ҳ�С�ĺ���
		if (a[child + 1] < a[child])
		{
			++child;
		}
		//������ӱȸ���С
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
Heap* HeapCreate(HpDataType* a, size_t n)//������
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	hp->_a = (HpDataType)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_capapcity = n;
	hp->_size = n;
	//����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
	return hp;
}
void HeapDestory(Heap* hp)//����
{

}
void HeapPush(Heap* hp, HpDataType x)//����
{

}
void HeapPop(Heap* hp)//ɾ��
{

}
HpDataType HeapTop(Heap* hp)//ȡ�Ѷ�������
{

}
int HeapSize(Heap* hp)//�ѵ����ݸ���
{

}
int HeapEmpty(Heap* hp)//�п�
{

}
void HeapSort(HpDataType* a, size_t n)//�Զ�����
{

}