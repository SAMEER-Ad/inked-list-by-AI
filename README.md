# inked-list-by-AI (linked list examples)

This repository contains small C++ examples demonstrating common singly-linked list operations.

Files added:
- linked_list.h — shared Node type and small helpers.
- insert_operations.cpp — insert at head/end/position.
- reverse_operations.cpp — iterative and recursive reversal.
- merge_operations.cpp — merge two sorted lists.
- Existing files kept: delete_operations.cpp, search_operations.cpp (already in repo).

Build
```bash
make
```

Available targets (after adding these files):
- insert_operations
- reverse_operations
- merge_operations
- search_operations
- delete_operations

Usage
Run the produced binary, e.g.:
```bash
./insert_operations
```

If you'd like, I can also add unit tests, combine examples into a single CLI, or convert this to a header-only library.
