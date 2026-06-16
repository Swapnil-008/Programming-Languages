import static java.lang.System.out;

public class ClassAndObject2
{
    // Inner classes:
    // When we define class inside another class we call them inner classes
    // Inner class is accessible outside the outer class
    // There are four types of inner classes:
    // 1) Regular inner class 2) Method local inner class 3) Anonymous inner class 4) Static inner class.
//    class OuterClass
//    {
//        class InnerClass
//        {
//            void display()
//            {
//                out.println("Inner class display");
//            }
//        }
//    }
    // On compilation of above code .class file get created for both inner and outer classes,
    // the name of .class file of inner class is OuterClass$InnerClass.class in above example
    // To create the reference of the inner class outside the outer class -> OuterClass.InnerClass ref;
    // To create the object of the inner class we always need object of outer class
    // Ex. Outer obj = new Outer()  ->  OuterClass.InnerClass ref = obj.new InnerClass()  ->  ref.display()

    // Accessing Inner Classes
    // i) Accessing inner class members outside outer class:
    // To access them outside outer class it is necessary to create an object of inner class, and for that object of outer class is required
    // ii) Accessing inner class members inside non-static methods of outer class:
    // To create object of inner class inside non-static member function of outer class we don't need to mention reference of outer class.
//    class OuterClass
//    {
//        class InnerClass
//        {
//            private void display()
//            {
//                out.println("Inner class display");
//            }
//        }
//        void show()
//        {
//            InnerClass innerClass = this.new InnerClass(); // As for creation of object of inner class it needs outer class object, 'this' represents
//            innerClass.display();   // Valid
//        }
//    }
    // iii) Accessing inside static member functions of outer class:
    // To create object of inner class inside static member function of outer class we need object of outer class, As static members doesn't have 'this'
//    class OuterClass
//    {
//        class InnerClass
//        {
//            private void display()
//            {
//                out.println("Inner class display");
//            }
//        }
//        void show(OuterClass obj)
//        {
//            InnerClass innerClass = obj.new InnerClass();
//            innerClass.display();   // Valid
//        }
//    }

    // Accessing outer class members inside inner class
    // i) Outer class members can be accessed directly from inner class member function
    // ii) Static member inside inner class:
    // We can access them using InnerClassName.staticMember
    // Inner classes can access outer class static members directly or via class name, but static members are only allowed in static nested classes, not in non-static inner classes.

    // 2) Method / Local Inner Class:
    // It is a class defined inside a method
    // The JVM creates .class file for local class has name in OuterClassName$<Number>InnerClassName.class
    // Here value of number starts from 1 and keeps increasing if inner classes have same name for each different inner class
    // Local classes are accessible only inside the function of definition, we can't access them outside
    // We can directly access the local variables of method inside the local class where the inner class has declared, but they automatically become final
    // hence, we can't change the value of the local variable from its inner class
    // We can access static and non-static members of outer class inside the local class if the local class has defined inside non-static member function,
    // Inside static member function we can't access

    // Anonymous Inner Class: Later...'

    // Garbage collector:
    // It is used to avoid the memory leak of allocated memory in runtime
    // It is nothing but a thread which runs in the background and recollects the memory on heap section which has no live references
    // In Java, when an object has no live references, it becomes unreachable and eligible for garbage collection
    // Following are some ways using which we can make the reference count of memory zero:
    // i) Nullifying the reference variable, decreases the reference count of runtime memory by 1 and if it's 0 then thread recollects it
    // ii) Assigning reference variable to some other memory:
    // If we assign reference of new object to existing reference variable then reference count of prev object decreases by 1
    // iii) Declaring reference variable as a local variable:
    // It gets destroyed with function stack frame which automatically lives the reference to memory and becomes eligible for recollection

    // Calling garbage collector explicitly:
    // i) By using System class:
    // gc() is a static member function of class system, so we call it as System.gc()
    // ii) By using Runtime class:
    // gc() is a non-static member function of class Runtime hence to call it we need object, but we can't create object using new operator, as its all constructors are private
    // So, we have to use static pre-defined method for creating an object -> getRuntime(), which methods returns an object of class called as factory method and singleton class
    // because one object gets created for whole class, if you try to call it multiple times still it will return the same reference
    // System.gc() internally created Runtime obj.gc()
    // Runtime class provides some methods which gives idea about memory in JVM in bytes:
    // i) maxMemory():
    // It is a non-static member function which returns maximum amount of memory JVM will contain.
    // ii) totalMemory():
    // It is a non-static member function which returns total amount of memory currently available for current and future objects
    // iii) freeMemory():
    // It is a non-static member function which returns amount of free memory in JVM, calling JVM may result in increased value of free memory

    // finalize() method:
    // Java doesn't have destructor, so instead of destructor java has given finalize method
    // This method is protected of class object, hence available in every class of Java
    // This method executes automatically like destructor, It is executed by garbage collector thread
    // To use it we have to override it in our class, default has blank implementation

    // Why finalize method is deprecated:
    // i) We don't know the exact time at which the JVM will run garbage collector
    // ii) We don't know in which sequence the garbage collector will destroy the object

    // Why main() method is declared as public static void?
    // main() of our class gets called by jvm, jvm is an entity which is outside the package, hence for accessing from outside it must be public
    // We can't create an object at runtime because runtime starts with the execution of main() method, hence for calling the main() by JVM it must be static

    // Strings: Later...

    public static  void main(String[] args)
    {
//        Runtime runtime = Runtime.getRuntime();
//        runtime.gc();
    }
}

// Static member inside inner class:
//class OuterClass
//{
//    int x = 10;
//    class InnerClass
//    {
//        static void show()
//        {
//            OuterClass outer = new OuterClass();
//            out.println(outer.x);
//        }
//    }
//    void display()
//    {
//        InnerClass.show();
//    }
//}

// Local Classes:
//class OuterClass
//{
//    void display1()
//    {
//        class InnerClass
//        {
//            void show()
//            {
//                out.println("Inside Show1");
//            }
//        }
//    }
//    void display2()
//    {
//        class InnerClass
//        {
//            void show()
//            {
//                out.println("Inside Show2");
//            }
//        }
//    }
//}

// Assigning reference variable to some other memory:
//class Node
//{
//    int data;
//    Node next;
//}
//
//class Program
//{
//    public static void main(String[] args)
//    {
//        Node n1, n2, n3;
//        n1 = new Node();
//        n2 = n1;          // Now the reference count of memory allocated for n1 object is 2
//        n2 =  new Node(); // the reference count of that memory is decreased by 1, so it is 1 now
//        n3 = new Node();
//        n1 = n3;          // again it decreased by 1, no live references exist → object becomes unreachable, so garbage collector will recollect it
//    }
//}

// Calling gc() explicitly using Runtime class
//class Node
//{
//    int data;
//    Node next;
//    Node(int d)
//    {
//        data = d;
//        next = null;
//    }
//    void createNode(int d)
//    {
//        data = d;
//        next = new Node(d);
//        out.println(System.identityHashCode(next));
//        Runtime rt = Runtime.getRuntime();
//        rt.gc();
//    }
//}

// Finalize method:
//class Node
//{
//    int data;
//    Node next;
//    Node(int d)
//    {
//        data = d;
//        next = null;
//        out.println(System.identityHashCode(this));
//    }
//    protected void finalize()
//    {
//        out.println("Name of thread: " + Thread.currentThread().getName());
//    }
//}