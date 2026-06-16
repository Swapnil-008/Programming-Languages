import java.util.Scanner;

public class Functions
{
    // int num;  -> primitive type instance variable
    // Scanner sc;  -> reference type instance variable
    // static int data; -> primitive type static variable
    // static Scanner sc2;  -> reference type static variable

    void  display()
    {
        // Functions:
        // There are two types of functions, user defined functions and library functions.
        // Library functions: These are the in-build functions in JAVA, to use them, we have to import their required classes and packages.
        // Syntax of function: [access_specifier] [static] return_type function_name([parameter_list]){body}
        // There are two types of member functions of class, static member functions and non-static member functions.
        // Non-static member functions works for object of class hence to call them we need object and dot operator.
        // Static member functions work for class only, hence to call them we need class_name and dot operator.
        // Non-static variables also called Instance variables.

        // Why use static function?
        // In Java, we use static methods when the method should not depend on object state.
        // We use static methods because static methods belong to the class, can be called without creating objects,
        // and are useful for utility functions, accessing static data, and cases where object creation is restricted.
        // If two static functions belong to same class they can call each other directly without class_name and dot operator

        // Types of variables:
        // In Java, we have two different methods for classification of variables -> According to datatype and According to place of declaration

        // According to datatype: Primitive variables and reference variables
        // Primitive variables: Variables declared with primitive datatypes (Ex. int, char, ...)
        // Reference variables: Variables having user defined datatypes (Ex. Class, Interface, Enumeration, ...)

        // According to place of declaration: Local variables, Non-static data members, Static data members
        // Instance variables: Variables declared inside the class but outside any function without static keyword
        // Static variables: Variables declared inside the class but outside any function with static keyword

        // Local variables: Variables declared inside the function, it can be primitive or reference variable
        // Ex. int num = 10;    -> As this variable is defined inside a function -> primitive type local variable
        // Scanner sc = new Scanner(System.in)  -> reference type local variable
        // Two variables with same name in different functions never affect each other

        // Memory areas used by JVM:
        // There are 5 types of memory areas are present in JVM, Method area, Heap area, Stack area, PC register, and Native method stacks

        // Method area: It contains information of class, JVM loads the information of class in binary form
        // when we use the class for first time, and also contains all static data members of a class.

        // Heap area: It contains all the memories created at runtime in java,
        // all the arrays and objects are created at runtime, so heap area contains memory of all objects and arrays

        // Stack area: It contains memory for all the local variables of all functions, On stack area JVM creates separate stack
        // for each thread hence if n threads executing our program, then stack area contains n stacks, one for each thread

        // PC register: It contains address of next executable instruction for each thread, PC register has independent memory
        // for each thread when current instruction get executed PC register of that thread also gets updated

        // Native method stack area: Native methods are those methods which are executing from java program
        // but implemented in some other language this area contains stacks for those methods

        // Parameter passing in function:
        // While passing variables as parameter we don't pass those variables to the called function,
        // we just pass the values of that variables to called function.
        // hence variables of calling function never become accessible from called function even if we pass them as parameter.
        // As an actual parameter we can mention a variable, constant values, or some expression Ex. addition(num, 10, 5+2)
        // Since formal parameters are local variables of its function, any changes made in formal parameters never get reflected back in actual parameters

        // Function overloading:
        // It means single function defined multiple times with different set of parameters.
        // Multiple forms of single function called it polymorphism. In that there are two types of polymorphism, compile time and runtime
        // Function overloading is a compile time polymorphism, In which compiler decides correct function definition by looking at parameter list mentioned at function call,
        // here compiler checks no. of parameters and datatype of parameters, function return_type doesn't matter for deciding correct function definition
        // Unlike C++, Java does NOT allow default arguments
    }
    static int add(int num1, int num2)
    {
        return num1 + num2;
    }
    static float add(float num1, float num2)
    {
        return num1 + num2;
    }
}