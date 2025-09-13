import java.util.*;
public class FrequencyString 
{
  public static void main(String[] args) {
    String str1;
    int i,len,j;
    @SuppressWarnings("resource")
    Scanner s=new Scanner(System.in);
    System.out.println("Enter string:");
    str1=s.nextLine();
    len=str1.length();


    int freq[]=new int[len];
    for(i=0;i<len;i++)
      {
        freq[i]=-1;
      }
    for(i=0;i<len;i++)
    { 
      int count=1;
      for(j=i+1;j<len;j++)
      {
        if(str1.charAt(i)==(str1.charAt(j)))
        {
           count++;
           freq[j]=0;
        }
      }

      if(freq[i]!=0)
        freq[i]=count;
    }
    for(i=0;i<len;i++)
      {
        if(freq[i]!=0)
        System.out.println(str1.charAt(i)+" is "+freq[i]+" times");
      }

    s.close();
  }
}
