import java.io.*;
import java.util.*;
public class Student 
{
  public static void main(String[] args)throws IOException 
  {
    Scanner s=new Scanner(System.in);
    File f=new File("StudentRecords.txt");
    int c;
    try
    {
      do
      {
        System.out.println("Enter your choice");
        System.out.println("1.Add Student\n2.Display all\n3.Exit");
        c=s.nextInt();
        String name,line;
        int roll,marks;
        switch(c)
        {
    
              case 1:  s.nextLine();
                      BufferedWriter bw=new BufferedWriter(new FileWriter(f,true));
                      System.out.println("Enter name:");
                      name=s.nextLine();
                      System.out.println("Enter roll no:");
                      roll=s.nextInt();
                      System.out.println("Enter marks:");
                      marks=s.nextInt();
                      bw.write("Name: "+name+" Roll no: "+roll+" Marks: "+marks);
                      bw.newLine();
                      bw.close();
                      System.out.println("Student added successfully");
                      break;
  
            case 2:   BufferedReader br=new BufferedReader(new FileReader
                      ("StudentRecords.txt"));
                     while((line=br.readLine())!=null)
                     {
                       System.out.println(line);
                     }
                     br.close();
                     break;
  
          case 3:    System.out.println("Exiting...");
                     System.exit(0);
          
          default: System.out.println("Wrong choice");
        }
    
         
      }
      while(c!=3);
     
    }
    catch(IOException e)
    {
      System.out.println("exception catched: "+e.getMessage());
    }
    
    




    s.close();
  }
}
