#include <iostream>

#define MAX_SIZE 100

using namespace std;


struct tstk
{
    float inf[MAX_SIZE];
    int size = 0;
    tstk* a;
};

//tstk* DelStackAll(tstk* sp)
//{
//    tstk* spt; int inf;
//    while (sp != NULL) {
//        spt = sp;
//        inf = sp->inf;
//        cout << inf << " ";
//        sp = sp->a;
//        delete spt;
//    }
//    return NULL;
//}

tstk* AddStack(tstk* sp, int inf)
{
    tstk* spt = new tstk;

    if (sp == nullptr)
    {
        sp = spt;
        sp->size = 1;
        sp->inf[sp->size] = inf;
        sp->a = nullptr;
        return sp;
    }

    if (sp->size >= MAX_SIZE) {
        cout << "Stack overflow!" << endl;
    }
    else {
        spt->size = sp->size + 1;
        spt->inf[sp->size] = inf;
        spt->a = sp;
    }
    return spt;
}


void stkPrint(tstk* sp) {
    if (sp == nullptr)
        cout << "Стек пуст" << endl;
    else {
        do
        {
            sp--;
            cout << sp->inf[sp->size] << "" << endl;
        } while (sp != 0);
    }
    cout << endl;
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
    const int max = 50, min = -50;
    for (i = 0; i <= MAX_SIZE; i++) {
        sp = AddStack(sp, min + rand() % ((max + 1) - min));
        cout << "cout - " << min + rand() % ((max + 1) - min) << endl;
    }
    cout << endl << endl;
    stkPrint(sp);
    //sp = DelStackAll(sp);

    return 0;
}