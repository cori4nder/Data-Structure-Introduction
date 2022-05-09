APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps

# libed: \
	matriz.o \

libed: \
	$(OBJ)/fila.o \

myapps:
	gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

# %.o: $(SRC)/%.c $(INCLUDE)/%.h
#	gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

run:
	./bin/app
	
clean:
	rm -rf ./bin/* ./obj/*
