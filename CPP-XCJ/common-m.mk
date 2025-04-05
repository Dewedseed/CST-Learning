
CXX = g++
CXXFLAGS = -Wall -O2 -I$(HEADERS_DIR)

OBJECTS = $(SOURCES:.cpp=.o)
TARGET  = run

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
