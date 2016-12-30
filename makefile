CXX=g++-6 
CXXFLAGS= -Wall -c -g  
INCLUDES=-I/usr/include/python2.7  
TARGET=main  

$(TARGET):    
	$(CXX) $(CXXFLAGS) $(INCLUDES) Graph.cpp    
	$(CXX) $(CXXFLAGS) $(INCLUDES) main.cpp
	$(CXX) -o $@ Graph.o main.o $(INCLUDES) -lpython2.7

clean:  
	rm -f $(TARGET) *.o