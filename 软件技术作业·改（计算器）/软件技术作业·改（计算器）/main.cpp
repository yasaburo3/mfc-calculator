#include<iostream>
#include<cmath>
#include<cstring>
#include"calculate.h"
#include"base.h"

using namespace std;

#define N 100

node *Change(char input[]);
/*---------------------------------------------------------------
							主函数
---------------------------------------------------------------*/

int main()
{
	double ans;	//表示最终结果
	char input[N];
	node *head;
	cin>>input;
	head = Change(input);//创建链表，并将input数组转化为链表，数值和运算符号分别存在不同的数据域
	ans = Calculate(head);
	cout<<ans;
	system("pause");
	return 0;

}



node *Change(char input[])//创建链表，并将input数组转化为链表，数值和运算符号分别存在不同的数据域
{
	node *head, *tail, *newnode;
	head = new node;//创建伪表头
	tail = head;
	int negative_flag = 0;
	if(input[0] == '-')//先判断首位符号的情况，若是负号则记录，最后吃掉符号
	{
		negative_flag = 1;
		Eat(input);//吃掉下一位
	}
	else if(input[0] == '+')
	{
		negative_flag = 0;
		Eat(input);
	}

	for(int i = 0; input[i] != '\0'; )
	{
		if(input[i] >= '0'&&input[i] <= '9')//把操作数存入结点
		{
			char w;
			double r = 0;				//r用来存储操作数，可能有很多位，需要判断
			int dot_flag = 0;					//用来判断有无小数点，需要在循环外定义
			int dot_num = 0;						//用来计小数位
			while(input[0] >= '0'&&input[0] <= '9'||input[0] == '.')
			{		
				if(input[0] >= '0'&&input[0] <= '9'&&dot_flag == 0)//处理小数点前的数位
				{
					w = input[0];					//再读一位，作为个位
					Eat(input);
					r = r*10+Exchange_n(w);
				}
				else if(input[0] == '.')
				{
					w = input[0];				
					Eat(input);					//吃掉小数点
					dot_flag = 1;
					dot_num = 1;
				}
				else if(input[0] >= '0'&&input[0] <= '9'&&dot_flag == 1)//处理小数点后面的数位
				{
					w = input[0];
					r = r+Exchange_n(w)*pow(0.1, dot_num);
					dot_num++;
					Eat(input);
				}
			}

			if(negative_flag == 1)				//有负号时取反
			{
				r = -r;
				negative_flag = 0;
			}
								//如果下一位是运算符，将r存入结点
			newnode = new node;
			newnode -> number = r;
			newnode -> operate = '0';//这样一来operate域里如果是0，就说明这个节点中存储的是数值
			tail -> next = newnode;
			tail = newnode;
		}

		else //如果是运算符号，将其存入结点
		{
			newnode = new node;
			newnode -> operate = input[0];
			tail -> next = newnode;
			tail = newnode;
			Eat(input);
		}
	}

	//在最后加上分号，这样用户就不需要输入分号了
	newnode = new node;
	newnode -> operate = ';';
	tail ->next = newnode;
	tail = newnode;

	tail -> next =NULL;
	return head;
}