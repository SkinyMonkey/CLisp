SRCS_FOLDER	= ./srcs

CC	=	clang

INCS	=	-I./incs

CFLAGS	=	-Wall -Wextra -g3 $(INCS)

SRCS	=	$(SRCS_FOLDER)/lisp.c\
		$(SRCS_FOLDER)/arithmetics.c\
		$(SRCS_FOLDER)/statements.c\
		$(SRCS_FOLDER)/booleans.c

MAIN	=	$(SRCS_FOLDER)/main.c

TEST	=	./tests/test.c

OBJS	=	$(SRCS:.c=.o) $(MAIN:.c=.o)

TESTOBJS=	$(SRCS:.c=.o) $(TEST:.c=.o)

all:	$(OBJS)
	$(CC) $(OBJS)

test:	$(TESTOBJS)
	$(CC) $(TESTOBJS)
	@echo "Testing"
	@echo "------------------------------------------------------"
	./a.out

clean:
	rm -rf $(OBJS)
	rm -rf $(TESTOBJS)

fclean:	clean
	rm -rf ./a.out

re: fclean all

retest: fclean test
