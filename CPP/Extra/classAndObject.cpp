#include<iostream> 
#include<vector> 
#include<unordered_map> 
using namespace std; 

// Compile Time object creation using member function

// class Employee 
// { 
//     public: 
//     int age; 
//     char name[30]; 
//     char company[30]; 
//     void scanData() 
//     { 
//         cout<<"Enter name: "; 
//         cin.getline(name, 30); 
//         cout<<"Enter Company: "; 
//         cin.getline(company, 30); 
//         cout<<"Enter Age: "; 
//         cin>> age; 
//         cin.ignore(1); 
// cin.ignore() is used to remove the leftover newline character '\n' from the input buffer after cin >>, so that subsequent getline() calls work correctly
//     } 
//     void printData() 
//     { 
//         cout<<"Name: "<<name<<endl; 
//         cout<<"Age: "<<age<<endl; 
//         cout<<"Company: "<<company<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Employee Emp1, Emp2; 
//     Emp1.scanData(); 
//     Emp2.scanData(); 
//     Emp1.printData(); 
//     Emp2.printData();
//     return 0; 
// } 
 
// class Number 
// { 
//     public: 
//     int x, y; 
// }; 
 
// Number add(Number T1, Number T2) 
// { 
//     Number Ans; 
//     Ans.x = T1.x + T2.x; 
//     Ans.y = T1.y + T2.y; 
//     return Ans; 
// } 
 
// int main() 
// { 
//     Number T1, T2; 
//     T1.x = 10; 
//     T1.y = 15; 
//     T2.x = 20; 
//     T2.y = 25; 
//     Number T3 = add(T1, T2); 
//     cout<<"X: "<<T3.x<<" "<<"Y: "<<T3.y<<endl; 
 
//     return 0; 
// } 
 
//-------------------------------------------- Static Data memeber -------------------------------------- 

// Static data members always works for class and only copy creates of static data member on data section, so any changes made by any object will be reflect for all, since only one copy of it gets created.
// We can access the static data members using .operator also, but still it doesn't work for that calling object.
// It is necessary to declare the static data member just after completion of class.
// Default value of static data member is 0

// class Number 
// { 
//     public: 
//     int x; 
//     static int y; 
// }; 

// int Number::y = 10; 
// int main() 
// { 
//     Number N1, N2; 
//     N1.x = 10; 
//     N1.y = 20; 
//     N2.x = 15; 
//     N2.y = 25; 
//     cout<<N1.x<<" "<<N1.y<<endl; 
//     cout<<N2.x<<" "<<N2.y<<endl; 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     public: 
//     int x; 
//     static int y; 
//     static Number show() 
//     { 
//         // cout<<x<<endl; --> error Non-static data members are not directly accessible inside static member function 
//         cout<<y<<endl; 
//         cout<<"In show"<<endl; 
//         Number Temp; 
//         Temp.x = 10; 
//         return Temp; 
//     } 
//     void print() 
//     { 
//         x = 5; 
//     } 
// }; 
// int Number::y = 25; 
// int main() 
// { 
//     Number N1, N2; 
//     N1 = Number::show(); 
//     // N1.print(); 
//     cout<<N1.x<<" "<<N2.x<<endl; // 10 6422356 <- Garbage value
//     return 0; 
// } 
 
//----------------------------------------------- Friend Function ---------------------------------------- 

// A friend function is a non-member function that is declared using the friend keyword inside a class, allowing it to access the class’s private and protected members.
// The function is granted access rights, but it does not become part of the class.

// 1) Independent function as friend
// class Base  
// { 
//     private: 
//     int b; 
//     friend void calc(); 
// }; 
 
// class Power 
// { 
//     private: 
//     int p; 
//     friend void calc(); 
// }; 
 
// void calc() 
// { 
//     Base Base; 
//     Power Power; 
//     cout<<"Enter Base: "; 
//     cin>>Base.b; 
//     cout<<"Enter Power: "; 
//     cin>>Power.p; 
//     long long res = 1; 
//     for(int i = 1; i <= Power.p; i++) 
//     { 
//         res = res * Base.b; 
//     } 
//     cout<<"Result: "<<res<<endl; 
// } 
 
// int main() 
// { 
//     calc(); 
//     return 0; 
// } 

// 2) Member Function of Another Class as Friend
 
// class Power 
// { 
//     private: 
//     int p; 
//     public: 
//     void calc(); 
// }; 
// class Base  
// { 
//     private: 
//     int b; 
//     friend void Power::calc(); 
// }; 
 
// void Power::calc() 
// { 
//     Base Base; 
//     cout<<"Enter Base: "; 
//     cin>>Base.b; 
//     cout<<"Enter Power: "; 
//     cin>>p; 
//     long long res = 1; 
//     for(int i = 1; i <= p; i++) 
//     { 
//         res = res * Base.b; 
//     } 
//     cout<<"Result: "<<res<<endl; 
// } 
 
// int main() 
// { 
//     Power Power; 
//     Power.calc(); 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     private: 
//     int x, y; 
//     friend void scan(Number &temp); 
//     friend void print(Number temp); 
// }; 
 
// void scan(Number &temp) 
// { 
//     cout<<"Enter X and Y: "; 
//     cin>>temp.x>>temp.y; 
// } 
 
