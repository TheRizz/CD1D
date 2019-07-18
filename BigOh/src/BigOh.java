import java.util.Scanner;

public class BigOh {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int number;                 // number of array elements
        double startTime;           // start time of function
        double endTime;             // end time of function     
        int[] values = new int[0];  // values input
        int[] averages = new int[0];// averages from the functions
        
        boolean valid = true;       // error checking 
        
    // outputs the header
    System.out.println(
    "******************************************************\n" +
    "*  PROGRAMMED BY : Debaggis, Beanstalk\n" +
    "*  CLASS         : CS1A\n" +
    "*  SECTION       : MW: 10:00a - 12:00p\n" +
    "*  LAB #3        : Intro To Functions\n" +
    "******************************************************\n" +
    "\n" +
    "The objective of this lab is to accumulate data from functions that\n"+
    "can have their runtimes quantified and compared to the Big Oh analysis"+
    "\nthat was taught in lecture. Through gathering this runtime data and\n"+
    "comparing it to the number of elements used in the arrays, we are\n"+
    "able to create a graph that shows common trends equivalent to what\n"+
    "is estimated through the Big Oh analysis.");

        // error checking the inputs to make sure that a proper input is read
        do {
            System.out.print("\nEnter the number of elements: ");
            number = in.nextInt();

            if(number < 0){
                System.out.println("Enter a number greater than 0\n");
            }
            else {
                valid = false;
                values = new int[number];
                averages = new int[number];
            }
        } while (valid);

        // runs the program until a -1 is entered for array size
        while (number != -1) {
            // sets the array values
            for (int i = 0; i < number; i++) {
                values[i] = (int) (Math.random() * 100);

            }

            // prints the run times for the binary search
            System.out.println("\nprefixAverages1: ");
            System.out.println("\nRandom Numbers Input: ");
            
            for (int i = 0; i < 5; i++) {
                
                System.out.print(values[i] + "\t");
                
            }
            
            System.out.println("\n\nRun Time per Search in Nano Seconds:");

            // runs the first 10 times
            for (int j = 0; j < 8; j++) {
                
                startTime = System.nanoTime();

                averages = prefixAverages1(number, values);

                endTime = System.nanoTime() - startTime;

                System.out.print(endTime + "\t");
                
            }
            
            System.out.println("\n\nArray Output");
            
            for (int i = 0; i < 5; i++) {
                
                System.out.print(averages[i] + "\t");
                
            }
            
            System.out.println("\n\nprefixAverage2: ");
            System.out.println("\nRandom Numbers Input: ");
            
            for (int i = 0; i < 5; i++) {
                
                System.out.print(values[i] + "\t");
                
            }
            System.out.println("\n\nRun Time per Search in Nano Seconds:");
            
            // runs the second test 10 times
            for (int j = 0; j < 8; j++) {
                
                startTime = System.nanoTime();

                averages = prefixAverages2(number, values);

                endTime = System.nanoTime() - startTime;

                System.out.print(endTime + "\t");
                
            }
            
            System.out.println("\n\nArray Output");
            
            for (int i = 0; i < 5; i++) {
                
                System.out.print(averages[i] + "\t");
                
            }
            
            System.out.println("");

        // error checking the inputs to make sure that a proper input is read
            do {
                System.out.print("\nEnter the number of elements: ");
                number = in.nextInt();

                if(number < 0 && number != -1){
                    System.out.println("Enter a number greater than 0\n");
                }
                else {
                    valid = false;
                    values = new int[number];
                }
            } while (valid);
        }
    }
    
    public static int[] prefixAverages1(int numElement, int[] X ){
        
        int A[] = new int[numElement];
        
        for (int i = 0; i < numElement - 1; i++) {
            
            int a = 0;
            
            for (int j = 0; j < i; j++) {
                
                a = a + X[j];
            }
            A[i] = a / (i + 1);
        }
        
        return A;
    }
    
    public static int[] prefixAverages2(int numElements, int[] X){
        
        int A[] = new int[numElements];
        int s = 0;
        
        for (int i = 0; i < numElements - 1; i++) {
            
            s = s + X[i];
            A[i] = s / (i + 1);
        }
    
        return A;
    }
    
}







