NAME = ft_ls

HEADER = ls.h

all : $(NAME)

CONVC = $(SRC:.c=.o)

SRC = ls.c \
	  ft_fill.c \
	  ft_malloc.c \
	  ft_opt_l.c \
	  ft_printnmath.c \
	  ft_reordersing.c \
	  ft_setup.c \
	  ft_mallocat.c \
	  main.c \
	  recu2.c \

$(NAME):
		Make -C Libft/
			gcc -c $(SRC)
				gcc -Wall -Wextra -Werror libft/libft.a $(SRC) -o $(NAME)

clean :
		make -C Libft/ clean
			rm -rf $(CONVC)

fclean : clean
		make -C Libft/ fclean
			rm -rf $(CONVC) ft_ls

re : fclean all

.PHONY : all clean re fclean
