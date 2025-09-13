import java.util.*;
public class Pallindrome 
{
  public static void main(String[] args) 
  {
    String str1,str2="";
    Scanner s=new Scanner(System.in);
    System.out.println("Enter string:");
    str1=s.nextLine();
    int len=str1.length();
    for(int i=0;i<len;i++)
    {
      str2+=str1.charAt(len-i-1);
    }
    System.out.println("Reverse: "+str2);
    if(str1.equals(str2))
    System.out.println("Pallindrome");
    else
    System.out.println("Not pallindrome");
    s.close();
  }
  
}
