#include <iostream> 
#include <stdlib.h> 
#include <conio.h> 
#define MAX_SIZE 100

using namespace std;
struct tstk
{
    int inf;
    int size = 0;
    tstk* a;
};

tstk* add(tstk* sp, int inf)
{
    tstk* spt = new tstk;

    if (sp == nullptr)
    {
        sp = spt;
        sp->size = 1;
        sp->inf = inf;
        sp->a = nullptr;
        return sp;
    }
    if (sp->size >= MAX_SIZE) {
        cout << "Стек переполнен!" << endl;
        return sp;
    }
    else {
        spt->size = sp->size + 1;
        spt->inf = inf;
        spt->a = sp;
    }

    return spt;
}

tstk* ReadStackD(tstk* sp, int& inf)
{
    if (sp == NULL) return NULL;
    tstk* spt = sp;
    inf = sp->inf;
    sp = sp->a;
    delete spt;
    return sp;
}

void Printst(tstk* sp) {
    while (sp) {
        cout << sp->inf << " ";
        sp = sp->a;
    }
    cout << endl;
}

tstk* DelStackAll(tstk* sp)
{
    tstk* spt; int inf;
    while (sp != NULL) {
        spt = sp;
        inf = sp->inf;
        cout << inf << " ";
        sp = sp->a;
        delete spt;
    }
    return NULL;
}

void main()
{
    setlocale(LC_ALL, "Russian");

    tstk* sp = NULL;
    const int max = 50, min = -50;

    cout << "1 Стек: " << endl;
    
    for (int i = 0; i < 100; i++) {
        int randNumber = min + rand() % ((max + 1) - min);
        sp = add(sp, randNumber);
    }

    Printst(sp);
    cout << endl;
    cout << "Размер 1-го стека: " << sp->size << endl;
    cout << endl;

    cout << "2 Стек содержащий только положительные числа из первого стека: " << endl;
    tstk* sp2 = NULL;
    while (sp)
    {
        int inf;
        sp = ReadStackD(sp, inf);
        if (inf % 2 == 0) sp2 = add(sp2, inf);
    }

    Printst(sp2);
    cout << endl;
    cout << "Размер 2-го стека: " << sp2->size << endl;
    cout << endl;

    cout << "во втором стеке были удалены такие элементы: " << endl;
    sp2 = DelStackAll(sp2);

    cout << endl;
}


