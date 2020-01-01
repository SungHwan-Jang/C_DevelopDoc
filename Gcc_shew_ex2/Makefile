CFLAGS=-Wall -g
OBJ= ex25.o
SRCS= $(OBJ:.o=.c)
CC=gcc
TARGET=main


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OBJ): $(SRCS)
	$(CC) -c $(SRCS) -o $(OBJ)

clean:
	rm -rf $(OBJ) $(TARGET)

