#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <iostream>
using namespace std;
struct node
{
int inf; // �������� ����������
struct node *next; // ������ �� ��������� �������
};

struct node *get_struct(int priem);
struct node *head = NULL, *last = NULL, *f = NULL; // ��������� �� ������ � ��������� �������� ������

void spstore(int j)
{
struct node *p = NULL;
p = get_struct(j);
if (head == NULL && p != NULL) // ���� ������ ���, �� ������������� ������ ������
{
head = p;
last = p;
}
else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
{
last->next = p;
last = p;
}

return;
}

struct node *get_struct(int priem)
{
struct node *p = NULL;

if ((p = (node*)malloc(sizeof(struct node))) == NULL) // �������� ������ ��� ����� ������� ������
{
printf("������ ��� ������������� ������\n");
exit(1);
}

p->inf = priem;

p->next = NULL;

return p; // ���������� ��������� �� ��������� �������
}

int remove(){
struct node *struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
struct node *prev;// ��������� �� �������������� ���������� �������

if (head->next != NULL) // ���� ��������� ������� ��������� � ������
{
int vozvr = struc->inf;
head=head->next; // �������� ��������� ��������������� ��������
free(struc);
return vozvr;
}
else
{
int vozvr = struc->inf;
head = NULL;
free(struc);
return vozvr;
}
return 0;

}

int main()
{
struct node *struc = head;
setlocale(LC_ALL, "Russian");
int size;
printf("������� ������ �������: ");
scanf("%d",&size);
int** mas = (int**)malloc(sizeof(int*) * size);
for (int i = 0; i < size; i++) {
mas[i] = (int*)malloc(sizeof(int) * size);
}
srand(time(NULL));
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
mas[i][j] = rand() % 2;
}
}

for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (i == j) {
mas[i][j] = 0;
}
if (mas[i][j] = mas[j][i]) {
mas[i][j] = mas[j][i];
}
}
}
for (size_t i = 0; i < size; ++i){ 
	printf("\n");
	for (size_t j = 0; j < size; ++j){
	printf("%d ",mas[i][j]);
	}
}
int *nodes = new int [size];

for (int i = 0; i < size; i++)
nodes[i] = 0;

int verch;
printf("\n������� ��������� �������: ");
scanf("%d", &verch);
spstore(verch);
int start = clock();
printf("\n����� � ������: ");
for (int i = 0; i < size; i++){
if(nodes[i] == 0){
nodes[i] = 1;

}
while (head)
{
int node = remove();
nodes[node] = 2;
for (int j = 0; j < size; j++)
{
if (mas[node][j] == 1 && nodes[j] == 0)
{ // ���� ������� ������� � �� ����������
spstore(j);
nodes[j] = 1;
}
}
printf(">%d",node + 1);
}
}
int end = clock();
double time = (end-start) / 1000.0;
printf("\nTime: %lf\n", time);
system("Pause");
return 0;
}