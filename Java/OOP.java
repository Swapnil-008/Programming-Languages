import static java.lang.System.out;
public class OOP
{
    // Inheritance:
    // There are four pillars of OOP and Inheritance is one of those four pillars, In which the properties of a class gets inherited into another class
    // Parent class also called as super class
    // private members of super class never get inherit into child class, only public, protected, and default members can inherit and out of these public and protected can inherit outside the package also
    // Types of Inheritance:
    // Java provides three types of Inheritance
    // 1) Single Inheritance 2) Multilevel Inheritance 3) Hierarchical Inheritance
    // Java has removed multiple inheritance to avoid ambiguity, because when multiple base classes contain member having same name and gets inherited into same class, hence every class in java can have only one direct parent class (super class)
    // Java has implemented multiple inheritance but with interfaces not with classes

    // Memory Allocation:
    // Memory allocation of data members has nothing to do with its accessibility, Object created of child class has allocated memory to all the data members belonging to the super class as well

    // Method overriding:
    // Basic requirement of method overriding is Inheritance
    // Method overriding is a concept where a child class provides its own implementation of a method that is already defined in the parent class.
    // But if we change the parameter list of such method in child class then it becomes method overloading

    // Polymorphism:
    // Polymorphism is a pillar of OOP, it refers to the ability of a method or object to behave differently based on the content

    // Runtime polymorphism:
    // Runtime polymorphism is achieved using method overriding, where the method to be executed is decided at runtime based on the actual object, not the reference variable.
    // Basic requirements are Method overriding and reference of super class
    // If a parent reference is pointing to a child object, then the child’s overridden method will be called

    // Super keyword:
    // It is used inside child class to refer the parent class members, mostly when parent and child both contain members with same name
    // static method can't be overridden for runtime polymorphism, method must be non-static, we can't use super keyword in static method, because super is non-static

    // Constructors:
    // In inheritance case, constructors gets executed in the order of inheritance from topmost superclass to class whose object has been created

    // Passing parameter to parent class constructor:
    // super keyword is used, the super statement must be first statement in the child class constructor, any constructor can be called of parent class using super keyword

    // Execution of finalize method in inheritance:
    // When finalize of child gets executed, parent class finalize never gets executed automatically we have to call finalize() of parent class explicitly from child class finalize method

    // Composition:
    // Object of one class created as a data member of another class, 'has a' relationship

    // Interfaces: for top level interfaces valid access specifiers are public and default
    // This is an entity same as class, but it doesn't contain normal methods and normal data members
    // When we don't have idea about implementation, but we know what must be implemented for an entity, then for such entities we define interfaces.
    // Interfaces can contain data members and member functions, Data members are static and final by default hence initialize at the time of declaration and no need to mention static and final keywords explicitly
    // Methods are by default abstract and public, Hence we can't provide the implementation of methods, and don't need to mention modifiers
    // As interfaces contain abstract methods we can't create the object of interface, but we can create reference of interface
    // To inherit interface in some class or other interface 'implements' keyword is used
    // The class which implements interface must override all the abstract methods from interface, otherwise the class should be declared as abstract class

    // Nested interfaces:
    // 1) Interfaces in class: for inner interfaces valid access specifiers are public, protected, private, and default
    // For implementing the interface inside class use className.interfaceName

    // 2) Interface inside interface: For implementing the inner interface use outerInterface.innerInterface
    // Implementing outer interface doesn't implement inner interface automatically

    // 3) Interface inheriting another interface: For inheriting one interface inside another interface extends keyword is used
    // Members of base interface get inherited into derived interface
    // Class in which derived interface is implemented, it has to define all the methods belonging to base interface as well as derived interface

    // Multiple Interfaces:
    // Implementing multiple interfaces in one class
    // If multiple interfaces implemented in same class, and methods of interfaces have same name still there will be no ambiguity and just one definition implementation is sufficient
    // But multiple interfaces implemented in same class contain data members having same name generates ambiguity, to solve that ambiguity we have to access that data member by interfaceName and dot-operator

    // default, static, and private methods inside interface
    // Later...
}

// Single Inheritance
//class Vehicle
//{
//    void starts()
//    {
//        System.out.println("Vehicle starts");
//    }
//}
//class Bike extends Vehicle
//{
//    void bikeStarts()
//    {
//        starts();
//    }
//}

