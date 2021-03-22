PROJECT_NAME= poker
FLAGS= -Wall -pedantic

SRC= src
SRC_POKER= src/poker
SRC_STF= simple_test_framework

EXEC_SRC=$(SRC)/*.cpp
EXEC_POKER=$(SRC_POKER)/*.cpp
EXEC_UT=ut/*.cpp

INC_PROJECT= -I. -I $(SRC)

compile:
	@g++ $(INC_PROJECT) $(FLAGS) $(EXEC_SRC) $(EXEC_POKER) -o $(PROJECT_NAME)
	@echo "$(PROJECT_NAME): compile success"

run: compile
	@echo "$(PROJECT_NAME): run"
	@./$(PROJECT_NAME)
	@rm $(PROJECT_NAME)

test:
	@g++ $(INC_PROJECT) $(FLAGS) $(EXEC_POKER) $(EXEC_UT) -o $(PROJECT_NAME)_test
	@./$(PROJECT_NAME)_test
	@rm $(PROJECT_NAME)_test