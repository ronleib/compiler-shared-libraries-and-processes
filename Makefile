
all:task1 task2 task3 lib fork clone daemon all allMain2

task1:hello_Ariel.c hello_Ariel.h main1_1.c
	 gcc -o main1_1 hello_Ariel.c main1_1.c

task2:hello_Ariel.h main1_1.c lib
	gcc main1_1.c ./libHello.so -o main1_2

task3:hello_Ariel.h main1_3.c lib
	gcc main1_3.c -fPIC -ldl -o main1_3

lib: hello_Ariel.c hello_Ariel.h
	gcc -shared hello_Ariel.c -fPIC -o libHello.so

fork: main2_1.c 
	gcc -o fork main2_1.c

clone: main2_2.c
	gcc -o clone main2_2.c

daemon: main2_3.c
	gcc -o daemon main2_3.c

allMain2: main2_4.c
	gcc -o Q2 main2_4.c

.PHONY: clean all

clean:
	-rm -f *.o *.so clone all friend fork daemon Q2 main1_1 main1_2 main1_3 libHello.so 2>/dev/null
