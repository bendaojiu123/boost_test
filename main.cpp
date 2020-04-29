#include <QCoreApplication>
#include <iostream>
//#include <test/timerTest.h>
#include "test/date_time_Test.h"
//#include "templateTest1.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    SumTestInt<2> t;
//    std::cout << t.getSum() << std::endl;

    testSort();

    return a.exec();
}
