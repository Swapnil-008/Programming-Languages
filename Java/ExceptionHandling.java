public class ExceptionHandling
{
    // Exception is a runtime error, in Java exception is an object that describes an error that has occurred in a piece of code
    // There are 5 keywords are used in Java exception handling try, catch, finally, throw, throws
    // In general form of exception handling there are three types of blocks: try, catch, and finally
    // try: statements which may generate exceptions
    // catch: exception handling code, multiple catch blocks can be used
    // finally: code which is to be executed compulsory after complete execution of try catch block

    // Exception types:
    // class Throwable is at top of exception class hierarchy, it is divided into two subclasses
    // 1) Error: This class defines exceptions that are not expected to be handled by your program or programmer
    // 2) Exception: Exceptions are problems that can be predicted and handled by the programmer

    // Exception handing mechanism:
    // Exception is an object of class belonging to the family of class Exception, On exception generation that object creates and caught by exception handler
    // There are two exception handlers: 1) default exception handler (JVM) 2) User defined exception handler (catch blocks)

    // Uncaught Exceptions:
    // When JVM throws an object of exception that can cause the execution of current program to stop, because that thrown exception must be caught by an exception handler
    // If we don't supply any exception handler of our code (catch blocks) then generated exception will be caught by JVM (default).
    // Default handler describes exception prints stacktrace and terminates program, stacktrace means JVM prints names of all the functions from exception generating to the main() function

    // Remaining Later...
}
