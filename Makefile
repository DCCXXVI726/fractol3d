# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DCCXXVi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 11:14:20 by DCCXXVi           #+#    #+#              #
#    Updated: 2019/06/28 11:37:41 by DCCXXVi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol3d
FLAG = -Wall -Wextra -Werror -g -O3
OBJDIR = objects/
LIBDIR = libft/
SRCDIR = src/
SRC = main.c 
INC = -I $(LIBDIR) \
-I ./includes
LIB = -L $(LIBDIR) -lft
FRWR = -framework SDL2 -F ~/Library/Frameworks
OBJS = $(addprefix objects/, $(SRC:.c=.o))

.PHONY: all clean fclean re git_%

all: $(NAME)

$(NAME): $(OBJS)
	make lib_ft
	$(CC) $(FLAG) $(OBJS) $(INC) $(LIB) $(FRWR) -o $(NAME)

objects/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAG) $(INC) -c $^ -o $@

lib_ft:
	make -C $(LIBDIR)

clean:
	make -C $(LIBDIR) clean
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	make -C $(LIBDIR) fclean
	rm -f $(NAME)
	
re:
	make fclean
	make

frame:
	cp -r ../framework ~/Library/Frameworks

git_%: clean
	git add --all
	git status
	git commit -m "$@"
	git push