#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class BiTreeNode
{
private:
	BiTreeNode  *leftChild;						//������ָ��
	BiTreeNode  *rightChild;					//������ָ��
public:
	char  data;									//������

	//���캯������������
	BiTreeNode():leftChild(NULL), rightChild(NULL){} //����һ�ſ���
	BiTreeNode(char  item, BiTreeNode  *left = NULL, 
				BiTreeNode  *right = NULL):
				data(item), leftChild(left), rightChild(right){} //�����������ϸ��ڵ㽨����
	~BiTreeNode(){}

	BiTreeNode  * &Left(void)	//ע�ⷵ��ֵ����Ϊָ�����������
		{return leftChild;}
	BiTreeNode  * &Right(void)	//ע�ⷵ��ֵ����Ϊָ�����������
		{return rightChild;}
};


class BiTree
{
private:
	BiTreeNode  *root;							//�����ָ��
    int i; 
	void Destroy(BiTreeNode  * &t);
	void PreOrder(BiTreeNode  * &t);
	void InOrder(BiTreeNode  * &t);
	void PostOrder(BiTreeNode  * &t);
    void  CreateBiTree(BiTreeNode * &T,const char strTree[]);
public:
	//���캯������������
	BiTree(void):root(NULL),i(0){};					//���캯��
	~BiTree(void){};								//��������

	//���������
   void MakeTree(const char item, BiTree  &left, BiTree  &right); //���������
   void MakeTree(const char strTree[]); //�����������������������������

	void PreOrder();		//ǰ�����	
	void InOrder();			//�������
	void PostOrder();		//�������
};


//���彨������
void BiTree::MakeTree(const char item, BiTree  &left, BiTree  &right)
//����������Ϊitem��������Ϊleft��������Ϊright�Ķ�����
{
	root = new BiTreeNode(item, left.root, right.root);
}

void BiTree::MakeTree(const char strTree[])
//����������������������������������к���
{
   i=0;
   CreateBiTree(root,strTree);
}

void BiTree::CreateBiTree(BiTreeNode * &T, const char strTree[])   //�ݹ齨��˽�к���
{
	char ch;
	ch=strTree[i++]; 
    if (ch=='0') T = NULL;
	else 
	{
		T=new BiTreeNode();
		T->data = ch;              // ���ɸ����
		CreateBiTree(T->Left(), strTree);   // ����������
		CreateBiTree(T->Right(), strTree);   // ����������
    } 
}
//���������������
void BiTree::PreOrder()
//ǰ��������ʶ����������к���
{
	PreOrder(root);
}

void BiTree::PreOrder(BiTreeNode* &t)
//ǰ��������ʶ�������˽�к���t
{
	if(t != NULL) //���������
	{
		cout<<(t->data); //���ʸ��ڵ�
		PreOrder(t->Left()); //����������
		PreOrder(t->Right()); //����������
	}
}

//���������������
void BiTree::InOrder()
//����������ʶ����������к���
{
	InOrder(root);
}

void BiTree:: InOrder(BiTreeNode* &t)
//����������ʶ�������˽�к���t
{
	if(t != NULL) //���������
	{
		InOrder(t->Left()); //����������
		cout<<(t->data); //���ʸ��ڵ�
		InOrder(t->Right()); //����������
	}
}

//�����������
void BiTree::PostOrder()
//����������ʶ����������к���
{
	PostOrder(root);
}

void BiTree:: PostOrder(BiTreeNode* &t)
//����������ʶ�������˽�к���t
{
	if(t != NULL) //���������
	{
		PostOrder(t->Left()); //����������
		PostOrder(t->Right()); //����������
		cout<<(t->data); //���ʸ��ڵ�
	}
}

//(��)	��д������bitree.cpp


int main()
{
	int m,i;
	char strTree[80];
	string teststr;
	getline(cin, str);
	BiTree myTree;
	getline(cin, str);// >> teststr;
	cin>>m;
	cin.get();
    for(i=0;i<m;i++)
	{
		cin>>strTree;
		myTree.MakeTree(strTree);
		myTree.PreOrder();
		cout<<endl;
		myTree.InOrder();
		cout<<endl;
		myTree.PostOrder();
		cout<<endl;
	}
	return 0;

}