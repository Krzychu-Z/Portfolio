"""Lab nrA4, zadanie 2, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 11.05.2021r."""
from math import floor
from time import time

# ----------2D matrix--1D matrix
def rabin_karp_search(file, seq):
    """
    This function provides Rabin-Karp algorithm for searching 2D patterns in any 2D matrix of any literal signs.
    It evaluates key for each sequence and then compares it with the key evaluated from searched pattern.
    Should the keys be identical algorithm performs regular comparison of fragment with seeked pattern.
    :param file: 2D matrix of characters - nested list
    :param seq: list of characters to be found
    :return: Prints location of any found pattern as well as shift needed to get to the element in 1D list
    """
    width = len(file[0])
    piece = len(seq)
    seq_key = 0
    region_key = 0
    para = 1

    if piece > len(file):
        print("Sequence passed into function is longer than text file itself!")
        return

    # Value of parameter
    for x in range(0, piece - 1):
        para = (para * 16) % 13

    # flatten matrix
    flat_list = sum(file, [])

    # Initial hash values
    for x in range(0, piece):
        seq_key = (16*seq_key + int(seq[x], 16)) % 13
        region_key = (16*region_key + int(flat_list[x], 16)) % 13

    # iterate across txt
    counter = 1
    for x in range(0, len(flat_list) - piece):
        if seq_key == region_key:
            if flat_list[x:x+piece] == seq:
                try:
                    checksum = 0
                    # Inner loop checks if in line under first element of sequence the sequence itself exists
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

        # Region_key for next iteration
        if x < (len(flat_list) - piece):
            region_key = (16 * (region_key - (int(flat_list[x], 16) * para)) + int(flat_list[x + piece], 16)) % 13

            # Negative region_key conversion:
            if region_key < 0:
                region_key = region_key + 13


# Testing
"""
book = []
f = open('5000_pattern.txt', 'r')
i = 0
while i < 5000:
    book.append(list(f.readline()[:5000]))
    i += 1

start = time()
rabin_karp_search(book, ['A', 'B', 'C'])
stop = time()

print("Execution time:", stop - start, "sec.")
"""