all: lol flex parser compile final 

lol:	
	@echo -n "\n------------------------------------------------------------------------------\n\n"

flex: 
	flex --outfile=al.c al.l

parser:
	bison --yacc --defines --output=parser.c parser.y
	
compile:
	gcc symtable.h
	gcc -c quads.c quads.h
	gcc -g -o pars al.c parser.c
	
final:
	gcc -g -o exc execute_arithmetic.c avm_assign.c execute_assign.c execute_bool.c  vm.c
run : 
	./pars a.txt

clean:
	-rm -rf mylexe exc *~ *.o al.c parser.c parser.h pars *.my *.gch
	clear
distclean: clean
	-rm flex al

