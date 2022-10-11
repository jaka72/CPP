NAME="myout"


OBJDIR := objdir
OBJS := $(addprefix $(OBJDIR)/,main.o bar.o baz.o)

$(OBJDIR)/%.o : %.c
		$(COMPILE.c) $(OUTPUT_OPTION) $<
#		gcc $(OBJS) $<
#		gcc -c  -o $@ $<

#all: $(NAME) $(OBJS)

$(OBJS): | $(OBJDIR)
	@c++ $(CFLAGS) $(OBJ_FILES) -o $(NAME)


$(OBJDIR):	
		mkdir $(OBJDIR)


#compile the executable
#$(NAME):	$(OBJ_FILES)


clean:
	rm -rf $(OBJDIR)