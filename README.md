README.md

# clone all repository from github
GeCo3: https://github.com/cobilab/geco3
GeCo2: https://github.com/cobilab/geco2 
GeCo: https://github.com/cobilab/geco
Jarvis: https://github.com/cobilab/jarvis
NAF: https://github.com/KirillKryukov/naf 

# install miniconda then run the following commands

conda install -y -c bioconda geco2
conda install -y -c bioconda geco3
conda install -y -c bioconda jarvis

# modify geco and jarvis (modify garbage in defs.h and common.c)

# add cpuUsage.c to to repository for RAM & CPU usage

# modify geco(1,2,3).c and gede(1,2,3).c and Jarvis.c for RAM & CPU usage

# compile and run using

cp Makefile.linux Makefile2.linux
mv Makefile2.linux Makefile
make

#To clean make
make clean

# for easy compile of all projects run compile.sh in bash in parent directory

bash compile.sh

# run cpuUsage by calling extern function in child thread which calculates both CPU and RAM usage
 
./GeCo -l 5 CompressedFileName
./GeDe -v DecompressedFileName
./GeCo2 -v -l 5 CompressedFileName
./GeDe2 -v DecompressedFileName
./GeCo3 -l 1 -lr 0.06 -hs 8 CompressedFileName
./GeDe3 DecompressedFileName
./JARVIS -v -l 3 CompressedFileName
./JARVIS -v -d DecompressedFileName

# We calculate CPU usage over a period of time and then give avg usage, same for RAM usage.

# run.sh is added for running geco gede geco2 gede2 geco3 gede3 jarvis compression and decompression respectively for input file

# multiple files can be provided at once

bash run.sh <filename> <filename> <filename>

# for run.sh to work effectively the <filename> files should be ouside current directory inside "dna" directory

