import java.util.*;
public class Calculator
{
  int a,b;
  Calculator(int a,int b)
  {
    this.a=a;
    this.b=b;
  }
  public void add()throws ArithmeticException
  {
    try
    {
      if(a<0||b<0)
       throw new ArithmeticException();
      else
      {
        int sum=a+b;
        System.out.println("Sum: "+sum);
      } 
    }
    catch(ArithmeticException e)
    {
      System.out.println("Negative number:"+e);
    }
  }
  public void subtract()throws ArithmeticException
  {
    try
    {
      if(a<0||b<0)
       throw new ArithmeticException();
      else
      {
        int diff=a-b;
        System.out.println("Difference: "+diff);
      } 
    }
    catch(ArithmeticException e)
    {
      System.out.println("Negative number:"+e);
    }
  }
  public void multiply()throws ArithmeticException 
  {
    try
    {
      if(a==0||b==0)
       throw new ArithmeticException();
      else
      {
        int product=a*b;
        System.out.println("Product: "+product);
      } 
    }
    catch(ArithmeticException e)
    {
      System.out.println("Input is 0:"+e);
    }
  }
  public void divide()throws ArithmeticException
  {
    try
    {
      if(a==0||b==0)
       throw new ArithmeticException();
      else
      {
        int q=a/b;
        System.out.println("Quotient: "+q);
      } 
    }
    catch(ArithmeticException e)
    {
      System.out.println("Input is 0:"+e);
    }
  }

  @SuppressWarnings("unused")
  public static void main(String[] args) 
  {
    int c;
    String a1,b1;
    Scanner s=new Scanner(System.in);
    do
    {
      
      System.out.println("Enter your choice:");
      System.out.println("1.Add\n2.Difference\n3.Product\n4.Division\n5.Exit\n");
      c=s.nextInt();
      if(c==5)
      System.exit(0);
      try
      {
        System.out.println("Enter a");
        a1=s.next();
        System.out.println("Enter b:");
        b1=s.next();
        if(a1.contains(".")||b1.contains("."))
         throw new InputMismatchException();
        int a=Integer.parseInt(a1);
        int b=Integer.parseInt(b1); 

        Calculator obj=new Calculator(a,b);
        if(obj==null)
         throw new NullPointerException();
        
         switch(c)
         {
          case 1: obj.add();break;

          case 2: obj.subtract();break;

          case 3: obj.multiply();break;

          case 4: obj.divide();break;

          case 5: System.out.println("\nExiting...");System.exit(0);

          default:System.out.println("Wrong choice!");
         }
      }
      catch(InputMismatchException e)
      {
        System.out.println(e);
      }
      catch(NullPointerException e)
      {
        System.out.println(e);
      }
      catch(NumberFormatException e)
      {
        System.out.println(e);
      }
      catch(Exception e)
      {
        System.out.println(e);
      }
      finally
      {
        System.out.println("Rest of the code");
      }
    }
    while(c!=5);

    s.close();
  }
}

