PROJECT_NAME= logical_images
FLAGS= -Wall -pedantic

SRC= src
SRC_FUNCS= src/funcs
SRC_LI= src/logical_images

EXEC_SRC= $(SRC)/*.cpp
EXEC_FUNCS= $(SRC_FUNCS)/*cpp
EXEC_LI= $(SRC_LI)/*.cpp
EXEC_UT=ut/*.cpp

INC_PROJEC= -I. -I $(SRC)

compile:
	@g++ $(INC_PROJEC) $(FLAGS) $(EXEC_SRC) $(EXEC_LI) $(EXEC_FUNCS) -o $(PROJECT_NAME)
	@echo "$(PROJECT_NAME): compile success"

run: compile
	@echo "$(PROJECT_NAME): run"
	@./$(PROJECT_NAME)
	@rm $(PROJECT_NAME)

test:
	@g++ $(INC_PROJEC) $(FLAGS) $(EXEC_LI) $(EXEC_FUNCS) $(EXEC_UT) -o $(PROJECT_NAME)_test
	@./$(PROJECT_NAME)_test
	@rm $(PROJECT_NAME)_test