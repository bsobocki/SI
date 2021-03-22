PROJECT_NAME= optDist
FLAGS= -Wall -pedantic 
OUT= -o $(PROJECT_NAME)
PROJECT_DIR=. 
SRC= src
EXEC_SRC= src/funcs/*.cpp
EXEC_UT= ut/*.cpp

compile:
	@g++ $(FLAGS) $(OUT) -I $(SRC) $(EXEC_SRC) $(SRC)/main.cpp

run: compile
	@./$(PROJECT_NAME)

test:
	@g++ $(FLAGS) $(OUT)_Test -I $(SRC) -I $(PROJECT_DIR) $(EXEC_UT) $(EXEC_SRC)
	@./$(PROJECT_NAME)_Test
	@rm $(PROJECT_NAME)_Test