// void print(Number temp) 
// { 
//     cout<<temp.x<<" "<<temp.y; 
// } 
 
// int main() 
// { 
//     Number T; 
//     scan(T); 
//     print(T); 
 
//     return 0; 
// } 
 
// class Number; 
 
// class Digit 
// { 
//     public: 
//     void scan(Number &temp); 
//     void print(Number &temp); 
// }; 
 
// class Number 
// { 
//     private: 
//     int x, y; 
//     friend void Digit::scan(Number &temp); 
//     friend void Digit::print(Number &temp); 
// }; 
 
// void Digit::scan(Number &temp) 
// { 
//     cout<<"Enter X and Y: "; 
//     cin>>temp.x>>temp.y; 
// } 
 
// void Digit::print(Number &temp) 
// { 
//     cout<<"X: "<<temp.x<<" Y: "<<temp.y<<endl; 
// } 
 
// int main() 
// { 
//     Number Temp; 
//     Digit D; 
//     D.scan(Temp); 
//     D.print(Temp); 
 
//     return 0; 
// } 

// 3) Entire Class as Friend: All member functions of another class get access.

// class Number;  // -> forward declaration
// class Digit 
// { 
//     void print(Number Temp); 
//     public: 
// }; 
// class Number 
// { 
//     private: 
//     int x; 
//     friend class Digit;
//     friend int main();
// }; 
 
// void Digit::print(Number Temp) 
// { 
//     cout<<"Enter x: "; 
//     cin>>Temp.x; 
// } 
 
// int main() 
// { 
//     int *p = new int[1];  // int *p = new int(20); 
//     *p = 20; 
//     cout<<*p; 
//     Number *N1 = new Number();
//     N1->x = 10;
//     cout<<N1->x<<endl;
//     return 0; 
// } 
 
// The difference between accesing the members of an object using ->(arrow) and .(dot) 
// When there is an actual object and we want to access members of that object that time .(dot operator) 
// When there is a pointer of object and we want to access the members of that object that time ->(arrow operator)  
 
//--------------------------------------------- Composition ---------------------------------------------- 
 
// Composition is the part of OOP, in which we create the object of another class as a data member of a class 
 
// class Date 
// { 
//     public: 
//     int day, month, year; 
//     void scanDate() 
//     { 
//         cout<<"\nDay, Month, and Year: "; 
//         cin>>day>>month>>year; 
//     } 
//     void printDate() 
//     { 
//         cout<<day<<"-"<<month<<"-"<<year<<endl; 
//     } 
// }; 
 
// class Employee 
// { 
//     public: 
//     char name[30]; 
//     Date BirthDate; 
//     Date JoiningDate; 
//     void scanData() 
//     { 
//         cout<<"Enter Name: "; 
//         cin.getline(name, 30); 
//         cout<<"Enter BirthDate"; 
//         BirthDate.scanDate(); 
//         cout<<"Enter JoiningDate"; 
//         JoiningDate.scanDate(); 
//         cin.ignore(1); 
//     } 
//     void printData() 
//     { 
//         cout<<"\nName: "<<name<<endl; 
//         cout<<"BirthDate: "; 
//         BirthDate.printDate(); 
//         cout<<"JoiningDate: "; 
//         JoiningDate.printDate(); 
//     } 
// }; 
 
// int main() 
// { 
//     Employee Emp1; 
//     Emp1.scanData(); 
//     Emp1.printData(); 
 
//     return 0; 
// } 
 
//------------------------------------- Constant Member Function ---------------------------------------- 

// Constant member function is a concept of OOP in which we create the constant member function by suffixing const keyword with the declaration of function
// Calling object can't be changed in constant member function, because 'this' refers to the calling object and it doesn't allow to make changes in it.
// But it does not prevent modification of function parameters

// class Number 
// { 
//     public: 
//     int x; 
//     Number()
//     {
//         x = 0;
//     }
//     void change(Number& Temp) const 
//     { 
//         // x = x + 2;                             // Generates compile time error 
//         Temp.x = Temp.x + 5; 
//     } 
// }; 
 
// int main() 
// { 
//     Number T1, T2;
//     T1.change(T2);                               // T1 is calling object, so the data members of calling object can't be change in const member function 
//     T1.x = 10;                                   // valid to change 
//     cout<<T1.x<<" "<<T2.x;
//     return 0; 
// } 
 
//----------------------------------------- Constant Object --------------------------------------------- 
 
// Constant object is a concept of OOP in which we make the object constant by prefixing the const keyword while creating the object
// We can't update the properties of constant object after the declaration.
// Constant Objects can only call constant member functions, they can't call non-constant member functions 

// class Number 
// { 
//     public: 
//     int x; 
//     Number(int x)
//     {
//         this->x = x;
//     }
//     void updateX(Number& temp) const
//     {
//         temp.x = temp.x + 10;
//     }
// }; 
 
// int main() 
// { 
//     Number T1(5);
//     const Number Temp = {10}; 
//     Temp.updateX(T1);
//     // Temp.x = 20;                                 // Generates Error 

//     cout<<T1.x<<" "<<Temp.x;
//     return 0; 
// } 
 
//------------------------------------- Returning Calling Object ----------------------------------------- 
 
