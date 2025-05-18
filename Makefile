# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Target and source
main_app: main_app.cpp
	$(CXX) $(CXXFLAGS) main_app.cpp -o main_app

# Clean target
clean:
	rm -f main_app *.o *.d
