# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Output executable name
TARGET = load_balancer

# Source files
SRCS = main.cpp Request.cpp WebServer.cpp RequestQueue.cpp LoadBalancer.cpp

# Object files
OBJS = main.o Request.o WebServer.o RequestQueue.o LoadBalancer.o

# Default target to build the program
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rules to build object files explicitly
main.o: main.cpp Request.h WebServer.h RequestQueue.h LoadBalancer.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Request.o: Request.cpp Request.h
	$(CXX) $(CXXFLAGS) -c Request.cpp -o Request.o

WebServer.o: WebServer.cpp WebServer.h Request.h
	$(CXX) $(CXXFLAGS) -c WebServer.cpp -o WebServer.o

RequestQueue.o: RequestQueue.cpp RequestQueue.h Request.h
	$(CXX) $(CXXFLAGS) -c RequestQueue.cpp -o RequestQueue.o

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h WebServer.h RequestQueue.h Request.h
	$(CXX) $(CXXFLAGS) -c LoadBalancer.cpp -o LoadBalancer.o

# Rule to clean up the build files
clean:
	rm -f $(TARGET) $(OBJS)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Doxygen documentation
docs:
	doxygen Doxyfile

.PHONY: all clean run docs
