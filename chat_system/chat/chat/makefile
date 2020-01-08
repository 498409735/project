CC:=gcc

CFLAG:=-Wall
CFLAG+= -Iinclude
TARGET:= bin/main
.PHONY:$(TARGET)

OBJ:= obj/server.o
OBJ+= obj/server_set.o


$(TARGET):$(OBJ)
	$(CC) $(CFLAG) -o $@ $^
obj/%.o:src/%.c
	$(CC) $(CFLAG) -o $@ $^ -c
	
.PHONY:clean
clean:
	rm -rf $(OBJ)