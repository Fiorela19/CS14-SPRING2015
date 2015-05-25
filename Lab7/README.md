Lab 7
Part B

Self-Balancing Tree

Advantages
 - It is already balanced and in-order
 - The worst case runtime is O(logn)
 - Uses less memory than a hash table
 - When iterating through a tree the contents are in-order

Disadvantages
 - insertion takes longer
 - on average look up takes longer than for hash tables
 - on average hash tables are faster

Hash Tables

Advantages
 - Search is at best O(1) which is faster that searching in trees
 - Deletion is O(1) on average
 - On average the runtime for find and insert are faster than trees

Disadvantages
 - The elements are not ordered
 - Iterating though a hash table is not in order

Measuring the average time to delete items in both trees and hash tables would 
be useful in comparing the two data structures. Measuring the time it takes to
access elements in both trees and hash tables would also be useful for comparing
the two.
