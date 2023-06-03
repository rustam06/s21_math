GCCC = gcc -c -Wall -Werror -Wextra $^ 

all: s21_math 

s21_math: s21_math.o s21_func_math.o
	gcc -o s21_math $^
	make clean
	./s21_math

s21_math.o: s21_math.c 
	$(GCCC)

s21_func_math.o: s21_func_math.c
	$(GCCC) 

git:
	git add .
	git commit -m "fix"
	git push origin

check: 
	clang-format -i *.c *.h 
	cppcheck —enable=all —suppress=missingIncludeSystem *.c 

cl:
	rm s21_math

clean: 
	rm -rf *.o

reb: 
	make cl
	make all