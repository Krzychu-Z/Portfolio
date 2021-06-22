"""Lab nr A6, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 25.05.2021r. - plik z funkcjami i klasami"""


class Container:
    def __init__(self, identifier, width, height, value=0, use=False):
        self.identifier = identifier
        self.width = width
        self.height = height
        self.value = value
        self.use = use
        self.matrix = []

        for x in range(self.height):
            self.matrix.append([])

            for y in range(self.width):
                self.matrix[x].append(self.identifier)

    def space(self):
        space = 0

        for each in self.matrix:
            space += len(each)

        return space


def graphic_matrix(matrix):
    """
    Simple function to print out 2D lists as 2D matrix
    :param matrix: 2D list
    :return: Prints 2D matrix representation of list
    """
    for x in range(len(matrix)):
        for y in matrix[x]:
            print(y, end=" ")

        print('\n')


def greedy_approximation(item_list):
    """
    Greedy algorithm solution for knapsack problem.
    :param item_list: List of 'Container' class objects -> items
    :return: List of 'Container' class objects  that should be packed in
    """
    # Find value/space ratio and then sort decreasingly by ratio
    # Works only if id's are unique - should be quite obvious
    ratio_dict = {}
    for x in item_list:
        ratio_dict[x.identifier] = x.value / x.space()

    ratio_dict = dict(sorted(ratio_dict.items(), key=lambda item: item[1]))

    # Dict of indexes -> list of objects
    new_list = []
    for x in ratio_dict:
        for each in item_list:
            if each.identifier == x:
                new_list.append(each)

        del x

    new_list.reverse()
    return new_list


def packing(knapsack, new_list):
    """
    Packing function to fill knapsack matrix with values of items' id's. Includes finding max value.
    :param knapsack: 'Container' class object with id and value of 0
    :param new_list: List of 'Container' class objects  that should be packed in
    :return: 'Container' class object, total value of packed in items (best for greedy algorithm)
    """
    # Fitting objects
    total_value = 0
    for m in new_list:

        # Outer set to iterate through knapsack
        for a in range(len(knapsack.matrix)):
            for b in range(len(knapsack.matrix[0])):
                progress_bar = 0
                if knapsack.matrix[a][b] == 0:
                    # Checking if space available
                    for x in range(len(m.matrix)):
                        for y in range(len(m.matrix[0])):
                            try:
                                if knapsack.matrix[x + a][y + b] == 0:
                                    progress_bar += 1
                            except IndexError:
                                pass

                    # If conditions met fill with item
                    if progress_bar == m.space() and not m.use:
                        for x in range(len(m.matrix)):
                            for y in range(len(m.matrix[0])):
                                try:
                                    knapsack.matrix[x + a][y + b] = m.identifier
                                except IndexError:
                                    pass

                        m.use = True
                        total_value += m.value
                    else:
                        # Rotate and check if space available
                        progress_bar = 0
                        for x in range(len(m.matrix[0])):
                            for y in range(len(m.matrix)):
                                try:
                                    if knapsack.matrix[x + a][y + b] == 0:
                                        progress_bar += 1
                                except IndexError:
                                    pass

                        # If conditions met fill with item
                        if progress_bar == m.space() and not m.use:
                            for x in range(len(m.matrix[0])):
                                for y in range(len(m.matrix)):
                                    try:
                                        knapsack.matrix[x + a][y + b] = m.identifier
                                    except IndexError:
                                        pass

                            m.use = True
                            total_value += m.value

    return knapsack, total_value
