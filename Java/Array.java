public class Array
{
    void   display()
    {
        // Declaration of arrays:
        // 1D array -> int[] arr = new int[10]  or  int arr[] = new int[10]  or  int arr[] = {10, 20, 30}  or  int arr[] =  new int[]{10, 20, 30}
        // 2D array -> int[][] arr = new int[rows][cols]   or   int arr[][] = new int[rows][cols]  or
        // int arr[][] = new int[][]{{row0}, {row1}, {row2}}  or int arr[][] = {{}, {}} -> but this initialization is valid at the time of declaration only
        // int arr[] = new int[10]; // initialized with 0
        // System.out.println(arr.length); // returns 10 even the values are not initialized
        // arr[0] = 10;
        // arr[1] = 10;
        //  System.out.println(System.identityHashCode(arr[0])); // prints the reference
        //  System.out.println(System.identityHashCode(arr[1])); // both have same reference
        // identityHashCode on primitive array elements does not show their reference. It first autoboxes them into Integer objects. Same output occurs due to Integer caching, not because array elements share the same reference.

        // While returning array from function we return reference of the array hence return type of function must be 'datatype[]'
        // Ex. static int[] returnArray(){ int arr[] = new int[5];  return arr; }

        // Jagged array:
        // 2D array which may have different no. of elements in each row

        // Varargs functions:
        // Functions with variable no. of parameters called varargs functions, Syntax of parameter: datatype ...variable_name Ex. int ...num, these set of elements must have same datatype
        // Internally varargs parameter gets converted into 1D array of elements, we can overload a function using varargs parameter
        // Ex. void show(int ...num), void show(double ...num);
        // Doesn't matter function have different parameters except varargs, varargs parameter must be last parameter in parameter list, hence one function can't have more than one varargs parameter
        // Sometime varargs function may cause ambiguity error Ex. below functions
        // When varargs methods are overloaded, Java selects the most specific method. A method with a fixed parameter + varargs is more specific than a pure varargs method.
    }
//    Generates ambiguity error
//    void func(int []arr)
//    {
//        System.out.println("In array");
//    }
//    void func(int ...arr)
//    {
//        System.out.println("In varargs");
//    }

    void show(int arr[])
    {
        int newArr[] = new int[5];
        System.out.println(System.identityHashCode(arr));
        System.out.println(System.identityHashCode(newArr));
        arr = newArr;
        System.out.println(System.identityHashCode(arr));
    }
}

// To print references of variables or memory -> System.identityHashCode(variable_name or object)