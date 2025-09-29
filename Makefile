# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:54:02 by mzhou             #+#    #+#              #
#    Updated: 2025/04/21 15:55:13 by mzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include var.mk

# ============================================================================ #
#                                  🫡RULES                                      #
# ============================================================================ #

#---targets and rules$(NAME): $(OBJS)
.PHONY: all clean fclean re bonus test debug leak help

# Default target
all: $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Build complete!$(RESET)"

# Link the final executable
$(NAME): $(OBJS) $(MLX_LIB)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) created successfully!$(RESET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Build MLX library
$(MLX_LIB):
	@echo "$(CYAN)Building MLX library...$(RESET)"
	@make -C $(MLX_DIR)

# Include dependency files
-include $(DEPS)

# ============================================================================ #
#                                 CLEANNING                                    #
# ============================================================================ #



#---clean🍻
clean:
	# @$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	# rm -f $(INCLUDE_DIR)libft.h $(INCLUDE_DIR)ft_printf.h $(INCLUDE_DIR)get_next_line.h $(INCLUDE_DIR)mlx.h $(INCLUDE_DIR)mlx_int.h
	# rm -f $(INCLUDE_BONUS_DIR)libft.h $(INCLUDE_BONUS_DIR)ft_printf.h $(INCLUDE_BONUS_DIR)get_next_line.h $(INCLUDE_BONUS_DIR)mlx.h $(INCLUDE_BONUS_DIR)mlx_int.h
	@printf '🧹$(GREEN)It was a good moment with you my .o friends, but i cleaned you upm(｡≧ｴ≦｡)m$(RESET)🧹🧹'
fclean: clean
	@$(MAKE) -C $(MINILIBX_DIR) fclean
	@rm -f $(NAME)
	# rm -f $(NAME_BONUS)
	@printf '🧹🧹$(GREEN)everything has gone with fclean ლ(◉◞౪◟◉ )ლ$(RESET)🧹🧹'

re: fclean $(NAME)
#
# #defaut target
# all: $(NAME)
#
# #build minilibx
# $(MINILIBX):
# 	@$(MAKE_CMD) -C $(MINILIBX_DIR)
# 	@echo "$(GREEN)Nobody knows how to use but this ancient minilibx has been build p(-,, - )q $(RESET)"
#
# # #build lib
# # $(LIB):
# # 	$(MAKE_CMD) -C $(LIB_DIR)
# # 	cp $(LIB_H) $(INCLUDE_DIR)
# # 	cp $(LIB_H) $(INCLUDE_BONUS_DIR)
# # 	@echo "$(GREEN)Libmi.a has been build and added successfully \(^o^)/$(RESET)"
#
# $(OBJS):
# 	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -c $< -o $@
#
# #build mandatory part
# $(NAME): $(MINILIBX) $(SRCS_MANDATORY)
# 	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRCS_MANDATORY) -I$(MINILIBX_DIR) -I$(INCLUDE_DIR) -o $(NAME) $(LFLAGS)
# 	@printf '$(GREEN)Woah the miniRT program is build(ﾉ◕ヮ◕)ﾉ$(RESET)'
#
#
# #build bonus part
# # bonus: fclean $(NAME_BONUS)
# #
# # $(NAME_BONUS): $(LIB) $(MINILIBX) $(SRCS_BONUS)
# # 	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRCS_BONUS) -I$(MINILIBX_DIR) -I$(INCLUDE_BONUS_DIR) -o $(NAME_BONUS) $(LIBMI_FLAGS) $(LFLAGS)
# # 	@echo "$(GREEN)Woah the bonus is build(ﾉ◕ヮ◕)ﾉ$(RESET)"
#
#
# debug:fclean
# 	# $(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)" $(NAME)
# 	$(MAKE) MAKE_CMD="make debug"
#
#
#
# .PHONY: clean fclean re bonus debug all test
