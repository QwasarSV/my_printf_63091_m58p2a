CC = gcc
CFLAGS += -Wall -Werror -Wextra
CFLAGS_DEBUG = $(CFLAGS)
MAIN = my_printf
SRCS = main.c \
		my_printf.c reverse_string.c itoa.c ltoa.c dec_2_hex_to_a.c dec_2_oct.c
OBJS = $(SRCS: .c = .o) 

all: $(MAIN)

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(LINKERFLAG) $^

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(MAIN) $(DEBUG)

re: fclean all