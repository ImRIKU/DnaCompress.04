# clone all repository from github
GeCo3: https://github.com/cobilab/geco3
GeCo2: https://github.com/cobilab/geco2 
GeCo: https://github.com/cobilab/geco
Jarvis: https://github.com/cobilab/jarvis
NAF: https://github.com/KirillKryukov/naf 

# modify geco and jarvis (modify garbage in defs.h and common.c)

# add cpuUsage.c to to repository for RAM & CPU usage

# modify geco(1,2,3).c and gede(1,2,3).c and jarvis.c for RAM & CPU usage

# run cpu usage by calling extern function

# compile and run using

cp Makefile.linux Makefile2.linux
mv Makefile2.linux Makefile
make

#To clean make
make clean

# for easy compile of all projects run compile.sh in bash

bash compile.sh
 
./GeCo -l 5 CompressedFileName
./GeDe -v DecompressedFileName
./GeCo2 -v -l 5 CompressedFileName
./GeDe2 -v DecompressedFileName
./GeCo3 -l 1 -lr 0.06 -hs 8 CompressedFileName
./GeDe3 DecompressedFileName
./JARVIS -v -l 3 CompressedFileName
./JARVIS -v -d DecompressedFileName

# We calculates CPU usage over a period of time and gives avg usage.

# We calculate the RAM usage at the beginning of the program and at the middle of the program to get effective RAM 

# run.sh is added for running geco gede geco2 gede2 geco3 gede3 jarvis compression and decompression respectively for input file

# multiple files can be provided at once

bash run.sh <filename> <filename> <filename>

# for run.sh to work effectively the <filename> files should be ouside current directory inside "dna" directory

