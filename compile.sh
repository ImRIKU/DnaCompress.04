echo "compiling....\n"

cd geco/src
cp Makefile.linux Makefile2.linux
mv Makefile2.linux Makefile
make clean
make

cd ../../geco2/src
cp Makefile.linux Makefile2.linux
mv Makefile2.linux Makefile
make clean
make

cd ../../geco3/src
cp Makefile.linux Makefile2.linux
mv Makefile2.linux Makefile
make clean
make

cd ../../jarvis/src
cp Makefile.linux Makefile2.linux
mv Makefile2.linux Makefile
make clean
make

echo "compile done\n"