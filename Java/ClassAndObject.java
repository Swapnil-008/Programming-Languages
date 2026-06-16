public class ClassAndObject
{
    // When we know the complete implementation of an entity we define the concrete class for that entity
    // It is not possible to define the member functions of a class outside the class like C++
    // Class level modifiers:
    // 1) Modifiers applicable on top level classes
    // public, <default>, abstract, final, strictfp
    // 2) Modifiers applicable on inner classes
    // public, <default>, abstract, final, strictfp, private, protected, static

    // 1) public: Accessible from everywhere
    // A class declared as public must have the same name as the .java file, and a .java file can contain at most one public class.

    // 2) <default>: Accessible within the same package

    // 3) final: Applicable on classes, member functions and variables also.
    // final variable: If the final local variable is not used in the function, then it could be uninitialized, program runs and compiles successfully without any error
    // final method: It can be used to stop a method overriding, child class couldn't override the parent defined implementation of final method
    // If the parent class doesn't want to allow the child class to override the method and use the parent class's method only
    // final class: It prevents the class to get inherit inside any other class
    // Methods inside final class also become final
    // It prevents to implement two OOP concepts -> Inheritance and Polymorphism (Runtime polymorphism / method override)

    // 4) abstract: Applicable on classes and methods only
    // abstract method: Method without body, class containing abstract methods must be declared as abstract class
    // abstract class: Abstract class can contain concrete methods as well as abstract methods, or it contains only concrete methods also
    // When we know the partial implementation of an entity we define abstract class for that entity
    // Abstract classes can't be instantiated -> because if it allows to create an object, the object must be able to call the methods of an own class (abstract class) but those methods don't have implementation
    // So it can't call them that's why abstract classes can't be instantiated, even if the abstract class contains concrete methods only
    // But it is allowed to create a reference variable of an abstract class, which is used for runtime polymorphism
    // Abstract class only used as a parent class to apply some restrictions on child class
    // i) When a child class inherits an abstract parent class, it must either override all abstract methods or declared itself as an abstract class
    // ii) Child has to override abstract methods of parent class, while overriding we shouldn't assign weaker access specifier as compared to original methods
    // Access specifier of abstract methods in parent class                           Access specifier allowed in child class definition
    //                    public                                                                             public
    //                    protected                                                                    protected, public
    //                    default                                                                  default, protected, public

    // Some illegal combinations of abstract modifier at method level:
    // i) private, abstract methods -> private methods can't inherit in child class to provide abstract methods implementation
    // ii) abstract, final methods -> final prevents child class to override the final methods, and abstract needs to override them for defining their implementation
    // iii) static, abstract methods
    // iv) strictfp, abstract methods
    // v) synchronized, abstract methods
    // vi) native, abstract methods

    // Combination of abstract with other modifiers at class level
    // i) abstract public class className {} -> valid
    // ii) abstract <default> class className {} -> valid
    // iii) final abstract class className {} -> invalid, final class can't inherit, and abstract class should be inherited into another class to provide implementation
    // We can define final methods inside abstract class, but we can't define abstract methods in final class

    // Why abstract methods?
    // When we want child class must provide its own implementation for those inherited methods

    // Members of class: Every class has always 2 types of members
    // i) Non-static members / Instance members  -> contains instance data members and instance methods
    // ii) static members  -> contains static data members and static methods

    // a) Accessing instance data members:
    // Instance data members are always created inside the object, hence for accessing them we use object name and . (dot-operator)
    // Inside instance methods of same class instance data members are directly accessible (means without object and .) those data members belong to the calling object

    // b) Accessing instance member functions: (object and dot-operator)
    // Any changes made in data members inside member functions get reflected into calling object

    // c) Accessing static data members: Default value is zero
    // Static data members always work for entire class and not for any specific object, we access them using className and dot-operator (.)
    // They can be accessed using object and dot-operator but as the only one copy of static data members created for whole class,
    // the changes made by any object becomes visible to all other objects

    // d) Accessing static member functions:
    // Static data members of class are directly accessible inside static and non-static member functions of same class
    // But as there is no any calling object available inside static member function, non-static data members are not directly accessible inside static member functions

    // Passing object as a parameter
    // Even though we passes object's reference, still it gets passed by value only, any changed in reference doesn't reflect in calling function
//    void display(Main mn)
//    {
//        mn.num = 20;
//        mn = null;
//    }

    // Array of objects:
    // Array of objects created in two steps:
    // 1) Creating array of references: Number num[] = new Number[5]
    // 2) Creating object for each reference: num[0] = new Number()

    // 'this' reference variable:
    // 'this' refers to the calling object inside non-static methods of class, we can't assign any content to 'this' variable, it is not available in static member function

    // Member level modifiers:
    // 1) private:
    // These members are accessible only within the member functions of its own class
    // 2) <default>:
    // These members are accessible to classes belongs to same package
    // 3) protected:
    // Accessible within the same package.
    // Also, accessible in subclasses (child classes), even if they are in different packages.
    // Important:
    // - Outside the package, protected members can be accessed only through inheritance.
    // - Access must be done using the child class reference, not the parent class reference.
    // Note:
    // In inheritance, a reference variable can refer to its own class object
    // as well as objects of its child classes (upcasting).

    // 4) final: There are three types of final variables, Instance final variable, Static final variable, and Local final variable
    //   i) Instance final variable: These don't have default value, we have to initialize them explicitly before completion of execution of constructor
    //   ii) Static final variable: These also don't have default value, but it could be initialized at the time of declaration or inside static block only,
    //   Since these variables must be declared before JVM starts the execution of main(), hence we can't initialize them inside constructor
    // 5) static: We have seen this earlier (in class level modifier)
    // 6) abstract: We have seen this earlier (in class level modifier)

    // 7) synchronized: It is applicable on methods and blocks
    // By using synchronized method or synchronized block we can avoid the race condition (multiple thread tries to get ownership of object when all of them are set on same object)
    // When a method becomes synchronized only one thread can execute it at a time and when that thread completes its execution or leaves synchronized method then only other waiting threads can get the access
    // Due to race condition, we may have to face data inconsistency (irregular or unpredictable output)
    // 8) Native: Later...
    // 9) Transient: Later...
    // 10) volatile: Applicable only on variable
    // It is used to avoid the inconsistency in values of variable
    // When multiple threads are set on the same object, they create their own copy,
    // and due to that changes made by one thread don't visible to others, it is used to avoid the creation of different copies and access the same copy of the variable from main memory.
    public  static void main(String[] args)
    {
        Child child = new Child();
        child.childFuture();
    }
}

// Final method can't override from child class
class Parent
{
    final void childFuture()
    {
        System.out.println("Become an Engineer");
    }
}
class Child extends Parent
{}