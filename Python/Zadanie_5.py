"""Lab nr1, zadanie 5, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 16.03.2021r."""
import random

# Tic-Tac-Toe
# Tried OOP but 'Cracow was not built in a day'
"""
class Field:
    # state = 0 - empty field, 1 - cross, 2 - circle
    state = 0
"""

# Board as a list of 9 fields
board = [0, 0, 0, 0, 0, 0, 0, 0, 0]


# subtask 1
def graphicboard():
    print("\n")

    for i in [0, 3, 6]:
        print("-" + str(i + 1) + "----" + str(i + 2) + "----" + str(i + 3) + "----")
        print("| X " if board[i] == 1 else "| O " if board[i] == 2 else "|   ",
              "| X " if board[i + 1] == 1 else "| O " if board[i + 1] == 2 else "|   ",
              "| X " if board[i + 2] == 1 else "| O " if board[i + 2] == 2 else "|   ",
              "|")

    print("----------------")


# subtask 2    sign - circle or cross
def fieldfiller(sign):
    # Checks for available moves
    count = 1
    # Used to relate possible movement number with real position in 'board' list
    mydict = {}

    for b in range(0, 9):
        if board[b] == 0:
            print("[" + str(count) + "]Possible movement to position number:", b + 1)
            mydict[count] = b
            count += 1

    # Takes movement of player as a number written in [] brackets

    while True:
        try:
            choice = int(input("Your choice: "))
        except ValueError:
            print("Typed in something different than number. Try again!")
            continue
        else:
            # Correct input
            if sign == 1:
                board[mydict[choice]] = 1
                break
            else:
                board[mydict[choice]] = 2
                break


# subtask 3      sign_1 - circle or cross
def seeresultfor(sign_1):

    # Tie
    if board[0] != 0 and board[1] != 0 and board[2] != 0 and board[3] != 0 and board[4] != 0 and board[5] != 0 and board[6] != 0 and board[7] != 0 and board[8] != 0:
        print("Tie! Nobody wins!")
        return 0

    # | X | X | X | (horizontal)
    for d in [0, 3, 6]:
        if board[d] == sign_1 and board[d + 1] == sign_1 and board[d + 2] == sign_1:
            print("X's won!" if sign_1 == 1 else "O's won!" if sign_1 == 2 else "Error occurred!")
            return 0

    # vertical
    for l in [0, 1, 2]:
        if board[l] == sign_1 and board[l + 3] == sign_1 and board[l + 6] == sign_1:
            print("X's won!" if sign_1 == 1 else "O's won!" if sign_1 == 2 else "Error occurred!")
            return 0

    # diagonal 1
    if board[0] == sign_1 and board[4] == sign_1 and board[8] == sign_1:
        print("X's won!" if sign_1 == 1 else "O's won!" if sign_1 == 2 else "Error occurred!")
        return 0

    # diagonal 2
    if board[2] == sign_1 and board[4] == sign_1 and board[6] == sign_1:
        print("X's won!" if sign_1 == 1 else "O's won!" if sign_1 == 2 else "Error occurred!")
        return 0


