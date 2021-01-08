#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "list.h"
#include "hash.h"
#include "bitmap.h"
#include "round.h"
#include "debug.h"
#include "limits.h"

int main(){

	struct list listNode[10];
	struct hash hashNode[10];
	struct bitmap bitmapNode[10];

	char inst[50];
	char *str, *name, *arg;
	int bitElemNum;
	int listNum = 0, hashNum = 0, bitmapNum = 0;

	while(1){
		fgets(inst, sizeof(inst), stdin);
		inst[strlen(inst) - 1] = '\0';
		str = strtok(inst, " ");

/*	
//				instruction : create				//
*/
		if(strcmp(str, "create") == 0){
			str = strtok(NULL, " ");

			//list
			if(strcmp(str, "list") == 0){
				name = strtok(NULL, " ");
				
				if(listNum < 10){
					strcpy(listNode[listNum].name, name);
					list_init(&listNode[listNum]);
					listNum++;
				}

				else{
					printf("Maximum number of list = 10!\n");
					continue;
				}
			}

			//hash table
			else if(strcmp(str, "hashtable") == 0){
				name = strtok(NULL, " ");
				
				if(hashNum < 10){
					strcpy(hashNode[hashNum].name, name);
					hash_init(&hashNode[hashNum],hash_func, less_func, NULL);
					hashNum++;
				}

				else{
					printf("Maximum number of hash = 10!\n");
					continue;
				}
			}

			//bitmap
			else if(strcmp(str, "bitmap") == 0){
				name = strtok(NULL, " ");
				arg = strtok(NULL, " ");
				bitElemNum = atoi(arg);

				if(bitmapNum < 10){
					bitmapNode[bitmapNum] = *(bitmap_create(bitElemNum));
					strcpy(bitmapNode[bitmapNum].name, name);
					bitmapNum++;
				}

				else{
					printf("Maximum number of hash = 10!\n");
					continue;
				}
			}
		}

/*
//				instruction : delete				//
*/
		else if(strcmp(str, "delete") == 0){

		}


/*
//				instruction : dumpdata				//
*/
		else if(strcmp(str, "dumpdata") == 0){

		}

/*
//				instruction : quit				//
*/
		else if(strcmp(str, "quit") == 0){
			return;
		}

		else if(strcmp(str, "list_insert") == 0){
			
		}
	}
}
