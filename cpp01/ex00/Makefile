ORANGE	= \033[0;33m
CYAN	= \033[0;36m
WHITE	= \033[0m
PURPLE	= \033[1;35m

NAME 	= zombie
SRCDIR	= .
SRCS 	= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJSDIR = objs
OBJS	= $(SRCS:%.cpp=$(OBJSDIR)/%.o)


CC 		= c++
CFLAGS 	= -Werror -Wall -Wextra -std=c++98

all: ${NAME}

${NAME}: ${OBJS}
		 @echo "${CYAN}Compiling $@"
		 ${CC} ${CFLAGS} -o ${NAME} ${OBJS}
		 @echo "${PURPLE}Finished compiling $@"

${OBJS}: ${OBJSDIR}/%.o: ${SRCDIR}/%.cpp
		 @mkdir -p ${@D}
		 ${CC} ${CFLAGS} -c $< -o $@

clean: 
		rm -rf ./objs

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re