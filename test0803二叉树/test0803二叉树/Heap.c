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
void AdjustUp(HpDataType* a, size_t child)//С�����ϵ���
{
	size_t parent = (child - 1) / 2;
	while (child>0)//parent����С��0��������child�ж�
	{
		if (a[child] < a[parent])
		{
			HpDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapCreate(Heap* hp, HpDataType* a, size_t n)//������
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capapcity = n;
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
//Heap* HeapCreate(HpDataType* a, size_t n)//������
//{
//	Heap* hp = (Heap*)malloc(sizeof(Heap));
//	hp->_a = (HpDataType)malloc(sizeof(HpDataType)*n);
//	memcpy(hp->_a, a, sizeof(HpDataType)*n);
//	hp->_capapcity = n;
//	hp->_size = n;
//	//����
//	for (int i = (n - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(hp->_a, hp->_size, i);
//	}
//	return hp;
//}
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void HeapDestory(Heap* hp)//����
{

}
void HeapPush(Heap* hp, HpDataType x)//����
{
	if (hp->_size == hp->_capapcity)
	{
		size_t newcapacity = hp->_capapcity * 2;
		hp->_a = (HpDataType*)realloc(sizeof(HpDataType)*newcapacity);
		hp->_capapcity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//���ϵ��������ɶ�
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)//ɾ��  ��һ�������һ��������ɾ�������µ���
{
	HpDataType tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
HpDataType HeapTop(Heap* hp)//ȡ�Ѷ�������
{
	return hp->_a[0];
}
int HeapSize(Heap* hp)//�ѵ����ݸ���
{
	return hp->_size;
}
int HeapEmpty(Heap* hp)//�п�
{
	return hp->_size == 0 ? 1 : 0;
}




void HeapSort(int* a, int n)//�Զ���������
{
	//��С��
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		AdjustDown(a, end, 0);
		--end;
	}
}