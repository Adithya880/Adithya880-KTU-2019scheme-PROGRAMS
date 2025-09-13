import java.util.Scanner;
import java.util.Arrays;

public class SecondSmallestLargest {
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the size of the array
        System.out.println("Enter the number of elements in the array:");
        int n = sc.nextInt();

        // Input array elements
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Check if the array has at least two elements
        if (n < 2) {
            System.out.println("Array must have at least two elements.");
            return;
        }

        // Sort the array
        Arrays.sort(arr);

        // Find second smallest and second largest
        int secondSmallest = arr[1]; // Second element after sorting
        int secondLargest = arr[n - 2]; // Second last element after sorting

        System.out.println("Second Smallest Element: " + secondSmallest);
        System.out.println("Second Largest Element: " + secondLargest);

        sc.close();
    }
}
