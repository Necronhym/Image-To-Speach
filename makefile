INPUT=c.cxx
OUTPUT=c
FLAGS=-o
LINKS=-llept -ltesseract -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lespeak
CC=g++ -fconcepts -Wall
c: $(INPUT)
	$(CC) $(INPUT) $(FLAGS) $(OUTPUT) $(LINKS)
