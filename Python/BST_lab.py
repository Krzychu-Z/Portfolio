"""Lab nrA3, zadanie 1, Krzysztof Żerebecki, AiSD Teleinformatyka 1 rok, 04.05.2021r."""
from random import uniform
from time import time


# Zadanie 1
class Node:
    def __init__(self, key, lchild=None, rchild=None):
        self.key = key
        self.lchild = lchild
        self.rchild = rchild


def graphic_tree(root, gen=1):
    if root.lchild is not None and root.rchild is None:
        print(str(root.key) + str("-"*gen), end="")
        graphic_tree(root.lchild, gen + 1)
    elif root.lchild is None and root.rchild is not None:
        print(str(root.key) + str("-"*gen), end="")
        graphic_tree(root.rchild, gen + 1)
    elif root.lchild is not None and root.rchild is not None:
        print(str(root.key) + str("-"*gen), end="")
        graphic_tree(root.rchild, gen + 1)
        print(str("\t" * gen) + str(" " * (gen - 1)) + str("-" * gen), end="")
        graphic_tree(root.lchild, gen + 1)
    else:
        print(root.key)


# Zadanie 2
def insert(tree, key):
    if tree.key < key and tree.rchild is None:
        tmp = Node(key)
        tree.rchild = tmp
        return tmp
    elif tree.key < key and tree.rchild is not None:
        insert(tree.rchild, key)
    elif tree.key > key and tree.lchild is None:
        tmp = Node(key)
        tree.lchild = tmp
        return tmp
    elif tree.key == key:
        pass
    else:
        insert(tree.lchild, key)


def minimum(root):
    if root.lchild is None:
        pass
        # print("Minimum value is:", root.key)
    else:
        minimum(root.lchild)


def maximum(root):
    if root.rchild is None:
        pass
        # print("Maximum value is:", root.key)
    else:
        maximum(root.rchild)


def search(root, key):
    if root.key == key:
        pass
        # print("Key exists in the tree")
    elif (root.key < key and root.rchild is not None) or (root.key > key and root.lchild is None and root.rchild is not None):
        search(root.rchild, key)
    elif (root.key > key and root.lchild is not None) or (root.key < key and root.rchild is None and root.lchild is not None):
        search(root.lchild, key)
    else:
        pass
        # print("Key doesn't exist in the tree")


root_1 = Node(1.5)
root_2 = Node(3.5)
root_3 = Node(4.5)
root_4 = Node(7.5)
root_5 = Node(9.5)

node_g1_1 = insert(root_1, 1.3)
node_g1_2 = insert(root_1, 1.6)
node_g1_3 = insert(root_2, 3.7)
node_g1_4 = insert(root_3, 4.0)
node_g1_5 = insert(root_3, 4.99)
node_g1_6 = insert(root_4, 7.3)
node_g1_7 = insert(root_4, 7.8)
node_g1_8 = insert(root_5, 9.3)
node_g2_1 = insert(root_4, 7.7)
node_g2_2 = insert(root_4, 7.9)
node_g3_1 = insert(root_4, 7.6)
"""
print("\n---------\nTree no 1:")
graphic_tree(root_1)
print("\n---------\nTree no 2:")
graphic_tree(root_2)
print("\n---------\nTree no 3:")
graphic_tree(root_3)
print("\n---------\nTree no 4:")
graphic_tree(root_4)
print("\n---------\nTree no 5:")
graphic_tree(root_5)
"""
# Zadanie 3
root_5000 = Node(2500000.0)

i = 0
start = time()
while i < 5000000:
    insert(root_5000, round(uniform(0, 5000000), 1))
    i += 1
stop = time()
# ---------------------------------------------------------------------time of executing loop
print("Construction time for 5000000 elements (insert):", stop - start - 0.9023852348327637, "sec\n")

i = 0
start = time()
while i < 5000000:
    minimum(root_5000)
    i += 1
stop = time()
print("Minimum finding time for 5000000 elements:", (stop - start - 0.9023852348327637)/5000000, "sec\n")

i = 0
start = time()
while i < 5000000:
    maximum(root_5000)
    i += 1
stop = time()
print("Maximum finding time for 5000000 elements:", (stop - start - 0.9023852348327637)/5000000, "sec\n")

start = time()
i = 0
while i < 5000000:
    search(root_5000, 3100007.1)
    i += 1

stop = time()
print("Time of finding random number for 5000000 elements:", (stop - start - 0.9023852348327637)/5000000, "sec\n")