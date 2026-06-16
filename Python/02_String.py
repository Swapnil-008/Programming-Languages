# Escape sequence characters: Special characters used for formating
# '\n' -> generates the new line
# '\t' -> adds the space bar
# str = "There is something hidden behind that wall.\nDon't \t you think?"
# print(str)

# Concatenation
str1 = "Hello"
str2 = " World"
print("Concatenation:", str1 + str2)

# Length
print("Length:", len(str1 + str2))

# Indexing
# Python follows 0 based indexing
# print("0th Character:", str1[0])
# Using indexing, we can only access characters of string, but we can't modify them
# Because strings are immutable in python, means their value can't be changed after creatiom
# str1[2] = 's'  -> It will generate error

# Slicing -> Accessing parts of a string
# str1[starting_index : ending_index] -> ending_index is not included
# print(str1[0 : 5])
# print(str1[0 : 5]) and print(str1( : 5)) both are same
# print(str1[0 : len(str)]) and print(str1[0 : ]) both are same

# Negative Indexing: 
# A  P  P  L  E
# 0  1  2  3  4  -> Positive Indexing
#-5 -4 -3 -2 -1  -> Negative Indexing

# str1 = "APPLE"
# print(str1[-5 : -2])

# Built-in functions of a string doesn't make change in the original string
# str1 = "I am a coder."

# print(str1.endswith("er."))  --> Returns True if string ends with passed substring

# print(str1.capitalize())  # Capitalizes the first character of a string

# print(str1.replace("P", "@")) # Replaces all occurances of first passed parameter string to second passed parameter string

# print(str1.find("a"))  # Returns first occurance index of a substring inside the string, -1 for not found

# print(str1.count("P")) # Returns count of occurance of a substring

# Find greatest number among three numbers
"""
num1 = int(input("Enter num1: "))
num2 = int(input("Enter num2: "))
num3 = int(input("Enter num3: "))

greatest = num1

if(num2 > greatest):
    greatest = num2

if(num3 > greatest):
    greatest = num3

print(greatest, "is the greatest among", num1, num2, num3)
"""