package selectionsort;
import java.util.Random;
import java.util.*;
public class selectionsort 
{
	void sort(int arr[],int n)
    {
    	for(int i=0;i<n-1;i++)
    	{
    		int min=i;
    		for(int j=i+1;j<n;j++)
    		if(arr[j]<arr[min])
    			min=j;
    		int temp=arr[min];
    		arr[min]=arr[i];
    		arr[i]=temp;
    	}
    }
    void print_Array(int arr[],int n)
    {
    	for(int i=0;i<n;i++)
    		System.out.println(arr[i]+" ");
    	System.out.println();
    }

public static void main(String[]args)
{
	int arr[]=new int[1000];
			long start,end;
      		selectionsort ob=new selectionsort();
			Scanner inp= new Scanner(System.in);
			Random r=new Random();
			System.out.println("Enter no of elements");
			int n=inp.nextInt();
			inp.close();
			for(int i=0;i<n;i++)
			{
				arr[i]=r.nextInt(1000);
			}
				System.out.println("Unsortrd array");
				ob.print_Array(arr,n);
		    	start=System.nanoTime();
				ob.sort(arr,n);
				end=System.nanoTime();
				System.out.println("Sorted array ");
				ob.print_Array(arr,n);
				System.out.println("Time taken is"+"\t"+(end-start)+"ns");
			
}
}
