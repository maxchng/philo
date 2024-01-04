# Makefile for philo

# Program name
NAME := philo

# Directory paths
SYS_HEADERS_PATH := ../
LIBFT_NOT_PATH := ../libft_not/
OBJS_PATH := ./objs/

# Source files
SRCS := philo.c \
		validate_input.c \
		set_info.c
# parse_argv.c \
# setup_stats.c \
# is_valid_input.c \
# set_config.c \
# create_philos.c \
# manage_threads.c \
# monitor_threads.c \
# philo_lifecycle.c \
# acquire_forks.c \
# release_forks.c \
# activity_log.c \
# time_utils.c \
# cleanup.c

# Object files
OBJS := $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

# Run the make tool in another directory
LIBFT_NOT_MAKE := $(MAKE) -C$(LIBFT_NOT_PATH)

# Compiler and flags
CC := cc
CFLAGS := -Wall -Werror -Wextra -fsanitize=thread

# Include flags, for the compiler to find additional header files
INCLUDE_SYS_HEADERS := -I$(SYS_HEADERS_PATH)
INCLUDE_LIBFT_NOT := -I$(LIBFT_NOT_PATH)includes/

# Locate, and Link flags, for the compiler to find and link the static library
LDFLAGS := -L$(LIBFT_NOT_PATH)
LDLIBS := -lft_not -pthread

# Remove command and flags
RM := rm
RMFLAGS := -rf

# Default target
all: $(NAME)

# Rule to build program
$(NAME): $(OBJS)
	@$(LIBFT_NOT_MAKE) re
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Pattern rule to compile .c files into .o files
$(OBJS_PATH)%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE_SYS_HEADERS) $(INCLUDE_LIBFT_NOT) -c $< -o $@

# Remove all object files
clean:
	@$(LIBFT_NOT_MAKE) clean
	@$(RM) $(RMFLAGS) $(OBJS)

# Remove all generated files
fclean: clean
	@$(LIBFT_NOT_MAKE) fclean
	@$(RM) $(RMFLAGS) $(NAME)

# Rebuild the program
re: fclean all

# Phony targets
.PHONY: all clean fclean re
