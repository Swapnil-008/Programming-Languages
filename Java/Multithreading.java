//public class Multithreading
//{
    // Multithreading:
    // Multithreading is a concept in Java which allows multiple threads to execute concurrently within the same program, which improves performance and responsiveness
    // A multithreaded program contains two or more executors, that can run simultaneously within the single program, each executor of program is called thread, and each thread executes separately
    // Ex. Text editor: typing text and checking grammar simultaneously
    // It improves efficiency by utilizing the idle time of CPU, by performing multiple tasks simultaneously
    // There are some problems in a single threaded system like thread waits and thread pooling,
    // So the thread pooling can be solved using thread mechanism and during thread waits CPU can be utilized by other threads

    // main thread:
    // When we call java program a thread begins running immediately, usually called it main thread.
    // main thread is important for two reasons:
    // 1) It is used to create other child threads
    // 2) It is usually the last thread to finish, because it performs various shutdown operations

    // Every thread in Java is an object
    // Some important methods of class Thread:
    // 1) currentThread(): static method, returns reference of currently executing thread
    // 2) setName(): non-static, sets name of thread, takes string as a parameter
    // 3) getName(): non-static, returns name of thread as a string
    // 4) setPriority(): non-static, sets priority of thread, value must be between 1 and 10, otherwise it generates illegal argument exception
    // 5) getPriority(): non-static, returns value between 1 and 10, which represents calling thread priority
    // 6) threadId(): non-static, it returns id of a thread, which is same throughout lifetime of thread
    // 7) sleep(): static, takes long value as a milliseconds, it is used to pause the execution of thread, this method could throw exception, so it must be used in try-catch block

    // Creating our own thread:
    // To create a thread, Runnable interface or Thread class is used
    // Steps to create a thread:
    // 1) Create a class which implements Runnable interface or inherits Thread class
        // a) Runnable interface contains only one abstract method: public void run()
        // b) The class inheriting the Thread class should override the run() method
        // c) The run() method defined in our class will be the entry point of the newly created thread
    // 2) Create the object of the user-defined class (the class that implements Runnable or extends Thread)
    // 3) If Runnable interface is used:
        // Create the object of Thread class and pass the Runnable object as a parameter to the Thread constructor
        // This defines that the created Thread will execute the run() method of the Runnable object
    // 4) If Thread class is extended:
        // Directly call start() using the object of the user-defined Thread class

    // If the run() method is directly called using the object of the user-defined class, then the run() method will be executed by the main thread and no new child thread will be created
    // Hence, we must call start() to create a new child thread, and the JVM internally calls the run() method in that child thread

    // Why throws is not allowed on run()
    // public void run() throws InterruptedException   // NOT allowed
    // Why?
    // Because:
    // run() is called internally by JVM.
    // JVM cannot handle checked exceptions
    // So Java compiler does not allow throws in run()
    // That’s why:
    // Any checked exception inside run() must be handled using try-catch
    // InterruptedException is a checked exception thrown when a sleeping or waiting thread is interrupted by another thread.
    // It can occur when a thread is: sleep(), wait(), join()
    // To wait a thread for another thread until that thread finish its execution, Thread class provides 2 methods
    // 1) isAlive(), 2) join()

    // 1) isAlive(): non-static member function of class Thread
    // It returns true if the thread on which it is called is still running otherwise it returns false

    // 2) join(): non-static member function of class Thread
    // This method waits until the thread terminates on which it is called

    // System.exit() is used to terminate all the threads
    // volatile boolean flag = true  -> volatile avoids to create the multiple copies for multiple threads

    // Thread priority:
    // Java has given us 3 constants to represent priority, these are static data members declared inside class Thread.
    // Thread.MIN_PRIORITY = 1, Thread.NORM_PRIORITY = 5, Thread.MAX_PRIORITY = 10
    // Priority of thread doesn't decide which thread executes first, it decides which thread will get the maximum CPU, priority high, CPU high

    // Synchronization:
    // Synchronization is used to control access to shared data so that only one thread can use it at a time
    // Synchronization works ONLY when multiple threads enter the SAME synchronized method on the SAME object
    // If either of these is different → synchronization becomes useless
    // synchronized ensures that only one thread executes a critical section or accesses shared data at a time
    // When a thread enters into synchronized method, It locks the object, and other threads wait until the lock is released,
    // and When method finishes Lock is released, so that other threads can access the synchronized method
    // Lock on thread released on complete the execution of synchronized method, there no need to call wait()
    // Synchronized block:
    // Later...

    // Interthread Communication:
    // It is used to avoid the polling of threads, We could achieve it using wait(), notify(), and notifyAll()
    // wait(), notify(), notifyAll() must be called inside synchronized code
    // wait(): It puts the current thread into waiting state and releases the object lock
    // notify(): It wakes ONE waiting thread on the same object
    // notifyAll(): It wakes ALL waiting threads, but only one thread gets the lock first Others go to BLOCKED state.
