#include<string>


double Exchange_n(char x)						//�������ַ�ת��Ϊ��ֵ
{
	int n;
	n=x-48;
	return n;
}

void Eat(char input[])							//�Ե���һλ
{
	for(int j = 0; j < strlen(input)-1; j++)					
			input[j]=input[j+1];
	input[strlen(input)-1] = '\0';
}

int Exchange_o(char x)							//����������ַ�ת��Ϊ��ֵ�����ԱȽ����㼶��
{
	int n;
	switch(x)											
	{
	case ';':n=0;break;
	case '+':case '-': n=1;break;
	case '*':case '/': n=2;break;
	case '^': n=3;break;
	default:n=-1;										
	}
	return n;
}

double Exp(double x, double y, char e)			//�õ�һ������
{
	switch(e)
	{											//�ȵ���x���󵯳�y��������ʱy��ǰ
	case '+':return (y+x);break;
	case '-':return (y-x);break;
	case '*':return (y*x);break;
	case '/':return (y/x);break;
	case '^':return pow(y,x);break;						
	}
}