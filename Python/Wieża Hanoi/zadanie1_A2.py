"""Lab nr A2, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 27.04.2021r."""
from zadanie2_A2 import iter_hanoi
from time import time


# zadanie 1

pole_s = list(range(1, 5))
pole_b = []
pole_d = []
i = 0

# if starting pole is integer or string -> turn that into list
if isinstance(pole_s, int) or isinstance(pole_s, str):
    tmp = pole_s
    pole_s = [tmp]

# sort pole_s decreasingly
pole_s = sorted(pole_s, reverse=True)


def recursive_hanoi(src, dest, buff, n):
    """
    Recursive hanoi tower solving algorithm. In order for this to work properly src list must be sorted
    decreasingly therefore sorting is performed first to ensure proper algorithm execution
    :param src: source list - starting pole
    :param dest: buffer list - buffer pole
    :param buff: destination list - destination pole
    :param n: number of rings in hanoi tower
    :return: empty src, empty buff, full dest
    """
    global i

    if n > 0:
        recursive_hanoi(src, buff, dest, n - 1)
        i += 1

        dest.append(src.pop())
        print("source:", pole_s, "buffer:", pole_b, "destination:", pole_d, "\tstep no:", i)

        recursive_hanoi(buff, dest, src, n - 1)


start = time()
# uncomment line below in order to solve problem using iterative algorithm
# pole_s, pole_b, pole_d = iter_hanoi(pole_s, pole_b, pole_d)
recursive_hanoi(pole_s, pole_d, pole_b, len(pole_s))
stop = time()
print(round(stop - start, 4), "sec.")
