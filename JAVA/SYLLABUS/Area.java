public class Area {
  double area(int x)//circle
  {
    return (3.14*x*x);
  }

  double area(int x,int y)//rectangle
  {
    return (x*y);
  }

  double area(int x,int y,int z)
  {
    double s=(x+y+z)/2.0;
    return (Math.sqrt(s*(s-x)*(s-y)*(s-z)));
  }

  public static void main(String[] args) {
    Area a=new Area();
    System.out.println("Area of circle: "+a.area(1));
    System.out.println("Area of rectangle: "+a.area(1,2));
    System.out.println("Area of triangle: "+a.area(6,8,10));
  }
}
