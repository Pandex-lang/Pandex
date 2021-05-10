# note : Makefile versions have difference in main target
# & I used of dependency for all: ( in my version , first
# target of code is default target )

cc = gcc
program=Pandex.c
flags = -I ./include
convert = Pandex

all: path

build: 
	$(cc) $(program) $(flags) -o $(convert)
	
path: build
	export PATH=$PATH:pwd	

# // 32767 Max file name size Windows
