cd geco/src
cp Makefile.linux Makefile1.linux
mv Makefile2.linux Makefile
make clean
make

cd ../../geco2/src
cp Makefile.linux Makefile1.linux
mv Makefile2.linux Makefile
make clean
make

cd ../../geco3/src
cp Makefile.linux Makefile1.linux
mv Makefile2.linux Makefile
make clean
make

cd ../../jarvis/src
cp Makefile.linux Makefile1.linux
mv Makefile2.linux Makefile
make clean
make

cd ../../

echo "compilation  done"