// 'this' is an inbult keyword which stores the address of calling object 
// 'this' keyword is used to refer the calling object

// class Number 
// { 
//     public: 
//     int x; 
//     Number change() 
//     { 
//         x = 10; 
//         return *this; 
//     } 
// }; 
 
// int main() 
// { 
//     Number T1, T2; 
//     T2 = T1.change(); 
//     cout<<T1.x<<"  "<<T2.x<<endl; 
 
//     return 0; 
// } 
 
//---------------------------------------------Nested Classes------------------------------------------ 
 
// class Outer 
// { 
//     public: 
//     int x; 
//     class Inner 
//     { 
//         public: 
//         static int y; 
//     }; 
//     Inner Temp; 
// }; 
 
// int Outer::Inner::y = 5; 
 
// int main() 
// { 
//     cout<<sizeof(Outer)<<endl; 
//     Outer Out; 
//     cout<<sizeof(Out)<<endl; 
 
//     Outer::Inner In; 
//     Out.x = 10; 
//     Outer::Inner::y = 20; 
//     In.y = 25; 
//     cout<<Out.x<<" "<<Outer::Inner::y<<endl; 
//     cout<<In.y; 
 
//     return 0; 
// } 
 
// If the Inner class is defined private then it will be accessible inside Outer class only, not inside any non-member function of Outer class 
 
// class Outer 
// { 
//     public: 
//     int x; 
//     class Inner 
//     { 
//         public: 
//         int y; 
//         void show(); 
//     }; 
//     Inner Temp; 
// }; 
 
// void Outer::Inner::show() 
// { 
//     cout<<y; 
// } 
 
// int main() 
// { 
//     Outer Out; 
//     Outer::Inner In; 
//     In.y = 10; 
//     In.show(); 
 
//     return 0; 
// } 

// class Outer 
// { 
//     public: 
//     int x; 
//     // private:
//     class Inner 
//     { 
//         public: 
//         int y; 
//         void show(); 
//     }; 
//     Inner Temp; 
//     // friend int main();
// }; 
 
// void Outer::Inner::show() 
// { 
//     cout<<y; 
// } 
 
// int main() 
// { 
//     Outer Out; 
//     Outer::Inner In; 
//     In.y = 10; 
//     In.show(); 
 
//     return 0; 
// } 
 
//-------------------------------------------- Local Classes -------------------------------------------- 
 
// Defining the class inside a function is called a local class of that function. 
// Not accessible outside the function. 
// Can't define the member function of local class outside the class. 
 
// int main() 
// { 
//     class Number 
//     { 
//         public: 
//         int x; 
//         void set() 
//         { 
//             x = 10; 
//         } 
//         void show() 
//         { 
//             cout<<x; 
//         } 
//     }; 
 
//     Number N1; 
//     N1.set(); 
//     N1.show(); 
 
//     return 0; 
// } 
 
// void print() 
// { 
//     Number Temp;                     //Generates error (unknown with Number) 
// } 
 
//-------------------------------------------- Constructor ----------------------------------------------- 
 
// Simple member function of a class having the same name as class with no return type. 
// There is no need to call the constuctor explicitly for execution of it's code, it automatically gets called on the creation of an object of a class. 
// Constuctor of the class should be public, otherwise we can't create the object of the class inside any non-member function of the class. 
// Constructor never get inherited. 
// Constructor can't be virtual. 
 
// class Number 
// { 
//     public: 
//     int x; 
//     Number() 
//     { 
//         cout<<"Object Created"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1, N2; 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 11; 
//         y = 22; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     void show() 
//     { 
//         cout<<x<<" "<<y<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1(10, 20), N2(15, 25); 
//     Number N3; 
//     N1.show(); 
//     N2.show(); 
//     N3.show(); 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         cout<<"In Default Constructor!"<<endl; 
//     } 
//     Number(int x, int y) 
//     { 
//         cout<<"In Parameterized Constructor"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1(); 
//     return 0; 
// } 
 
// When we pass object of same class as a parameter to it's own constructor, we call that constructor a copy constructor 
// Passed object must be caught by reference, otherwise compiler will generate error. 

// When an object is passed by value to a copy constructor, the compiler needs to create a copy of that object, 
// which again invokes the copy constructor, that leads to infinite recursion. Passing by reference avoids this extra copy and directly refer to the original object.

// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 10; 
//         y = 20; 
//         cout<<"In Default Constructor"<<endl; 
//     } 
//     Number(Number &Temp) 
//     { 
//         *this = Temp; 
//     } 
//     void show() 
//     { 
//         cout<<"X: "<<x<<"  "<<"Y: "<<y<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1; 
//     N1.show(); 
//     Number N2(N1);                          //Number N2 = N1    (both are same) 
//     N2.show(); 
//     return 0; 
// } 
 
// ------ Private Constructors ------ 
 
// 1) Independent Function 
 
// class Number 
// { 
//     private: 
//     Number() 
//     { 
//         x = 10; 
//     } 
//     public: 
//     int x; 
//     friend void set(); 
// }; 
 
// void set() 
// { 
//     Number temp; 
//     cout<<temp.x; 
// } 
 
// int main() 
// { 
//     set(); 
 
//     return 0; 
// } 
 
// 2) Member function of another class 
 
