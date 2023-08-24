package FloydAlgorithm;
import java.util.*;
public class Lp10A {
public static void main(String[ ] args) {
// TODO Auto-generated method stub
int a[ ][ ]=new int[10][10];
int i,j;
Scanner in=new Scanner(System.in);
System.out.println("Floyd's");
System.out.println("enter no. of nodes");
int n=in.nextInt();
System.out.println("Enter the adjacency matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
a[i][j]=in.nextInt();
}
}
System.out.println("The entered adjacency matrix is");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
	System.out.print(a[i][j]+"\t");
	}
	System.out.println();
	}
	Floyd(a,n);
	System.out.println("All pair shortest path matrix");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
	System.out.print(a[i][j]+"\t");
	}
	System.out.println();
	}
	}
	static void Floyd(int a[][],int n)
	{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
	a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
	}
	}
	}
	static int min(int a,int b)
	{
	if(a>b)
	return b;
	else
	return a;
	}
	}