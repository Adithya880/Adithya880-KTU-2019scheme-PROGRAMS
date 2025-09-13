
import java.util.*;
class AgeRelatedException extends Exception
{
  AgeRelatedException()
  {
    super();
  }
}

public class Person 
{
  public void age(int age)throws AgeRelatedException
  {
    if(age<18)
     throw new AgeRelatedException();
    else
      System.out.println("You are eligible");

  }
  public static void main(String[] args) 
  {
    Person p=new Person();
    Scanner s=new Scanner(System.in);
    int age;
    try
    {
      System.out.println("Enter age");
      age=s.nextInt();
      p.age(age);
    }
    catch(AgeRelatedException e)
    {
      System.out.println("Exception catched");
    }
    finally
    {
      System.out.println("Rest of the code");
    }
    s.close();
  }
}
