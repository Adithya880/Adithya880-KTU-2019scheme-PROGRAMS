import java.io.*;
import java.util.*;
class FileHandling1

{
    public static void main(String args[]) throws IOException
    {

      Scanner s=new Scanner(System.in);
      String line;
      int charaCount=0,wordCount=0,sentenceCount=0;
         try
         {
          File f=new File("Count.txt");
          System.out.println(f.createNewFile());
          BufferedWriter bw=new BufferedWriter(new FileWriter(f));
          System.out.println("enter text(type exit to stop)");
          while (true) 
          {
            line = s.nextLine();
            if (line.equals("exit")) 
            {
                break;
            }
            bw.write(line);
            bw.newLine(); // To ensure lines are separated
          }
          bw.close();
          BufferedReader br=new BufferedReader(new FileReader("Count.txt"));
          while((line=br.readLine())!=null)
            {
              charaCount+=line.length();
              String[] words = line.trim().split("\\s+");
              wordCount += words.length;

              String[] sentences = line.trim().split("[.!?]");
              sentenceCount+=sentences.length;
            }
            br.close();
         }
         catch(IOException e)
         {
          System.out.println("Exception catched");
         }
         System.out.println("Character count: "+charaCount);
         System.out.println("word count: "+wordCount);
         System.out.println("sentence count: "+sentenceCount);
         s.close();
    }
    
}