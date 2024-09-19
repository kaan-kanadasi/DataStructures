import csv
from collections import Counter

# flat-file databases 
# with keyword automatically closes the file as soon as we are out of the scope of with block
with open("/workspaces/DataStructures/CS50/Lec7/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    scratch,c,python = 0,0,0
    print("File is beaing read")

    for row in reader:
        print(row["language"])

    for row in reader:
        favorite = row["language"]
        if (favorite == "Scratch"):
            scratch +=1
        elif(favorite == "C"):
            c += 1
        else:
            python += 1

    
    counts = {} # creates an empty dictionary
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1
    

    counts_otherWay = Counter()
    for row in reader:
        favorite = row["language"]
        counts_otherWay[favorite] += 1


for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")

for favorite in sorted(counts, key =counts.get, reverse=True): # sorted by value
    print(f"{favorite}: {counts[favorite]}")

for favorite, count in counts_otherWay.most_common():
    print(f"{favorite}: {count}")