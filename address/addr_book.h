#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include "system.h"

//연락처 정보
struct Address {
	unsigned int id;
	char name[15];
	char phone[14];
	char content[100];
	struct Address* next;
};

enum MENU {
	VIEW=1, SEARCH, ADD, REMOVE, SAVE, EXIT
};
enum SEARCHMENU {
	SEARCH_ID = 1, SEARCH_NAME, SEARCH_PHONE, BACK
};

void menu(Address** list, Address** tail); //main menu of addr_book
void search(Address* addr); //search address data
void search_id(Address* addr, int id);//search id
void search_name(Address* addr, char* name);//search name
void search_phone(Address* addr, char* phone);//search phone
bool remove(Address* addr);//remove address
void save(Address* addr);//save addrsss list to txt file
void display(Address* addr); //display address list
void add(Address** list); // add new address data
void load(Address** tail); // load address list from txt file
void free_mem(Address* addr); //free address list memory to prevent memory leakage