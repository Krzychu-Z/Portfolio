"""Lab nr 1A, zadanie 1, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 20.04.2021r."""
from random import randint
from time import time
from Zadanie2_A1 import mergesort


def insertionsort(args):

    for i in range(1, len(args)):
        tmp = args[i]
        j = i - 1

        while j >= 0 and args[j] > tmp:
            args[j + 1] = args[j]
            j = j - 1

        args[j + 1] = tmp

    return args


""" Zadanie 3 """
insertion_times = []
merge_times = []


i = 0
while i < 200:
    collection = []

    # drawing numbers
    a = 0
    while a < 25000:
        collection.append(randint(-10000, 10000))
        a += 1

    # insertion sort
    start = time()
    ordered = insertionsort(collection)
    stop = time()

    # merge sort
    start_merge = time()
    ordered_m = mergesort(collection)
    stop_merge = time()

    insertion_times.append(stop - start)
    merge_times.append(stop_merge - start_merge)

    i += 1

print("Time of 200 x insertion sort on 25000 long list of int:", round(sum(insertion_times)/60, 4), "minutes")
print("Time of 200 x merge sort on 25000 long list of int:", round(sum(merge_times)/60, 4), "minutes")
print("\nAverage time of insertion sort:", round(sum(insertion_times)/200, 4), "seconds")
print("Average time of merge sort:", round(sum(merge_times)/200, 4), "seconds")
print("\nFastest execution of insertion sort:", round(min(insertion_times), 4), "seconds")
print("Fastest execution of merge sort:", round(min(merge_times), 4), "seconds")
print("\nSlowest execution of insertion sort:", round(max(insertion_times), 4), "seconds")
print("Slowest execution of merge sort:", round(max(merge_times), 4), "seconds")


"""--------- Intel Core i5-6200U CPU @ 2,30GHz without parallelization

Time of 200 x insertion sort on 25000 long list of int: 143.9245 minutes
Time of 200 x merge sort on 25000 long list of int: 1.0273 minutes

Average time of insertion sort: 43.1773 seconds
Average time of merge sort: 0.3082 seconds

Fastest execution of insertion sort: 37.3015 seconds
Fastest execution of merge sort: 0.212 seconds

Slowest execution of insertion sort: 66.8441 seconds
Slowest execution of merge sort: 0.7958 seconds

"""
