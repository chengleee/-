/******线性表的动态分配顺序存储结构******/
#define LIST_INIT_SIZE 100		//线性表存储空间的初始分配量
#define LISTINCREMENT 10		//线性表存储空间的分配增量
typedef struct
{
	Elemtype *elem;		//存储空间基址
	int length;			//当前长度
	int listsize;		//当前分配的存储容量
}SqList;

/******线性表的单链表存储结构******/
typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

/******线性表的静态单链表存储结构******/
#define MAXSIZE 1000
typedef struct
{
	Elemtype data;
	int cur;
}SLinkList[MAXSIZE],component;

/******线性表的双向链表存储结构******/
typedef struct DuLNode
{
	Elemtype data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

/******带头结点的线性链表类型定义******/
typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}*Link,*Position;
typedef struct
{
	Link head,tail;
	int len;		//指示线性链表中数据元素的个数
}LinkList;

/******栈的顺序表示******/
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct
{
	Elemtype *base;
	Elemtype *top;
	int stacksize;
}SqStack;

/******单链队列******/
typedef struct QNode
{
	QElemtype data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/******循环队列******/
#define MAXSIZE 100
typedef struct
{
	QElemtype *base;
	int front;
	int rear;
}SqQueue;

/******串的定长顺序存储表示******/
#define MAXSIZE 255
typedef struct char SString[MAXSIZE+1];

/******串的堆分配存储表示******/
typedef struct
{
	char *ch;
	int length;
}HString;

/******串的块链存储表示******/
#define CHUNKSIZE 80
typedef struct Chunk		//chunk ：厚块
{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;
typedef struct 
{
	Chunk *head,*tail;
	int curlen;
}LString;

/******数组的顺序存储表示******/
#include <stdarg.h>			//标准头文件，提供宏va_start、va_arg、va_end,用于存取变长参数表
#define MAX_ARRAR_DIM 8		//假设数组维数的最大值为8
typedef struct
{
	Elemtype *base;			//数组元素基址
	int dim;				//数组维数
	int *bounds;			//数组维界基址
	int *constants;			//数组映像函数常量基址
}Array;						//数组类型

/******稀疏矩阵的三元组顺序表示******/
#define MAXSIZE 12500		//假设非零元素个数的最大值为12500
typedef struct
{
	int i,j;		//该非零无的行下标和列下标
	Elemtype e;
}Triple;			//三元组
typedef struct
{
	Triple data[MAXSIZE+1];		//非零元三元组表，data[0]未用
	int mu,nu,tu;			//矩阵的行数、列数和非零元个数
}TSMatrix;			//稀疏矩阵类型(sparse matrix)

/******带行逻辑链接的顺序表******/
typedef struct
{
	Triple data[MAXSIZE+1];		//非零元三元组表
	int rpos[MAXRC+1];			//各行第一个非零元的位置表
	int mu,nu,tu;				//矩阵的行数、列数、和非零元个数
}TLSMatrix;

/******稀疏矩阵的十字链表******/
typedef struct OLNode
{
	int i,j;		//该非零元素下标
	Elemtype e;
	struct OLNode *right,*domn;		//后继链域
}OLNode,*OLink;
typedef struct
{
	OLink *rhead,*chead;	//行和列表头指针
	int mu,nu,tu;		//稀疏矩阵的行数、列数、非零元素个数
}CrossList;

/******广义表的头尾链表存储表示******/
typedef enum {ATOM,LIST}ElemTag;	//ATOM=0:原子;LIST=1：子表
typedef struct GLNode
{
	ElemTag tag;		//公共部分，用于区分原子结点和表结点
	union
	{
		AtomType atom;		//atom是原子结点的值域，AtomType由用户定义
		struct				
		{
			struct GLNode *hp,*tp;
		}ptr;				//ptr是表结点的指针域，ptr.hp和ptr.tp分别指向表头和表尾
	};
}*GList;

/******广义表的扩展线性链表存储表示******/
typedef enum {ATOM,LIST}ElemTag; //ATOM==0:原子；LIST==1：子表
typedef struct GLNode
{
	ElemTag tag;		//公共部分，用于区分原子结点和表结点
	union
	{
		AtomType atom;		//原子结点的值域
		struct GLNode *hp;	//表结点的表头指针
	};
	struct GLNode *tp;		//相当于线性链表的next，指向下一个元素结点
}*GList;

/******二叉树的顺序存储表示******/
//只适用于完全二叉树
#define MAX_TREE_SIZE 100					//二叉树的最大结点数
typedef TElemType SqBiTree[MAX_TREE_SIZE];	//0号单元存储根结点
SqBiTree bt;	

/******二叉树的二叉链表存储表示******/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,rchile;			//左右孩子指针
}BiTNode,*BiTree;

/******二叉树的二叉线索存储表示******/
typedef enum PointerTag{Link,Thread};		//Link==0:指针,Thread==1：线索
typedef struct BiThreeNode
{
	TElemType data;
	struct BiThreeNode *lchild,*rchild;
	PointerTag LTag,RTag;					//左右标志
}BiThreNode,*BiThrTree;


/******树的双亲表存储表示******/
#define MAX_TREE_SIZE 100
typedef struct PTNode
{
	TElemType data;
	int parent;		//双亲位置域
}PTNode;
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;		//根的位置和结点数
}PTree;


/******树的孩子链表存储表示******/
typedef struct CTNode
{
	int child;
	struct CTNode *next;
}*ChildPtr;
typedef struct 
{
	TElemType data;
	ChildPtr firstchild;	//孩子链表头指针
}CTBox;
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n,r;	//结点数和根的位置
}CTree;

/*******树的二叉链表存储方式******/
typedef struct CSNode
{
	ElemType data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;