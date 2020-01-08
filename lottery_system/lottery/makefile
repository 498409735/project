CC:=gcc

CFLAG:=-Wall
CFLAG+= -Iinclude
CFLAG+= -g
TARGET:= bin/main
.PHONY:$(TARGET)

OBJ:= obj/main.o
OBJ+= obj/user.o
OBJ+= obj/admin.o 
OBJ+= obj/lottery.o

$(TARGET):$(OBJ)
	$(CC) $(CFLAG) -o $@ $^
obj/%.o:src/%.c
	$(CC) $(CFLAG) -o $@ $^ -c 
	
.PHONY:clean
clean:
	rm -rf $(OBJ)