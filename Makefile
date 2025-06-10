#Makefile for using OpenGL of Red Hat Linux 7.x
#CSE 4200, Matthew Borja, Spring 2024

PROG    = mysaniquarium
CFLAGS  = -w -s -O2 -ansi -DSHM
XLIBS   = -lX11
LIBS    = -lglut -lGLU -lGL
INCLS   = -I/usr/X11R/include
LIBDIR  = -L/usr/X11/lib
#source codes
SRCS = $(PROG).cpp functions.cpp fish.cpp food.cpp
#substitute .cpp by .o to obtain object filenames
OBJS = $(SRCS:.cpp=.o)

#$< evaluates to the target's dependencies,
#$@ evaluates to the target

$(PROG): $(OBJS)
	g++ -o $@ $(OBJS)  $(LIBDIR) $(LIBS) $(XLIBS)

$(OBJS):
	g++ -c  $*.cpp $(INCLS)

clean:
	rm $(OBJS)

