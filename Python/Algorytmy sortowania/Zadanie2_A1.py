"""Lab nr 1A, zadanie 2, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 20.04.2021r."""
from math import floor


def merge(arr_one, arr_two):
    """
    Merges two sorted lists in one sorted list

    :param arr_one: sorted list
    :param arr_two: other sorted list
    :return: new sorted list of all elements from both lists
    """
    try:
        result = []

        while len(arr_one) > 0 and len(arr_two) > 0:
            if arr_one[0] > arr_two[0]:
                result.append(arr_two[0])
                del arr_two[0]
            else:
                result.append(arr_one[0])
                del arr_one[0]

        while len(arr_one) > 0:
            result.append(arr_one[0])
            del arr_one[0]

        while len(arr_two) > 0:
            result.append(arr_two[0])
            del arr_two[0]

        return result
    except ValueError as e:
        print("Error while passing data into function\nInfo: ", e)


def mergesort(data):
    """
    Merge sort algorithm for lists

    :param data: list that should be sorted with merge sort algorithm
    :return: sorted list. If list has one element then there is no need to run whole algorithm
    """
    try:
        if len(data) <= 1:
            return data
        else:
            first_half = []
            second_half = []

            # If length of the list is an odd number then round down the division
            for i in range(0, floor(len(data)/2)):
                first_half.append(data[i])

            for j in range(floor(len(data)/2), len(data)):
                second_half.append(data[j])

            # recursively divides sub-arrays
            first_half = mergesort(first_half)
            second_half = mergesort(second_half)

            return merge(first_half, second_half)

    except ValueError as e:
        print("Error while passing data into function\nInfo: ", e)


