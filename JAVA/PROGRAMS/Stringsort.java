import java.io.*;
import java.util.*;

public class Stringsort 
{

static void writeToFile(String content, String filename) 
{
    BufferedWriter writer = null;
    try 
    {
        writer = new BufferedWriter(new FileWriter(filename));
        writer.write(content);
    } 
    catch (IOException e) 
    {
        System.out.println("Error writing to file: " + e.getMessage());
    } 
    finally 
    {
        try 
        {
            if (writer != null) 
              writer.close();
        } 
        catch (IOException e) 
        {
            System.out.println("Error closing file: " + e.getMessage());
        }
    }
}

static List<String> readFromFile(String filename) 
{
  List<String> words = new ArrayList<>();
  BufferedReader reader = null;
  try 
  {
      reader = new BufferedReader(new FileReader(filename));
      String line;
      while ((line = reader.readLine()) != null) 
      {
          // Tokenize the line by spaces
          StringTokenizer tokenizer = new StringTokenizer(line, " ");
          while (tokenizer.hasMoreTokens()) 
          {
              words.add(tokenizer.nextToken());
          }
      }
  } 
  catch (IOException e) 
  {
      System.out.println("Error reading from file: " + e.getMessage());
  } 
  finally 
  {
      try 
      {
          if (reader != null) reader.close();
      } 
      catch (IOException e) 
      {
          System.out.println("Error closing file: " + e.getMessage());
      }
  }
  return words;
}
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter words separated by spaces:");
        String input = scanner.nextLine();

        // File names
        String inputFile = "input.txt";
        String outputFile = "sorted_output.txt";

        // Write words to the input file
        writeToFile(input, inputFile);

        // Read words from input file, sort them, and write to output file
        List<String> words = readFromFile(inputFile);
        Collections.sort(words); // Sort words alphabetically
        writeToFile(String.join(" ", words), outputFile); // Join sorted words and write to output

        System.out.println("Words have been sorted and written to " + outputFile);

        scanner.close();
    }
}
