CC = g++

target = particula.exe

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

FLGS =

$(target): $(OBJS)
	$(CC) -o $@ $^
$(OBS):%.o%.cpp
	$(CC) -c $< -o $@

clean:
		@rm -f *.o *~
borra:
		@rm -f *.o *.exe *~
run:
		@./$(target)