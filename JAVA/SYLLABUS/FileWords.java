import java.io.*;
import java.util.*;
public class FileWords 
{
  public static void main(String[] args) {
    String line;
    int count=0;
    ArrayList<String> l=new ArrayList<String>();
    Scanner s=new Scanner(System.in);
    File f1=new File("File1.txt");
    File f2=new File("File2.txt");
    try
    {
      
      BufferedWriter bw1=new BufferedWriter(new FileWriter(f1));
      System.out.println("Enter text(type exit to stop):");
      while(true)
      {
        line=s.nextLine();
        if(line.equals("exit"))
         break;
        bw1.write(line);
        bw1.newLine();
      }
      bw1.close();

      BufferedReader br=new BufferedReader(new FileReader(f1));
      while((line=br.readLine())!=null)
      {
        String[] words=line.trim().split("\\s+");
        count+=words.length;
        for(String word:words)
        {
          l.add(word);
        }
      }
      br.close();
      Collections.sort(l);
      BufferedWriter bw2=new BufferedWriter(new FileWriter(f2));
      for(String word:l)
      {
        bw2.write(word);
        bw2.newLine();
      }
      
      bw2.close();
     
    }
    catch(IOException e)
    {
      System.out.println("Exception catched: "+e);
    }
    System.out.println("word count: "+count);
    s.close();
  }
}
