#include<iostream>
#include<cmath>
#include<stack>
#include"base.h"
#include"calculate.h"
using namespace std;

int SearchFlag(node *head, node **pp, node **qq);//搜索链表，看是否含有括号，若有括号，直接得出最内括号位置

double Calculate(node *head)
{
	node *p = head -> next;
	node *q =p;
	node *(*pp) =&p;
	node *(*qq) =&q;
	//先处理括号
	while(SearchFlag(head, pp, qq) == 1)//此时p和q已经锁定了最内括号，其中q指向'('结点的前驱，p
	{
		node *h, *newnode, *t;
		p -> operate = ';';
		t = p;
		t = t -> next;
		p -> next = NULL;
		h = q -> next;//'('的结点相当于头结点
		p = p -> next;
		newnode = new node;
		newnode -> number = Calculate(h);
		newnode -> operate = '0';
		q -> next = newnode;
		newnode -> next = t;
	}



	stack<double> NS;//操作数组成的栈
	stack<char> OS;//运算符号组成的栈
	OS.push(';');//把分号压在最下面
	int t = 0;//t=0时扫描下一个结点
	double x,y,answer,m;
	char e;
	p = head;
	while(t != 2)
	{
		if(t == 0)//p指向下一个结点
		{
			p = p -> next;
		}

		if(p -> operate == '0')//如果结点中存有数值
		{
			NS.push(p -> number);
		}
		else if(p -> operate != '0')//如果结点中存储的是符号
		{
			char w = p -> operate;
			if(w == '+'||w == '-'||w == '*'||w == '/'||w == '^'||w == ';')
			{
				char s = OS.top();
				if(Exchange_o(w) > Exchange_o(s))		//以决定入栈还是运算
				{                                   //若新符号优先，则入栈，继续读取下一位字符
					OS.push(w);
					t = 0;
				}
				else if(s == ';'&&w == ';')			//若新符号为分号，此时处理结束，得到最终结果,并退出循环
				{
					answer = NS.top();
					NS.pop();
					return answer;
					t = 2;
				}
				else								//若旧符号优先或平权，则进行旧符号运算，并将结果压入NS栈
				{
					x = NS.top();
					NS.pop();
 					y = NS.top();
					NS.pop();
					e = OS.top();
					OS.pop();
					m = Exp(x,y,e);					//构成运算
					NS.push(m);
					t = 1;							//继续处理之后的字符
				}
			}
		}
	}

}

int SearchFlag(node *head, node **pp, node **qq)//搜索链表，看是否含有括号，若有括号，直接得出最内括号位置
{
	int flag;
	node *p, *q;
	p = head -> next;
	q = head;
	while(p -> operate != ')'&&p -> next != NULL)
	{
		if(p -> operate == '(')
		{
			while(q -> next != p)		//q应指向'('结点的前驱
			{
				q =q -> next;
			}
		}
		p = p -> next;
	}
	if(p -> next == NULL&&head == q)
		flag = 0;
	else 
		flag = 1;
	
	*pp =p;
	*qq =q;
	return flag;
}

