# Dictionary:
# Dictionaries are used to store data values in key:value pairs
# They are unordered, mutable, and don't allow duplicate keys

emptyDictionary = {}   # syntax for empty dictionary
info = {
    "key": "value",
    "name": "swap",
    "age": 22,
    "subjects": ["Python", "CPP", "JAVA"]
}
# info["age"] += 1  # mutable
# print(info["age"])
# info["subjects"].append("SQL")
# print(info["subjects"])
# print(type(info["subjects"]))

# Nested Dictionary
student = {
    "name": "swap",
    "languages": {
        "CPP": "DSA",
        "JAVA": "OOP",
        "PYTHON": "AI/ML",
        "JAVASCRIPT": "DEVELOPMENT",
        "SQL": "DATABASE"
    }
}
# student["languages"] -> This will return "languages" dictionary
# print(type(student["languages"]))
# print(student["languages"]["CPP"])

# Dictionary methods:

# print(student.keys())  # returns collection of keys
# print(student.values())  # returns collection of values
# print(student.items()) # returns collection of tuples or dictionary_items
# print(type(student.items()))
# items = list(student.items())
# print(type(items[0])) # tuple

print("Keys: ",list(info.keys()))  # returns collection of keys
print("Values: ", list(info.values()))  # returns collection of values
print("Items: ", list(info.items())) # returns collection of tuples or dictionary_items
print(type(info.items()))
items = list(info.items())
print(type(items[0])) # tuple

# print(student["name"]) # returns value of the key, if key not fouond it returns error
# print(student.get("name")) # returns value of the key, if key not found it returns none

student["age"] = 22  # if the key present it overrides the specified value to it, otherwise add new key-value pair in dictionary
student.update({"age": 22})  # if the key present it assigns the mentioned value to it, otherwise add new key-value pair in dictionary
print(student)

# Store following word meanings in a python dictionary : 

dict1 = {
    "table": ["a piece of furniture", "list of facts & figures"],
    "cat": "a small animal"
}

i = 0
student_marks = {}
while i < 3:
    subject = str(input("Enter subject: "))
    marks = int(input("Enter marks: "))
    student_marks[subject] = marks
    i = i + 1

print(student_marks)