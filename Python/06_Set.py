# Set:
# Set is a mutable
# Set is the collection of unordered items
# Each item in the set must be unique and immutable (int, float, boolean, str, tuple)
# List, Dictionary are mutable that's why we can't add into sets

collection = {1, 2, 5, 10, 5, "hello"}
print(collection)  # it ignores duplicates, and keep it only once

emptySet = set() # empty set syntax

# Set methods:
collection.add(15)  # adds element
collection.remove(10)  # removes element, generates error if specified element not found
collection.add((1, 2, 5))
print(collection)
# To observe the pop() method results
# collection.pop()
# print(collection)
# collection.pop()
# print(collection)
# collection.pop()
# print(collection)

# Elements are stored randomly in set, pop() removes the first element from the order of set
# It seems pop() removes element randomly
# collection.add([10, 15])  # genarates error as we are inserting list in set

# collection.clear()  # It makes empty to set

collection2 = {5, 10, 1, 2, 3, 18}
print(collection.union(collection2))  # combines both set values and returns new set
print(collection.intersection(collection2))  # combines common values and returns new 

set1 = {"python", "java", "C++", "python", "javascript", "java", "python", "java", "C++", "C"}
print(set1)
print(len(set1))

set2 = set()
set2.add(int(9))
set2.add(float(9.0))
print(set2)

# List = [], Tuple = (), Dictionary = {}