# subtask 4
def algorithmcross(turn):
    pos1 = random.choice([0, 2, 3, 5, 6, 8])

    if turn == 1:
        board[pos1] = 1
        return 0
    elif turn == 3:
        # next position free
        if (pos1 == 0 or pos1 == 3 or pos1 == 6) and board[pos1 + 1] == 0:
            board[pos1 + 1] = 1
            return 0
        # next position taken
        elif (pos1 == 0 or pos1 == 6) and board[pos1 + 1] == 2:
            board[3] = 1
            return 0
        elif pos1 == 3 and board[pos1 + 1] == 2:
            board[0] = 1
            return 0

        # symmetric case
        if (pos1 == 2 or pos1 == 5 or pos1 == 8) and board[pos1 - 1] == 0:
            board[pos1 - 1] = 1
            return 0
        # next position taken
        elif (pos1 == 2 or pos1 == 8) and board[pos1 - 1] == 2:
            board[5] = 1
            return 0
        elif pos1 == 5 and board[pos1 - 1] == 2:
            board[2] = 1
            return 0

    # general algorithm
    else:
        # searching for double X
        # | X | X | X | (horizontal)
        for d in [0, 3, 6]:
            if board[d] == 1 and board[d + 1] == 1 and board[d + 2] == 0:
                board[d + 2] = 1
                return 0
            elif board[d] == 1 and board[d + 1] == 0 and board[d + 2] == 1:
                board[d + 1] = 1
                return 0
            elif board[d] == 0 and board[d + 1] == 1 and board[d + 2] == 1:
                board[d] = 1
                return 0

        # | O | O | O | (horizontal)
        for d in [0, 3, 6]:
            if board[d] == 2 and board[d + 1] == 2 and board[d + 2] == 0:
                board[d + 2] = 1
                return 0
            elif board[d] == 2 and board[d + 1] == 0 and board[d + 2] == 2:
                board[d + 1] = 1
                return 0
            elif board[d] == 0 and board[d + 1] == 2 and board[d + 2] == 2:
                board[d] = 1
                return 0

        # vertical X
        for l in [0, 1, 2]:
            if board[l] == 1 and board[l + 3] == 1 and board[l + 6] == 0:
                board[l + 6] = 1
                return 0
            elif board[l] == 1 and board[l + 3] == 0 and board[l + 6] == 1:
                board[l + 3] = 1
                return 0
            elif board[l] == 0 and board[l + 3] == 1 and board[l + 6] == 1:
                board[l] = 1
                return 0

        # vertical O
        for l in [0, 1, 2]:
            if board[l] == 2 and board[l + 3] == 2 and board[l + 6] == 0:
                board[l + 6] = 1
                return 0
            elif board[l] == 2 and board[l + 3] == 0 and board[l + 6] == 2:
                board[l + 3] = 1
                return 0
            elif board[l] == 0 and board[l + 3] == 2 and board[l + 6] == 2:
                board[l] = 1
                return 0

        # diagonal X 1
        if board[0] == 1 and board[4] == 1 and board[8] == 0:
            board[8] = 1
            return 0
        elif board[0] == 1 and board[4] == 0 and board[8] == 1:
            board[4] = 1
            return 0
        elif board[0] == 0 and board[4] == 1 and board[8] == 1:
            board[0] = 1
            return 0

        # diagonal O 1
        if board[0] == 2 and board[4] == 2 and board[8] == 0:
            board[8] = 1
            return 0
        elif board[0] == 2 and board[4] == 0 and board[8] == 2:
            board[4] = 1
            return 0
        elif board[0] == 0 and board[4] == 2 and board[8] == 2:
            board[0] = 1
            return 0

        # diagonal X 2
        if board[2] == 1 and board[4] == 1 and board[6] == 0:
            board[6] = 1
            return 0
        elif board[2] == 1 and board[4] == 0 and board[6] == 1:
            board[4] = 1
            return 0
        elif board[2] == 0 and board[4] == 1 and board[6] == 1:
            board[2] = 1
            return 0

        # diagonal O 2
        if board[2] == 2 and board[4] == 2 and board[6] == 0:
            board[6] = 1
            return 0
        elif board[2] == 2 and board[4] == 0 and board[6] == 2:
            board[4] = 1
            return 0
        elif board[2] == 0 and board[4] == 2 and board[6] == 2:
            board[2] = 1
            return 0

        # middle taking
        if board[4] == 0:
            board[4] = 1
            return 0

        # random taking
        for m in range(0, 9):
            if board[m] == 0:
                board[m] = 1
                return 0


