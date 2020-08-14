#include"Heap.h"
#include"BinaryTree.h"

BTNode* Rebulid(char* a,int* pi)
{
	if (a[*pi] == '#')
		return NULL;
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = Rebulid(a,pi);
		++(*pi);
		root->_right = Rebulid(a, pi);
		return root;
	}
}
void Inorder(BTNode* root)
{
	if (root == NULL)
		return;
	Inorder(root->_left);
	printf("%c ", root->_data);
	Inorder(root->_right);
}
int main()
{
	char a[100];
	scanf("%s", a);
	//������������ع�������
	int i = 0;
	BTNode* root = NULL;
	root = Rebulid(a, i);
	//�������
	Inorder(root);
	return 0;
}
