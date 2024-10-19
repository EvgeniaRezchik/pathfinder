CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

src_dir = src
obj_dir = obj
library = libmx.a

src_files = $(wildcard $(src_dir)/*.c)

obj_files = $(src_files:$(src_dir)/%.c=$(obj_dir)/%.o)

all:
	make LIBMX

LIBMX: $(library)

$(library): $(obj_files)
	ar rcs $@ $^

$(obj_dir)/%.o: $(src_dir)/%.c | $(obj_dir)
	$(CC) $(CFLAGS) -c $< -o $@

$(obj_dir):
	mkdir -p $@

clean:
	rm -rf $(obj_dir)

uninstall:
	rm -f $(library)

reinstall: uninstall all