// class Digit 
// { 
//     public: 
//     void set(); 
// }; 
 
// class Number 
// { 
//     private: 
//     Number() 
//     { 
//         x = 10; 
//     } 
//     public: 
//     int x; 
//     friend void Digit::set(); 
// }; 
 
// void Digit::set() 
// { 
//     Number temp; 
//     cout<<temp.x; 
// } 
 
// int main() 
// { 
//     Digit D; 
//     D.set(); 
 
//     return 0; 
// } 
 
// Instead of making a friend function, we could make a member function static, so that for accessing from non-member function there will no need of creating an object. 
 
// class Number  
// { 
//     private: 
//     Number() 
//     { 
//         cout<<"Inside Default Constructor!"<<endl; 
//     } 
//     Number(int x) 
//     { 
//         cout<<"Inside Parameterized Constructor"<<endl; 
//         this->x = x; 
//     } 
//     public: 
//     int x; 
//     static void show() 
//     { 
//         Number Temp(10); 
//         cout<<Temp.x<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number::show(); 
 
//     return 0; 
// } 
 
// Default Copy Constructor 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 10; 
//         y = 20; 
//         cout<<"In Default Constructor"<<endl; 
//     } 
//     // Number(Number &Temp) 
//     // { 
//     //     cout<<"In Copy Constructor"<<endl; 
//     //     *this = Temp; 
//     // } 
//     void show() 
//     { 
//         cout<<"X: "<<x<<"  "<<"Y: "<<y<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1; 
//     Number N2 = N1; 
//     N2.show(); 
//     return 0; 
// } 
 
// Shallow Copy -> Just copies the address of the passed object to the calling object's data member  
// class Number 
// { 
//     public: 
//     int *ptr; 
//     Number() 
//     { 
//         ptr = new int(10); 
//         cout<<"In Default Constructor"<<endl; 
//     } 
//     Number(Number &Temp) 
//     { 
//         ptr = Temp.ptr; 
//         cout<<"In Copy Constructor"<<endl; 
//     } 
//     void show() 
//     { 
//         cout<<(long long)ptr<<" "<<*ptr<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1; 
//     Number N2 = N1; 
//     N1.show(); 
//     N2.show(); 
 
//     return 0; 
// } 
 
// Deep Copy -> Create new memory for data member of calling object and just copy the value of the passed object 
 
// class Number 
// { 
//     public: 
//     int *ptr; 
//     Number() 
//     { 
//         ptr = new int(10); 
//         cout<<"In Default Constructor"<<endl; 
//     } 
//     Number(Number &Temp) 
//     { 
//         ptr = new int(*Temp.ptr);           // *Temp.ptr -> accessing the content of a ptr data member
//         cout<<"In Copy Constructor"<<endl; 
//     } 
//     void show() 
//     { 
//         cout<<(long long)ptr<<" "<<*ptr<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1; 
//     Number N2 = N1; 
//     N1.show(); 
//     N2.show(); 
 
//     return 0; 
// } 

// A constructor cannot be static because it is responsible for initializing an object and operates on a specific instance through the this pointer, whereas a static function does not have a this pointer and is not associated with any particular object. 
//-------------------------------------------- Destructor ------------------------------------------------ 
 
// Destructor is used for the execution of a code at the time of object getting destroyed. It get's executed automatically 
// Can't pass parameter to destructor. 
// Destructors can't be inherited, static, and virtual. 
 
// class Number 
// { 
//     public: 
//     int x; 
//     Number(int x) 
//     { 
//         this->x = x; 
//         cout<<"Inside Constructor!, X: "<<x<<endl; 
//     } 
//     ~Number() 
//     { 
//         cout<<"Inside Destructor!, X: "<<x<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number *N1 = new Number(10); 
//     Number *N2 = new Number(20); 
//     Number N3(30); 
     
//     delete N1; 
//     delete N2; 
 
//     return 0; 
// } 
 
// int temp = 0; 
// class Number 
// { 
//     public: 
//     int x; 
//     Number() 
//     { 
//         x = temp; 
//         cout<<"Inside Constructor!, X: "<<x<<endl; 
//         temp++; 
//     } 
//     ~Number() 
//     { 
//         cout<<"Inside Destructor!, X: "<<x<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number *N = new Number[3]; 
//     delete []N; 
     
//     return 0; 
// } 
// // Inside Constructor!, X: 0 
// // Inside Constructor!, X: 1 
// // Inside Constructor!, X: 2 
// // Inside Destructor!, X: 2 
// // Inside Destructor!, X: 1 
// // Inside Destructor!, X: 0 
 
// Remember ------------------------------------------------------------------- 
 
// class Number 
// { 
//     public: 
//     int x; 
//     Number() 
//     { 
//         cout<<"Inside Default Constructor!: "<<(long long)this<<endl; 
//     } 
//     Number(Number &temp) 
//     { 
//         cout<<"Inside Copy Constructor!: "<<(long long)this<<endl; 
//     } 
// }; 
 
// void show(Number temp)   // Number& temp --> to avoid this unexpected behaviour
// { 
//     cout<<"Inside show: "<<(long long)&temp<<endl; 
// } 
 
// int main() 
// { 
//     Number N1; 
//     show(N1); 
 
//     return 0; 
// } 
 
