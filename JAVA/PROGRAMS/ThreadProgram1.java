import java.util.*;
class Generator extends Thread
{
  public void run()
  {
    Random rand=new Random();
    try
    {
      for(int i=0;i<5;i++)
      {
        int n=rand.nextInt(20);
        System.out.println(n);
        if(n%2==0)
        {
          Thread1 t1=new Thread1(n);
          t1.start(); 
          //t1.sleep(500);
        }
        else
        {
          Thread2 t2=new Thread2(n);
          t2.start();
        }
      }
    }
    catch(Exception e)
    {
      System.out.println(e);
    }
  }
}



class Thread1 extends Thread
{
  int x;
  public Thread1(int x)
  {
    this.x=x;
  }
  public void run()
  {
      System.out.println("Square: "+x*x);
      System.out.println("Thread t1 exited");
  }
  }
  


class Thread2 extends Thread
{
  int x;
  public Thread2(int x)
  {
    this.x=x;
  }
  public void run()
  {
      System.out.println("Cube: "+x*x*x);
      System.out.println("Thread t2 exited");
  }
}


public class ThreadProgram1 
{
  public static void main(String[] args)
  {
    Generator g=new Generator();
    g.start();
  }
  
}
