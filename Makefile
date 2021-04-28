all: build run

build:
	gcc -m32 main.c -o demo_baza

run:
	./demo_baza -o 4 4<>xpo.dat -tel 022207000 -ime Nii -priimek Son -dan 30 -mesec 11 -leto 2000
setup:
	 main.c

clean:
	rm -f demo_baza
