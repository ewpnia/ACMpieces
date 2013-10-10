#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class BiTreeNode
{
private:
	BiTreeNode  *leftChild;						//左子树指针
	BiTreeNode  *rightChild;					//右子树指针
public:
	char  data;									//数据域

	//构造函数和析构函数
	BiTreeNode():leftChild(NULL), rightChild(NULL){} //构造一颗空树
	BiTreeNode(char  item, BiTreeNode  *left = NULL, 
				BiTreeNode  *right = NULL):
				data(item), leftChild(left), rightChild(right){} //左右子树加上根节点建立树
	~BiTreeNode(){}

	BiTreeNode  * &Left(void)	//注意返回值类型为指针的引用类型
		{return leftChild;}
	BiTreeNode  * &Right(void)	//注意返回值类型为指针的引用类型
		{return rightChild;}
};


class BiTree
{
private:
	BiTreeNode  *root;							//根结点指针
    int i; 
	void Destroy(BiTreeNode  * &t);
	void PreOrder(BiTreeNode  * &t);
	void InOrder(BiTreeNode  * &t);
	void PostOrder(BiTreeNode  * &t);
    void  CreateBiTree(BiTreeNode * &T,const char strTree[]);
public:
	//构造函数和析构函数
	BiTree(void):root(NULL),i(0){};					//构造函数
	~BiTree(void){};								//析构函数

	//构造二叉树
   void MakeTree(const char item, BiTree  &left, BiTree  &right); //构造二叉树
   void MakeTree(const char strTree[]); //构造二叉树，利用先序遍历结果建树

	void PreOrder();		//前序遍历	
	void InOrder();			//中序遍历
	void PostOrder();		//后序遍历
};


//定义建树函数
void BiTree::MakeTree(const char item, BiTree  &left, BiTree  &right)
//构造数据域为item，左子树为left，右子树为right的二叉树
{
	root = new BiTreeNode(item, left.root, right.root);
}

void BiTree::MakeTree(const char strTree[])
//构造二叉树，利用先序遍历结果建树，公有函数
{
   i=0;
   CreateBiTree(root,strTree);
}

void BiTree::CreateBiTree(BiTreeNode * &T, const char strTree[])   //递归建树私有函数
{
	char ch;
	ch=strTree[i++]; 
    if (ch=='0') T = NULL;
	else 
	{
		T=new BiTreeNode();
		T->data = ch;              // 生成根结点
		CreateBiTree(T->Left(), strTree);   // 构造左子树
		CreateBiTree(T->Right(), strTree);   // 构造右子树
    } 
}
//定义先序遍历函数
void BiTree::PreOrder()
//前序遍历访问二叉树，公有函数
{
	PreOrder(root);
}

void BiTree::PreOrder(BiTreeNode* &t)
//前序遍历访问二叉树，私有函数t
{
	if(t != NULL) //如果树不空
	{
		cout<<(t->data); //访问根节点
		PreOrder(t->Left()); //遍历左子树
		PreOrder(t->Right()); //遍历右子树
	}
}

//定义中序遍历函数
void BiTree::InOrder()
//中序遍历访问二叉树，公有函数
{
	InOrder(root);
}

void BiTree:: InOrder(BiTreeNode* &t)
//中序遍历访问二叉树，私有函数t
{
	if(t != NULL) //如果树不空
	{
		InOrder(t->Left()); //遍历左子树
		cout<<(t->data); //访问根节点
		InOrder(t->Right()); //遍历右子树
	}
}

//后序遍历函数
void BiTree::PostOrder()
//后序遍历访问二叉树，公有函数
{
	PostOrder(root);
}

void BiTree:: PostOrder(BiTreeNode* &t)
//后序遍历访问二叉树，私有函数t
{
	if(t != NULL) //如果树不空
	{
		PostOrder(t->Left()); //遍历左子树
		PostOrder(t->Right()); //遍历右子树
		cout<<(t->data); //访问根节点
	}
}

//(三)	编写主程序bitree.cpp


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