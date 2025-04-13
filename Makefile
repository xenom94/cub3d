NAME		=	cub3d
CC			=	cc 
CFLAGS		=	-Imlx_linux -Werror -Wextra -Wall
RM			=	rm -rf
SRCS		=	
OBJS		= ${SRCS:.c=.o}

all			:	$(NAME)

$(NAME)	: $(SRCS)
		make -C libft
		$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME) 
			
clean		:
			$(RM) $(OBJS)
			make clean -C libft

fclean		: clean
			$(RM) $(NAME)
			make fclean -C libft

re			: fclean all

.PHONY: all clean fclean re