// Internally it converted into temp = N1 (that's why it called copy constructor) 
// Inside Default Constructor! 
// Inside Copy Constructor! 
// Inside show 
// To avoid this exceptional behaviour, catch the object by reference, no new memory will be create  
 
//------------------------------------- Operator Overloading -------------------------------------------- 
 
// Used to treat user defined datatype as a premitive datatype to enable the user to perform the arithmetic operations on it. 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     void show() 
//     { 
//         cout<<"x: "<<x<<" y: "<<y<<endl; 
//     } 
// }; 
 
// Number operator+(Number t1, Number t2) 
// { 
//     Number res; 
//     res.x = t1.x + t2.x; 
//     res.y = t1.y + t2.y; 
//     return res; 
// } 
 
// int main() 
// { 
//     Number N1(10, 15), N2(20, 25); 
//     Number N3; 
//     N3 = N1 + N2; 
//     N3.show(); 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     // N3 = -N2
//     Number operator-() 
//     { 
//         Number ans; 
//         ans.x = -x; 
//         ans.y = -y; 
//         return ans;
//     }

//     //-N1
//     // void operator-() 
//     // {
//     //     x = -x; 
//     //     y = -y; 
//     // } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     void show() 
//     { 
//         cout<<"x: "<<x<<" y: "<<y<<endl; 
//     }
// }; 
 
// int main() 
// { 
//     Number N1(10, 15), N2(20, 25); 
//     Number N3(5, 10); 
//     // N1 = -N1;                        // Generates error for void operator()-
//     // -N1; 
//     N1.show(); 
//     N3 = -N3; 
//     N3.show(); 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     Number operator+(Number temp) 
//     { 
//         cout<<"In Overloaded Function"<<endl; 
//         Number ans; 
//         ans.x = x + temp.x; 
//         ans.y = y + temp.y; 
//         return ans; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1(10, 15), N2(20, 25), N4(30, 35); 
//     Number N3; 
//     N3 = N1 + N2 + N4;                            // Internally N3 = ans(N1 + N2) + N4; 
//     cout<<N3.x<<" "<<N3.y<<endl; 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     Number operator+(Number temp) 
//     { 
//         cout<<"In Overloaded Function +"<<endl; 
//         Number ans; 
//         ans.x = x + temp.x; 
//         ans.y = y + temp.y; 
//         return ans; 
//     } 
//     Number operator-(Number temp) 
//     { 
//         cout<<"In Overloaded Function -"<<endl; 
//         Number ans; 
//         ans.x = x - temp.x; 
//         ans.y = y - temp.y; 
//         return ans; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1(10, 15), N2(20, 25), N4(30, 35); 
//     Number N3; 
//     N3 = N1 - N2 + N4;                            // Internally N3 = ans(N1 - N2) + N4; 
//     cout<<N3.x<<" "<<N3.y<<endl; 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     int x, y; 
//     public: 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     friend Number operator++(Number temp); 
//     void show() 
//     { 
//         cout<<x<<" "<<y<<endl; 
//     } 
// }; 
 
// Number operator++(Number temp) 
// { 
//     cout<<"In Overloaded Function"<<endl; 
//     Number ans; 
//     ans.x = ++temp.x; 
//     ans.y = ++temp.y; 
//     return ans; 
// } 
 
// int main() 
// { 
//     Number N1(10, 15); 
//     Number N3; 
//     N3 = ++N1;                           
//     N3.show(); 
 
//     return 0; 
// } 
 
// Why independent function for operator overloading when we have member functions?? 
// While overloading binary operator, it is possible that LHS operand is a Non-object variable in that case we can't use member function to overload your binary operator. Because Non-object variable on LHS can't work as calling object. 
 
//Example. 
 
// class Number 
// { 
//     public: 
//     int x, y; 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     void show() 
//     { 
//         cout<<"x: "<<x<<" y: "<<y<<endl; 
//     } 
// }; 
 
// Number operator+(int a, Number t2) 
// { 
//     Number res; 
//     res.x = a + t2.x; 
//     res.y = a + t2.y; 
//     return res; 
// } 
 
// int main() 
// { 
//     Number N2(20, 25); 
//     Number N3; 
//     N3 = 10 + N2; 
//     N3.show(); 
 
//     return 0; 
// } 
 
// class Distance 
// { 
//     public: 
//     int km, mtr; 
//     Distance() 
//     { 
//         km = 0; 
//         mtr = 0; 
//     } 
//     Distance(int km, int mtr) 
//     { 
//         this->km = km; 
//         this->mtr = mtr; 
//     } 
// }; 
 
// void operator~(Distance &D) 
// { 
//     cout<<"Enter km and mtr: "; 
//     cin>>D.km>>D.mtr; 
// } 
 
// void operator!(Distance D) 
// { 
//     cout<<"km: "<<D.km<<" "<<"mtr: "<<D.mtr<<endl; 
// } 
 
// int main() 
// { 
//     Distance D1, D2; 
//     ~D1; 
//     ~D2; 
//     !D1; 
//     !D2; 
 
//     return 0; 
// } 
 
// Pre-increment 
// class Number 
// { 
//     int x, y; 
//     public: 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     friend void operator++(Number &temp); 
//     void show() 
//     { 
//         cout<<x<<" "<<y<<endl; 
//     } 
// }; 
 
