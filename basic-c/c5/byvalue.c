#include <stdio.h>
int global = 20;

void func(int a)//形参也是局部变量，调用时分配空间，返回时释放
{
	p rintf("in func,%p: a=%d\n", &a, a);
	a += 5;
	printf("in func,%p: a=%d\n", &a, a);
}
int get()
{
	return global;
}
int main()
{
	int a=10;
	printf("in main,%p: a=%d\n", &a, a);
	func(a);
	printf("in main,%p: a=%d\n", &a, a);
	int b = get();
	b *= 5;
	printf("global=%d, b=%d\n", global, b);
	int c = a;
	return 0;
}
