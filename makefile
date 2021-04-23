SortStringsDynamic: SortStringsDynamic.o Utilities.o
	gcc SortStringsDynamic.o Utilities.o -o SortStringsDynamic

SortStringsDynamic.o: SortStringsDynamic.c
	gcc -c SortStringsDynamic.c

Utilities.o: Utilities.c
	gcc -c Utilities.c

clean:
	rm *.o SortStringsDynamic