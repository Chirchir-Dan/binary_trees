# binary_trees

# Binary Trees
General
This README provides an overview of binary trees, including their characteristics, types, and traversal methods.

## What is a Binary Tree?
A binary tree is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. This structure is useful for various applications such as searching, sorting, and hierarchical data representation.

### Binary Tree vs. Binary Search Tree
Binary Tree: A general tree structure where each node has up to two children.
Binary Search Tree (BST): A specialized type of binary tree where the left child of a node contains only nodes with keys less than the node's key, and the right child only nodes with keys greater than the node's key. This property makes BSTs useful for efficient searching and sorting operations.
Time Complexity Benefits
Binary trees can offer significant time complexity advantages over linked lists, particularly for search operations:

Linked Lists: Searching an element takes O(n) time in the worst case.
Binary Search Trees: Searching, insertion, and deletion operations can take O(log n) time in the average case, due to the tree's hierarchical structure.
Key Properties of Binary Trees
Depth: The depth of a node is the number of edges from the node to the tree's root node.
Height: The height of a node is the number of edges on the longest path from the node to a leaf. The height of a tree is the height of its root.
Size: The size of a binary tree is the total number of nodes it contains.

### Traversal Methods
Binary trees can be traversed using several methods, each with its own use case:

In-order Traversal: Visit the left subtree, the root, and the right subtree. This traversal yields nodes in non-decreasing order for BSTs.
Pre-order Traversal: Visit the root, the left subtree, and the right subtree. Useful for creating a copy of the tree.
Post-order Traversal: Visit the left subtree, the right subtree, and the root. Useful for deleting nodes and freeing memory.
Level-order Traversal: Visit nodes level by level from top to bottom. Also known as breadth-first traversal.

### Types of Binary Trees
Complete Binary Tree: All levels, except possibly the last, are fully filled, and all nodes are as far left as possible.
Full Binary Tree: Every node other than the leaves has exactly two children.
Perfect Binary Tree: All internal nodes have exactly two children, and all leaves are at the same level.
Balanced Binary Tree: The height of the tree is minimized, ensuring operations such as insertion, deletion, and search are performed efficiently. An example is an AVL tree, where the heights of the two child subtrees of any node differ by no more than one.
Understanding these fundamental concepts is crucial for effectively utilizing binary trees in various computational problems and algorithms.

## Collaborators
[David Kingasia](https://www.linkedin.com/in/davidkingasia/)
[Daniel Kipkosgei](https://www.linkedin.com/in/daniel-kipkosgei-2ab84117b/)
