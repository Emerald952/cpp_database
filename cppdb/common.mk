#variable for C++ compiler
CXX = g++

# Use relative include path if we're not inside cppdb
#Compiler flags, use c++ 17, enable all comman warning and extra useful warning, optimize the compiled code for speed
#-Iheader looks in the header/ folder to search for #include files
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 \
            -Iheaders \
            -I../cppdb/headers


# Linker flags
LDFLAGS = -L../cppdb -lcppdb

#Compile .cpp to .o file of same name
%.o: sources/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
#$< input file and $@ output file	