// void operator++(Number &temp) 
// { 
//     cout<<"In Overloaded Function"<<endl; 
//     ++temp.x; 
//     ++temp.y; 
// } 
 
// int main() 
// { 
//     Number N1(10, 15); 
//     Number N3; 
//     ++N1;                           
//     N1.show(); 
 
//     return 0; 
// } 
 
// Post-increment 
// class Number 
// { 
//     int x, y; 
//     public: 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     friend void operator++(Number &temp, int a); 
//     void show() 
//     { 
//         cout<<x<<" "<<y<<endl; 
//     } 
// }; 
 
// void operator++(Number &temp, int a) 
// { 
//     cout<<"In Overloaded Function"<<endl; 
//     temp.x = temp.x + 1; 
//     temp.y = temp.y + 1; 
// } 
 
// int main() 
// { 
//     Number N1(10, 15); 
//     Number N3; 
//     N1++;                           
//     N1.show(); 
 
//     return 0; 
// } 
 
// class Number 
// { 
//     int x, y; 
//     public: 
//     Number() 
//     { 
//         x = 0; 
//         y = 0; 
//     } 
//     Number(int x, int y) 
//     { 
//         this->x = x; 
//         this->y = y; 
//     } 
//     // For independent function
//     // friend int operator==(Number temp1, Number temp2); 

//     int operator==(Number temp2) 
//     { 
//         if((x == temp2.x) && (y == temp2.y)) 
//         { 
//             return 1; 
//         } 
//         return 0; 
//     } 
//     void show() 
//     { 
//         cout<<x<<" "<<y<<endl; 
//     } 
// }; 
 
// int operator==(Number temp1, Number temp2) 
// { 
//     if((temp1.x == temp2.x) && (temp1.y == temp2.y)) 
//     { 
//         return 1; 
//     } 
//     return 0; 
// } 
 
// int main() 
// { 
//     Number N1(10, 15); 
//     Number N3(10, 15); 
//     cout<<(N1 == N3)<<endl;                        
//     N1.show(); 
//     N3.show();
 
//     return 0; 
// } 
 
// Overload Insertion and Extraction Operator ---------------------------------------------- 
 
//1) Using member function 
// If we overload the insertion operator using member function then cin will be calling object and we have to define that function inside istream class, but istream class is not accessible to us hence we can't overload the insertion and extraction operator using member function. 
 
// Always catch the object of cin and cout in overloaded function by reference, because the copy constructor inside istream and ostream classes is private. 
 
// Always return the object of overloaded operator to enable the cascading (cin>>D1>>D2 multiple times operator used), if the return type of overloaded function is void then we can't perform the cascading on that operator Ex. cin>>D1>>D2 so in operator overloading whenever we try to use the overloaded operator continously multiple times, it performs in parts like in above example first it will scan for cin>>D1 and then it will scan for cin>>D2, but if you returned nothing then it will be like nothing>>D2 which would cause error. (return the object by reference beacuse of the private copy constructor) 
 
// class Distance 
// { 
//     public: 
//     int km, mtr; 
//     void show() 
//     { 
//         cout<<"Km: "<<km<<" "<<"Mtr: "<<mtr<<endl; 
//     } 
//     double totalKm() 
//     { 
//         double tempKm = km + (mtr / 1000) + (double)(mtr % 1000) / 1000; 
//         return tempKm; 
//     } 
// }; 
 
// istream& operator>>(istream& cin, Distance &D)   // Caught object of distance class by reference to reflect changes in it
// { 
//     cout<<"Enter Km and Mtr: "; 
//     cin>>D.km>>D.mtr; 
//     return cin; 
// } 
 
// ostream& operator<<(ostream& cout, Distance D) 
// { 
//     cout<<"Km: "<<D.km<<" "<<"Mtr: "<<D.mtr<<endl; 
//     return cout; 
// } 
 
// int main() 
// { 
//     Distance D1, D2; 
//     cin>>D1>>D2; 
//     cout<<D1<<D2; 
 
//     return 0; 
// } 

//---------------------------------------- Inheritance ------------------------------------------------ 
 
// Child class inherites the Properties of Parent class. 
// In child object Memory will allocate to all the data-member of child class as well as all the data-members of parent class, no matter what are the access specifiers they have.
// Actually, private date memebers of parent class also inherites into class internally, but child class can't access them.
// Protected members of a class are not accessible inside non-member function of any class. 
// We use protected when we want attributes must be inherit into child class but should not be accesible in non-member function of child class. 

// 👉 Inheritance is one of the four pillars of OOP. It allows a child (derived) class to acquire the properties and behaviors (data members and member functions) of a parent (base) class, so the child class does not need to redefine them, reducing code redundancy and improving reusability.

// 👉 There are mainly four types of inheritance:

// Single inheritance – a class inherits from one base class
// Multilevel inheritance – a chain like grandparent → parent → child
// Multiple inheritance – a class inherits from more than one base class
// Hierarchical inheritance – multiple classes inherit from a single base class

// 👉 Regarding memory allocation, memory is allocated for all data members of both base and derived classes, regardless of the access specifier used during inheritance (public, protected, or private).

