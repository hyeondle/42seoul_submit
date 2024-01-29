############ PRESET #############

	############ PARAMETER #############

		PRESET_CFLAGS_FOR_SUBMIT	= -Wall -Wextra -Werror
		PRESET_CFLAGS_FOR_DEBUG		= -Wall -Wextra -Werror -g
		PRESET_CFLAGS_FOR_ASAN		= -Wall -Wextra -Werror -g -g3 -fsanitize=address
		PRESET_CFLAGS_FOR_MSAN		= -Wall -Wextra -Werror -o -g3 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
		PRESET_CFLAGS_FOR_TESTING	= -g
		PRESET_CFLAGS_FOR_TEST_MSAN	=  -g -g3 -fsanitize=address

		PRESET_LDFLAGS_FOR_SUBMIT	= 
		PRESET_LDFLAGS_FOR_DEBUG	= -g
		PRESET_LDFLAGS_FOR_ASAN		= -g -g3 -fsanitize=address
		PRESET_LDFLAGS_FOR_MSAN		= -g -g3 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
	

CC=c++
CFLAGS=-std=c++98 $(PRESET_CFLAGS_FOR_SUBMIT)
LDFLAGS=-std=c++98 $(PRESET_LDFLAGS_FOR_SUBMIT)

# CFLAGS=-std=c++98 $(PRESET_CFLAGS_FOR_ASAN)
# LDFLAGS=-std=c++98 $(PRESET_LDFLAGS_FOR_ASAN)

SRCDIR = src
OBJDIR = obj
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
HEADERS=$(wildcard $(SRCDIR)/*.hpp)
#SOURCES=LibCpp.cpp
#OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
OBJECTS=$(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
#OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=./bins/Webserv

# 제외하고자 하는 파일 목록을 정의합니다.
SOURCES_IGNORE := 	$(SRCDIR)/Request_new.cpp \
					#$(SRCDIR)/Request3.cpp \
					#$(SRCDIR)/main.cpp \
                    $(SRCDIR)/echo_server.cpp \
                    $(SRCDIR)/another_file_to_ignore.cpp



# 이미 찾은 소스 목록에서 제외할 파일들을 제거합니다.
SOURCES := $(filter-out $(SOURCES_IGNORE),$(SOURCES))


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@


#=============== MAINTENANCE RULES ===============#

#-------- COMPILE OBJ_FILES --------#

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR) #[^각주1]
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

#=============== BASIC RULES ===============#

#-------- REQUIREMENT --------#

clean :
	rm -f $(OBJECTS)
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(EXECUTABLE)

re : 
	$(MAKE) fclean
	@echo 1 > /dev/null
	$(MAKE) all

#-------- ADDITIONAL --------#

run :
	$(MAKE) $(EXECUTABLE)
	./$(EXECUTABLE)

test :
	$(MAKE) $(EXECUTABLE)
	./$(EXECUTABLE) bins/w3.conf

post_test :
	curl -v -X POST -H "Transfer-Encoding: chunked" -T ./bins/testfile2.txt http://127.0.0.1:8081/directory/testfile.txt

post_test2 :
	curl -v -X POST -T ./bins/testfile.txt http://127.0.0.1:8081/directory/youpi.bla

post_test3 :
	curl -v -X POST -H "Transfer-Encoding: chunked" -T ./bins/testfile.txt http://127.0.0.1:8081/directory/testfile.txt

post_test4 :
	curl -v -X POST -H "Transfer-Encoding: chunked" -T ./bins/testfile.txt http://127.0.0.1:8081/directory/youpi.bla



post_test6 :
	curl -v -X POST -H "Transfer-Encoding: chunked" -T ./bins/testfile3.txt http://127.0.0.1:8081/directory/youpi.bla

#=============== PHONY RULES ===============#

.PHONY :	all							\
		 	clean	fclean	re			\
			run		test	post_test	\


# [^각주1] : 조건의 파이프에 대하여, chatgpt 작성
# The | symbol in this context is a Makefile order-only prerequisite. 
# It is used to specify a dependency of the rule without specifying
#	that the rule should be rerun if the dependency changes.
#
# In the rule you provided, $(OBJDIR)/%.o: %.cpp | $(OBJDIR),
#	the | symbol separates the regular prerequisites (%.cpp) from the 
#	order-only prerequisites ($(OBJDIR)). This means that the $(OBJDIR)
#	directory is a prerequisite for the rule, but the rule will not be
#	rerun if the $(OBJDIR) directory changes.
#
# The rule is saying that any object file (%.o) located in the $(OBJDIR)
#	directory should depend on the corresponding source file (%.cpp) in
#	the current directory, and that the object file should be built by
#	compiling the source file with the compiler specified in $(CC) and
#	the flags specified in $(CFLAGS).
