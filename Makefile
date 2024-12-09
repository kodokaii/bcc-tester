NAME 		= bcc-tester

CC 			= cc
RM			= rm -f
CFLAGS 		+= -Wall -Wextra -O3
CLINKS		=

SRC 		= main.c\
				bcrypt_tester.c\
				blowfish.c\
				combo.c\
				variants.c

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CLINKS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re