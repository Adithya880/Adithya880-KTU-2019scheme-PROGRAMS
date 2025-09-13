import java.util.Scanner;
import java.util.StringTokenizer;

public class Stringtkn 
{
  public static void main(String[] args) 
  {
    String input;
    int sum=0;
    Scanner s=new Scanner(System.in);
    System.out.println("Enter a line of integers separated by spaces:");
    input=s.nextLine();
    StringTokenizer st=new StringTokenizer(input);
    System.out.println("Integers:");
    while(st.hasMoreTokens())
    {
      int num=Integer.parseInt(st.nextToken());
      System.out.println(num);

      sum+=num;
    }
    System.out.println("Sum: "+sum);
    s.close();
  }
}