// Multilevel Inheritance
//class Grand
//{
//    private void grandMonthlySalary(int salary)
//    {
//        System.out.println("Grand monthly salary");
//    }
//    public long grandAnnualIncome()
//    {
//        System.out.println("Grand Annual income");
//        return 0;
//    }
//}
//class Parent extends Grand
//{
//    public long parentAnnualIncome(int income)
//    {
//        System.out.println("Parent salary");
//        return income + grandAnnualIncome();
//    }
//}
//class Child extends Parent
//{
//    public long childAnnualIncome(int income)
//    {
//        System.out.println("Child salary");
//        return income + parentAnnualIncome(income * 10);
//    }
//}

// Hierarchical Inheritance
//class Vehicle
//{
//    public void start(String name)
//    {
//        System.out.println(name + "started");
//    }
//}
//class Car extends Vehicle
//{
//    public void startCar(String name)
//    {
//        start(name);
//    }
//}
//class Bike extends Vehicle
//{
//    public void startBike(String name)
//    {
//        start(name);
//    }
//}

// Runtime polymorphism:
//class Parent {
//    void show() {
//        System.out.println("Parent show");
//    }
//}
//class Child extends Parent {
//    void show() {
//        System.out.println("Child show");
//    }
//}
//public class Demo {
//    public static void main(String[] args) {
//        Parent ref = new Child();
//        ref.show();       // It will execute the method of child class, as the child class object is stored in reference variable
//    }
//}

// static method in runtime polymorphism
//class Parent {
//    public static void show() {
//        System.out.println("Parent show");
//    }
//}
//class Child extends Parent {
//    public static void show() {
//        System.out.println("Child show");
//    }
//}

// Passing parameter to parent class constructor:
//class Parent
//{
//    Parent()
//    {
//        System.out.println("Parent Default Constructor");
//    }
//    Parent(int x)
//    {
//        System.out.println("Parent Constructor x: " + x);
//    }
//    void show()
//    {
//        System.out.println("Parent show");
//    }
//}
//class Child extends Parent
//{
//    Child()
//    {
//        super(10);
//        System.out.println("Child Constructor");
//    }
//    void show()
//    {
//        System.out.println("Child show");
//    }
//}

// Interface:
//interface inter1
//{
//    int x = 10;
//    void display();
//    void show();
//}
//class inter2 implements inter1
//{
//    public void display()
//    {
//        out.println("display " + x);
//    }
//    public void show()
//    {
//        out.println("show");
//    }
//}

// Interface in class:
//class OuterClass
//{
//    interface InnerInterface
//    {
//        int x = 10;
//        void display();
//    }
//    void show()
//    {
//        out.println("OuterClass show");
//    }
//}
//class MyClass implements OuterClass.InnerInterface
//{
//    public void display()
//    {
//        out.println("Interface overridden display");
//    }
//}

// Interface inside interface:
//interface OuterInterface
//{
//    void show();
//    interface InnerInterface
//    {
//        int x = 10;
//        void display();
//    }
//}
//class MyClass implements OuterInterface,  OuterInterface.InnerInterface
//{
//    @Override
//    public void display()
//    {
//        out.println("Inside display");
//    }
//    @Override
//    public void show()
//    {
//        out.println("Inside show");
//    }
//}

// Interface inheriting another interface:
//interface Interface1
//{
//    public void display();
//}
//interface Interface2 extends Interface1
//{
//    public void show();
//}
//class MyClass implements Interface2
//{
//    public void display()
//    {
//        out.println("Inside display");
//    }
//    public void show()
//    {
//        out.println("Inside show");
//    }
//}

// Multiple Interfaces:
//interface Interface1
//{
//    int x = 10;
//    public void display();
//}
//interface Interface2
//{
//    int y = 20;
//    public void show();
//}
//class Parent
//{
//    int a = 10;
//    public void myFunction()
//    {
//        out.println("myFunction");
//    }
//}
//class Child extends Parent implements Interface1, Interface2
//{
//    public void display()
//    {
//        out.println("Inside display x: " + x);
//    }
//    public void show()
//    {
//        out.println("Inside show y: " + y);
//    }
//}

// Multiple Interfaces:
//interface Interface1
//{
//    int z = 10;
//    public void display();
//}
//interface Interface2
//{
//    int z = 15;
//    public void display();
//}
//class MyClass implements Interface1, Interface2
//{
//    public void display()
//    {
//    //    out.println("Inside display z: " + z);   // This statement generates ambiguity error
//        out.println("Inside display z1: " + Interface1.z + " z2: " + Interface2.z);
//    }
//}