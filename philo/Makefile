NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=pthread

RM = rm -f

SRCS = main.c \
       error.c \
       utils.c \
       handle.c \
       init_sim.c \
       routine.c \
       run_simulation.c \
       thread_sim.c \
       validate.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
