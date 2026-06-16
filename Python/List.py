# Lists: A built in data type that stores set of values
# It can store elements of different types (integer, float, string, etc.)
# Lists are mutable
marks = [30, 20, 45, 40, 17]
print(marks)
print(marks[0])
print(type(marks))

# Python supports to store different types of data inside a single list
student = ["Swap", 22, 62.5, "DeMahi"]
# print(student)

# List slicing is same as String Slicing

# List methods:
# Changes made my list methods reflects to original list

marks.append(28)  # adds element at the end
# print(marks)

marks.sort()  # sorts in ascending order
marks.sort(reverse=True)  # sorts in descending order
marks.reverse()  # reverses the list
marks.insert(2, 100)  # elements in right from mentioned index moves right by one place and given index places at specified index
print(marks)
marks.remove(100)  # removes first occurence of element 
marks.pop(4)  # removes element present at given index
print(marks)

"""
movies = []
movies.append(input("First favorite movie: "))
movies.append(input("Second favorite movie: "))
movies.append(input("Thord favorite movie: "))
print(movies)
"""

# Palindrome or Not
"""
list1 = [10, 20, 30, 20, 10]
list2 = list1.copy()
list2.reverse()
if(list1 == list2):
    print(list1, "is palindrome")
else:
    print(list1, "is not palindrome")
"""