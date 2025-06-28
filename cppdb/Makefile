include common.mk

#name of final executable file
TARGET = libcppdb.a

#List of all .cpp source files in /sources
SRCS = $(wildcard src/*.cpp)
#wildcard finds all cpp files in /sources

#Convert .cpp file in SRCS to .o file with same name
# Object files(.o) are compiled pieces of code , not yet linked
OBJS = $(patsubst src/%.cpp, %.o, $(SRCS))
#sources/% removes the sources/ prefix

#default rule, builds thestatic library
all: $(TARGET)

#build the static library from object files
# $@ stands for the target
$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

#Compile .cpp to .o file of same name
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
#$< input file and $@ output file

#Delete the .o and executable file, keeps folder clean and forces a full rebuild next time
clean: 
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean