
# All sources files
SRCS			=	ft_isdigit.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_putchar.c ft_putstr.c ft_hexaddr.c \
					ft_rnputnbr.c ft_unsignint.c ft_hexsm.c ft_hexcap.c\

OBJS			= $(SRCS:.c=.o) # Coversion of sources (C files to object files to create library)

CC				= cc #compiling rule
RM				= rm -f  #force remove command
CFLAGS			= -Wall -Wextra -Werror #the C Flags

NAME			= libft.a  #name of the library to be created

# The below is the all rule, this rule calls the above rules (i.e) converts all the sources files to object files and creates a library.
# the purpose of object files are that, they are required to create the library. Its like we combine all the object files together to form the library.
# ar rcs is the command to update the library once you make anychanged to the files.
all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

# Clean rule is for removing the object files that we created once the library is successfully created as we no longer need them.
clean:
				$(RM) $(OBJS)

# fclean is the rule to clean all the object files and the library.
fclean:			clean
				$(RM) $(NAME)

# re rule is for using the fclean and repeating the whole process once again
re:				fclean $(NAME)

# .phony rule is that we tell the makefile only to include the rules mentioned in this file, for example if i have a file in my directory as all or clean etc..
# it should not execute that file instead execute the rule from the makefile.
.PHONY:			all clean fclean re bonus