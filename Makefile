rndm.exe: rndm.cc
	g++ -std=c++11 -I /home/liu_lab/shared/include/ -L /home/liu_lab/shared/lib/ -lCore -lMathCore -lHist -lGpad rndm.cc -o rndm.exe
