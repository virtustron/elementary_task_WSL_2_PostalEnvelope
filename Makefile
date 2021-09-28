src = ./src/
bin = ./bin/

#all: 
#	g++ -c $(src)ChessBoardConsoleUI.cpp -o $(bin)ChessBoardConsoleUI.o
#	g++ -c $(src)main.cpp -o $(bin)main.o
#	g++ -o $(bin)main $(bin)main.o $(bin)ChessBoardConsoleUI.o
all: main
		
main: build_all
	g++ -o $(bin)main $(bin)main.o $(bin)Envelope.o $(bin)EnvelopeComparator.o $(bin)EnvelopeConsoleUI.o $(bin)InvalidEnvelopeSizeException.o

build_all:
	g++ -o $(bin)Envelope.o -c $(src)Envelope.cpp
	g++ -o $(bin)EnvelopeComparator.o -c $(src)EnvelopeComparator.cpp
	g++ -o $(bin)EnvelopeConsoleUI.o -c $(src)EnvelopeConsoleUI.cpp
	g++ -o $(bin)InvalidEnvelopeSizeException.o -c $(src)InvalidEnvelopeSizeException.cpp
	g++ -o $(bin)main.o -c $(src)main.cpp









