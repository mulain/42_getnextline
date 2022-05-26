# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 21:58:19 by wmardin           #+#    #+#              #
#    Updated: 2022/05/25 18:11:06 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=4

AR = ar rcs

SRC = 	get_next_line.c\
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)

DIR_BACKUP = /mnt/e/42/Projects/Backup/get_next_line_v01

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) a.out
	
fclean: clean
	$(RM) $(NAME)

re: fclean all
	
test:
	$(CC) $(CFLAGS) $(SRC)
	./a.out

testnoflag:
	$(CC) -D BUFFER_SIZE=4 $(SRC)
	./a.out

save:
	mkdir -p $(DIR_BACKUP)
	cp *.c *.h Makefile $(DIR_BACKUP)