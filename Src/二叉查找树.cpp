// ������������ֳƶ���������
// �밴��ע����ʾ��ʵ���䴴�������롢���Һ�ɾ������

#include <iostream>
using namespace std;

#define MAXNUM 100

//���ڵ�ṹ��
struct BiNode {  
	int 		data;			// ���ڵ�ֵ
	BiNode	*lChild, *rChild;	// ���Һ���
};

//���������� ��
class BiSortTree {			
	public:
		BiSortTree();								//���캯��
		~BiSortTree();								//��������

		void CreateBST(int *r, int n);				//��������������

		int  SearchBST(int k);						//���ҽ��

		void InsertBST(int k);						//������

		void InOrderTravel();						//�������������

		int	FindMin();								//��������������Сֵ
		int FindMax();								//���������������ֵ

		void DeleteNode(int k);						//ɾ�����k

													
		int  BisSuccess;							//�����Ƿ�ɹ���1--�ɹ���0--���ɹ���
		int  BisPos;								//����λ�ã���ʾ��BisCount���еĵڼ���λ�ã�����ȫ������Ϊ׼�������Ϊ1��㣩��
		int  BisCount;								//���Ҵ������൱�����Ĳ�����

	private:
		BiNode *root;								//��ָ��
		void DeleteTree(BiNode *s);					//ɾ��һ����s

		void SearchNode(BiNode *s, int k);			//����sΪ�������в���һ�����k

		void InsertNode(BiNode *s, BiNode *q);	    //����sΪ����������һ�����q

		void InOrderTravel(BiNode *s);				//���������sΪ���ڵ��������

		int	FindMin(BiNode *s);						//������sΪ���ڵ������������Сֵ
		int FindMax(BiNode *s);						//������sΪ���ڵ�������������ֵ

		BiNode* DeleteNode(BiNode *s, int k);		//����sΪ���ڵ��������ɾ�����k, ��������
};

// ���캯��
BiSortTree::BiSortTree() 
{
	root = new BiNode;							//���ɿ���
	root->data = NULL;							//�����ֵΪ��
	root->lChild = NULL; 
	root->rChild = NULL; 
}

//��������
BiSortTree::~BiSortTree() 
{
	DeleteTree(root);							//ɾ�����н��
}

