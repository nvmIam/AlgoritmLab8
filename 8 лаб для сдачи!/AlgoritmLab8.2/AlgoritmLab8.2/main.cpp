#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <iostream>
using namespace std;
struct node
{
int inf; // полезная информация
struct node *next; // ссылка на следующий элемент
};

struct node *get_struct(int priem);
struct node *head = NULL, *last = NULL, *f = NULL; // указатели на первый и последний элементы списка

void spstore(int j)
{
struct node *p = NULL;
p = get_struct(j);
if (head == NULL && p != NULL) // если списка нет, то устанавливаем голову списка
{
head = p;
last = p;
}
else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
{
last->next = p;
last = p;
}

return;
}

struct node *get_struct(int priem)
{
struct node *p = NULL;

if ((p = (node*)malloc(sizeof(struct node))) == NULL) // выделяем память под новый элемент списка
{
printf("Ошибка при распределении памяти\n");
exit(1);
}

p->inf = priem;

p->next = NULL;

return p; // возвращаем указатель на созданный элемент
}

int remove(){
struct node *struc = head; // указатель, проходящий по списку установлен на начало списка
struct node *prev;// указатель на предшествующий удаляемому элемент

if (head->next != NULL) // если найденный элемент последний в списке
{
int vozvr = struc->inf;
head=head->next; // обнуляем указатель предшествующего элемента
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
printf("Введите размер матрицы: ");
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
printf("\nВведите стартовую вершину: ");
scanf("%d", &verch);
spstore(verch);
int start = clock();
printf("\nОбход в ширину: ");
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
{ // если вершина смежная и не обнаружена
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