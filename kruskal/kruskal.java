package kruskal;
import java.util.*;
public class kruskal{
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int cost[][]=new int[10][10];
		int i,j,mincost=0;
		Scanner in=new Scanner(System.in);
		System.out.println("kruskal's");
		System.out.println("enter no. of nodes");
		int n=in.nextInt();
		System.out.println("enter cost matrix");
		for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
		{
			cost[i][j]=in.nextInt();
		}
	}
		System.out.println("The entered cost matrix is");
		for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
		{
		System.out.print(cost[i][j]+"\t");
		}
		System.out.println();
		}
		System.out.println("The MST edges and costs are");
		mincost=Kruskal(cost,n,mincost);
		System.out.println("The MST cost is");
		System.out.println(mincost);
		}
		static int Kruskal(int cost[][],int n,int mincost)
		{
		int ne=1,min;
		int a=0,b=0,u=0,v=0;
		int parent[]=new int[10];
		while(ne<n)
		{
		min=999;
		for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)
		{
		if(cost[i][j]<min)
		{
		min=cost[i][j];
		a=u=i;
		b=v=j;
		}
		}
		}
		u=find(u,parent);
		v=find(v,parent);
		if(union(u,v,parent)!=0)
		{
		System.out.print((ne++)+") min edge is ");
		System.out.println("("+a+","+b+") and cost is "+min);
		mincost+=min;
		parent[v]=u;
		}
		cost[a][b]=cost[b][a]=999;
		}
		return mincost;
		}
		static int find(int i,int parent[])
		{
		while(parent[i]!=0)
		i=parent[i];
		return i;
		}
		static int union(int i,int j,int parent[])
		{
		if(i!=j)
		{
		parent[j]=i;
		return 1;
		}
		else
		return 0;
		}
		}
		
