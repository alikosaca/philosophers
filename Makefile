NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

FT_PRINTF_PATH = ft_printf

FT_PRINTF = $(FT_PRINTF_PATH)/ft_printf.a

SRCS = main.c \
	   parse_arguments.c \
	   init_simulation.c \
	   simulation.c \
	   philosopher_actions.c \
	   monitor.c \
	   utils.c \
	   time_utils.c \
	   cleanup.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(OBJS)
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re