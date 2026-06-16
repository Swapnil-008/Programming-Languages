import javax.management.QueryEval;
import java.util.*;

public class CollectionFramework
{
    // ##Collection:
    // ---------------------------------- List ---------------------------------
    // ArrayList:
    // It is defined to allow the user to add elements in the array dynamically
    // It is used when the user is not known from the size or number of elements to be added in the array while creating an array
    // It is from util package, We can't pass the primitive datatype, and in parentheses we can set the initial capacity / size
    // Integer, Boolean, Double these are Wrapper classes, wrapper class is an object version of a primitive datatype

    // Stack:
    // This is a data structure which follows LIFO principle
    // Recently entered element outs first

    // ---------------------------------- Queue --------------------------------
    // Queue:
    // This is a data structure which follows FIFO principle
    // Earlier entered element outs first
    // Queue can be implemented using list as well linked list

    // PriorityQueue:
    // It is type of Queue in which it sets some priority to an elements and according to that priority elements gets arranged
    // In that we can implement either min-heap or max-heap, min-heap keeps the minimum element on peek (elements in Ascending order), max-heap keeps the maximum element on peek (elements in Descending order)

    // ArrayDeque:
    // It is a type of queue which supports to insert and remove from both ends of the queue

    // ------------------------------------- Set --------------------------------
    // HashSet:
    // It keeps only one frequency of each element
    // Elements get arranged in random order

    // LinkedHashSet:
    // It follows the linked list properties and keep the elements in order

    // TreeSet:
    // It arranges the elements in sorted order

    // -------------------------------------##Map:-------------------------------
    // HashMap:
    // It used to store the elements in key, value pairs
    // Elements gets stored in random order

    // TreeMap:
    // It also stores the elements in key, value pairs
    // Elements gets stored in sorted order

    // ##Arrays:
    // This class provides different functionalities over arrays

