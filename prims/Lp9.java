package prims;
import java.util.*;
public class Lp9 {
public static void main(String[] args) {
// TODO Auto-generated method stub
int cost[][]=new int[10][10];
int i,j,mincost=0;
Scanner in=new Scanner(System.in);
System.out.println("PRIMS");
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
System.out.println("the entered cost matrix is");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
System.out.print(cost[i][j]+"\t");
}
System.out.println();
}
System.out.println("MST edges and cost are ");
mincost=Prims(cost,n,mincost);
System.out.println("MST cost is");
System.out.println(+mincost);
System.out.println("----------");
}
static int Prims(int cost[][],int n,int mincost)
{
int nearV[]=new int[10],t[][]=new int[10][3],u=0,i,j,k;
for(i=2;i<=n;i++)
nearV[i]=1;
nearV[1]=0;
for(i=1;i<n;i++)
{
int min=999;
for(j=1;j<=n;j++)
{
if(nearV[j]!=0&&cost[j][nearV[j]]<min)
{
min=cost[j][nearV[j]];
u=j;
}
}
t[i][1]=u;
t[i][2]=nearV[u];
mincost+=min;
nearV[u]=0;
for(k=1;k<=n;k++)
{
if(nearV[k]!=0&&cost[k][nearV[k]]>cost[k][u])
nearV[k]=u;
}
System.out.print(i+")min edge is ("+t[i][1]);
System.out.println(","+t[i][2]+") and cost is "+min);
}
return mincost;
}
}