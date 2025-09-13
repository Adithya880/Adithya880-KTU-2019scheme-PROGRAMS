import java.util.*;
public class Frequency 
{
    public static void main(String[] args) 
    {
      @SuppressWarnings("resource")
      Scanner s=new Scanner(System.in);
      int i,n,j;
      System.out.println("Enter size:");
      n=s.nextInt();
      int a[]=new int[n];
      int freq[]=new int[n];
      System.out.println("Enter array:");
      for(i=0;i<n;i++)
      {
        a[i]=s.nextInt();
        freq[i]=-1;
      }
      System.out.println("Array:");
      for(i=0;i<n;i++)
      {
        System.out.print(a[i]+" ");
      }
      for(i=0;i<n;i++)
      { 
         int count=1; 
        for(j=i+1;j<n;j++)
        {
          if(a[i]==a[j])
          {
            count++;
            freq[j]=0;//mark as visited
          }
        }

        if(freq[i]!=0)
          freq[i]=count;

      }
      System.out.println("");
      for(i=0;i<n;i++)
      {
        if(freq[i]!=0)
        System.out.println(a[i]+" is "+freq[i]+" times");
      }
      
      s.close();
    }
}
