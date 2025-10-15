# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    var.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anony <anony@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:06:01 by mzhou             #+#    #+#              #
#    Updated: 2025/10/02 20:58:18 by anony            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

# ============================================================================ #
#                               COMPILOR & FLAGS                                  #
# ============================================================================ #

MAKE_CMD ?= $(MAKE)
CC := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -I$(INCLUDE_DIR)
CFLAGS += -MMD -MP
DEBUG_FLAGS := -g
# LIBMI_FLAGS = -L$(LIB_DIR) -lmi
MINILIBX_DIR := ./minilibx-linux
LFLAGS := -lmlx -L$(MINILIBX_DIR) -lXext -lX11 -lm


#minilibx variables
MINILIBX := $(MINILIBX_DIR)/libmlx.a
MINILIBX_H := $(MINILIBX_DIR)/*.h

# ============================================================================ #
#                                DIRECTORIES                                   #
# ============================================================================ #

SRC_DIR := srcs
OBJ_DIR := objs
INCLUDE_DIR := includes
DEP_DIR := $(OBJ_DIR)/.deps
TEST_DIR := tests

#subdirectories
VECTOR_DIR := $(SRC_DIR)/vector_operations
INTER_DIR := $(SRC_DIR)/intersections
COLORS_DIR := $(SRC_DIR)/get_colors
PIXELS_DIR := $(SRC_DIR)/get_pixels_coordinates
UTILS_DIR := $(SRC_DIR)/utils
PARSING_DIR := $(SRC_DIR)/parsing


# ============================================================================ #
#                                  SOURCES                                     #
# ============================================================================ #

#main
# MAIN_SRC := 

#Vector operations
VECTOR_SRC := $(VECTOR_DIR)/vector_operations.c \
			  $(VECTOR_DIR)/vector_operations2.c

#Intersection calculations
INTER_SRC := $(INTER_DIR)/get_intersection.c \
			 $(INTER_DIR)/ray_sphere_intersect.c \
			 $(INTER_DIR)/ray_plane_intersect.c \
			 $(INTER_DIR)/ray_cylinder_intersect.c

#Get colors
COLORS_SRC := $(COLORS_DIR)/get_ortho_vector.c \
			  $(COLORS_DIR)/get_colors.c

#Get pixels coordinates
PIXELS_SRC := $(PIXELS_DIR)/get_screen.c \
			  $(PIXELS_DIR)/get_pixels_coordinates.c

#Utils
UTILS_SRC := $(UTILS_DIR)/utils.c \
			 $(UTILS_DIR)/minilibx.c

#Parsing
PARSING_SRC := $(PARSING_DIR)/checkers.c \
			   $(PARSING_DIR)/ft_atod_check_format.c \
			   $(PARSING_DIR)/ft_atoi_check_format.c \
			   $(PARSING_DIR)/ft_itoa.c \
			   $(PARSING_DIR)/getters_double.c \
			   $(PARSING_DIR)/getters_int.c \
			   $(PARSING_DIR)/parse.c \
			   $(PARSING_DIR)/parse_objects.c \
			   $(PARSING_DIR)/parse_utils.c \

#Main
MAIN_SRC := $(SRC_DIR)/main.c

#srcs variables
SRCS :=	$(VECTOR_SRC) \
		$(INTER_SRC) \
		$(COLORS_SRC) \
		$(PIXELS_SRC) \
		$(UTILS_SRC) \
		$(MAIN_SRC)


# Get all .c files recursively
# SRCS := $(shell find $(SRC_DIR) -name '*.c')

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