//����DeleteTree�� ɾ����sΪ���ڵ����, ����������
void BiSortTree::DeleteTree(BiNode *s)
{
	if (s == NULL) return;
	DeleteTree(s->lChild);						//ɾ������
	DeleteTree(s->rChild);						//ɾ���Һ���
	delete s;									//ɾ�����
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

//���к���CreateBST�� ��������������
void BiSortTree::CreateBST(int *r, int n) 
{
	int i;
	BiNode *s;

	root->data = r[0];			//�����ڵ��һ��ֵ
	root->lChild = NULL;		//���Ӹ���
	root->rChild = NULL;		//�Һ��Ӹ���
	for (i=1; i<n; i++) {		//�ӵ�2��ֵ��ʼ�����β������������
		s = new BiNode;			//�½�һ���ڵ�
		s->data   = r[i];		//�ѵ�i��ֵ�����½ڵ�
		s->lChild = NULL;		//�½ڵ����Ӹ���
		s->rChild = NULL;		//�½ڵ��Һ��Ӹ���
		InsertNode(root, s);	//����˽�к���, ʹ��InsertNode���������½ڵ�
	}
}

//���к���InsertBST��������ֵ����֪����������
void BiSortTree::InsertBST(int k) 
{
	BiNode *s;					

	s = new BiNode;				  //�½�һ���ڵ�
	s->data = k;				  //����ֵk���½ڵ�
	s->lChild = NULL;			  //�½ڵ����Ӹ���
	s->rChild = NULL;			  //�½ڵ��Һ��Ӹ���
	InsertNode(root, s);		  //����˽�к���, ʹ��InsertNode���������½ڵ�
}

//˽�к���InsertNode�������½ڵ�q����sΪ���ڵ����
void BiSortTree::InsertNode(BiNode *s, BiNode *q) 
{
	if (q->data < s->data) {						//���s��ֵС�ڵ�ǰ���ڵ�
		if (!s->lChild==NULL)						//�����ǰ���ڵ���������
			InsertNode(s->lChild, q);				//��������������
		else {										//else:��ǰ���ڵ�û��������
			s->lChild = q;							//���½ڵ�s������ǰ���ڵ������
			return;									//����
		}
	}
	else {											//else: ���s��ֵ��С�ڵ�ǰ���ڵ�
		if (!s->rChild==NULL)						//�����ǰ���ڵ���������
			InsertNode(s->rChild, q);				//��������������
		else {										//else: ��ǰ���ڵ�û��������
			s->rChild = q;							//���½ڵ�s������ǰ���ڵ���Һ���
			return;									//����
		}
	}
}

//���к���SearchBST: �ڵ�ǰ���в��ҽ��k
int BiSortTree::SearchBST(int k) 
{
	BisCount = 0;				//��ʼ�����Ҵ���Ϊ0
	BisPos = 1;					//��ʼ������λ��Ϊ1

	if (root->data == NULL) {   //�����ǰ��Ϊ��
		BisSuccess = 0;			//���Ҳ��ɹ�
		return(0);				//����
	}

	SearchNode(root, k);		//����˽�к���, ����rootΪ���ڵ�����в���k, ʹ��SearchNode����

	cout << BisSuccess << " " << BisCount << " " << BisPos << endl; // ������

	return(BisSuccess);			//���سɹ���־
}

//˽�к���SearchNode: ����sΪ�������в���һ�����k
void BiSortTree::SearchNode(BiNode *s, int k)
{
	BiNode *NextBiNode;					//��һ�����ҿ�ʼ��

	BisCount++;							//���Ҵ�����1

	if (s->data == k) {					//�����ǰ�ڵ��ֵΪk
		BisSuccess = 1;					//���ò��ҳɹ���־Ϊ�ɹ�
		return;							//����
	}
	else {								//�����ǰ�ڵ��ֵ��Ϊk
		if (s->data > k)				//���kС�ڵ�ǰ�ڵ��ֵ
		{
			BisPos = 2*BisPos-1;		//�޸Ĳ���λ��BisPosΪ��ǰ�ڵ�����ӵ�λ��, ��λ��Ϊ��ǰλ�õ�2����1
			NextBiNode = s->lChild;		//������һ�����ҵ�NextBiNodeΪ��ǰ�ڵ������
		}
		else							//else�����k��С�ڵ�ǰ�ڵ��ֵ
		{
			BisPos = 2*BisPos;			//�޸Ĳ���λ��BisPosΪ��ǰ�ڵ���Һ��ӵ�λ��, ��λ��Ϊ��ǰλ�õ�2��
			NextBiNode = s->rChild;		//������һ�����ҵ�NextBiNodeΪ��ǰ�ڵ���Һ���
		}
	}

	if (NextBiNode != NULL)				//�����һ�����ҵ�NextBiNode����Ϊ��
		SearchNode(NextBiNode, k);		//����NextBiNodeΪ���ڵ�����в���k, ʹ��SearchNode����
	else {								//else:��һ�����ҵ�NextBiNodeΪ��
		BisSuccess = 0;					//���ò��ұ�־BisSuccessΪʧ��
		BisCount++;						//���Ҵ�����1����Ϊ��ʵ�ϻ���Ҫ�ڱȽ�һ�Σ�������ǰ����
		InsertBST(k);					//���ݶ�̬���ұ����Ҳ��ɹ��������k����ǰ����ʹ��InsertBST����
	}
}

//���к���InOrderTravel: ���������ǰ��
void BiSortTree::InOrderTravel()
{
	InOrderTravel(root);	//����˽�к���, ���������rootΪ���ڵ����
	cout << endl;
}

//˽�к���InOrderTravel: ���������sΪ���ڵ����
void BiSortTree::InOrderTravel(BiNode *s)
{
	if(s == NULL) return;

	//�������
	if(s->lChild != NULL)
		InOrderTravel(s->lChild);

	cout << s->data << " ";

	if(s->rChild != NULL)
		InOrderTravel(s->rChild);
}

//���к���FindMin: ���ҵ�ǰ������Сֵ
int	BiSortTree::FindMin()
{
	return FindMin(root); //����˽�к���,������rootΪ���ڵ��������Сֵ
}

//˽�к���FindMin: ������sΪ���ڵ��������Сֵ
int	BiSortTree::FindMin(BiNode *s)
{
	if( s == NULL )					//���Ϊ����
		return NULL;				//���ؿ�
	else if( s->lChild == NULL )	//���������Ϊ�գ���ǰֵΪ��Сֵ
		return s->data;				//���ص�ǰֵ
	else							//��������������
		return FindMin(s->lChild);	//���������������ҵ�����Сֵ��ʹ��FindMin����
}

//���к���FindMax: ���ҵ�ǰ�������ֵ
int	BiSortTree::FindMax()
{
	return FindMax(root); //����˽�к���,������rootΪ���ڵ���������ֵ
}

//˽�к���FindMax: ������sΪ���ڵ���������ֵ
int	BiSortTree::FindMax(BiNode *s)
{
	if( s == NULL )					//���Ϊ����
		return NULL;				//���ؿ�
	else if( s->rChild == NULL )	//���������Ϊ�գ���ǰֵΪ���ֵ
		return s->data;				//���ص�ǰֵ
	else							//��������������
		return FindMax(s->rChild);	//���������������ҵ������ֵ��ʹ��FindMax����
}

//���к���DeleteNode: �ӵ�ǰ����ɾ��ֵk
void BiSortTree::DeleteNode(int k)
{
	root = DeleteNode(root, k); //����˽�к���DeleteNode, ����rootΪ���ڵ������ɾ��k, ����ָ�븳��root
}

//˽�к���DeleteNode: ����sΪ���ڵ������ɾ��k, ��������ָ��
BiNode* BiSortTree::DeleteNode(BiNode *s, int k)
{
	if( s == NULL )											//���sΪ����
		return NULL;										//���ؿ�ָ��
	else if( k < s->data )									//���kС�ڵ�ǰ�ڵ�ֵ����k��������
	{
		s->lChild = DeleteNode( s->lChild, k );				//����������ɾ��k��ʹ��DeleteNode����������ָ�븳��������
	}
	else if( k > s->data )  								//���k���ڵ�ǰ�ڵ�ֵ����k��������
	{
        s->rChild = DeleteNode( s->rChild, k ); 			//����������ɾ��k��ʹ��DeleteNode����������ָ�븳��������
	}
    else													//else: k���ڵ�ǰ�ڵ�ֵ����ǰ�ڵ�Ϊɾ���ڵ�
	if( s->lChild && s->rChild )							//�����ɾ���ڵ����������ӣ���1.������ֱ��ǰ���滻����2.Ȼ��ɾ��ֱ��ǰ��
		{
			int temp = FindMax( s->lChild );				//�ҵ�ֱ��ǰ��temp��ֱ��ǰ��Ϊ�����������ֵ��ʹ��FindMax˽�к���
			s->data = temp;									//��ǰ�ڵ��滻Ϊֱ��ǰ��
			s->lChild = DeleteNode( s->lChild, temp );		//����������ɾ��ֱ��ǰ��temp��ʹ��DeleteNode����������ָ�븳��������
		}
	else													//else: ��ɾ���ڵ�ֻ��0��1������
	{
		BiNode *tempNode = s;								//���ݵ�ǰ�ڵ�ָ��

		if( s->lChild == NULL )								//���������Ϊ�գ���������Ҫô�գ�Ҫô����
			s = s->rChild;									//������������ǰ�ڵ�
		else if( s->rChild == NULL )						//else if: ���������Ϊ�գ���������Ҫô�գ�Ҫô����
			s = s->lChild;									//������������ǰ�ڵ�

		delete tempNode;									//ɾ����ǰ�ڵ�ı���tempNode
	}

	return s;												//��������
}


int main(int argc, char* argv[])
{
	int t[MAXNUM];
	int i, j, sKey,iKey, dKey;						//sKey��������ֵ�� iKey:������ֵ�� dKey����ɾ��ֵ
	int TestNo, SampleNo;

	BiSortTree *BST = new BiSortTree;

	cin >> TestNo;									// ������Դ���
	for (i=0; i<TestNo; i++) {
		cin >> SampleNo;							// ����������Ŀ
		for (j=0; j<SampleNo; j++) cin >> t[j];		// �����������ݣ���˳���		
		cin  >> sKey >> iKey >> dKey;				//���������sKey�� ������iKey�� ��ɾ��dKey

		
		//1 �����������������
		BST->CreateBST(t, SampleNo);				//�������������
		BST->InOrderTravel();						//�����������������������
		cout << "Min Value:" << BST->FindMin() << endl;	//�����ǰ������Сֵ
		cout << "Max Value:" << BST->FindMax() << endl;	//�����ǰ�������ֵ
		////////////////////////////////////////////////////////////////////////////////////////////////
	
		//2 ����sKey����
		BST->SearchBST(sKey);						//����sKey
		BST->InOrderTravel();						//���Һ�������������ע����Ҳ��ɹ�ʱ���룬��������б仯
		////////////////////////////////////////////////////////////////////////////////////////////////

		//3 ����iKey����
		BST->InsertBST(iKey);						//����iKey
		BST->InOrderTravel();						//���������������
		BST->SearchBST(iKey);						//��������iKey
		////////////////////////////////////////////////////////////////////////////////////////////////

		//4 ɾ��dKey����
		BST->DeleteNode(dKey);						//ɾ��dKey
		BST->InOrderTravel();						//ɾ��������������
		BST->SearchBST(dKey);						//ɾ�������dKey
		////////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;
}