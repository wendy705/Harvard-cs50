from csv import reader, DictReader
from sys import argv

if len(argv) < 3:
    print("usage error: missing argument in dna.py sequence.txt database.csv")
    exit()

#read the dna sequence from the file and set each row in the list
with open(argv[2]) as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dnalist = row

#store it in a string
dna = dnalist[0]
#create a dictionary to store the sequences we intend to count
sequences = {}

#extract the sequences from the database and set them into a list
with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break

#copy the list in a dictionary where the genes are the keys
for item in dnaSequences:
    sequences[item] = 1

#iterate trough the dna sequence, when it finds repetitions of the values from sequence dictionary it counts them
for key in sequences:
    l = len(key)
    maxSeq = 0
    seq = 0
    for i in range(len(dna)):
        #after having counted a sequence it skips at the end of it to avoid counting again
        while seq > 0:
            seq -= 1
            continue

        #if the segment of dna corresponds to the key and there is a repetition of it we start counting
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                seq += 1
                i += l

            #it compares the value to the previous longest sequence and if it is longer it overrides it
            if seq > maxSeq:
                maxSeq = seq

    #store the longest sequences in the dictionary using the correspondent key
    sequences[key] += maxSeq

#open and iterate trough the database of people treating each one like a dictionary so it can compare them to the sequences
with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        #compares the sequences to every person and prints their name before leaving the program if there is a match
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")