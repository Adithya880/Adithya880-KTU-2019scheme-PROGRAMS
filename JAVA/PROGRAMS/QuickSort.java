import java.util.*;
class Sorting
{

  void swap(int a[],int x, int y) 
  {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
 }

  int partition(int a[], int lb, int ub) 
  {
    int pivot = a[lb];
    int down = lb + 1;
    int up = ub;

    while (down <= up) {
        while (down <= up && a[down] <= pivot) 
        {
            down++;
        }
        while (down <= up && a[up] > pivot) 
        {
            up--;
        }
        if (down < up) 
        {
            swap(a,down,up);
        }
    }
    swap(a,lb,up);
    return up;
}

void quicksort(int a[], int lb, int ub) 
{
    if (lb < ub) 
    {
        int pi = partition(a, lb, ub);
        quicksort(a, lb, pi - 1);
        quicksort(a, pi + 1, ub);
    }
}
}

public class QuickSort 
{ 
  public static void main(String[]args)
  {
    int i;
    @SuppressWarnings("resource")
    Scanner s=new Scanner(System.in);
    System.out.println("Enter size:");
    int n=s.nextInt();
    int a[]=new int[n];
    System.out.println("Enter the array:");
    for(i=0;i<n;i++)
    {
      a[i]=s.nextInt();
    }
    Sorting qs=new Sorting();
    qs.quicksort(a,0,n-1);

    System.out.println("The sorted array:");
    for(i=0;i<n;i++)
    {
      System.out.print(a[i]);
      System.out.print("\t");
    }
    System.out.println();
    s.close();
  }
  
}
