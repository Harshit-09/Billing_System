#ifndef __FUNCTION_H
#define __FUNCTION_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void input();
void writefile();
void search();
void output();
int tl,sl,ts;

struct date{
	   int month;
	   int day;
	   int year;
	   };

  struct account {
	int number;
	char name[100];
	int acct_no;
	float mobile_no;
	char street[100];
	char city[100];
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
  }customer;

#endif
