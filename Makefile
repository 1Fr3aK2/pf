SRCS =  src/algorithms/sort_three.c src/algorithms/sort_four.c \
        src/algorithms/sort_five.c src/algorithms/push_swap.c src/algorithms/sort.c \
        src/moves/push.c src/moves/reverse.c src/moves/rotate.c src/moves/swap.c \
        src/errors/errors.c src/utils/utils.c src/utils/utils_2.c src/utils/push_swap_utils.c \
        src/utils/push_swap_utils_2.c src/stacks/init_stacks.c \
        src/main/main.c

NAME = push_swap

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJ_DIR = obj

# Lista de arquivos .o correspondentes aos .c
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTFDIR = ./includes/libft/ft_printf
FT_PRINT = $(FT_PRINTFDIR)/libftprintf.a

all: $(NAME)

# Regra para criar o executável a partir dos arquivos objeto e bibliotecas
$(NAME): $(OBJS) $(LIBFT) $(FT_PRINT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINT)
	@echo $(NAME) ready!

# Regra para compilar arquivos objeto a partir de arquivos fonte
$(OBJ_DIR)/%.o: src/%.c | $(CREATE_DIR)
	@mkdir -p $(@D)  # Cria o diretório para o arquivo objeto, se não existir
	@$(CC) $(CFLAGS) -c $< -o $@

$(CREATE_DIR):
	@mkdir -p $(OBJ_DIR)/algorithms
	@mkdir -p $(OBJ_DIR)/moves
	@mkdir -p $(OBJ_DIR)/errors
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/stacks
	@mkdir -p $(OBJ_DIR)/main

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(FT_PRINT):
	@$(MAKE) -C $(FT_PRINTFDIR) --no-print-directory

clean:
	@$(RM) -r $(OBJ_DIR)  # Remove o diretório obj e seu conteúdo
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory  # Limpa os arquivos da biblioteca libft
	@$(MAKE) -C $(FT_PRINTFDIR) clean --no-print-directory  # Limpa os arquivos da biblioteca ft_printf

fclean: clean
	@$(RM) $(NAME)  # Remove o executável
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(FT_PRINTFDIR) fclean --no-print-directory
re: fclean all

.PHONY: all clean fclean re
