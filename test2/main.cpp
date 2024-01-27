#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "hello";
    QCoreApplication a(argc, argv);

    return a.exec();
}