    public static void main(String[] args)
    {
        // ArrayList:
//        ArrayList<String> students = new ArrayList<String>(2);
//        students.add("Swapnil");
//        students.add("Swapnil");
//        System.out.println(System.identityHashCode(students));
//        students.add("Swapnil");   // While adding this element JVM allocates a new internal array with a larger size and copies the existing elements into it. The reference to the ArrayList object remains the same, only its internal storage changes
//        System.out.println(System.identityHashCode(students)); // It gives the same reference as before adding the third element
//        System.out.println(students);
//        List<Integer> numbers = new ArrayList<Integer>(2);
//        numbers.add(1);
//        numbers.add(2);
//        System.out.println(numbers);
//        numbers.add(1, 100);  // Adding element at particular index
//        System.out.println(numbers);
//        numbers.set(1, 50); // It sets the mentioned value on passed index
//        System.out.println(numbers.contains(50));  // It returns true if mentioned element present in list
//        for(int i = 0; i < numbers.size(); i++)  // For iterating the ArrayList
//        {
//            System.out.print(numbers.get(i) + " ");
//        }
//        System.out.println();
//        // Iterating through Iterator
//        Iterator<Integer>itr = numbers.iterator();
//        while(itr.hasNext())
//        {
//            System.out.print(itr.next() + " ");
//        }
//        System.out.println();
//        List<Integer> numbers2 = new ArrayList<Integer>(2);
//        numbers2.add(10);
//        numbers2.addAll(numbers);   // Add all elements of 'numbers' arrayList to numbers2
//        System.out.println(numbers2);
//        System.out.println(numbers2.get(2));  // for getting element of specific index
//        numbers2.remove(2);  // It removes the element of numbers2 list having index 2
//        System.out.println(numbers2);
//        numbers2.remove(Integer.valueOf(10));  // It removes the first occurrence of element having the value mentioned in parameter
//        System.out.println(numbers2);
//        numbers2.clear();   // It removes all the elements from the list

        // Stack:
//        Stack<Integer> stack = new Stack<Integer>();
//        stack.push(1);   // It pushes the element into stack
//        stack.push(2);
//        stack.push(3);
//        System.out.println(stack);
//        System.out.println(stack.peek());  // It returns top element of the stack
//        System.out.println(stack.pop());   // It removes and returns top element from the stack

        // Queue:
//        Queue<Integer> queue = new LinkedList<Integer>();
//        queue.offer(10);  // For inserting an element add() is an alternative method, but it is quite risky because if the element doesn't get inserted due to some reason then it generates exception
//        queue.offer(20);  // where the offer() method just returns false for unsuccessful insertion, true for successful insertion from both methods
//        System.out.println(queue.offer(30));;  // returns true on successful insertion
//        System.out.println(queue);
//        System.out.println(queue.peek());   // It returns top element of the queue or next element getting popped, and returns null if the queue is an empty
//        System.out.println(queue.poll());   // It removes and returns front element from the queue
//        // peek()  <--> element()
//        // poll()  <--> remove() --> offer, poll, peek are safe methods that return special values, while add, remove, element throw exceptions on failure.

        // PriorityQueue:
        // Min-Heap -
//        PriorityQueue<Integer> pqueue = new PriorityQueue<Integer>();
//        pqueue.offer(10);
//        pqueue.offer(20);
//        pqueue.offer(5);
//        pqueue.offer(25);
//        System.out.println(pqueue);
//        System.out.println(pqueue.poll());

        // Max-Heap -
//        PriorityQueue<Integer> pqueue = new PriorityQueue<Integer>(Comparator.reverseOrder());
//        pqueue.offer(10);
//        pqueue.offer(20);
//        pqueue.offer(5);
//        pqueue.offer(25);
//        System.out.println(pqueue);
//        System.out.println(pqueue.poll());

        // ArrayDeque:
//        ArrayDeque<Integer> deque = new ArrayDeque<Integer>();
//        deque.offerFirst(1);
//        deque.offerFirst(2);
//        deque.offerLast(5);     // alternative deque.offer()
//        deque.offerLast(6);
//        System.out.println(deque);
//        System.out.println(deque.peek());
//        System.out.println(deque.pollFirst());    // alternative deque.poll()
//        System.out.println(deque.pollLast());

        // HashSet:
//        Set<Integer> set = new HashSet<Integer>();
//        set.add(1);
//        set.add(20);
//        set.add(15);
//        set.add(30);
//        set.add(20);
//        System.out.println(set);
//        set.remove(15);
//        System.out.println(set);
//        System.out.println(set.contains(15));

        // LinkedHashSet:
//        Set<Integer> set = new LinkedHashSet<Integer>();
//        set.add(1);
//        set.add(2);
//        set.add(3);
//        set.add(4);
//        set.add(5);
//        System.out.println(set);

        // TreeSet:
//        Set<Integer> set = new TreeSet<Integer>();
//        set.add(15);
//        set.add(23);
//        set.add(5);
//        set.add(1);
//        set.add(10);
//        set.add(20);
//        set.add(30);
//        System.out.println(set);

        // Set with user defined data structure
//        Set<Student> set = new HashSet<Student>();
//        set.add(new Student(10, "Swapnil"));
//        set.add(new Student(12, "Tanvi"));
//        set.add(new Student(15, "Sunny"));
//        set.add(new Student(15, "Sunny"));  // This entry will be discarded due to equals and hashcode methods of student class
//        System.out.println(set);

        // HashMap:
//        Map<String, Integer> map = new HashMap<String, Integer>();
//        map.put("a",1);
//        map.put("b",2);
//        map.put("c",3);
//        System.out.println(map);
//        // map.put("b",20);  // It will override the value of the key "b" as it contained already
//        if(!map.containsKey("b"))   // It will prevent the key from overriding its previous value
//        {
//            map.put("b",20);
//        }
//        map.putIfAbsent("b", 20);   // for avoiding the above if condition
//        // For iterating the map with map entries
//        for(Map.Entry<String, Integer> entry: map.entrySet())
//        {
//            System.out.println(entry);
//            // System.out.println(entry.getKey());  // for getting key only
//            // System.out.println(entry.getValue());  // for getting value only
//        }
//        for(String key: map.keySet())  // this iterates the map with keys only
//        {
//            System.out.println(key);
//        }
//        for(Integer value: map.values()) // this iterates the map with values only
//        {
//            System.out.println(value);
//        }
//        System.out.println(map.containsKey("b"));  // it checks whether key is present in map or not
//        System.out.println(map.containsValue(10)); // it checks whether value is present in map or not

        // TreeMap:
//        Map<String, Integer> map = new TreeMap<String, Integer>();
//        map.put("f", 6);
//        map.put("b", 2);
//        map.put("c", 3);
//        map.put("a", 1);
//        map.put("d", 4);
//        System.out.println(map);
//        for(Map.Entry<String, Integer> entry: map.entrySet())
//        {
//            System.out.println(entry);
//        }
//        map.remove("c");   // If the key is present in the map, it gets removed
//        for(Map.Entry<String, Integer> entry: map.entrySet())
//        {
//            System.out.println(entry);
//        }

        // Arrays:
//        int[] numbers = {30, 20, 10, 40, 15, 25, 45, 32};
//        Arrays.sort(numbers);
//        for (int i = 0; i < numbers.length; i++)
//        {
//            System.out.print(numbers[i] + " ");
//        }
//        System.out.println();
//        int index = Arrays.binarySearch(numbers, 50);
//        System.out.println(index);

        // Collections:

//        List<Integer>list = new ArrayList<Integer>();
//        list.add(10);
//        list.add(2);
//        list.add(32);
//        list.add(4);
//        list.add(25);
//
//        System.out.println("Min element: " + Collections.min(list));
//        System.out.println("Max element: " + Collections.max(list));
//        System.out.println(Collections.frequency(list, 3));
//        System.out.println(list);
//        Collections.sort(list, Comparator.reverseOrder());
//        System.out.println(list);

        List<Student> list = new ArrayList<Student>();
        list.add(new Student(10, "Ramesh"));
        list.add(new Student(5, "Akash"));
        list.add(new Student(2, "Shivam"));
        list.add(new Student(7, "Akash"));
        list.add(new Student(3, "David"));
        list.add(new Student(12, "Karan"));
        System.out.println(list);
//        Collections.sort(list, new Comparator<Student>()
//        {
//            @Override
//            public int compare(Student o1, Student o2)
//            {
//                return o1.name.compareTo(o2.name);  // same as compareTo method
//            }
//        });
        //Sorting students by name in ascending and rollNo in descending
        Collections.sort(list, new Comparator<Student>()
        {
            @Override
            public int compare(Student o1, Student o2)
            {
                int nameCompare = o1.name.compareTo(o2.name);
                if(nameCompare != 0)
                {
                    return nameCompare;
                }
                return Integer.compare(o2.rollNo, o1.rollNo);
            }
        });
        System.out.println(list);
    }
}

class Student implements Comparable<Student>
{
    int rollNo;
    String name;
    public Student(int rollNo, String name)
    {
        this.rollNo = rollNo;
        this.name = name;
    }

    @Override
    public String toString()
    {
        return "\nStudent: {" + "rollNo=" + rollNo + ", name='" + name + '}';
    }
    // Because of these methods, no any duplicate student object could be added in HashSet having same rollNo and name
    @Override
    public boolean equals(Object o)
    {
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return rollNo == student.rollNo && Objects.equals(name, student.name);
    }
    @Override
    public int hashCode()
    {
        return Objects.hash(rollNo, name);
    }
    @Override
    public int compareTo(Student o)
    {
        // this represents current student and o represents another student,
        // if we return this.rollNo - o.rollNo, it is used to sort in ascending order, if it is positive then it swaps the current student with another student, otherwise there is no need to swap
        // if we return o.rollNo - this.rollNo, it is used to sort in descending order, if it is negative then it swaps the current student with another student, otherwise there is no need to swap
        // for comparing string return this.name.compareTo(o.name);
        return this.rollNo - o.rollNo;
    }
}