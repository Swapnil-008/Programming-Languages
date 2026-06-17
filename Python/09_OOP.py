# Object Oriented Programming (OOP):
# OOP is a programming paradigm where we design programs using classes and objects, combining data and behavior into a single unit to model real-world entities.

# Class and object
# Class is a blueprint for creating objects

# Creating class
# class Student:
#     name = "Swap"

# # Creating object
# s1 = Student()

# print(s1.name)

# __init__ function or constructor:
# All classes hava a function called __init__(), which is always executed when the object is being initiated
# Constructor always has one fixed parameter called self
# The self parameter is a reference to the current instance of the class, and is used to access variables that belongs to the class
# Parameters passed while creating an object are the attributes of an entity, except self
# If we didn't define any constructor for our class still it contains a default constructor provided by python
# If we defined the parameterized constructor for our class then python doesn't provide default constructor, so if our class requires default constructor we have to define it by ourself
"""
class Student:
    # Default constructor
    def __init__(self):
        pass
    # Parameterized constructor
    def __init__(self, name, age, rollNo):
        self.name = name
        self.age = age
        self.rollNo = rollNo

s1 = Student("swap", 22, 11008)
print(type(s1.name))
print(type(s1.age))
print(type(s1.rollNo))
"""

# Class and Instance attributes 

# Instance attributes -> These attributes are different for every object
# accessed by ObjectName.attributeName
# Class attributes -> These attributes are same for complete class, and only one copy of each attribute is created for complete class
# accessed by ClassName.attributeName
"""
class Student:
    college = "PICT"  # Class attribute
    # Parameterized constructor
    def __init__(self, name, age, rollNo):  # Instance attributes
        self.name = name
        self.age = age
        self.rollNo = rollNo
print(Student.college)  # accessing class attribute
S1 = Student("Swap", 22, 43178)
print(S1.name)   # accessing instance attribute
"""

# Methods
# Methods are functions that belong to objects

"""
class Student:
    college = "PICT"  # Class attribute
    # Parameterized constructor
    def __init__(self, name, age, rollNo):  # Instance attributes
        self.name = name
        self.age = age
        self.rollNo = rollNo

    # Non-static methods - works for object
    def welcomeStudent(self):
        print("Welcome,", self.name)

    def getName(self):
        return self.name
    
S1 = Student("Swap", 22, 43178)
S1.welcomeStudent()  # calling methods for S1 object
print(S1.getName())
"""

"""
class Student:
    college = "PICT"  # Class attribute
    # Parameterized constructor
    def __init__(self, name, age, rollNo, subjects):  # Instance attributes
        self.name = name
        self.age = age
        self.rollNo = rollNo
        self.subjects = subjects

    def welcomeStudent(self):
        print("Welcome,", self.name)

    def getSubjectsAvg(self):
        total = 0
        for x in self.subjects.values():
            total += x
        return total / len(self.subjects.values())

S1 = Student("Swap", 22, 43178, {"Physics": 98, "Chemistry": 91, "Maths": 85})
print(S1.getSubjectsAvg())

"""

# Static methods
# Methods that don't use self parameter and works for entire class, and not for any specific object

# Decorator allow us to wrap a function in order to extend the behaviour of the wrapped function, without permaently modifying it
"""
class Student:
    @staticmethod  # Decorator
    def sayHello():
        print("Hello students")

Student.sayHello()
"""

# OOP Pillars

# Abstraction:
# Hiding the implementation details of a class and only showing the essential features to the user

class Car:
    def __init__(self):
        self.__accelerate = False   # Made private
        self.__brake = False
        self.__clutch = False
    
    def startCar(self):
        self.__clutch = True
        self.__accelerate = True
        print("Car Started Successfully 🚗")

C1 = Car()
C1.startCar()  # User is just known to start the car, but for starting the car what is happening is completely hidden from user that's called abstraction

# Encapsulation:
# Encapsulation is the process of wrapping data (variables) and methods (functions) together into a single unit (class), and restricting direct access to some components.
class Car:
    def __init__(self):
        self.__speed = 0

    def accelerate(self):
        self.__speed += 10

    def getSpeed(self):
        return self.__speed
    
# User cannot directly do: car.__speed = 1000 

"""
class Account:
    def __init__(self, balance, account_no):
        self.__balance = balance
        self.__account_no = account_no

    def credit(self, amount):
        self.__balance += amount
        print("Rs.", amount, "credited!")

    def debit(self, amount):
        self.__balance -= amount
        print("Rs.", amount, "debited!")

    def print_balance(self):
        print("Available balance: Rs.", self.__balance, sep="")

account = Account(1000, 1108)
account.credit(500)
account.print_balance()
account.debit(845)
account.print_balance()
"""

# del keyword:
# It is used to delete object properties or object itself

# del S1.name  # deleting name property of S1 object
# del S1 # deleting s1 object itself

# Private(like) attributes and methods (Conceptual implementaions in python)
# Private attributes and methods are meant to be used only within the class and are not accessible from outside the class

class Person:
    def __init__(self, name, age):
        self.__name = name     # those two underscores before attribute name denotes private attribute
        self.__age = age

    def getName(self):
        return self.__name
    
    def __hello(self, name):   # private method
        print("Hello Person!", name)

    def welcome(self):
        self.__hello(self.__name)

P1 = Person("Swap", 22)
# print(P1.__name) # Since name is a private attribute, it will generate error

