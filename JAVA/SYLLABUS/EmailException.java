import java.util.*;
class InvalidEmailException extends Exception
{
  InvalidEmailException(String msg)
  {
    super(msg);
  }
}

public class EmailException {

  public void checkEmail(String email)throws InvalidEmailException
  {
    if(email.contains("@")&&email.endsWith(".com"))
      System.out.println("Email is valid");
    else
       throw new InvalidEmailException("Invalid email format");
  }
  
  @SuppressWarnings("resource")
  public static void main(String[] args) 
  {
    try 
    {
      String emailid;
      Scanner s=new Scanner(System.in);
      System.out.println("Enter email ID:");
      emailid=s.nextLine();
      if(emailid.equals(""))
       throw new ClassNotFoundException("Empty");
      int len=emailid.length();
      if(len>30)
        throw new OutOfMemoryError(">30");
      EmailException em=new EmailException();
      em.checkEmail(emailid); 
      s.close();
    }
    catch(ClassNotFoundException e)
    {
      System.out.println("Exception catched:"+e.getMessage());
    }
    catch(OutOfMemoryError e)
    {
      System.out.println("Exception catched:"+e.getMessage());
    }
    catch(NullPointerException e)
    {
      System.out.println("Exception catched:"+e.getMessage());
    }
    catch (InvalidEmailException e) 
    {
      System.out.println("Exception catched:"+e.getMessage());
    }
    
    
  }
}
