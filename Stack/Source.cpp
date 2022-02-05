#include <iostream>
#define MAX_SIZE 100

//������ 19 (4)
//�������� ���� � ������� � ������� �� - 50 �� + 50. ϳ��� ��������� �����
//�������� ������������ ��������.� ���� ������ �� ����� ������ ����
//�������.
//
//4. �������� ����� ����, �� ������ ����� �������� ����� � ������� �����.

using namespace std;

struct stack {
	float elem[MAX_SIZE];
	int top;
};

void init(struct stack* stk) {
	stk->top = 0;
}

int getcount(struct stack* stk) {
	return stk->top;
}
void push(struct stack* stk, float f) {
	if (stk->top < MAX_SIZE) {
		stk->elem[stk->top] = f;
		stk->top++;
		cout << f << " ";
	}
	else
		cout << "The stack is full, the number of elements: " << stk->top << " ";

}


int isempty(struct stack* stk) {
	if (stk->top == 0)    return 1;
	else return 0;
}

float pop(struct stack* stk) {
	float elem;
	if ((stk->top) > 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return elem;
	}
	else
	{
		cout << "Stack removed" << endl;
		return 0;
	}
}

void filter(struct stack* stk) {
	int i;
	i = stk->top; // i - number of elements in the stack
	do {
		i--;
		if (stk->elem[i] >= -50 && stk->elem[i] <= 50) {
			stk->elem[i];
			cout << stk->elem[i] << " ";
		}
	} while (i > 0);

}


void stkPrint(struct stack* stk) {
	int i;
	i = stk->top; // i - number of elements in the stack
	if (isempty(stk) == 1) return; // stack is empty
	cout << endl;
	do {
		i--;
		cout << stk->elem[i] << " ";

	} while (i > 0);

	cout << endl;
}



int main() {
	setlocale(LC_ALL, "ru");

	struct stack* stk;

	const int max = MAX_SIZE, min = -MAX_SIZE;
	stk = (struct stack*)malloc(sizeof(struct stack));
	init(stk); // ������������� ����� init(stk), ��� s � ����

	cout << "---------------------------------" << endl;
	cout << "����� ���� �����: " << endl;
	for (int i = 0; i < MAX_SIZE; i++) {
		push(stk, min + rand() % ((max + 1) - min)); //��������� �������� � ���� push(stk, i), ��� stk � ����, i � ���������� �������;
	}
	cout << endl;
	cout << "In the stack " << getcount(stk) << " items" << endl;
	cout << "---------------------------------" << endl;
	stkPrint(stk); // ����� ��������� ����� stkPrint(stk), ��� s � ����
	cout << endl;
	cout << "FILTER" << endl;
	filter(stk); // ��� ��� ����� �� ���� ������ ����������� �� �����
	cout << endl;
	stkPrint(stk); // �� � ��� ����� �������
	cout << "FILTER END" << endl;
	cout << "Removing the stacks..." << endl;
	do {
		cout << "��������� �������: " << pop(stk) << endl; // Removing elements. �������� �������� �� ����� i=pop(stk);
	} while (isempty(stk) == 0);
	cout << endl;
	cout << "In the stack " << getcount(stk) << " items" << endl;

	return 0;
}