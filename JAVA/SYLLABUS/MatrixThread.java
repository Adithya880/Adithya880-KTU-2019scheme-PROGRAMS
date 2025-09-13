import java.util.*;

class Thread1 extends Thread
{
  Scanner s=new Scanner(System.in);
  public void run()
  {
    int a[][]=new int[5][4];
    int i,j,k;
    System.out.println("Enter matrix elements:");
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        a[i][j]=s.nextInt();
      }
    }
    System.out.println("Matrix:");
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        System.out.print(a[i][j]+"     ");
      }
      System.out.println();
    }
    for(j=0;j<4;j++)
    {
      a[4][j]=0;
      for(k=0;k<4;k++)
      {
        a[4][j]+=a[k][0];
      }
    }
    System.out.println("Matrix:");
    for(i=0;i<5;i++)
    {
      for(j=0;j<4;j++)
      {
        System.out.print(a[i][j]+"     ");
      }
      System.out.println();
    }
    
  }
}

class Thread2 extends Thread
{
  Scanner s=new Scanner(System.in);
  public void run()
  {
    int a[][]=new int[4][4];
    Random ran=new Random();
    int i,j;
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        a[i][j]=ran.nextInt(2);
      }
    }
    System.out.println("Matrix:");
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        System.out.print(a[i][j]+"     ");
      }
      System.out.println();
    }
    int r,maxr=0,c,maxc=0,maxri=0,maxci=0;
    for(i=0;i<4;i++)
    { 
      r=0;
      for(j=0;j<4;j++)
      {
        if(a[i][j]==1)
          r++;
      }
      if(r>maxr)
      {
        maxr=r;
        maxri=i+1;
      }
    }
    
    for(j=0;j<4;j++)
    { 
      c=0;
      for(i=0;i<4;i++)
      {
        if(a[i][j]==1)
          c++;
      }
      if(c>maxc)
      {
        maxc=c;
        maxci=j+1;
      }
    }

    System.out.println("Maximum 1s are found in row "+maxri+" and "+maxr);
    System.out.println("Maximum 1s are found in column "+maxci+" and "+maxc);
    
  }
}

public class MatrixThread {

  public static void main(String[] args) {
    Thread1 t1=new Thread1();
    
    Thread2 t2=new Thread2();
    t1.start();
    t2.start();
  }
}