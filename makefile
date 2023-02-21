CC = gcc
EXEC = AsciiArtTool
MAIN = tool/main
ASCII_ART_TOOL = tool/AsciiArtTool
RLELIST = /home/mtm/public/2223a/ex1/RLEList
OBJS = $(MAIN).o $(ASCII_ART_TOOL).o RLEList.o 
DEBUG = -g
CFLAGS = -std=c99 -I/home/mtm/public/2223a/ex1 -Itool -Wall -pedantic-errors -Werror -DNDEBUG 

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) $(DEBUG) -o $@

$(MAIN).o: $(MAIN).c $(ASCII_ART_TOOL).h $(RLELIST).h
	$(CC) $(CFLAGS) -c $(MAIN).c -o $(MAIN).o

$(ASCII_ART_TOOL).o: $(ASCII_ART_TOOL).c $(ASCII_ART_TOOL).h $(RLELIST).h
	$(CC) $(CFLAGS) -c $(ASCII_ART_TOOL).c -o $(ASCII_ART_TOOL).o

RLEList.o: RLEList.c $(RLELIST).h
	$(CC) $(CFLAGS) -c RLEList.c

 
clean:
	 rm -f $(OBJS) $(EXEC)

