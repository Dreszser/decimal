FLAGS = -Wall -Wextra -Werror -std=c11
FLAGS += -o ./

CFLAGS = -Wall -Wextra -Werror -std=c11

GCOV_FLAGS = --coverage
LIB = s21_decimal.a
CEXE = s21_test
CHECK_FILE = ./tests/*.check

BM=$(wildcard binary_math/*.c)
COMP=$(wildcard comparison/*.c)
MATH=$(wildcard math/*.c)
SF=$(wildcard supporting_funcs/*.c)
CF=$(wildcard convert_funcs/*.c)
OF=$(wildcard other_funcs/*.c)

CFILES = convert_funcs/*.c binary_math/*.c comparison/*.c supporting_funcs/*.c other_funcs/*.c math/*.c

#============= FLAGS FOR OS =========================================================

UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif

rebuild: clean all

all: ${LIB}

#============= LIBRIRY ==============================================================

s21_decimal.a:
	gcc ${CFLAGS} -c ${CFILES} -I .
	ar rc ${LIB} *.o
	ranlib ${LIB}
	rm -rf *.o

gcov_s21_decimal.a:
	gcc ${CFLAGS} ${GCOV_FLAGS} -c ${CFILES}  -I .
	ar rc ${LIB} *.o
	ranlib ${LIB}

vg: clean test.o gcov_s21_decimal.a  
	gcc test.o ${GCOV_FLAGS} s21_decimal.a -o out ${LDFLAGS}
	chmod a+x out
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./out
	${FREE}

#========== CLEAN ===================================================================

clean:
	rm -rf *.o *.out *.a s21_decimal s21_test *.gcno *.gcda test.*
	rm -rf *.gcov *.log *.html *.css report *.dSYM *.info out test_gcov

FREE = rm -rf test.c *.o *.gcda *.gcno out

#=========== STYLE ==================================================================

format_check:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -n ${MATH} ${CF} ${BM} ${COM} ${SF} ${OF} tests/*.check *.h
	rm -f .clang-format

format:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -i ${MATH} ${CF} ${BM} ${COM} ${SF} ${OF} tests/*.check *.h
	rm -f .clang-format

#============= TEST =================================================================

test: clean s21_decimal.a
	gcc ${FLAGS}${CEXE} main.c print_decimal/print_s21_decimal.o ${MATH} ${CF} ${BM} ${COM} ${SF} ${OF} -lm -I .
	./${CEXE}

test.o:
	checkmk clean_mode=1 $(CHECK_FILE) > test.c
	gcc $(CFLAGS) -g -c test.c

gcov_report: clean test.o gcov_s21_decimal.a  
	gcc $(CFLAGS) ${GCOV_FLAGS} test.o ${LIB} -o ${CEXE} ${LDFLAGS}
	./${CEXE}
	mkdir -p report
	gcovr --html-details report/index.html --html-medium-threshold 80 --html-high-threshold 100 --html-title "s21_decimal coverage report"
	${FREE}