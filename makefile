yasm -f elf64 -g dwarf2 -l part2.lst part2.asm
gcc part2.o -no-pie
./a.out