// class Parent 
// { 
//     private: 
//     int x; 
//     void show(); 
//     public: 
//     int y; 
//     void disp(); 
//     protected: 
//     int z; 
//     void print(); 
// }; 
 
// class Child : public Parent 
// { 
//     public: 
//     int w; 
// }; 
 
// int main() 
// { 
//     Child child; 
//     cout<<sizeof(child); 
 
//     return 0; 
// } 
 
// class Parent 
// { 
//     private: 
//     int x; 
//     void show(); 
//     public: 
//     int y; 
//     void disp() 
//     { 
//         x = 10; 
//         cout<<"In Disp() x: "<<x<<endl; 
//     } 
// }; 
 
// class Child : public Parent 
// { 
//     public: 
//     int w; 
// }; 
 
// int main() 
// { 
//     Child child; 
//     cout<<sizeof(child)<<endl; 
//     child.disp(); 
 
//     return 0; 
// } 
 
// Ambiguity in Inheritance ------------------------------------------------- 
 
// 1) Single Inheritance 
// class Parent 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Parent show()"<<endl; 
//     } 
// }; 
 
// class Child : public Parent 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Child show()"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Child child; 
//     child.show(); 
//     child.Parent::show(); 
 
//     return 0; 
// } 
 
// 2) Multiple Inheritance 
// If we don't define the show fn in child class and inherites the show of parent1 and parent2, then if try to access the show inherited in child by child.show() then it will generate error, ambiguity between parent1 show and parent2 show

// class Parent1 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Parent1 show()"<<endl; 
//     } 
// }; 
 
// class Parent2 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Parent2 show()"<<endl; 
//     } 
// }; 
 
// class Child : public Parent1, public Parent2 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Child show()"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Child child; 
//     child.show(); 
//     child.Parent1::show(); 
//     child.Parent2::show(); 
 
//     return 0; 
// } 
 
// Constructor in Inheritance 
// When we create an object of child class, constructors of all the parent classes of child class will get executed first and then constuctor of child class will get executed. 
// For calling the parameterized constructor of Child class, you have to use child class parameterized constructor 
 
// class Parent 
// { 
//     public: 
//     Parent(int temp) 
//     { 
//         cout<<"In Parent Constructor"<<endl; 
//         cout<<temp<<endl; 
//     } 
//     void show() 
//     { 
//         cout<<"In Parent show()"<<endl; 
//     } 
// }; 
 
// class Child : public Parent 
// { 
//     public: 
//     int y; 
//     Child():Parent(10) 
//     { 
//         cout<<"In Child Constructor"<<endl; 
//     } 
//     void show() 
//     { 
//         cout<<"In Child show()"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Child child; 
//     child.show(); 
//     child.Parent::show(); 
 
//     return 0; 
// } 
 
//We can't pass the data member of a child class as a parameter to parent class constructor, if we pass, then a garbage value will be passed. 
 
//In case of virtual parent classes, Constructors of virtual parent classes get execute first and then non-virtual parent classes get executed. 
 
// class Parent1 
// { 
//     public: 
//     Parent1() 
//     { 
//         cout<<"In parent1 constructor"<<endl; 
//     } 
//     void show() 
//     { 
//         cout<<"In Parent1 show()"<<endl; 
//     } 
// }; 
 
// class Parent2 
// { 
//     public: 
//     Parent2() 
//     { 
//         cout<<"In parent2 constructor"<<endl; 
//     } 
//     void show() 
//     { 
//         cout<<"In Parent2 show()"<<endl; 
//     } 
// }; 
 
// class Child : public Parent1, public virtual Parent2 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Child show()"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Child child; 
//     child.show(); 
//     child.Parent1::show(); 
//     child.Parent2::show(); 
 
//     return 0; 
// } 
 
// Diamond Problem ----------------------------------------------------- 
 
// When a grand class inherites into multiple parent classes, and multiple parent classes inherites into single child class, there multiple copies of members of grand class creates in child class, while accesing the members directly using child object generates ambinguity, we can solve that ambiguity error using membership identity lable, but still logically it is not correct a class having a multiple copies of same members, so to avoid the creation of multiple copies we use virtual class concept, in that when parent classes inherit the grand class, inherites it as a virtual class, which will ensure that while inherites into child class, child class has only one copy of those members. 

// without virtual class 
// class Grand 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Grand Show()"<<endl; 
//     } 
// }; 
 
// class Parent1 : public  Grand 
// { 
 
// }; 
 
// class Parent2 : public Grand 
// { 
 
// }; 
 
// class Child : public Parent1, public Parent2 
// { 
     
// }; 
 
// int main() 
// { 
//     Child child; 
//     // child.show();                                        //Generates ambiguity error 
//     child.Parent1::show(); 
//     child.Parent2::show(); 
 
//     return 0; 
// } 
 
// with virtual class 
// while inheriting -> to use 'virtual' the sequence can be 'virtual public Parent' or 'public virtual Parent' 
// class Grand 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Grand Show()"<<endl; 
//     } 
// }; 
 
// class Parent1 : public virtual Grand 
// { 
 
// }; 
 
// class Parent2 : public virtual Grand 
// { 
       
// }; 
 
// class Child : public Parent1, public Parent2 
// { 
     
// }; 
 
// int main() 
// { 
//     Child child; 
//     child.show(); 
 
