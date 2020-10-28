#pragma once

#include<stdio.h>
//冒泡排序
void BobbleSort(int a[], int len)
{
	int i, j,tmp;
	int flag = 0;
	for (i = 0; i < len-1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}
//选择排序(每次找最大或最小的)
void SelectSort(int arr[], int len)
{
	int i, j, min;
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i+1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
			int tmp = arr[j];
			arr[j] = arr[min];
			arr[min] = tmp;
		}
	}
}
//插入排序
void InsertSort(int* arr, int len)
{
	int i, j, tmp;
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}
//希尔排序  是插入排序的一种，分组进行插入排序
void ShellSort(int arr[])
{
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int gap = len / 2; gap > 0; gap++)
	{
		for (int i = gap; i < len; i++)
		{
			int j = i;
			int tmp = arr[j];
			if (arr[j] < arr[j - gap])
			{
				while (j - gap >= 0 && tmp < arr[j - gap])
				{
					arr[j] = arr[j - gap];
					j -= gap;
				}
				arr[j] = tmp;
			}
		}
	}
}
//堆排序
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustHeap(int arr[], int start, int end)
{
	int parent = start;
	int child = parent * 2 + 1;
	while (child <= end)
	{
		if (child + 1 <= end && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] > arr[child])
			return;
		else
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}
void HeapSort(int arr[], int len)
{
	int i;
	for (i = len / 2 - 1; i >= 0; i--)
	{
		AdjustHeap(arr, i, len-1);
	}
	for (i = len - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		AdjustHeap(arr, 0, i - 1);
	}
}
//归并排序
void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] > sourceArr[j])
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while (i != midIndex + 1)
	{
		tempArr[k++] = sourceArr[i++];
	}
	while (j != endIndex + 1)
	{
		tempArr[k++] = sourceArr[j++];
	}
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;
		MergeSort(sourceArr, tempArr, startIndex, midIndex);
		MergeSort(sourceArr, tempArr, midIndex, endIndex);
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}
}
//快速排序
void sort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	int key = a[left];
	while (i < j)
	{
		while (i < j&&key <= a[j])
		{
			j--;
		}
		a[i] = a[j];
		while (i < j&&key >= a[i])
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	sort(a, left, i - 1);
	sort(a, i + 1, right);
}