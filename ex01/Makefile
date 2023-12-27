NAME		=	ex01

CXX			=	c++

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp

CXXFLAGS	=	-Wall -Wextra -Werror -g -Wshadow -std=c++98 #-fsanitize=address

RM			=	rm -f

OBJS		=	$(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