//     return 0; 
// } 
 
// While using virtual for class we have to follow some rules: 
// 1) Use virtual keyword when a base class is inherited through multiple paths, to avoid multiple copies in the child. 
// 2) Every path from Grand → Child must use virtual inheritance; otherwise, multiple copies of the base will appear. 
// 3) Partial virtual inheritance is useless – if one parent uses virtual and another does not, the child will still get duplicate copies. 
// 4) All inheritance paths from base to child must declare the base as virtual for multiple inheritance cases. 
// 5) Using virtual on non-base parents is unnecessary – only apply it to the common base (Grand) being inherited. 
 
//Destructor execute exactly in the opposite sequence of constructor. 
 
//--------------------------------------Initializatoin List-------------------------------------------- 
 
// class Number 
// { 
//     public: 
//     int a, b; 
//     Number() 
//     { 
//         a = 0; 
//         b = 0; 
//     } 
//     Number(int x, int y) : b(a + 3), a(y) 
//     { 
//         cout<<"In parameterized Constructor"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Number N1(5, 10); 
//     cout<<N1.a<<" "<<N1.b<<endl; 
 
//     return 0; 
// } 
 
//------------------------------------------Polymorphism----------------------------------------------- 
 
// Polymorphism -> many forms 
// There are two types of polymorphism: 
 
// 1) Compiletime Polymorphism: 
// In our program every function is connected with correct function defination. When this job of connecting function call with correct function defination is done by compiler then we call it compiletime polymorphism. To do this compiler always works with datatype of variable. 
//Function overloading, operator overloading, and template; 
 
// class Parent 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Parent Show()"<<endl; 
//     } 
// }; 
 
// class Child : public Parent 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Child Show()"<<endl; 
//     } 
// }; 
 
// // Here for checking the correct function defination compiler checks the datatype of pc and pp. 
// // In Child Show() 
// // In Parent Show() 
// int main() 
// { 
//     Parent parent; 
//     Child child; 
//     Child *pc; 
//     Parent *pp; 
//     pc = &child; 
//     pp = &parent; 
//     pc->show(); 
//     pp->show(); 
//     return 0; 
// } 
 
// class Parent 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Parent Show()"<<endl; 
//     } 
// }; 
 
// class Child : public Parent 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Child Show()"<<endl; 
//     } 
// }; 
 
// // Here for checking the correct function defination compiler checks the datatype of pc and pp. 
// // In Parent Show() 
// // In Parent Show() 
// int main() 
// { 
//     Parent parent; 
//     Child child; 
//     Parent *pp; 
//     pp = &parent; 
//     pp->show(); 
//     pp = &child; 
//     pp->show(); 
 
//     return 0; 
// } 
 
// Rule of polymorphism --------------------------------------------------- 
// A pointer of class can store the address of it's own object and it can store address of object of all those classes which are directly or indirectly derived from your class. 
// Ex. Grand *pg;  then pg can store the address of all the parent and child classes's object of it's hierarchy. 
// Ex. Parent *pp; then pp can store the address of it's own object or child class's object, but can't store the addres of object of grand class. 
 
// 2) Runtime Polymorphism: 
// In our program every function is connected with correct function defination. When this job of connecting function call with correct function defination is done by executer we call it runtime polymorphism. 
// To do this executer checks the content of variable and not the datatype of variable. 
// Ex. Function overriding. 
 
// There are some conditions for runtime polymorphism, which must be satisfied: 
// i)Multilevel Inheritance 
// ii)Over-riden function 
// iii)Copy of over-ridden function in top-most base class must be virtual. 
// iv)Pointer to base class are required. 
 
// class Parent 
// { 
//     public: 
//     virtual void show() 
//     { 
//         cout<<"In Parent show()"<<endl; 
//     } 
// }; 
 
// class Child : public Parent 
// { 
//     public: 
//     void show() 
//     { 
//         cout<<"In Child show()"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Parent parent; 
//     Child child; 
//     Parent *pp; 
//     pp = &parent; 
//     pp->show(); 
//     pp = &child; 
//     pp->show(); 
 
//     return 0; 
// } 
 
// It focuses on the content of the variable not on the datatype of the variable. 
// In Parent show() 
// In Child show() 
 
//----------------------------------------- Abstact class --------------------------------------------- 
 
// When we define pure virtual function inside a class, that class is called abstract class. 
// When we define a function prefixed with virtual keyword and assign '0' (= 0) to declaration of function, we call that function a pure virtual function. function don't have body. 
//we can't create the object of abstract class 
//It can contain normal data members and member functions also, still we can't create the object of it. 
// The derived class which inherits abstract class must have to define all the pure virtual functions from abstract class. If derived class doesn't define pure virtual functions from abstact class, the derived class also becomes abstract class. 
// We use this concept mostly to implement restrictions on derived class (they have to define pure virtual function)  
 
// class Vehicle 
// { 
//     public: 
//     virtual void start() = 0; 
// }; 
 
// class Car : public Vehicle 
// { 
//     public: 
//     void start() 
//     { 
//         cout<<"Car is starting!"<<endl; 
//     } 
// }; 
 
// int main() 
// { 
//     Car car; 
//     car.start(); 
 
//     return 0; 
// } 
