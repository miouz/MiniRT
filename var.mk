# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    var.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:06:01 by mzhou             #+#    #+#              #
#    Updated: 2025/04/21 16:01:54 by mzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

# ============================================================================ #
#                               COMPILOR & FLAGS                                  #
# ============================================================================ #

MAKE_CMD ?= $(MAKE)
CC := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -I($INCLUDE_DIR)
CFLAGS += -MMD -MP
DEBUG_FLAGS := -g
# LIBMI_FLAGS = -L$(LIB_DIR) -lmi
LFLAGS := -L.. -lmlx -L$(MINILIBX_DIR) -lXext -lX11 -lm


#minilibx variables
MINILIBX := $(MINILIBX_DIR)libmlx.a
MINILIBX_H := $(MINILIBX_DIR)*.h

# ============================================================================ #
#                                DIRECTORIES                                   #
# ============================================================================ #

SRC_DIR := srcs
OBJ_DIR := objs
INCLUDE_DIR := includes
DEP_DIR := $(OBJS_DIR)/.deps
TEST_DIR := tests
MINILIBX_DIR := minilibx-linux

#subdirectories
VECTOR_DIR := $(SRC_DIR)/vector_operations
INTER_DIR := $(SRC_DIR)/intersection
RENDER_DIR := $(SRC_DIR)/rendering
SCREEN_DIR := $(SRC_DIR)/parsing
UTILS_DIR := $(SRC_DIR)/utils

# ============================================================================ #
#                                  SOURCES                                     #
# ============================================================================ #

#Vector operations
VECTOR_SRC := $(VECTOR_DIR)/vector_operations.c \
			  $(VECTOR_DIR)/vector_utils.c

#Intersection calculations
INTER_SRC := $(INTER_DIR)/get_intersection.c \
			 $(INTER_DIR)/ray_sphere_intersect.c \
			 $(INTER_DIR)/ray_plane_intersect.c \
			 $(INTER_DIR)/ray_cylinder_intersect.c

#srcs variables
SRCS :=	$(VECTOR_SRC) \
		$(INTER_SRC) \

#Convert source files to object files
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# ============================================================================ #
#                                   COLORS                                     #
# ============================================================================ #

#color variables
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
RESET := \033[0m
BOLD := \033[1m
