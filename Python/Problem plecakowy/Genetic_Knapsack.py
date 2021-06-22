"""Lab nr A6, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 25.05.2021r. - plik z algorytmem genetycznym"""
from random import randint
from math import floor


def gods_finger(base_list):
    """
    Starter function to generate chaotic population based on list of 'Container' class objects -> items to be packed.
    Creates as many specimens as there are items to be packed.
    :param base_list: List of 'Container' class objects -> items
    :return: List of binary coded specimens -> 0 is for item in base_list that is not to be packed and 1 is the opposite
    """
    population = []

    for x in range(len(base_list)):
        population.append([])
        for y in range(len(base_list)):
            population[x].append(randint(0, 1))

    return population


def fitness(specimen, base_list, knapsack_space):
    """
    Evaluates specimen's fitness to survive. If total space exceeds knapsack space -> fitness = 0 else
    fitness = total value
    :param specimen: List of binary coded specimen e.g. [0,1,1,0,..,1]
    :param base_list: List of 'Container' class objects -> items
    :param knapsack_space: Space of knapsack -> int evaluated by class method .space()
    :return: fitness value for specified specimen
    """
    space = 0
    total_value = 0

    for x in range(len(specimen)):
        if specimen[x] == 1:
            space += base_list[x].space()
            total_value += base_list[x].value

    if space > knapsack_space:
        return 0
    else:
        return total_value


def pair_selection(population, base_list, knapsack_space):
    """
    Function to pair specimens. Function evaluates fitness for each specimen in population and throws away
    half of all -> the worst half (however the crossover function returns 4 new specimens thus population keeps
    the size). Then it randomly pairs survivors.
    :param population: List of binary coded specimens.
    :param base_list: List of 'Container' class objects -> items
    :param knapsack_space: Space of knapsack -> int evaluated by class method .space()
    :return: List of pairs treated as lists of specimens.
    """
    value_list = []

    for x in population:
        value_list.append(fitness(x, base_list, knapsack_space))

    value_list.sort(reverse=True)

    # Natural selection - cut away 1/2 of worst combinations like Thanos
    value_list = value_list[:floor(0.5 * len(value_list))]

    if len(value_list) % 2 == 1:
        value_list.pop(-1)

    # Random pairing
    pair_set = []
    for a in range(0, len(value_list), 2):
        # Choose a pair from shortened population
        xx = value_list[randint(0, len(value_list) - 1)]
        # Don't consider xx value any more
        del value_list[value_list.index(xx)]
        xy = value_list[randint(0, len(value_list) - 1)]
        del value_list[value_list.index(xy)]

        pair = []
        for m in population:
            if len(pair) == 2:
                break
            elif xx == fitness(m, base_list, knapsack_space):
                pair.append(m)
                del m
            elif xy == fitness(m, base_list, knapsack_space):
                pair.append(m)
                del m

        pair_set.append(pair)

    return pair_set


def crossover(genome1, genome2):
    """
    Simple crossover function to combine two genomes to create 4 new specimens. Splits two genomes at random
    place and swaps their suffixes.
    :param genome1: Binary coded specimen 1
    :param genome2: Binary coded specimen 2
    :return: List of 4 new specimens.
    """
    new_generation = []
    i = 0
    while i < 2:
        splitter = randint(1, len(genome1) - 2)
        trim_1 = genome1[splitter:]
        trim_2 = genome2[splitter:]
        new_generation.append(genome1[0:splitter] + trim_2)
        new_generation.append(genome2[0:splitter] + trim_1)
        i += 1

    return new_generation


def mutation(genome):
    """
    Simple function to introduce mutation into new specimen. Mutation probability is set at around 10%.
    :param genome: Binary coded specimen
    :return: Mutated binary coded specimen
    """
    mutation_index = floor(len(genome)*0.1)

    i = 0
    while i < mutation_index:
        random_index = randint(0, len(genome) - 1)

        if genome[random_index] == 0:
            genome[random_index] = 1
        else:
            genome[random_index] = 0

        i += 1

    return genome


def evolution(base_list, knapsack_space, generation=1, population=[]):
    """
    Genetic algorithm solution for knapsack problem.
    :param base_list: List of 'Container' class objects -> items
    :param knapsack_space: Space of knapsack -> int evaluated by class method .space()
    :param generation: Int to determine generation. If generation is 1 -> start with chaos.
    :param population: Initially empty list of binary coded specimens. For generations other than 1 insert result
                       of previous evolution.
    :return: List of binary coded specimens of the generation
    """
    if generation == 1:
        population = gods_finger(base_list)

    pairs = pair_selection(population, base_list, knapsack_space)

    # Do crossover
    new_crossovers = []
    for each in pairs:
        # We know that pair consists of two
        tmp = crossover(each[0], each[1])
        for x in tmp:
            new_crossovers.append(x)

    # Do mutation
    new_generation = []
    for each in new_crossovers:
        new_generation.append(mutation(each))

    # Evaluate top value and combination
    value_list = []

    for x in new_generation:
        value_list.append(fitness(x, base_list, knapsack_space))

    value_list.sort(reverse=True)

    final_list = []
    for each in new_generation:
        if fitness(each, base_list, knapsack_space) == value_list[0]:
            for x in range(len(each)):
                if each[x] == 1:
                    final_list.append(base_list[x])

            break

    return new_generation, final_list, value_list[0]


def translator(population, base_list, knapsack_space):
    """
    Simple function used to turn binary coded specimen's list into list of 'Container' objects and evaluate
    overall value.
    :param population: List of binary coded specimens
    :param base_list: List of all 'Container' class objects -> items
    :param knapsack_space: Space of knapsack -> int evaluated by class method .space()
    :return: List of 'Container' objects -> solution of knapsack problem, overall value of that solution
    """
    value_list = []

    for x in population:
        value_list.append(fitness(x, base_list, knapsack_space))

    value_list.sort(reverse=True)

    final_list = []
    for each in population:
        if fitness(each, base_list, knapsack_space) == value_list[0]:
            for x in range(len(each)):
                if each[x] == 1:
                    final_list.append(base_list[x])

            break

    return final_list, value_list[0]
