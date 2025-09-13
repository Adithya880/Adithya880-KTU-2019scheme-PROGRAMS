public class GarbageCollectorDemo {

  // Constructor to display object creation
  public GarbageCollectorDemo() {
      System.out.println("Object created: " + this);
  }

  // This method is called when the object is garbage collected
  @Override
  protected void finalize() throws Throwable {
      System.out.println("Object finalized and garbage collected: " + this);
  }

  @SuppressWarnings("unused")
  public static void main(String[] args) {
      // Create objects
      GarbageCollectorDemo obj1 = new GarbageCollectorDemo();
      GarbageCollectorDemo obj2 = new GarbageCollectorDemo();

      // Nullify references so the objects are eligible for garbage collection
      obj1 = null;
      obj2 = null;

      // Suggest garbage collection
      System.out.println("Requesting garbage collection...");
      System.gc(); // Suggests JVM to run the garbage collector

      // Pause the program to let the garbage collector run
      try {
          Thread.sleep(1000); // Wait for 1 second
      } catch (InterruptedException e) {
          e.printStackTrace();
      }

      System.out.println("End of program.");
  }
}
