import java.io.*;
import java.util.*;

public class ResidentAssociation {
    static int boysCount = 0;   // Counter for boys
    static int girlsCount = 0,gradCount=0;  // Counter for girls

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        File f = new File("ResidentRecords.txt");
        int choice;

        try {
            do {
                System.out.println("Enter your choice:");
                System.out.println("1. Add Resident");
                System.out.println("2. Display All Residents");
                System.out.println("3. Exit");
                choice = s.nextInt();
                String name, line, gender;
                int id, age, graduationYear;
                
                switch (choice) {
                    case 1:
                        s.nextLine(); // Consume newline
                        BufferedWriter bw = new BufferedWriter(new FileWriter(f, true));
                        System.out.println("Enter name:");
                        name = s.nextLine();
                        System.out.println("Enter resident ID:");
                        id = s.nextInt();
                        System.out.println("Enter age:");
                        age = s.nextInt();
                        s.nextLine(); // Consume newline
                        System.out.println("Enter gender (Male/Female):");
                        gender = s.nextLine();
                        System.out.println("Enter graduation year:");
                        graduationYear = s.nextInt();
                        
                        // Write resident details to file
                        bw.write("Name: " + name + ", ID: " + id + ", Age: " + age + ", Gender: " + gender + ", Graduation Year: " + graduationYear);
                        bw.newLine();
                        bw.close();
                        
                        // Update counts
                        if (gender.equalsIgnoreCase("Male")) {
                            boysCount++;
                        } else if (gender.equalsIgnoreCase("Female")) {
                            girlsCount++;
                        }
                        if(graduationYear==2025)
                         gradCount++;
                        
                        System.out.println("Resident added successfully");
                        break;

                    case 2:
                        BufferedReader br = new BufferedReader(new FileReader(f));
                        System.out.println("Resident Records:");
                        while ((line = br.readLine()) != null) 
                        {
                            System.out.println(line);
                        }
                        br.close();
                        
                        // Display counts
                        System.out.println("Number of boys: " + boysCount);
                        System.out.println("Number of girls: " + girlsCount);
                        System.out.println("Number of graduates: " + gradCount);
                        break;

                    case 3:
                        System.out.println("Exiting...");
                        System.exit(0);

                    default:
                        System.out.println("Wrong choice");
                }
            } while (choice != 3);

        } catch (IOException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }

        s.close();
    }
}
