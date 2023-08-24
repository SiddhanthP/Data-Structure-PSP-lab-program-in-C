/*2A.Sort a given set of n integer elements using Quick Sort method and compute its time complexity. 
 * Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph of the time taken versus non graph sheet. 
 * The elements can be read from a file or can be generated using the random number generator. 
 * Demonstrate using Java how the divide and-conquer method works along with its time complexity analysis: worst case, average case and best case.*/
package QUICKSORT;
import java.util.*;
public class QUICKSORT {
    public static void main(String[] args) {
    	QUICKSORT Lab = new QUICKSORT();
        int a[] = new int[1000000];
        try (Scanner in = new Scanner(System.in)) {
			long start, end;
			System.out.println("QuickSort");
			System.out.println("enter no. of elements");
			int n = in.nextInt();
			for (int i = 0; i < n; i++) {
			    a[i] = Lab.generateRandom(a, 1000000);
			}
			System.out.println("elements to be sorted are");
			for (int i = 0; i < n; i++) {
			    System.out.print(a[i] + " ");
			}
			System.out.println();
			start = System.nanoTime();
			quicksort(a, 0, n - 1);
			end = System.nanoTime();
			System.out.println("the sorted elements are");
			for (int i = 0; i < n; i++) {
			    System.out.print(a[i] + " ");
			}
			System.out.println();
			System.out.println("time taken is" + "\t" + (end - start) + "ns");
		}
        System.out.println("--------");
    }

    static void quicksort(int a[], int p, int q) {
        int j;
        if (p < q) {
            j = partition(a, p, q);
            quicksort(a, p, j - 1);
            quicksort(a, j + 1, q);
        }
    }

    static int partition(int a[], int m, int p) {
        int v, i, j;
        v = a[m];
        i = m;
        j = p;
        while (i < j) {
            while (a[i] <= v)
                i++;
            while (a[j] > v)
                j--;
            if (i < j)
                interchange(a, i, j);
        }
        a[m] = a[j];
        a[j] = v;
        return j;
    }

    static void interchange(int a[], int i, int j) {
        int p;
        p = a[i];
        a[i] = a[j];
        a[j] = p;
    }

    public int generateRandom(int a[], int bound) {
        Random r = new Random();
        int offset = r.nextInt(bound);
        while (alreadyThere(a, offset))
            offset = r.nextInt(bound);
        return offset;
    }

    private boolean alreadyThere(int arr[], int e) {
        for (int i = 0; i < arr.length; i++) {
            if (e == arr[i])
                return true;
        }
        return false;
    }
}