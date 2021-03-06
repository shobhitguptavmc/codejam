/* heapSort on string */

#include<stdio.h>
#include<string.h>
#include<conio.h>
#define N 20

int H[N], hn = 0;
char A[N][50];

void showHeap(int n)
{
	for(int i = 1; i<=n; i++)
		printf("%s ", A[H[i]]);
	printf("\n");
}

int comp(int i, int j)
{
	return strcmp(A[i],A[j]);
}

void adjust(int i)
{
	int p = i, c = i * 2, t = H[i];
	while(c<=hn)
	{
		if(c<hn && comp(H[c],H[c+1])>0)
			c++;
		if(comp(H[c],t)<0)
		{
			H[p] = H[c];
			p = c, c = p*2;
		}
		else
			break;
	}
	H[p] = t;
}

void heapify()
{
	for(int i = hn/2; i >0; i--)
		adjust(i);
}

void insert()
{
	H[++hn] = hn;
	int c = hn, p = hn/2, t = H[hn];
	while(c>1)
	{
		if(comp(t,H[p])<0)
		{
			H[c] = H[p];
			c = p, p = c/2;
		}
		else
			break;
	}
	H[c] = t;
}

void heapSort(void)
{
	int k = hn;
	for(int t, i = 1; i<=k; i++)
		t = H[1], H[1] = H[hn], H[hn] = t, hn--, adjust(1);
}

void main()
{
	clrscr();
	int n, i, p, k;
	scanf("%d",&n);
	for(i=1;i<=n;H[i]=i,i++)
	scanf("%s",&A[i]);
	hn = n;
	heapify();
	showHeap(n);
	scanf("%d",&p);
	for(i=1;i<=p;i++)
	{
		scanf("%s",&A[++n]);
		insert();
	}
	showHeap(n);
	heapSort();
	showHeap(n);
}