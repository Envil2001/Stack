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
    while (sp)
    {
        cout << sp->inf << " ";
        sp = sp->a;
    }
    cout << endl;
}


void main()
{
    setlocale(LC_ALL, "Russian");

    tstk* sp = NULL;
    const int max = 50, min = -50;
    for (int i = 0; i < MAX_SIZE + 1; i++) {
        //cout << min + rand() % ((max + 1) - min) << " ";
        if ((min + rand() % ((max + 1) - min)) > 0) {
            sp = add(sp, min + rand() % ((max + 1) - min));
        }
    }
    cout << endl << endl;
    cout << "Размер: " << sp->size << endl << endl;

    Printst(sp);
    //tstk* sp2 = NULL;
    //while (sp)
    //{
    //    int inf;
    //    sp = ReadStackD(sp, inf);
    //    if (inf > 0) sp2 = add(sp2, inf);
    //}
}


