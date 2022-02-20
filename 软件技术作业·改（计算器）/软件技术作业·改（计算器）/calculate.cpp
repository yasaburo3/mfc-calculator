#include<iostream>
#include<cmath>
#include<stack>
#include"base.h"
#include"calculate.h"
using namespace std;

int SearchFlag(node *head, node **pp, node **qq);//�����������Ƿ������ţ��������ţ�ֱ�ӵó���������λ��

double Calculate(node *head)
{
	node *p = head -> next;
	node *q =p;
	node *(*pp) =&p;
	node *(*qq) =&q;
	//�ȴ�������
	while(SearchFlag(head, pp, qq) == 1)//��ʱp��q�Ѿ��������������ţ�����qָ��'('����ǰ����p
	{
		node *h, *newnode, *t;
		p -> operate = ';';
		t = p;
		t = t -> next;
		p -> next = NULL;
		h = q -> next;//'('�Ľ���൱��ͷ���
		p = p -> next;
		newnode = new node;
		newnode -> number = Calculate(h);
		newnode -> operate = '0';
		q -> next = newnode;
		newnode -> next = t;
	}



	stack<double> NS;//��������ɵ�ջ
	stack<char> OS;//���������ɵ�ջ
	OS.push(';');//�ѷֺ�ѹ��������
	int t = 0;//t=0ʱɨ����һ�����
	double x,y,answer,m;
	char e;
	p = head;
	while(t != 2)
	{
		if(t == 0)//pָ����һ�����
		{
			p = p -> next;
		}

		if(p -> operate == '0')//�������д�����ֵ
		{
			NS.push(p -> number);
		}
		else if(p -> operate != '0')//�������д洢���Ƿ���
		{
			char w = p -> operate;
			if(w == '+'||w == '-'||w == '*'||w == '/'||w == '^'||w == ';')
			{
				char s = OS.top();
				if(Exchange_o(w) > Exchange_o(s))		//�Ծ�����ջ��������
				{                                   //���·������ȣ�����ջ��������ȡ��һλ�ַ�
					OS.push(w);
					t = 0;
				}
				else if(s == ';'&&w == ';')			//���·���Ϊ�ֺţ���ʱ����������õ����ս��,���˳�ѭ��
				{
					answer = NS.top();
					NS.pop();
					return answer;
					t = 2;
				}
				else								//���ɷ������Ȼ�ƽȨ������оɷ������㣬�������ѹ��NSջ
				{
					x = NS.top();
					NS.pop();
 					y = NS.top();
					NS.pop();
					e = OS.top();
					OS.pop();
					m = Exp(x,y,e);					//��������
					NS.push(m);
					t = 1;							//��������֮����ַ�
				}
			}
		}
	}

}

int SearchFlag(node *head, node **pp, node **qq)//�����������Ƿ������ţ��������ţ�ֱ�ӵó���������λ��
{
	int flag;
	node *p, *q;
	p = head -> next;
	q = head;
	while(p -> operate != ')'&&p -> next != NULL)
	{
		if(p -> operate == '(')
		{
			while(q -> next != p)		//qӦָ��'('����ǰ��
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

