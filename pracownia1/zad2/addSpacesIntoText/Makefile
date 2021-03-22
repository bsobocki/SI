SRC=./src
UT_SRC=./test/test_framework
SRC_ALL=$(SRC) $(UT_SRC)

EXEC_UT=./ut/*.cpp 
EXEC_SRC=./src/*.cpp 

compile_main:
	@g++ $(EXEC_SRC) -Wall -pedantic -I $(SRC)  -o run

run: compile_main
	@./run polskie_slowa.txt pan_tadeusz_bez_spacji.txt pan_tadeo_ze_spacjami.txt
	@rm run