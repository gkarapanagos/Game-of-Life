#	Programming Assignment #6
#	George Karapanagos
#	Polymorphism (Predator-prey)

CXXFLAGS =	-m32 -g -Wall -fmessage-length=0

OBJS =		Organism.o PA6.o

LIBS =

TARGET =	PA6

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) *.exe
