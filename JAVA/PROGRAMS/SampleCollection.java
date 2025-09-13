import java.util.*;
public class SampleCollection 
{
  public static void main(String[] args) 
  {
        ArrayList<String> l=new ArrayList<String>();
        l.add("Ravi0");
        l.add("Ravi1");
        System.out.println(l.size());
        @SuppressWarnings("rawtypes")
        Iterator i=l.iterator();
        while(i.hasNext())
        {
          System.out.println(i.next());
        }
        l.remove("Ravi0");
        System.out.println(l.size());
  }
}
