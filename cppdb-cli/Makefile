include ../cppdb/common.mk

# Target executable
TARGET = cppdb-cli

# Source files
SRCS = $(wildcard sources/*.cpp)

# Object files
OBJS = $(patsubst sources/%.cpp, %.o, $(SRCS))

# Default rule
all: ../cppdb/libcppdb.a $(TARGET)

# Build executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean