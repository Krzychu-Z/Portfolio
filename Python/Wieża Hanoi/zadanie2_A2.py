"""Lab nr A2, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 27.04.2021r."""


# zadanie 2
def iter_hanoi(src, buff, dest):
    """
    Iterative hanoi tower solving algorithm. In order for this to work properly src list must be sorted
    decreasingly therefore sorting is performed first to ensure proper algorithm execution
    :param src: source list - starting pole
    :param buff: buffer list - buffer pole
    :param dest: destination list - destination pole
    :return: empty src, empty buff, full dest
    """
    if isinstance(src, int) or isinstance(src, str):
        tmp = src
        src = [tmp]

    src = sorted(src, reverse=True)

    n = len(src)
    i = 1
    print("source:", src, "buffer:", buff, "destination:", dest, "\tstep no:", i - 1)
    while len(src) > 0 or len(buff) > 0:
        # Algorithm for odd length of hanoi towers
        if n % 2 == 1:
            if i % 3 == 1:
                # according to the algorithm there is no way both src and dest are empty when number of step % 3 == 1
                if len(dest) == 0:
                    dest.append(src[-1])
                    del src[-1]
                elif len(src) == 0:
                    src.append(dest[-1])
                    del dest[-1]
                else:
                    if dest[-1] > src[-1]:
                        dest.append(src[-1])
                        del src[-1]
                    else:
                        src.append(dest[-1])
                        del dest[-1]
            elif i % 3 == 2:
                # according to the algorithm there is no way both src and buff are empty when number of step % 3 == 2
                if len(buff) == 0:
                    buff.append(src[-1])
                    del src[-1]
                elif len(src) == 0:
                    src.append(buff[-1])
                    del buff[-1]
                else:
                    if buff[-1] > src[-1]:
                        buff.append(src[-1])
                        del src[-1]
                    else:
                        src.append(buff[-1])
                        del buff[-1]
            else:
                # according to the algorithm there is no way both dest and buff are empty when number of step % 3 == 0
                if len(dest) == 0:
                    dest.append(buff[-1])
                    del buff[-1]
                elif len(buff) == 0:
                    buff.append(dest[-1])
                    del dest[-1]
                else:
                    if dest[-1] > buff[-1]:
                        dest.append(buff[-1])
                        del buff[-1]
                    else:
                        buff.append(dest[-1])
                        del dest[-1]

        # Algorithm for even length of hanoi towers
        elif n % 2 == 0:
            if i % 3 == 1:
                # according to the algorithm there is no way both src and buff are empty when number of step % 3 == 1
                if len(buff) == 0:
                    buff.append(src[-1])
                    del src[-1]
                elif len(src) == 0:
                    src.append(buff[-1])
                    del buff[-1]
                else:
                    if buff[-1] > src[-1]:
                        buff.append(src[-1])
                        del src[-1]
                    else:
                        src.append(buff[-1])
                        del buff[-1]
            elif i % 3 == 2:
                # according to the algorithm there is no way both src and dest are empty when number of step % 3 == 2
                if len(dest) == 0:
                    dest.append(src[-1])
                    del src[-1]
                elif len(src) == 0:
                    src.append(dest[-1])
                    del dest[-1]
                else:
                    if dest[-1] > src[-1]:
                        dest.append(src[-1])
                        del src[-1]
                    else:
                        src.append(dest[-1])
                        del dest[-1]
            else:
                # according to the algorithm there is no way both dest and buff are empty when number of step % 3 == 0
                if len(dest) == 0:
                    dest.append(buff[-1])
                    del buff[-1]
                elif len(buff) == 0:
                    buff.append(dest[-1])
                    del dest[-1]
                else:
                    if dest[-1] > buff[-1]:
                        dest.append(buff[-1])
                        del buff[-1]
                    else:
                        buff.append(dest[-1])
                        del dest[-1]

        i += 1
        print("source:", src, "buffer:", buff, "destination:", dest, "\tstep no:", i - 1)

    return src, buff, dest