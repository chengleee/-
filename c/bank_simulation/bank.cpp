#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int status;
typedef struct
{
	int n;			//客户序号
	int queue_num;		//客户所在队列号
	int arrivetime;		//客户到达时间	
	int staytime;		//客户停留时间
}guestdata;			//客户数据

typedef struct
{
	guestdata *front;
	guestdata *rear;
	int length;		//队列长度
}line;				//定义队列

typedef struct LNode
{
	guestdata data;
	struct LNode *next;
}Link;

typedef struct
{
	Link *head;
	Link *tail;
	int l;			//客户总数
}alldata; 			//客户信息汇总

status init_alldata(alldata &s)		//初始化总数据链表
{
	s.head=(Link *)malloc(sizeof(Link));
	if(!s.head)
		    exit(OVERFLOW);
	    s.tail=s.head->next=NULL;
	s.l=0;
	return OK;
}

status init_line(line (&l)[4])		//初始化队列
{
	int i;
	for(i=0;i<=4;i++)
	{
		l[i].front=(guestdata *)malloc(sizeof(guestdata));
		if(!l[i].front)
			exit(OVERFLOW);
		l[i].rear=l[i].front;
		l[i].length=0;
	}
	return OK;
}

status insert_alldata(alldata &s,guestdata &e)	//插入总数据表
{
	Link *p;
	p=(Link *)malloc(sizeof(Link));
	if(!p)
		exit(OVERFLOW);
	p->data=e;
	p->next=s.head->next;
	s.head->next=p;
	return OK;
}

status comparelength(line l[4])		//比较当前队列长度
{
	if(l[0].length<=l[1].length&&l[0].length<=l[2].length&&l[0].length<=l[3].length)
		return 0;
	if(l[1].length<l[0].length&&l[1].length<=l[2].length&&l[1].length<=l[3].length)
		return 1;
	if(l[2].length<l[0].length&&l[2].length<l[1].length&&l[2].length<=l[3].length)
		return 2;
	else
		return 3;
}

status insert_line(line (&l)[4],guestdata e)		//插入队列
{
	l[e.queue_num].length++;
	*(++l[e.queue_num].rear)=e;
	return OK;
}

status leave_line(line &l,guestdata &e)	//离开队列	
{
	guestdata *a;
	if(l.rear==l.front)
		return 0;
	e=*(l.front+1);
	a=l.front+1;
	free(l.front);
	l.front=a;
	return OK;
}

void print(alldata s)
{
	Link *q;
	q=s.head->next;
	while(q!=s.tail)
	{
		printf("序号:%d 所在窗口:%d 到达时间:%d 停留时间:%d\n",q->data.n,q->data.queue_num+1,q->data.arrivetime,q->data.staytime);
		q=q->next;
	}
}

status bank_simulation()
{
	int sum=0;
	float average;
	alldata ad;
	line l[4];
	guestdata e;
	init_alldata(ad);
	init_line(l);
	e.n=1;
	e.queue_num=comparelength(l);
	e.arrivetime=rand()%6;
	e.staytime=rand()%31;
	sum=e.staytime;
	insert_alldata(ad,e);
	insert_line(l,e);
	while(e.arrivetime<=400)
	{
		e.n++;
		e.queue_num=comparelength(l);
		e.arrivetime+=rand()%6;
		e.staytime=rand()%31;
		insert_alldata(ad,e);
		insert_line(l,e);
		sum+=e.staytime;
	}
	average=sum*1.0/e.n;
	ad.l=e.n;
	print(ad);
	printf("客流量:%d 客户平均仪时间:%f\n",ad.l,average);
	return OK;
}

int main()
{
	bank_simulation();
}
