import java.util.*;
import java.io.*;
public class StrinkgTkn {
  public static void main(String[] args) {
    String input,fn;
    int count=0;
    Scanner s=new Scanner(System.in);
    ArrayList<String> l=new ArrayList<String>();
    System.out.println("Enter String separated by spaces: ");
    input=s.nextLine();
    StringTokenizer st=new StringTokenizer(input);
    while(st.hasMoreTokens())
    {
      String i=st.nextToken();
      System.out.println(i);
      l.add(i);
      count++;
    }
    System.out.println("Count: "+count);
    Collections.sort(l);
    fn="SortedWords.txt";
    try
    {
      File f=new File(fn);
      BufferedWriter bw= new BufferedWriter(new FileWriter(f)); 
      bw.write("Count: "+count);
      for(String word:l)
      {
        bw.newLine();
        bw.write(word);
        
      }
      bw.close();
    }
    catch(IOException e)
    {
      System.err.println(e.getMessage());
    }
    s.close();
  }
}
