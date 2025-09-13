import java.util.*;

class Employee {
    String name;
    int age, ph;
    String address;
    double salary;

    // Constructor to initialize the Employee fields
    Employee(String name, int age, int ph, String address, double salary) {
        this.name = name;
        this.age = age;
        this.ph = ph;
        this.address = address;
        this.salary = salary;
    }

    // Method to print salary
    void printSalary() {
        System.out.println("Salary: " + salary);
    }

    // Method to display employee details
    void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Phone Number: " + ph);
        System.out.println("Address: " + address);
    }
}

class Officer extends Employee {
    String specialization;

    // Constructor for Officer
    Officer(String name, int age, int ph, String address, double salary, String specialization) {
        super(name, age, ph, address, salary); // Call Employee constructor
        this.specialization = specialization;
    }

    // Method to display Officer details
    void officerDisplay() {
        display();
        printSalary();
        System.out.println("Specialization: " + specialization);
    }
}

class Manager extends Employee {
    String department;

    // Constructor for Manager
    Manager(String name, int age, int ph, String address, double salary, String department) {
        super(name, age, ph, address, salary); // Call Employee constructor
        this.department = department;
    }

    // Method to display Manager details
    void managerDisplay() {
        display();
        printSalary();
        System.out.println("Department: " + department);
    }
}

public class EmployeeMain {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // Input for Officer
        System.out.println("Enter Officer Details:");
        System.out.print("Name: ");
        String officerName = s.nextLine();
        System.out.print("Age: ");
        int officerAge = s.nextInt();
        System.out.print("Phone Number: ");
        int officerPhone = s.nextInt();
        s.nextLine();  // Consume newline
        System.out.print("Address: ");
        String officerAddress = s.nextLine();
        System.out.print("Salary: ");
        double officerSalary = s.nextDouble();
        s.nextLine();  // Consume newline
        System.out.print("Specialization: ");
        String officerSpecialization = s.nextLine();

        Officer officer = new Officer(officerName, officerAge, officerPhone, officerAddress, officerSalary, officerSpecialization);
        
        // Input for Manager
        System.out.println("\nEnter Manager Details:");
        System.out.print("Name: ");
        String managerName = s.nextLine();
        System.out.print("Age: ");
        int managerAge = s.nextInt();
        System.out.print("Phone Number: ");
        int managerPhone = s.nextInt();
        s.nextLine();  // Consume newline
        System.out.print("Address: ");
        String managerAddress = s.nextLine();
        System.out.print("Salary: ");
        double managerSalary = s.nextDouble();
        s.nextLine();  // Consume newline
        System.out.print("Department: ");
        String managerDepartment = s.nextLine();

        Manager manager = new Manager(managerName, managerAge, managerPhone, managerAddress, managerSalary, managerDepartment);

        // Display details of Officer and Manager
        System.out.println("\nOfficer Details:");
        officer.officerDisplay();

        System.out.println("\nManager Details:");
        manager.managerDisplay();

        s.close();
    }
}
