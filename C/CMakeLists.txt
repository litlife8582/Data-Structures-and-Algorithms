cmake_minimum_required(VERSION 4.0)
project(C_and_C__ C)

set(CMAKE_C_STANDARD 11)

include_directories(Graph)

add_executable(C_and_C__
        "Array ADT/CreationOfArray_Dynamically.c"
        "Array ADT/CreationOfArray_Static.c"
        "Array ADT/DeletingElements.c"
        "Array ADT/InsertingElements.c"
        "Array ADT/InsertingElementsInSortedArray.c"
        "Array ADT/MergingArray.c"
        "Array ADT/OperationsInArray.c"
        "Array ADT/ReversingArray.c"
        "Array ADT/ShiftArray.c"
        "Array ADT/tempCodeRunnerFile.c"
        Arrays/Creation.c
        Arrays/Static_And_Dynamic_Array.c
        "Binary Search Tree/BinarySearchTree.c"
        Graph/GraphTraversal.c
        Graph/queue.c
        Graph/queue.h
        "Linked List/DoublyLinkedList.c"
        "Linked List/RecursiveDisplayOfLL.c"
        "Linked List/SinglyLinkedList.c"
        "Minimum Spanning Tree (Prims and Kruskal's Algorithm)/MinimumSpanningTree.c"
        Queue/Problems/QueueUsingTwoStacks.c
        Queue/CircularQueue.c
        Queue/Queue.c
        Recursion/Combination_nCr_Using_Formula.c
        Recursion/Combination_nCr_Using_Recursion.c
        Recursion/Factorial.c
        Recursion/Fibonacci_Using_Memoization.c
        Recursion/Global_Recursion.c
        Recursion/GreatestCommonDivisor.c
        Recursion/Indirect_Recursion.c
        Recursion/Lets_Code_Recursion.c
        Recursion/Nested_Recursion.c
        Recursion/Power.c
        Recursion/Static_Recursion.c
        Recursion/Sum_Of_Natural_Numbers.c
        Recursion/Taylor_Series.c
        Recursion/Taylor_Series_Horners_Rule.c
        Recursion/Towers_Of_Hanoi.c
        Recursion/Tree_Recursion.c
        Searching/BinarySearch.c
        Searching/LinearSearch.c
        "Single Source Shortest Path Algortihm - Djikstra's Algorithm/Dijkstra's_Algorithm.c"
        Sorting/InsertionSort.c
        Sorting/MergeSort.c
        Sorting/QuickSort.c
        Sorting/SelectionSort.c
        Stacks/Creations_and_Operations.c
        Stacks/EvaluationOfPostfix.c
        Stacks/InfixToPostfix.c
        Stacks/InfixToPrefix.c
        Trees/Tree.c)
