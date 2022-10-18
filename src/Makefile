CC:=gcc
SANITIZER:= #-fsanitize=address
CFLAGS:= $(SANITIZER) -Wall -Werror -Wextra -std=c11 
CFLAGS_TEST:= $(SANITIZER) --coverage -c -g 
CHECK:=-lcheck 
SOURCE:= s21*.c
SOURCE_OBJ:= s21*.o 
TEST_FILE:= test.c

CDFLAGS:=$(SANITIZER) --coverage  

# Do not forget to REMOVE check target from all and add clean
all: check s21_string.a test clean
 
test: s21_string.a $(TEST_FILE) clean
	$(CC)  -L. $(CHECK) s21_string.a $(TEST_FILE) -o test_exec
	./test_exec
# We are rebuilding Lib with --coverage flag, since we need it to genhtml.
gcov_report: clean $(SOURCE)
	$(CC) $(CFLAGS_TEST) $(SOURCE)
	ar rc s21_string.a $(SOURCE_OBJ)
	ranlib 	s21_string.a
	- $(CC) $(CFLAGS) -L. $(CHECK) s21_string.a $(CDFLAGS) $(TEST_FILE) -o test_exec
	- ./test_exec 
	./lcov/bin/lcov -f -c --directory . -o ./coverage.info 
	./lcov/bin/genhtml coverage.info --output-directory=res
	rm -f *.gcda *.gcov *.o *.gcno

clean: 
	rm -f *.gcda 
	rm -f *.gcov 
	rm -f *.o 
	rm -f *.gcno 
	rm -f coverage.info
	rm -f test_exec

clean_lib:
	rm -f s21_string.a


s21_string.a: clean_lib $(SOURCE) 
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar rc s21_string.a $(SOURCE_OBJ)
	ranlib 	s21_string.a

# We are checking source code via CPPLINT. If there's mistakes - grep will show them.
# Also there's smile at the end.
check: ${SOURCE} test.c *.h
ifeq ("","$(wildcard ./CPPLINT.cfg)")
	cp -f ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
endif
	!(python3 ../materials/linters/cpplint.py --extensions=c $^ | grep -q :)
	!(grep '<string.h>' s21*)
	!(grep '<stdio.h>' s21*)

leaks: test
	CK_FORK=no leaks -atExit -- ./test_exec

