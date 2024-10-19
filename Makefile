CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

src_dir = src
obj_dir = obj
libmx_dir = libmx
library = libmx/libmx.a
executable = pathfinder

src_files = $(wildcard $(src_dir)/*.c)

obj_files = $(src_files:$(src_dir)/%.c=$(obj_dir)/%.o)

all:
	make PATHFINDER

PATHFINDER: $(executable)

$(executable): $(library) $(obj_files)
	$(CC) $(CFLAGS) $(obj_files) -o $(executable) $(library)

$(library):
	cd $(libmx_dir) && make

$(obj_files): | $(obj_dir)

$(obj_dir)/%.o: $(src_dir)/%.c | $(obj_dir)
	$(CC) $(CFLAGS) -c $< -o $@

$(obj_dir):
	mkdir -p $@

clean:
	cd $(libmx_dir) && make clean
	rm -rf $(obj_dir)

uninstall:
	cd $(libmx_dir) && make uninstall
	rm -f $(executable)

reinstall: uninstall all

