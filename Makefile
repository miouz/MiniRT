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
	@printf "$(GREEN)$(BOLD)✓ Build complete!\n$(RESET)"

#Link the final executable
$(NAME): $(OBJS) $(MINILIBX)
	@printf "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@printf "$(GREEN)$(BOLD)✓ $(NAME) created successfully!\n$(RESET)"

#Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf '$(YELLOW)Woah Compiling $<... (ﾉ◕ヮ◕)ﾉ\n$(RESET)'
	@$(CC) $(CFLAGS) -c $< -o $@

#Build MLX library
$(MINILIBX):
	@printf "$(CYAN)Building this ancient minilibx... p(-,, - )q\n$(RESET)"
	@make -C $(MINILIBX_DIR)

#Include dependency files
-include $(DEPS)

# ============================================================================ #
#                                 DEV TOOLS                                    #
# ============================================================================ #

#Compile with -g flag
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all
	@printf "$(CYAN)Compiling with debug flag...\n$(RESET)"

#Run with valgrind
valgrind: debug
	@printf "$(CYAN)Running valgrind...\n$(RESET)"
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --verbose \
	         --log-file=valgrind-out.txt \
	         ./$(NAME) scenetest.rt

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
