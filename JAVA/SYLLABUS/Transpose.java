import java.util.*;

public class Transpose {

  public static void main(String[] args) {
    int a[][]=new int[3][3];
    int t[][]=new int[3][3];
    Scanner s=new Scanner(System.in);
    int i,j;
    System.out.println("Enter matrix elements:");
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        a[i][j]=s.nextInt();
      }
    }
    System.out.println("Matrix:");
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        System.out.print(a[i][j]+"     ");
      }
      System.out.println();
    }
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        t[j][i]=a[i][j];
      }
    }
    System.out.println("Transposed  Matrix:");
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        System.out.print(t[i][j]+"     ");
      }
      System.out.println();
    }
  }
}