CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

SRCS = insert_operations.cpp reverse_operations.cpp merge_operations.cpp search_operations.cpp delete_operations.cpp
BINARIES = insert_operations reverse_operations merge_operations search_operations delete_operations

all: $(BINARIES)

insert_operations: insert_operations.cpp
	$(CXX) $(CXXFLAGS) -I. -o $@ $<

reverse_operations: reverse_operations.cpp
	$(CXX) $(CXXFLAGS) -I. -o $@ $<

merge_operations: merge_operations.cpp
	$(CXX) $(CXXFLAGS) -I. -o $@ $<

search_operations: search_operations.cpp
	$(CXX) $(CXXFLAGS) -I. -o $@ $<

delete_operations: delete_operations.cpp
	$(CXX) $(CXXFLAGS) -I. -o $@ $<

clean:
	rm -f $(BINARIES)