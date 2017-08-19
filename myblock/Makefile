objs:=obj/block_display.o obj/main.o obj/print.o obj/block_options.o obj/timer.o\
	  obj/check_border.o
INC:=-Iinclude

bin/main:$(objs)
	gcc -g $^ $(INC) -o $@

$(objs):obj/%.o:src/%.c
	gcc -c $< $(INC) -o $@


clean:
	rm $(objs)
