
NAME = libftprintf.a
NAMELFT	= libft.a
CC = gcc

CFLAGS = -Wall -Werror -Wextra
OBJDIR = build/
SRCDIR = src/
HEADER = header
LIBB = ./libft/
LIBINCLUDE = ./libft/libft.a


SRCS := ft_printf.c ft_printer.c ft_decode_spec.c ft_print_int.c ft_print_num.c
OBJS := $(SRCS:.c=.o)
SRCS_PREFIXED := $(addprefix $(SRCDIR), $(SRCS))
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJS))

SRCSB := ft_decode_parameter_bonus.c ft_handle_int_bonus.c ft_printer_bonus.c ft_print_hex_bonus.c \
		 ft_print_uns_bonus.c ft_print_str_bonus.c ft_decode_spec_bonus.c ft_print_char_bonus.c \
		 ft_printf_bonus.c ft_print_int_bonus.c ft_print_pointer_bonus.c ft_utility_bonus.c \
		 ft_handle_hex_bonus.c ft_handle_uns_bonus.c ft_utility_2_bonus.c
OBJSB := $(SRCSB:.c=.o)
SRC_BONUS_PREFIXED := $(addprefix $(SCRDIR), $(SRCSB))
OBJECTSB_PREFIXED := $(addprefix $(OBJDIR), $(OBJSB))

$(NAME): $(OBJECTS_PREFIXED) 
	@make -C $(LIBB) all
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJECTS_PREFIXED)
	@echo "libftprintf Done !"

$(OBJECTS_PREFIXED): build/%.o : src/%.c header/ft_printf.h libft/libft.h	
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBB) -c $< -o $@

$(OBJECTSB_PREFIXED): build/%.o : src/%.c header/ft_printf_bonus.h libft/libft.h	
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBB) -c $< -o $@

all: $(NAME)

clean:
	@cd $(LIBB) && make clean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(LIBB)/libft.a
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTSB_PREFIXED)
	@make -C $(LIBB) all
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJECTSB_PREFIXED)
	@echo "libftprintf Bonus Done !"

tester3: bonus
	@cp libftprintf.a ./Libftprintf_test_base/libftprintf.a
	@cp ./libft/libft.h ./Libftprintf_test_base/libft.h
	@cp ./header/ft_printf_bonus.h ./Libftprintf_test_base/libftprintf.h
	@cd ./Libftprintf_test_base && make && ./a.out

tester:
	@cd ./printfTester && make a

tester2: fclean
	-@cd ./ft_printf_tester && sh test m
	-@cd ./ft_printf_tester && sh test b1 b2
