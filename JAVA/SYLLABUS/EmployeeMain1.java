
class Employee1
{
  void display()
  {
    System.out.println("Name of the class is Employee");
  }
  void calcSalary()
  {
    System.out.println("Salary of employee is 10000");
  }
}

class Engineer extends Employee1
{
  void calcSalary()
  {
    System.out.println("Salary of engineer is 20000");
  }
}

public class EmployeeMain1 {
  public static void main(String[] args) {
    Employee1 emp=new Engineer();
  emp.display();
  emp.calcSalary();
  }
  
}
