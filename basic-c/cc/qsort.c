//������ݸ���������1����ֱ�����
//���������Ԫ�أ���ֱ�ӱȽ��������
//ȡλ�þ��е�Ԫ����Ϊ�ֽ�ֵ��
//��������һ��Ԫ�ؽ���
//��������ָ��L��R�ֱ�ָ��ڶ��������һ��Ԫ��
//������ֻҪL��R������
//	���������ұȷֽ�ֵ��С������
//	���������ұȷֽ�ֵС������
//	���û�������ͽ�������������
//�ѷֽ�ֵ����һ��Ԫ�أ������������ҵ����Ǹ����ݽ���
//�������������������
#define swap(a,b) {int t=a;a=b;b=t;}
void sort(int* a, int n)
{
	if(n<=1) return;
	if(n==2){
		if(a[0]>a[1])
			swap(a[0],a[1]);
		return;
	}
	swap(a[0],a[n/2]);
	register int pivot=a[0];
	int* L=a+1;
	int* R=a+n-1;
	while(L<R){
		while(L<R&&*L<pivot) ++L;
		while(a<R&&*R>=pivot) --R;
		if(L<R)
			swap(*L,*R);
	}
	if(*R<*a)
		swap(*a,*R);
	sort(a,R-a);
	sort(R+1,n-1-(R-a));
}