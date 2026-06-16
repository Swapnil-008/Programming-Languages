public class Main
{
    static int num;
    public static void main(String[] args)
    {
        Basics basics = new Basics();
        Functions functions = new Functions();
        basics.display();

        // Any standalone decimal value in Java is ALWAYS treated as a double, not a float
        int num1 = 10, num2 = 20;
        // System.out.println(Functions.add(num1, num2));
        float num3 = 10.5f; float num4 = 20.5f;
        // System.out.println(Functions.add(num3, num4));

        Array arrays = new Array();
        arrays.display();
        int x = (int)2147483649L;
        System.out.println("X: "+x);
        int arr[] = new int[5];
        // System.out.printf("before: %d\n", System.identityHashCode(arr));
        // arrays.show(arr);
        // System.out.printf("\nafter: %d", System.identityHashCode(arr));

        // arrays.func(arr);   Generates ambiguity error

        Main mn1 = new Main();
        ClassAndObject classAndObject = new ClassAndObject();
        System.out.println(System.identityHashCode(mn1));
//        classAndObject.display(mn1);
        System.out.println(System.identityHashCode(mn1));
        System.out.println("Num: " + num);

        Number number = new Number();
        number.num = number.createArray(10);
//        number.scan();
//        number.display();
//        OuterClass outerClass =  new OuterClass();
//        outerClass.display();
//        outerClass.display1();
//        Node node = new Node(10);
//        node.createNode(20);
//        Parent ref = new Child();
//        ref.show();
//        Child child = new Child();

//        MyThread myThread1 = new MyThread();
//        MyThread myThread2 = new MyThread();
//        myThread1.start();
//        try {
//            Thread.sleep(1000);
//        }
//        catch(InterruptedException e)
//        {
//            System.out.println("Interrupted");
//        }
//        myThread2.start();
//        try {
//            Thread.sleep(1000);
//        }
//        catch(InterruptedException e)
//        {
//            System.out.println("Interrupted");
//        }
//        Thread ref = Thread.currentThread();
//        ref.setName("MainThread");
//        System.out.println("main() ends executed by " + Thread.currentThread().getName());
    }
}
