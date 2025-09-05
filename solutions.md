````markdown name=solutions.md
```markdown
# Selected Solutions and Notes

This file provides short explanations and links to example programs included in the repo.

- Insert / Delete / Search / Print: see insert_operations.cpp and delete_operations.cpp (existing file).

- Reverse: reverse_operations.cpp demonstrates both iterative and recursive approaches.

- Cycle detection / removal: detect_cycle.cpp and remove_cycle.cpp use Floyd's algorithm.

- Merge two sorted lists: merge_operations.cpp uses a dummy head and reuses nodes.

- Remove duplicates: remove_duplicates.cpp shows an unordered_set approach (O(n) time, O(n) space). For sorted lists, duplicates can be removed in one pass with O(1) space.

- Sort: sort_list.cpp implements merge sort (O(n log n) time, O(log n) recursion stack).

- Middle / k-th from end: find_middle.cpp and kth_from_end.cpp use two-pointer techniques.

- Palindrome: palindrome_check.cpp reverses the second half, compares, and restores the list.

- Rotate / Partition / Swap pairs / Zigzag: see rotate_list.cpp, partition_list.cpp, swap_pairs.cpp, zigzag.cpp.

Notes:
- Most examples reuse the Node structure in linked_list.h and the inline helpers. This keeps each example file standalone and easy to compile.
- Some examples intentionally create cycles or intersections for demonstration; be careful to break links before deleteList to avoid double-free or leaks.
```
````