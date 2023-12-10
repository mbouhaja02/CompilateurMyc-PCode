all :	lang
SRC=src

syntax : lexic	${SRC}/lang.y
	bison -v -y  -d  ${SRC}/lang.y
lexic : ${SRC}/lang.l
	flex ${SRC}/lang.l

PCode/PCode.o : PCode/PCode.c PCode/PCode.h
	cd PCode; make pcode

lang		:	syntax ${SRC}/Table_des_symboles.c ${SRC}/Table_des_chaines.c PCode/PCode.o
	gcc -o ${SRC}/lang ${SRC}/lex.yy.c ${SRC}/y.tab.c PCode/PCode.o ${SRC}/Table_des_symboles.c ${SRC}/Table_des_chaines.c 

clean		:	
	rm -f lex.yy.c *.o y.tab.h y.tab.c ${SRC}/lang *~ y.output; cd PCode; make clean


