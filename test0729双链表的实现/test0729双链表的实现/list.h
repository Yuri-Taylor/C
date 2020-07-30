#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListCreate();//创建返回链表的头节点

void ListDestory(ListNode* phead);//销毁

void ListPrint(ListNode* phead);//打印

void ListPushBack(ListNode* phead, LTDataType x);//尾插

void ListPushFront(ListNode* phead, LTDataType x);//头插

void ListPopBack(ListNode* phead);//尾删

void ListPopFront(ListNode* phead);//头删

ListNode* ListFind(ListNode* phead, LTDataType x);//查找

void ListInsert(ListNode* pos, LTDataType x);//在pos位置前面插入

void ListErase(ListNode* pos);//删除pos位置的节点
