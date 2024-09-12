ORANGE	= \033[0;33m
CYAN	= \033[0;36m

NAME 	= unnecessary_violence
SRCDIR	= ./src
SRCS 	= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJSDIR = objs
OBJS	= $(SRCS:%.cpp=$(OBJSDIR)/%.o)


CC 		= c++
CFLAGS 	= -Werror -Wall -Wextra -std=c++98

all: ${NAME}

${NAME}: ${OBJS}
		 @echo "Compiling $@"
		 ${CC} ${CFLAGS} -o ${NAME} ${OBJS}
		 @echo "${ORANGE}Finished compiling $@"

${OBJS}: ${OBJSDIR}/%.o: ${SRCDIR}/%.cpp
		 @mkdir -p ${@D}
		 ${CC} ${CFLAGS} -c $< -o $@

clean: 
		rm -rf ./objs

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re