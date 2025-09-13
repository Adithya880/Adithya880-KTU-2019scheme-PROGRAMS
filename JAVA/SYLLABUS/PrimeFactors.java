import java.util.Scanner;

public class PrimeFactors {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an integer:");
        int n = sc.nextInt();

        if (n <= 1) {
            System.out.println("No prime factors for " + n);
        } else {
            System.out.println("Prime factors of " + n + ":");
            printPrimeFactors(n);
        }

        sc.close();
    }

    // Method to print prime factors
    private static void printPrimeFactors(int n) {
        // Divide by 2 until n is odd
        while (n % 2 == 0) {
            System.out.print(2 + " ");
            n /= 2;
        }

        // n must be odd at this point, check for odd divisors
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                System.out.print(i + " ");
                n /= i;
            }
        }

        // If n is a prime number greater than 2
        if (n > 2) {
            System.out.print(n);
        }
    }
}
