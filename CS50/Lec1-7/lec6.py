# Python
print("hello, world")

name = input("Enter your name: ")
print("hello" + name)
print(f"hello {name}")

# types - bool, int, float, str... range, list, tuple, dict, set

def sum():
    x = int(input("x: "))
    y = int(input("y: "))
    print(x + y)


first = input()
second = input()
# in C for the inputs that we wrote, even if we typed the same thign the conditiınal said different 
# sinc eit had different memory adresses, but it is not that way in PY
if(first == second):
    print("Same")
else:
    print("Different")


# in Object oriented programming, the variables can have functionality built into them
# in contrast, in C the functions requare only one variable to be passed 
s = input("Do you agree?").lower()
if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")

before = input("Before:")
print("After: ", end="") # end="" to avoid \n
for c in before:
    print(c.upper(), end="")
print() # to print a new line after the loop finishes


# the main function doesn't get called by itself 
def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("Meow")
main()


z=1/3
print(f"{z:.50f}")


# exceptions
def get_int(prompt):
    while True: 
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer") # you can just type "pass" to not type anything but continue to get input


def mario(num):
    while True:
        n = int(input("Height: "))
        if (n > 0):
            break
    for _ in range(num):
        print("#")


scores = []
for i in range (3):
    score = int(input("Score: "))
    scores = scores + [score] # scores.append(score)
average = sum(scores) / len (scores)
print (f"'Average: {average}")


names = ["Kaan", "Ahmet", "Purdue"]
name = input("Name")
for n in names:
    if name == n:
        print("found")
        break
else: 
    print("Not found") # in python the for loops can laso have a else clause

if name in names:
    print("Found")
else: 
    print("Not found") # in python the for loops can laso have a else clause


# dictionaries
people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"}, 
    {"name": "John", "number": "+1-949-468-2750"},
]
name_dic = input("Name: ")
for person in people:
    if person["name"] == name_dic:
        print(f"Found {person['number']}")
        break
else:
    print("Not found")


people_simpler = {
    "Carter": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}
name = input ("Name: ")
if name in people_simpler:
    number = people_simpler[name]
    print(f"Found {number}")
else:
    print("Not found")


# to use argv - from sys import argv