def algorithmcircle(turn):
    pos1 = random.choice([0, 2, 3, 5, 6, 8])

    if turn == 2:
        if board[pos1] == 0:
            board[pos1] = 2
            return 0
        elif pos1 == 0:
            board[0] = 2
            return 0
        elif pos1 == 2:
            board[0] = 2
            return 0
        elif pos1 == 3:
            board[0] = 2
            return 0
        elif pos1 == 5:
            board[2] = 2
            return 0
        else:
            board[0] = 2
            return 0

    # general algorithm
    else:
        # searching for double O
        # | O | O | O | (horizontal)
        for d in [0, 3, 6]:
            if board[d] == 2 and board[d + 1] == 2 and board[d + 2] == 0:
                board[d + 2] = 2
                return 0
            elif board[d] == 2 and board[d + 1] == 0 and board[d + 2] == 2:
                board[d + 1] = 2
                return 0
            elif board[d] == 0 and board[d + 1] == 2 and board[d + 2] == 2:
                board[d] = 2
                return 0

        # | X | X | X | (horizontal)
        for d in [0, 3, 6]:
            if board[d] == 1 and board[d + 1] == 1 and board[d + 2] == 0:
                board[d + 2] = 2
                return 0
            elif board[d] == 1 and board[d + 1] == 0 and board[d + 2] == 1:
                board[d + 1] = 2
                return 0
            elif board[d] == 0 and board[d + 1] == 1 and board[d + 2] == 1:
                board[d] = 2
                return 0

        # vertical O
        for l in [0, 1, 2]:
            if board[l] == 2 and board[l + 3] == 2 and board[l + 6] == 0:
                board[l + 6] = 2
                return 0
            elif board[l] == 2 and board[l + 3] == 0 and board[l + 6] == 2:
                board[l + 3] = 2
                return 0
            elif board[l] == 0 and board[l + 3] == 2 and board[l + 6] == 2:
                board[l] = 2
                return 0

        # vertical X
        for l in [0, 1, 2]:
            if board[l] == 1 and board[l + 3] == 1 and board[l + 6] == 0:
                board[l + 6] = 2
                return 0
            elif board[l] == 1 and board[l + 3] == 0 and board[l + 6] == 1:
                board[l + 3] = 2
                return 0
            elif board[l] == 0 and board[l + 3] == 1 and board[l + 6] == 1:
                board[l] = 2
                return 0

        # diagonal O 1
        if board[0] == 2 and board[4] == 2 and board[8] == 0:
            board[8] = 2
            return 0
        elif board[0] == 2 and board[4] == 0 and board[8] == 2:
            board[4] = 2
            return 0
        elif board[0] == 0 and board[4] == 2 and board[8] == 2:
            board[0] = 2
            return 0

        # diagonal X 1
        if board[0] == 1 and board[4] == 1 and board[8] == 0:
            board[8] = 2
            return 0
        elif board[0] == 1 and board[4] == 0 and board[8] == 1:
            board[4] = 2
            return 0
        elif board[0] == 0 and board[4] == 1 and board[8] == 1:
            board[0] = 2
            return 0

        # diagonal O 2
        if board[2] == 2 and board[4] == 2 and board[6] == 0:
            board[6] = 2
            return 0
        elif board[2] == 2 and board[4] == 0 and board[6] == 2:
            board[4] = 2
            return 0
        elif board[2] == 0 and board[4] == 2 and board[6] == 2:
            board[2] = 2
            return 0

        # diagonal X 2
        if board[2] == 1 and board[4] == 1 and board[6] == 0:
            board[6] = 2
            return 0
        elif board[2] == 1 and board[4] == 0 and board[6] == 1:
            board[4] = 2
            return 0
        elif board[2] == 0 and board[4] == 1 and board[6] == 1:
            board[2] = 2
            return 0

        # middle taking
        if board[4] == 0:
            board[4] = 2
            return 0

        # random taking
        for m in range(0, 9):
            if board[m] == 0:
                board[m] = 2
                return 0


# main
kolejka = 1

while True:
    try:
        if kolejka == 1:
            start = int(input("Pick cross[1] or circle[2].\n"))
        else:
            pass
    except ValueError:
        print("Picked something different than 1 or 2. Try again!")
        continue
    else:
        # Correct input
        if start == 1:
            graphicboard()
            print("Turn number: " + str(kolejka) + "\nYour move!")
            fieldfiller(start)
            seeresultfor(1)
            seeresultfor(2)
            graphicboard()
            if seeresultfor(1) == 0:
                break
            kolejka += 1
            print("Turn number: " + str(kolejka) + "\nComputer's move!")
            algorithmcircle(kolejka)
            seeresultfor(1)
            seeresultfor(2)
            if seeresultfor(1) == 0:
                graphicboard()
                break
            kolejka += 1
        elif start == 2:
            print("Turn number: " + str(kolejka) + "\nComputer's move!")
            algorithmcross(kolejka)
            graphicboard()
            seeresultfor(1)
            seeresultfor(2)
            if seeresultfor(1) == 0:
                break
            kolejka += 1
            print("Turn number: " + str(kolejka) + "\nYour move!")
            fieldfiller(start)
            seeresultfor(1)
            seeresultfor(2)
            if seeresultfor(1) == 0:
                graphicboard()
                break
            kolejka += 1
            graphicboard()
        else:
            print("Picked different value than 1 or 2. Try again!")
            continue
