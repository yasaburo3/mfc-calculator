#include<string>


double Exchange_n(char x)						//将数字字符转化为数值
{
	int n;
	n=x-48;
	return n;
}

void Eat(char input[])							//吃掉下一位
{
	for(int j = 0; j < strlen(input)-1; j++)					
			input[j]=input[j+1];
	input[strlen(input)-1] = '\0';
}

int Exchange_o(char x)							//将运算符号字符转换为数值，用以比较运算级别
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

double Exp(double x, double y, char e)			//得到一个运算
{
	switch(e)
	{											//先弹出x，后弹出y，则运算时y在前
	case '+':return (y+x);break;
	case '-':return (y-x);break;
	case '*':return (y*x);break;
	case '/':return (y/x);break;
	case '^':return pow(y,x);break;						
	}
}