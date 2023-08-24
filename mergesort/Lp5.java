package mergesort;
import java.util.Random;
import java.util.Scanner;
public class Lp5 {
public static void main(String[] args) {
// TODO Auto-generated method stub
Lp5 Lab=new Lp5();
int a[]=new int[100000];
Scanner in=new Scanner(System.in);
long start,end;
System.out.println("MergeSort");
System.out.println("enter no. of elements");
int n=in.nextInt();
for(int i=0;i<n;i++)
{
a[i]=Lab.generateRandom(a,10000);
}
System.out.println("elements to be sorted are");
for(int i=0;i<n;i++)
{
System.out.print(a[i]+" ");
}
System.out.println();
start=System.nanoTime();
mergesort(a,0,n-1);
end=System.nanoTime();
System.out.println("the sorted elements are");
for(int i=0;i<n;i++)
{
System.out.print(a[i]+" ");
}
System.out.println();
System.out.println("time taken is"+"\t"+(end-start)+"ns");
System.out.println("--------");
}
static void mergesort(int a[],int l,int h)
{
int m;
if(l<h)
{
m=(l+h)/2;
mergesort(a,l,m);
mergesort(a,m+1,h);
merge(a,l,m,h);
}
}
static void merge(int a[],int low,int mid,int high)
{
int j,i,h,k;
int b[]=new int[100000];
h=low;
i=low;
j=mid+1;
while((h<=mid)&&(j<=high))
{
if(a[h]<a[j])
{
b[i]=a[h];
h=h+1;
}
else
{
b[i]=a[j];
j=j+1;
}
i=i+1;
}
if(h>mid)
{
for(k=j;k<=high;k++)
{
b[i]=a[k];
i++;
}
}
else
{
for(k=h;k<=mid;k++)
{
b[i]=a[k];
i++;
}
}
for(k=low;k<=high;k++)
{
a[k]=b[k];
}
}
public int generateRandom(int a[],int bound)
{
	Random r=new Random();
	int offset=r.nextInt(bound);
	while(alreadyThere(a,offset))
	offset=r.nextInt(bound);
	return offset;
	}
	private boolean alreadyThere(int arr[],int e)
	{
	for(int i=0;i<arr.length;i++)
	{
	if(e==arr[i])
	return true;
	}
	return false;
	}
	}