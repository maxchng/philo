# Makefile for philosophers

# Program name
NAME := philo

# Directory paths
SYS_HEADERS_PATH := ../
LIBFT_PATH := ../libft/
OBJS_PATH := ./objs/

# Source files
SRCS := philo.c \
		parse_argv.c \
		is_valid_input.c \
		set_philo_config.c \
		philo_requirements.c

# Object files
OBJS := $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

# Run the make tool in another directory
LIBFT_MAKE := $(MAKE) -C$(LIBFT_PATH)

# Compiler and flags
CC := cc
CFLAGS := -Wall -Werror -Wextra

# Include flags, for the compiler to find additional header files
INCLUDE_SYS_HEADERS := -I$(SYS_HEADERS_PATH)
INCLUDE_LIBFT := -I$(LIBFT_PATH)includes/

# Locate, and Link flags, for the compiler to find and link the static library
LDFLAGS := -L$(LIBFT_PATH)
LDLIBS := -lft -pthread

# Remove command and flags
RM := rm
RMFLAGS := -rf

# Default target
all: $(NAME)

# Rule to build program
$(NAME): $(OBJS)
	@$(LIBFT_MAKE) re
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Pattern rule to compile .c files into .o files
$(OBJS_PATH)%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE_SYS_HEADERS) $(INCLUDE_LIBFT) -c $< -o $@

# Remove all object files
clean:
	@$(LIBFT_MAKE) clean
	@$(RM) $(RMFLAGS) $(OBJS)

# Remove all generated files
fclean: clean
	@$(LIBFT_MAKE) fclean
	@$(RM) $(RMFLAGS) $(NAME)

# Rebuild the program
re: fclean all

# Phony targets
.PHONY: all clean fclean re
