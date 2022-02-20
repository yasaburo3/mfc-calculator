#include<iostream>
#include<cmath>
#include<cstring>
#include"calculate.h"
#include"base.h"

using namespace std;

#define N 100

node *Change(char input[]);
/*---------------------------------------------------------------
							������
---------------------------------------------------------------*/

int main()
{
	double ans;	//��ʾ���ս��
	char input[N];
	node *head;
	cin>>input;
	head = Change(input);//������������input����ת��Ϊ������ֵ��������ŷֱ���ڲ�ͬ��������
	ans = Calculate(head);
	cout<<ans;
	system("pause");
	return 0;

}



node *Change(char input[])//������������input����ת��Ϊ������ֵ��������ŷֱ���ڲ�ͬ��������
{
	node *head, *tail, *newnode;
	head = new node;//����α��ͷ
	tail = head;
	int negative_flag = 0;
	if(input[0] == '-')//���ж���λ���ŵ���������Ǹ������¼�����Ե�����
	{
		negative_flag = 1;
		Eat(input);//�Ե���һλ
	}
	else if(input[0] == '+')
	{
		negative_flag = 0;
		Eat(input);
	}

	for(int i = 0; input[i] != '\0'; )
	{
		if(input[i] >= '0'&&input[i] <= '9')//�Ѳ�����������
		{
			char w;
			double r = 0;				//r�����洢�������������кܶ�λ����Ҫ�ж�
			int dot_flag = 0;					//�����ж�����С���㣬��Ҫ��ѭ���ⶨ��
			int dot_num = 0;						//������С��λ
			while(input[0] >= '0'&&input[0] <= '9'||input[0] == '.')
			{		
				if(input[0] >= '0'&&input[0] <= '9'&&dot_flag == 0)//����С����ǰ����λ
				{
					w = input[0];					//�ٶ�һλ����Ϊ��λ
					Eat(input);
					r = r*10+Exchange_n(w);
				}
				else if(input[0] == '.')
				{
					w = input[0];				
					Eat(input);					//�Ե�С����
					dot_flag = 1;
					dot_num = 1;
				}
				else if(input[0] >= '0'&&input[0] <= '9'&&dot_flag == 1)//����С����������λ
				{
					w = input[0];
					r = r+Exchange_n(w)*pow(0.1, dot_num);
					dot_num++;
					Eat(input);
				}
			}

			if(negative_flag == 1)				//�и���ʱȡ��
			{
				r = -r;
				negative_flag = 0;
			}
								//�����һλ�����������r������
			newnode = new node;
			newnode -> number = r;
			newnode -> operate = '0';//����һ��operate���������0����˵������ڵ��д洢������ֵ
			tail -> next = newnode;
			tail = newnode;
		}

		else //�����������ţ����������
		{
			newnode = new node;
			newnode -> operate = input[0];
			tail -> next = newnode;
			tail = newnode;
			Eat(input);
		}
	}

	//�������Ϸֺţ������û��Ͳ���Ҫ����ֺ���
	newnode = new node;
	newnode -> operate = ';';
	tail ->next = newnode;
	tail = newnode;

	tail -> next =NULL;
	return head;
}