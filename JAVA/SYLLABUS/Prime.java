import java.util.*;

public class Prime {
  public static void main(String[] args) {
    int n,flag=0;
    Scanner s=new Scanner(System.in);
    n=s.nextInt();
    for(int i=2;i<n/2;i++)
    {
      if(n%i==0)
      {
        flag=1;
        break;
      }
    }
    if(flag==1)
    System.out.println("Not prime");
    else
    System.out.println("Prime");
    s.close();
  }
}
