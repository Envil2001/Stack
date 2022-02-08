#include <iostream>

#define MAX_SIZE 100

using namespace std;


struct tstk
{
    int inf;
    int size;
    tstk* a;
};

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

tstk* AddStack(tstk* sp, int inf)
{
    tstk* spt = new tstk;

    if (sp->size >= MAX_SIZE) {
        cout << "Ошибка: полный стек" << endl;
    }
    else {
        spt->size = sp->size + 1;
        cout << sp->size << " else " << endl;
        spt->inf = inf;
        spt->a = sp;
    }
    return spt;
}

//tstk* ReadStackD(tstk* sp, int& inf)
//{
//    if (sp == NULL) return NULL;
//    tstk* spt = sp;
//    inf = sp->inf;
//    sp = sp->a;
//    delete spt;
//    return sp;
//}

int main()
{
    tstk* sp = NULL;
    int i, j;
    //const int max = 50, min = -50;
    //for (i = 0; i <= MAX_SIZE; i++)
    for (i = -50; i <= 150; i++)
    {
        //sp = AddStack(sp, min + rand() % ((max + 1) - min));
        //cout << min + rand() % ((max + 1) - min) << " ";
        sp = AddStack(sp, i); 
        //cout << i << " ";

    }
    cout << endl << endl;

    sp = DelStackAll(sp);

    return 0;
}