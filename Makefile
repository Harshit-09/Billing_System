#Target_name : Dependencies
#<TAB>Command

target : main.c ./3_Implementation/src/output.c ./3_Implementation/src/search.c ./3_Implementation/src/write.c ./3_Implementation/src/input.c ./3_Implementation/inc/function.h
	gcc main.c ./3_Implementation/src/output.c ./3_Implementation/src/search.c ./3_Implementation/src/write.c ./3_Implementation/src/input.c -o new.out
