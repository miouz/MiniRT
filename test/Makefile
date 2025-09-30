include ../var.mk

TEST_BIN := $(NAME)_test
CFLAGS += -I../srcs/includes

#Use pkg-config to find Criterion automatically
CRITERION_CFLAGS := $(shell pkg-config --cflags criterion 2>/dev/null)
CRITERION_LIBS := $(shell pkg-config --libs criterion 2>/dev/null)

TEST_LDFLAGS := $(CRITERION_LIBS) -lm

# ============================================================================ #
#                                DIRECTORIES                                   #
# ============================================================================ #

PARENT_DIR := ..
PROJECT_SRC_DIR := $(PARENT_DIR)/srcs
PROJECT_OBJ_DIR := $(PARENT_DIR)/objs
TEST_SRC_DIR := .
TEST_OBJ_DIR := build

# ============================================================================ #
#                              SOURCE FILES                                    #
# ============================================================================ #

#Project sources (exclude main.c)
VECTOR_SRC := $(wildcard $(PROJECT_SRC_DIR)/vector_operations/*.c)
INTER_SRC := $(wildcard $(PROJECT_SRC_DIR)/intersection/*.c)

PROJECT_SRCS := $(filter-out %/main.c, $(VECTOR_SRC) $(INTER_SRC))
PROJECT_OBJS:= $(PROJECT_SRCS:$(PROJECT_SRC_DIR)/%.c=$(PROJECT_OBJ_DIR)/%.o)

#Test files
TEST_SRCS := $(wildcard test_*.c)
TEST_OBJS:= $(TEST_SRCS:%.c=$(TEST_OBJ_DIR)/%.o)

# ============================================================================ #
#                                   RULES                                      #
# ============================================================================ #

all: $(TEST_BIN)
	@printf '$(GREEN)✓ All tests built in single executable$(RESET)'

$(TEST_BIN): $(TEST_OBJS) $(PROJECT_OBJS)
	@echo "$(CYAN)Linking $(TEST_BIN)...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@ $(TEST_LDFLAGS)
	@echo "$(GREEN)$(BOLD)✓ $(TEST_BIN) created successfully!$(RESET)"

#Compile project source files to object files
$(PROJECT_OBJ_DIR)/%.o: $(PROJECT_SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf '$(YELLOW)Woah compiling project srcs $<... (ﾉ◕ヮ◕)ﾉ$(RESET)'
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

#Compile test files to object files
$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(CRITERION_CFLAGS) -c $< -o $@
	@printf '$(YELLOW)Woah compiling test srcs $<... (ﾉ◕ヮ◕)ﾉ$(RESET)'

# ============================================================================ #
#                                 🍻CLEANNING                                    #
# ============================================================================ #

clean:
	@rm -rf $(PROJECT_OBJ_DIR)/*.o $(TEST_OBJ_DIR)/*.o
	@printf '🧹$(GREEN)Cleaning .o files... m(｡≧ｴ≦｡)m$(RESET)🧹🧹\n'

fclean: clean
	@rm -f $(TEST_BIN)
	@printf '🧹🧹$(GREEN)Nothing left...ლ(◉◞౪◟◉ )ლ$(RESET)🧹🧹\n'

re: fclean $(TEST_BIN)

# ============================================================================ #
#                              MAKEFILE SETTING                                #
# ============================================================================ #

#not print command
.SILENT:

#Delete target files if command fails
.DELETE_ON_ERROR:

.PHONY: all clean fclean re test debug valgrind
