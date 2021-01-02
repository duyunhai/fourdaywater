#include <cmath>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 5000
 
char c[MAXN], oper[MAXN];
double number[MAXN];
int oper_num, num_num, p;
 
void work();
void calc();
void get_number();
void get_operator();
int get_priority(int n);
 
int main(){
	printf("请输入所要计算的多项式：\n");
    scanf("%s", &c);
    work();
    printf("计算结果为：%lf\n", number[1]);
    return 0;
}
 
void work(){
    while (p < strlen(c)){
	if (c[p] >= '0' && c[p] <= '9') get_number();
	if (c[p] == '+' || c[p] == '-' || c[p] == '*' 
            || c[p] == '/' || c[p] == '^') get_operator();
	if (c[p] == '(') oper[++oper_num] = '(';
	if (c[p] == ')'){
	    oper[++oper_num] = ')';
	    while (oper_num > 1 && oper[oper_num-1] != '(') calc();
	    oper_num -= 2;
	}	
        p++;	
    }
    oper[++oper_num] = ')';
    while (oper_num > 1) calc();	
}
 
void calc(){
    double res = 1;
    double a2 = number[num_num--];
    double a1 = number[num_num];	
    char handle = oper[--oper_num];
    oper[oper_num] = oper[oper_num + 1];	
    if (handle == '+') res = a1 + a2;
    if (handle == '-') res = a1 - a2;
    if (handle == '*') res = a1 * a2;
    if (handle == '/') res = a1 * 1.0 / a2;
    if (handle == '^') {
    	for (int i = 1;i <= abs(a2); i++) res = res * a1;
    	if (a2<0) res = 1.0 / res;
    }
    number[num_num] = res;
}
 
void get_number(){
    int n = 1, start_p = p;
    char c_num[MAXN];	
    while ((c[p] <= '9' && c[p] >= '0') || c[p] == '.') {	
    	n++;
    	p++;
    }
    strncpy(c_num, c+start_p, n);
    sscanf(c_num, "%lf", &number[++num_num]);
    if (c[start_p-1] == '-' && (c[start_p-2] == '(' || start_p == 1)){
    	number[num_num] = -number[num_num];
    	oper_num--;
    }
}
 
void get_operator(){
    oper[++oper_num] = c[p];
    while (oper_num > 1 && oper[oper_num-1] != '(' 
        && get_priority(oper_num) <= get_priority(oper_num-1)) calc(); 
}
 
int get_priority(int n){
    if (oper[n] == '+' || oper[n] == '-') return 0;
    if (oper[n] == '*' || oper[n] == '/' || oper[n] == '^') return 1;
    return 2;
}