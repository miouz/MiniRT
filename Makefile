# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anony <anony@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:54:02 by mzhou             #+#    #+#              #
#    Updated: 2025/10/01 16:14:38 by anony            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include var.mk

# ============================================================================ #
#                                  🫡RULES                                      #
# ============================================================================ #


#Default target
all: $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Build complete!$(RESET)"

#Link the final executable
$(NAME): $(OBJS) $(MINILIBX)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) created successfully!$(RESET)"

#Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf '$(YELLOW)Woah Compiling $<... (ﾉ◕ヮ◕)ﾉ$(RESET)'
	@$(CC) $(CFLAGS) -c $< -o $@

#Build MLX library
$(MINILIBX):
	@echo "$(CYAN)Building this ancient minilibx... p(-,, - )q$(RESET)"
	@make -C $(MINILIBX_DIR)

#Include dependency files
-include $(DEPS)

# ============================================================================ #
#                                 DEV TOOLS                                    #
# ============================================================================ #

#Compile with -g flag
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all
	@echo "$(CYAN)Compiling with debug flag...$(RESET)"

#Run with valgrind
valgrind: debug
	@echo "$(CYAN)Running valgrind...$(RESET)"
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --verbose \
	         --log-file=valgrind-out.txt \
	         ./$(NAME) scenes/test.rt

#Run unit test with criterion
test: fclean
	$(MAKE) -C $(TEST_DIR)

# ============================================================================ #
#                                 🍻CLEANNING                                    #
# ============================================================================ #

clean:
	@rm -rf $(OBJ_DIR)
	@printf '🧹$(GREEN)Cleaning .o files... m(｡≧ｴ≦｡)m$(RESET)🧹🧹\n'

fclean: clean
	@rm -f $(NAME)
	# rm -f $(NAME_BONUS)
	@printf '🧹🧹$(GREEN)Nothing left...ლ(◉◞౪◟◉ )ლ$(RESET)🧹🧹\n'

re: fclean $(NAME)

# ============================================================================ #
#                              MAKEFILE SETTING                                #
# ============================================================================ #

#not print command
.SILENT:

#Delete target files if command fails
.DELETE_ON_ERROR:

.PHONY: all clean fclean re bonus test debug valgrind
