src = ./src/
bin = ./bin/

#all: 
#	g++ -c $(src)ChessBoardConsoleUI.cpp -o $(bin)ChessBoardConsoleUI.o
#	g++ -c $(src)main.cpp -o $(bin)main.o
#	g++ -o $(bin)main $(bin)main.o $(bin)ChessBoardConsoleUI.o
all: main
		
main: $(bin)main.o $(bin)ChessBoardConsoleUI.o $(bin)ChessBoard.o $(bin)InvalidChessBoardSizeException.o
	g++ -o $(bin)main $(bin)main.o $(bin)ChessBoardConsoleUI.o $(bin)ChessBoard.o $(bin)InvalidChessBoardSizeException.o
	
$(bin)main.o: $(bin)ChessBoardConsoleUI.o
	g++ -o $(bin)main.o -c $(src)main.cpp 

$(bin)ChessBoardConsoleUI.o: $(bin)ChessBoard.o $(bin)InvalidChessBoardSizeException.o
	g++ -o $(bin)ChessBoardConsoleUI.o -c $(src)ChessBoardConsoleUI.cpp 

$(bin)ChessBoard.o: 
	g++ -o $(bin)ChessBoard.o -c $(src)ChessBoard.cpp

$(bin)InvalidChessBoardSizeException.o:
	g++ -o $(bin)InvalidChessBoardSizeException.o -c $(src)InvalidChessBoardSizeException.cpp






