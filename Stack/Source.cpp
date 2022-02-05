#include <iostream>
#define MAX_SIZE 100

//Варіант 19 (4)
//Створити стек з числами в діапазоні від - 50 до + 50. Після створення стека
//виконати індивідуальне завдання.В кінці роботи всі стеки повинні бути
//видалені.
//
//4. Створити новий стек, що містить тільки позитивні числа з першого стека.

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

void stkPrint(struct stack* stk) {
	int i;
	i = stk->top; // i - number of elements in the stack
	if (isempty(stk) == 1) return; // stack is empty
	cout << "Positive numbers in this stack: ";
	do {
		i--;
		if (stk->elem[i] > 0) {
			cout << stk->elem[i] << " ";
		}

	} while (i > 0);

	cout << endl;
}
int main() {
	setlocale(LC_ALL, "ru");

	struct stack* stk;

	const int max = 50, min = -50;
	stk = (struct stack*)malloc(sizeof(struct stack));
	init(stk);

	for (int i = min; i < max; i++) {
		cout << i << " ";
		push(stk, i);
	}
	cout << endl;
	cout << "In the stack " << getcount(stk) << " items" << endl;
	stkPrint(stk);
	cout << endl;
	cout << "Removing the stacks..." << endl;
	do {
		pop(stk); // Removing elements
		getcount(stk);  // We get the number of elements
	} while (isempty(stk) == 0);
	cout << "In the stack " << getcount(stk) << " items" << endl;

	return 0;
}