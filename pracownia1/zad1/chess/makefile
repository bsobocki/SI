PROJ_NAME=chess
FLAGS= -Wall -pedantic

PROJ_DIR=.
SRC=src
CHESS=${SRC}/chess
UT=ut
TF=simple_test_framework

INC= -I ${PROJ_DIR} -I ${SRC}
INC_TEST= -I ${TF}

EXEC_SRC=${SRC}/*.cpp
EXEC_CHESS=${CHESS}/*.cpp
EXEC_UT=${UT}/*.cpp
EXEC_TF=simple_test_framework/*.cpp

run: compile
	@./${PROJ_NAME}
	@rm ${PROJ_NAME}

compile:
	@g++ ${FLAGS} ${INC} ${EXEC_SRC} ${EXEC_CHESS} -o ${PROJ_NAME}

test:
	@g++ ${FLAGS} ${INC} ${INC_TEST} ${EXEC_UT} ${EXEC_CHESS} -o ${PROJ_NAME}_test
	@./${PROJ_NAME}_test
	@rm ${PROJ_NAME}_test