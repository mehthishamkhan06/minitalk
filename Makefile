name = minitalk

SRCS = server.c client.c

OBJS			= $(SRCS:.c=.o)

BONUS = server_bonus.c client_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

CC : cc 
RM : rm -f
Flags : -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus