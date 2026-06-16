import java.util.Scanner;

public class Number
{
    int[] num;

    int[] createArray(int n)
    {
        return new int[n];
    }
    void scan()
    {
        System.out.println("Enter number: ");
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < num.length; i++)
        {
            num[i] = sc.nextInt();
        }
    }
    void display()
    {
        for (int x : num)
        {
            System.out.print(x + " ");
        }
    }
}

