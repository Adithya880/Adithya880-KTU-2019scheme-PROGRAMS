import java.util.*;

class Person 
{   
   final int deposit=5000;
   int balance=deposit;
   synchronized void withdrawal(int amt)
   {
     if(amt <= balance)
     {
      balance=balance-amt;
      System.out.println("Balance:$"+balance);
     } 
     else
     {
       System.out.println("Insufficient balance:$"+balance);
     }

   }
}

class MainPerson extends Thread
{
  int amt;
  Person p;
  MainPerson(Person p,int amt)
  {
    this.amt=amt;
    this.p=p;
  }
  public void run()
  {
    p.withdrawal(amt);
  }
}

public class ThreadSync 
{
  public static void main(String[]args)
  {
    Scanner s=new Scanner(System.in);
    int amt;
    Person p=new Person();

    try
    {
      System.out.print("1st PERSON:\n"); 
      System.out.print("Enter the amount to be withdrawn:");
      amt=s.nextInt();
      MainPerson mp1=new MainPerson(p,amt);
      mp1.start();
      MainPerson.sleep(1000);
      
      if(p.balance!=0)
      {
        System.out.print("2nd PERSON:\n"); 
        System.out.print("Enter the amount to be withdrawn:");
        amt=s.nextInt();
        MainPerson mp2=new MainPerson(p,amt);
        mp2.start();
        MainPerson.sleep(1000);
      }
     
      if(p.balance!=0)
      {
        System.out.print("3rd PERSON:\n"); 
        System.out.print("Enter the amount to be withdrawn:");
        amt=s.nextInt();
        MainPerson mp3=new MainPerson(p,amt);
        mp3.start();
        
      }
    }
    catch(InterruptedException e)
    {
      System.out.println("Thread interrupted: " + e.getMessage());
    }
    finally 
    {
      s.close();
    }
  }
}
