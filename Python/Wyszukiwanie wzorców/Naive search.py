"""Lab nrA4, zadanie 1, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 11.05.2021r."""
from math import floor
from time import time


# ----------2D matrix--1D matrix
def naive_search(file, seq):
    """
    This function provides naive search for any pattern in any 2D matrix of any literal signs.
    It compares each piece of matrix character by character to spot 2D pattern existence in input nested list.
    :param file: 2D matrix of characters - nested list
    :param seq: list of characters to be found
    :return: Prints location of any found pattern as well as shift needed to get to the element in 1D list
    """
    width = len(file[0])
    piece = len(seq)

    if piece > len(file):
        print("Sequence passed into function is longer than text file itself!")
        return

    # flatten matrix
    flat_list = sum(file, [])

    if type(seq) == 'str':
        seq = list(seq)

    # outer loop looks for e.g. 'ASDAVV....S' sequence
    counter = 1
    for x in range(0, len(flat_list) - piece):
        if flat_list[x:x+piece] == seq:
            try:
                checksum = 0
                # inner loop checks if in line under first element of sequence the sequence itself exists
                for y in range(1, piece):
                    if flat_list[x + y * width] == seq[y]:
                        checksum += 1
                        if checksum == piece - 1:
                            print(str(counter) + ". Pattern matched with translation of", x)
                            print("\tCoordinates: (" + str(floor(x/width)) + ", " + str(x % width) + ")")
                            counter += 1

            except IndexError:
                pass
                # IndexError occurs when function reads last lines -> sequence can't exist


# Testing
"""
book = []
f = open('5000_pattern.txt', 'r')
i = 0
while i < 5000:
    book.append(list(f.readline()[:5000]))
    i += 1

start = time()
naive_search(book, ['A', 'B', 'C'])
stop = time()

print("Execution time:", stop - start, "sec.")
"""