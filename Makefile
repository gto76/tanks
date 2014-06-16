tanks: src/input.c  src/menu.c  src/process.c  src/init.c  src/main.c  src/output.c
	gcc  src/input.c  src/menu.c  src/process.c  src/init.c  src/main.c  src/output.c -o tanks `pkg-config --cflags --libs allegro` -lm
