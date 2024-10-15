import java.util.Scanner;

public class Solution {
    
    // Function to convert the input string into the zigzag pattern
    public String convert(String s, int nRows) {
        // Handle edge case where only 1 row is given or if string length is less than the row count
        if (nRows == 1 || s.length() <= nRows) {
            return s;
        }

        // Convert the string to a character array for easier manipulation
        char[] c = s.toCharArray();
        int len = c.length;

        // Create an array of StringBuffer, one for each row
        StringBuffer[] sb = new StringBuffer[nRows];
        for (int i = 0; i < sb.length; i++) {
            sb[i] = new StringBuffer();
        }

        // Iterate over the characters of the string
        int i = 0;
        while (i < len) {
            // Fill down the rows (vertically)
            for (int idx = 0; idx < nRows && i < len; idx++) {
                sb[idx].append(c[i++]);
            }

            // Then fill obliquely up (diagonally)
            for (int idx = nRows - 2; idx >= 1 && i < len; idx--) {
                sb[idx].append(c[i++]);
            }
        }

        // Combine all the rows to form the final string
        for (int idx = 1; idx < sb.length; idx++) {
            sb[0].append(sb[idx]);
        }

        // Return the result stored in the first StringBuffer
        return sb[0].toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner scanner = new Scanner(System.in);

        // Take the input string from the user
        System.out.println("Enter the string: ");
        String s = scanner.nextLine();

        // Take the number of rows for zigzag conversion
        System.out.println("Enter the number of rows: ");
        int numRows = scanner.nextInt();

        // Call the function and print the converted zigzag string
        String result = solution.convert(s, numRows);
        System.out.println("Zigzag conversion result: " + result);
    }
}
