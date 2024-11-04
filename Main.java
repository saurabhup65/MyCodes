public class Main {
    public static void main(String[] args) {
        System.out.println(sumFirstAndLastDigit(252)); // Output: 4
        System.out.println(sumFirstAndLastDigit(257)); // Output: 9
        System.out.println(sumFirstAndLastDigit(0));   // Output: 0
        System.out.println(sumFirstAndLastDigit(5));   // Output: 10
        System.out.println(sumFirstAndLastDigit(-10)); // Output: -1
    }

    public static int sumFirstAndLastDigit(int number) {
        // Check if the number is negative
        if (number < 0) {
            return -1; // Return -1 for invalid input
        }

        // Convert the number to a string
        String numberStr = Integer.toString(number);

        // Get the first digit
        int firstDigit = Character.getNumericValue(numberStr.charAt(0));
        
        // Get the last digit; use length - 1 to get the last character
        int lastDigit = Character.getNumericValue(numberStr.charAt(numberStr.length() - 1));

        // Return the sum of the first and last digits
        return firstDigit + lastDigit;
    }
}
