public class Package
{
    // Packages:
    // Java has many in-built classes which programmer requires for different usage, for easy access java has encapsulated those classes into packages.
    // For accessing those classes, we have to import the required package
    // There are two ways of importing packages:  Fully qualified class name and import statement

    // Fully qualified class name: for importing some class from package, we mention that class name with its complete package name, this method is faster than import statement
    // Ex. To import Scanner class -> java.util.Scanner, but then whenever we have to use Scanner class, we have to mention complete name
    // Ex. java.util.Scanner sc = new java.util.Scanner(java.lang.System.in);

    // Import statement: There are two options to use import statement -> Explicit import and Implicit import
    // Explicit import: In this we explicitly mention the name of class in import statement, Ex. import java.util.Scanner
    // Some packages may have subpackages, so we have to mention those also -> Ex. import java.awt.event.MouseAdapter;
    // Implicit import: In this we mention * with that all the classes belonging to same package imports automatically

    // If we are using some class which belongs to more than one package, and we have imported both the packages implicitly then there compiler will generate ambiguity error
    // Ex. we are using class Date, and we have implicitly imported packages: java.util.* and java.sql.* both the packages have that class -> reference to date class is ambiguous
    // This problem can be solved in two ways: Fully qualified class name (java.util.Date date = new java.util.Date()) and Explicit import (import java.util.Date)

    // Classes belonging to sub-packages of implicitly imported package aren't available in program, Ex. java.awt.event.MouseAdapter -> event is a sub-package of awt package
    // In above Ex. for making the classes available of event sub-package we have to mention its complete name like java.awt.event.*

    // Static import:
    // It is used to import the static members of class, While importing always use fully qualified path Ex. import static java.lang.System.out -> used as out.println(num);

    // Own package creation:
    // Later...
}