//}

//class MyThread extends Thread
//{
//    public  void run()
//    {
//        System.out.println("run() is executed by " + Thread.currentThread().getName());
//    }
//}
//class MyProgram
//{
//    public static void main(String[] args)
//    {
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
//    }
//}

//class MyThread extends Thread
//{
//    int x;
//    MyThread()
//    {
//        x = 0;
//    }
//    MyThread(int x)
//    {
//        this.x = x;
//    }
//    public void run()
//    {
//        Thread ref = Thread.currentThread();
//        for (int i = 1; i <= 5; i++)
//        {
//            System.out.println("Thread " + ref.getName() + " is running");
//        }
//    }
//}
//class MyProgram
//{
//    public static void main(String[] args)
//    {
//        MyThread myThread1 = new MyThread(10);
//        MyThread myThread2 = new MyThread(20);
//        myThread1.start();
//        // If we don't use sleep then both the threads will execute simultaneously, so the output could be mixed data
//        try {
//            Thread.sleep(1000);
//        }
//        catch(InterruptedException e)
//        {
//            System.out.println("Interrupted");
//        }
//        myThread2.start();
//        Thread ref = Thread.currentThread();
//        ref.setName("MainThread");
//        System.out.println("main() ends executed by " + Thread.currentThread().getName());
//    }
//}

// Runnable interface
//class MyThread implements Runnable
//{
//    int x;
//    MyThread()
//    {
//        x = 0;
//    }
//    MyThread(int x)
//    {
//        this.x = x;
//    }
//    public void run()
//    {
//        Thread ref = Thread.currentThread();
//        for (int i = 1; i <= 5; i++)
//        {
//            System.out.println("Thread " + ref.getName() + " is running " + i);
//        }
//    }
//}
//class MyProgram
//{
//    public static void main(String[] args)
//    {
//        Runnable ref = new MyThread();
//        Thread thread1 = new Thread(ref, "thread1");
//        Thread thread2 = new Thread(ref, "thread2");
//        thread1.start();
//        // If we don't use sleep then both the threads will execute simultaneously, so the output could be mixed data
//        try {
//            Thread.sleep(1000);
//        }
//        catch(InterruptedException e)
//        {
//            System.out.println("Interrupted");
//        }
//        thread2.start();
//    }
//}

// isAlive():
//class MyThread extends Thread
//{
//    int x;
//    MyThread()
//    {
//        x = 0;
//    }
//    MyThread(int x)
//    {
//        this.x = x;
//    }
//    public void run()
//    {
//        Thread ref = Thread.currentThread();
//        for (int i = 1; i <= 5; i++)
//        {
//            System.out.println("Thread " + ref.getName() + " is running");
//        }
//    }
//}
//class MyProgram
//{
//    public static void main(String[] args)
//    {
//        MyThread myThread1 = new MyThread(10);
//        MyThread myThread2 = new MyThread(20);
//        myThread1.start();
//        while(myThread1.isAlive())
//        {
//            // Do nothing
//        }
//        myThread2.start();
//        while(myThread1.isAlive())
//        {
//            // Do nothing
//        }
//        Thread ref = Thread.currentThread();
//        ref.setName("MainThread");
//        System.out.println("main() ends executed by " + Thread.currentThread().getName());
//    }
//}

// join():
//class MyThread extends Thread
//{
//    int x;
//    MyThread()
//    {
//        x = 0;
//    }
//    MyThread(int x)
//    {
//        this.x = x;
//    }
//    public void run()
//    {
//        Thread ref = Thread.currentThread();
//        for (int i = 1; i <= 5; i++)
//        {
//            System.out.println("Thread " + ref.getName() + " is running");
//        }
//    }
//}
//class MyProgram
//{
//    public static void main(String[] args) throws InterruptedException  // Used because of join() method
//    {
//        MyThread myThread1 = new MyThread(10);
//        MyThread myThread2 = new MyThread(20);
//        myThread1.start();
//        myThread1.join();
//        myThread2.start();
//        myThread2.join();
//        Thread ref = Thread.currentThread();
//        ref.setName("MainThread");
//        System.out.println("main() ends executed by " + Thread.currentThread().getName());
//    }
//}

