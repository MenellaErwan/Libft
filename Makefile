GCC := gcc -Wall -Wextra -Werror
AR := ar -crs
LIBFT := $(wildcard ./libft/*.c)
GNL := $(wildcard ./get_next_line/*.c)
NAME := libft.a
OBJ := $(GNL:.c=.o) $(LIBFT:.c=.o)
HEADER := ./libft/libft.h ./get_next_line/get_next_line.h
BUFFER := 64

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(GCC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all