print(P1.getName())
# print(P1.__hello())   # private method is not accessible from outside the class
P1.welcome()

# Inheritance
# When one class (child/derived) derives the properties and methods of another class (parent/base)

class Car:
    @staticmethod
    def start():
        print("Car started...")

    @staticmethod
    def stop():
        print("Car stopped...")

class ToyotaCar(Car):
    def __init__(self, brand, color):
        self.brand = brand
        self.color = color

TC1 = ToyotaCar("Fortuner", "Black")
TC2 = ToyotaCar("Innova", "White")

# start and stop methods of car inherited in car
# print(TC1.brand)
# print(TC1.color)
# TC1.start()
# print(TC2.brand)
# print(TC2.color)
# TC2.start()
# TC1.stop()
# TC2.stop()

# Types of Inheritance
# Single Inheritance
# Multi-level Inheritance =>   GrandParent -> Parent -> Child
# Multiple Inheritance => Multiple classes gets inherited in a single class -> class C(A, B):   class A and B are inherited in class C

# Super method
# super() method is used to access methods of the parent class

class Car:
    def __init__(self, type):
        self.type = type

    @staticmethod
    def start():
        print("Car started...")

    @staticmethod
    def stop():
        print("Car stopped...")

class ToyotaCar(Car):
    def __init__(self, name, type):
        super().__init__(type)
        self.name = name
        super().start()

c1 = ToyotaCar("Fortuner", "Electric")
print(c1.type)

# Property
# We use @property decorator in the class to use the method as a property

class Student:
    def __init__(self, name, phy, chem, math):
        self.name = name
        self.phy = phy
        self.chem = chem
        self.math = math
        # self.percentage = str((self.phy + self.chem + self.math) / 3) + "%"

    @property
    def calPercentage(self):
        return str((self.phy + self.chem + self.math) / 3) + "%"

s1 = Student("Swap", 95, 98, 92)
# print(s1.percentage)
# s1.phy = 97
# print(s1.percentage)  # Now we have updated the marks of phy still we got same percentage as previous, bcoz percentage is calculated at the time of object creation, that's why we have to keep the percentage depends on subject marks dynamically

print(s1.calPercentage)
s1.phy = 87
print(s1.calPercentage)   # Now we can see the changes in percentage

# Polymorphism

# Operator Overloading:
# When the same operator allowed to have different meaning according to context.

class ComplexNumber:
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary

    def showNumber(self):
        print(self.real, "i + ", self.imaginary, "j", sep="")

    # Normal function
    # def add(self, num2):
    #     newReal = self.real + num2.real
    #     newImaginary = self.imaginary + num2.imaginary
    #     return ComplexNumber(newReal, newImaginary)

    # Dunder function
    def __add__(self, num2):
        newReal = self.real + num2.real
        newImaginary = self.imaginary + num2.imaginary
        return ComplexNumber(newReal, newImaginary)
    
    def __sub__(self, num2):
        newReal = self.real - num2.real
        newImaginary = self.imaginary - num2.imaginary
        return ComplexNumber(newReal, newImaginary)

num1 = ComplexNumber(4, 6)
num1.showNumber()
num2 = ComplexNumber(2, 3)
num2.showNumber()

# If we define a normal method of a class then we have to call like this for addition of two complex numbers
# num3 = num1.add(num2)
# num3.showNumber()

# But if we want to perform the addition of two complex numbers using just '+' operator then we have to overload that operator for ComplexNumber class, because arithmatetic operations can be performed with primitive datatypes only but objects are user defined datatypes, overloading an operator means writing a dunder function for it
# addition
num3 = num1 + num2
print("Addition: ", end="")
num3.showNumber()

# subtraction
num3 = num1 - num2
print("Subtraction: ", end="")
num3.showNumber()

# Dunder Functions:
# Dunder function means overloading an operator to work with user defined datatypes like object of class ComplexNumber in this example

# for addition obj1.__add__(obj2)

# Practice questions:

class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius * self.radius
    
    def perimeter(self):
        return 2 * 3.14 * self.radius
    
circle = Circle(10)
print("Area of circle:", circle.area())
print("Perimeter of circle:", circle.perimeter())

class Employee:
    def __init__(self, role, department, salary):
        self.role = role
        self.department = department
        self.salary = salary

    def showDetails(self):
        print(" ----- Employee Details -----")
        print("Role:", self.role)
        print("Department:", self.department)
        print("Salary:", self.salary)

class Engineer(Employee):
    def __init__(self, name, age, role, department, salary):
        super().__init__(role, department, salary)
        self.name = name
        self.age = age

    def showDetails(self): # Overriding parent method
        super().showDetails()
        print("Name:", self.name)
        print("Age:", self.age)

engineer = Engineer("Swapnil", "23", "Software Developer", "IT", 80000)
engineer.showDetails()

class Order:
    def __init__(self, items):
        self.items = items

    def __gt__(self, other):
        sum1 = 0
        sum2 = 0
        for price in self.items.values():
            sum1 += price
        for price in other.items.values():
            sum2 += price
        print("Price1:", sum1)
        print("Price2:", sum2)
        return sum1 > sum2
    
order1 = Order({"item1": 1000, "item2": 500, "item3": 985})
order2 = Order({"item1": 1200, "item2": 400, "item3": 755})

print(order1 > order2)