//class MyThread extends Thread
//{
//    volatile boolean flag = true;
//    public void run()
//    {
//        Thread ref = Thread.currentThread();
//        while (flag)
//        {
//            System.out.println( ref.getName());
//        }
//    }
//}
//class MyProgram
//{
//    public static void main(String[] args)
//    {
//        MyThread myThread = new MyThread();
//        Thread thread1 = new Thread(myThread);
//        Thread thread2 = new Thread(myThread);
//        thread1.start();
//        try {
//            Thread.sleep(1);
//        }
//        catch(InterruptedException e)
//        {
//            System.out.println("Interrupted");
//        }
//        myThread.flag = false;
//    }
//}

// Synchronization:
//class MyThread implements Runnable
//{
//    int count = 1;
//    @Override
//    public void run()
//    {
//        this.increment();
//    }
//    synchronized public void increment()
//    {
//        for(int i=0;i<10;i++)
//        {
//            System.out.println(Thread.currentThread().getName()+": "+count);
//            count++;
//        }
//    }
//}
//class MyProgram
//{
//    public static void main(String[] args) throws InterruptedException
//    {
//        MyThread ref = new MyThread();
//        Thread thread1 = new Thread(ref, "Thread1");
//        Thread thread2 = new Thread(ref, "Thread2");
//        thread1.start();
//        thread2.start();
//    }
//}

//class Container
//{
//    int num;
//    boolean flag;  // false -> container is empty, true -> container has data
//    synchronized public void produce(int data) throws InterruptedException
//    {
//        // If container has data, producer must wait
//        while(flag)
//        {
//            wait();
//        }
//        Thread ref = Thread.currentThread();
//        num = data;
//        System.out.println(ref.getName() + " Produced  : " + num);
//        flag = true;  // Mark container has data
//        notifyAll();  // Wake up consumer
//    }
//    synchronized public void consume() throws InterruptedException
//    {
//        // If container is empty, consumer must wait
//        while(!flag)
//        {
//            wait();
//        }
//        Thread ref = Thread.currentThread();
//        System.out.println(ref.getName() + " Consumed  : " + num);
//        flag = false;  // mark container as empty
//        notifyAll();   // // wake up producer
//    }
//}
//
//class Producer extends Thread
//{
//    Container ref; // Reference to shared container
//    Thread t;
//    Producer(Container ct)
//    {
//        ref = ct;
//        t = new Thread(this, "Producer");
//    }
//    public void startProducer() // Starts the Producer thread
//    {
//        t.start();
//    }
//    public void run()
//    {
//        try{
//            int data = 1;
//            while(true)  // If container is empty → producer produce, Else → Producer keeps checking again and again, that's called polling
//            {
//                ref.produce(data);
//                data++;
// //                if(!ref.flag)
// //                {
// //                    ref.produce(data);
// //                    data++;
// //                }
// //                else{
// //                    System.out.println("Producer is polling ");
// //                }
//            }
//        }
//        catch(InterruptedException e)
//        {
//            System.out.println(e);
//        }
//    }
//
//}
//
//class Consumer extends Thread
//{
//    Container ref;
//    Thread t;
//    Consumer(Container ct)
//    {
//        ref = ct;
//        t = new Thread(this, "Consumer");
//    }
//    public void startConsumer()
//    {
//        t.start();
//    }
//    public void run()
//    {
//        try{
//            while(true)
//            {
//                ref.consume();
// //                if(ref.flag) //If data exists → consume, Else → consumer keeps checking
// //                {
// //                    ref.consume();
// //                }
// //                else{
// //                    System.out.println("Consumer is polling ");
// //                }
//            }
//        }catch(InterruptedException e)
//        {
//            System.out.println(e);
//        }
//    }
//}
//}
//class Program
//{
//    public static void main(String args[]) throws InterruptedException
//    {
//        Container ct = new Container();
//        Producer pro = new Producer(ct);
//        Consumer con = new Consumer(ct);
//
//        pro.startProducer();
//        con.startConsumer();
//
//        Thread.sleep(10);
//        System.exit(0);
//    }
//}

public class Multithreading
{

}
