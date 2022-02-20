struct node //定义带表头的链表
{
	double number;//操作数
	char operate;//运算符号
	struct node *next;
};
double Calculate(node *head);