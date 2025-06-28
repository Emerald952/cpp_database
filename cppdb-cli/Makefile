include ../cppdb/common.mk

# Target executable
TARGET = cppdb-cli

# Source files
SRCS = $(wildcard *.cpp)

# Object files
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

# Default rule
all: ../cppdb/libcppdb.a $(TARGET)

# Build executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

#Compile .cpp to .o file of same name
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean