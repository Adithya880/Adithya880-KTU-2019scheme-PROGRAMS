import java.util.*;
public class BinSearch 
{
   public static void main(String[]args)
   {
      @SuppressWarnings("resource")
      Scanner s=new Scanner(System.in);
      int mid,low,high,i;
      System.out.println("Enter size:");
      int n=s.nextInt();
      int a[]=new int[n];
      System.out.println("Enter the sorted array:");
      for(i=0;i<n;i++)
      {
        a[i]=s.nextInt();
      }
      System.out.println("Enter key:");
      int key=s.nextInt();
      low=0;
      high=n-1;
      mid=0;
      while(low<=high)
      {
        mid=(low+high)/2;

        if(a[mid]==key)
         {
          System.out.println("Element found");
          break;
         } 
        else if(a[mid]>key)
          high=mid-1;
        else
          low=mid+1;
        
      }

      if(a[mid]!=key)
       System.out.println("Element not found");
    s.close();
   }
  
}
