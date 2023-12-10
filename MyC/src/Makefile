SRC=src
PCode_DIR=../PCode

.PHONY: all clean lexic syntax lang

all: lang

syntax: lexic lang.y
	bison -v -y -d lang.y

lexic: lang.l
	flex lang.l

$(PCode_DIR)/PCode.o: $(PCode_DIR)/PCode.c $(PCode_DIR)/PCode.h
	$(MAKE) -C $(PCode_DIR) PCode.o

lang: syntax $(PCode_DIR)/PCode.o Table_des_symboles.c Table_des_chaines.c
	gcc -o lang lex.yy.c y.tab.c $(PCode_DIR)/PCode.o Table_des_symboles.c Table_des_chaines.c

clean:
	rm -f lex.yy.c *.o y.tab.h y.tab.c lang *~ y.output
	$(MAKE) -C $(PCode_DIR) clean
