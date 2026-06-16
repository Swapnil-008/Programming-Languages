import java.util.Scanner;

public class Basics
{
    void  display()
    {
//        Main.num = 10;
        // Java is not considered as pure OOP language because it doesn't support some OOP concepts like operator overloading, multiple inheritance.
        // In Java, you can't use uninitialized local variables, every local variable must be initialized before it's first use.

        // Datatypes and it's ranges
        // Byte -> 1byte -> -128 - 127
        // Short -> 2bytes -> -32768 - 32767
        // Int -> 4bytes -> -2147483648 - 2147483647
        // Long -> 8bytes -> to use long datatype we have to suffix 'l' or 'L' with value Ex. long x = 2147482648l, otherwise it will be treated as an integer and if it's out of range of int it will generate error
        // Java is Unicode based language, to represent different Unicode based characters which are less that or equal to 65536 (0 - 65535) in number, for that we need 2bytes hence in Java size of char is 2bytes

        // Literals:
        // Literals are constant values, we use them to assign variables and there are different types of literals in Java.

        // 1) Integral literals:

        // i) Decimal format: 0-9
        // ii) Octal format: 0-7, value prefixed by 0(zero)
        // When we try to print octal val using println it always prints val in decimal format, to print the integral constant in actual format we have to use printf() with required format specifiers.
        // Ex. int num = 023;     System.out.printf("num: %o", num);   '%O' format specifier generates runtime error.
        // iii) Hexadecimal format: 0-9, A-F, a-f, value prefixed by '0x' or '0X'
        // Ex. int num = 0x35f;   System.out.printf("num: %x",num);    '%X' format specifier also allowed
        // iv) Binary format: 0/1, value prefixed by '0b' or '0B'
        // Ex. int num = 0b1110;  System.out.println(num);

        // 2) Character literals:

        // i) Direct character constant mention in ''
        // Ex. char temp = 'n';  "n" -> wrong, 'nb' -> wrong
        // ii) Integral constant: must be in range of character (0 - 65535)
        // Ex. char temp = 75; -10 -> wrong, 65536 -> wrong
        // iii) Hexadecimal Unicode: in the form of '\u1243' must have exact 4 digits
        // char unicode = '\u0041';   System.out.println(unicode);
        // iv) Escape sequence: format specifier -> '%c' or '%C'
        // char ch = '\n';            System.out.printf("ch: %c num", ch);

        // Boolean datatype is not compatible with any other datatype hence we can only assign true or false to boolean variables, use format specifier '%b' or '%B'
        // Floating point constants
        // int num = 8_50_458;     System.out.println(num);  for making more readable

        // Operators:
        // 1) Assignment operators: '='
        // 2) Arithmetic operators: '+', '-', '*', '/', '%'   In c++, modulus operator doesn't work with float datatype, but in Java it works
        // 3) Relational operators: '>', '<', '>=', '<=', '==', '!='  Statements containing relational operators called condition

        // 4) Logical operators: '&&', '||', '&', '|', '!'  Logical operators work with boolean type operands only
        // '&&' (Short circuit logical AND): If the result of 1st condition becomes false then JVM never checks the result of 2nd condition and returns false from first condition only, this behaviour of logical AND operator is called short-circuiting
        // '||' (Short circuit logical OR): If the result of 1st condition becomes true then JVM never checks the result of 2nd condition and returns true from the first condition only.
        // '&' (Logical AND): It works same as '&&' the only difference is '&' doesn't provide the short-circuiting, hence in '&' both conditions will be checked compulsory
        // Ex. result = (1 > 10) & (10 / 0);  this ex. will generate error even 1st condition is false, this can be avoided using short-circuiting
        // '|' (Logical OR): It works same as '||' the only difference is '|' doesn't provide the short-circuiting, hence in '|' both conditions will be checked compulsory

        // 5) Bitwise operators: '<<', '>>', '&', '|', '~'
        // '<<' (Left shift): Shifts the every bit to left by one position, Ex. int num = 5; num << 1 -> 10, hence num << n = num * 2^n -> This formula is valid till the answer is in the range of given datatype
        // '>>' (Right shift): Shifts the every bit to right by one position, Ex. int num = 16; num >> 1 -> 8, hence num >> n = num / 2^n
        // '&' (Bitwise AND): 1 & 1 = 1 otherwise 0
        // '|' (Bitwise OR): 0 | 0 = 0 otherwise 1
        // '^' (Bitwise NOT | XOR): X ^ X = 0, X ^ Y = 1
        // '~' (Bitwise Compliment): Reverse the bits and converts it into decimal, simple formula -> if num is +ve then ~num -> -(num+1), if num is -ve then ~num -> +(num-1)

        // Scanning data from user:
        // Scanner class belongs to java.util package, so we have to import that package, by using statement java.util.* (entire package) or java.util.scanner (specific class)
        // Ex. Scanner sc = new Scanner(System.in) -> calls parameterized constructor with System.in parameter which represents standard input
        // To scan values Scanner class has defined different member functions for different datatype
        // Ex. sc.nextInt(), sc.nextByte(), same for all integral and boolean datatypes, and sc.next(), sc.nextLine() for string datatype

        // sc.next() doesn't have problem with '\n' left in buffer but with this we can scan single word string only, space act as terminating character
        // With sc.nextLine() we can scan string of multiple words, only '\n' is the terminating character for nextLine(), but if any earlier method has left '\n' in buffer then it terminates immediately, without scanning the string, so for that first we have to remove that '\n'
        // Scanner class doesn't provide any method for char datatype, so we have to scan string and extracts it's first character

        // Typecasting:
        // Changing the datatype of a variable temporary, In that there are two types Implicit typecasting and Explicit typecasting
        // Implicit typecasting: In this type of typecasting conversion happens automatically by JVM, it takes place only when datatypes are compatible with each other and there is no lossy conversion Ex. char ch = 65
        // Explicit typecasting: In this type of typecasting conversion is done explicitly by programmer, it takes place only when datatypes are compatible with each other, this typecasting may cause lossy conversion Ex. byte b = (byte) 130 -> output: b = -126

        // Binary of any negative decimal = 2's compliment of decimal
        // Binary to decimal: If sign bit is 1, represents -ve number, then find 2's compliment of binary, convert it into decimal and apply -ve sign

        // final:
        // final keyword is used to crete read only variables, and it's value can't be changed once we initialize it, initialization can be made at the time of declaration or after declaration
        // final keyword can be used to stop method overriding and to stop class from getting inherited also

        // Any statement written after break or return generates error -> unreachable statement

        // Switch:
        // 'default' can be mentioned anywhere in the switch block, we can't write any other statement except 'case' and 'default' inside switch
        // Duplicate cases not allowed in switches,
        // We can use yield in switch -> we have to catch switch in variable, every case must be handled and add semicolon on closing bracket of switch, if we used yield in switch then we can't use break or return inside switch

        // Enumeration:
        // In Java, enumerations are classes we use them to create symbolic constants, to access those symbolic constants we have to use enumeration_name.enumeration_constant
        // we can create objects in enumeration

        // Named blocks:
        // Syntax: BLOCK_NAME:{} we can use break statement to terminate the execution of block -> break BLOCK_NAME -> it will terminate the execution of mentioned block
        // We can define Nested blocks also, Nested blocks can't have same name, two independent blocks can have same name

//        int num = 10;
//        BLOCK1:
//        {
//            System.out.println("Inside BLOCK1");
//            BLOCK2:
//            {
//                System.out.println("Inside BLOCK2");
//                if(num == 10)
//                {
//                    break BLOCK1;
//                }
//            }
//            System.out.println("Leaving BLOCK1");
//        }
//        System.out.println("Outside BLOCK1");

        // Loops:
        // while loop -> entry controlled loop, do while loop -> exit controlled loop
        // for each: for(datatype variable_name: set_of_elements){} Datatype of set of elements and datatype of single element must be same.
        // for each loop copies every element of set of elements into variable and then use, and both have different memory so, any changes made in the variable never get reflected in set of elements
        // But as the for each loop copies immediate elements into variables, immediate element of 2D array is 1D array and if it's copying reference of 1D array in variable
        // then changes made in elements of 1D arrays reflects into original array, hence changes made in elements of 2D array reflects into original one.

        int arr[][] = new int[][]{{10, 20, 30}, {50, 60}, {40, 70, 80, 90}};
        for(int num[]: arr)
        {
            for(int i = 0; i < num.length; i++)
            {
                System.out.print(num[i] + " ");
                num[i] = 0;                    // Now we have printed it first and then update, now lets check in below for loop, whether the changes are reflected or not
            }
//            for(int temp: num)
//            {
//                System.out.print(temp + " ");
//                temp = 0;   // Change doesn't reflect
//            }
            System.out.println();
        }
        System.out.println();
        for(int num[]: arr)
        {
            for(int val: num)
            {
                System.out.print(val + " ");  // But if we used for each loop for 1D array also in above code, then changes will not reflect in 2D array
            }
            System.out.println();
        }

        // Break:
        // Terminates execution of named block, switch case, loops
        // Break condition always terminate the current loop
    }
}
