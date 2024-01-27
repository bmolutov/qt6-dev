#include <QCoreApplication>
#include <iostream>
#include <string>

void solve() {
    std::cout << "please enter your name: ";
    std::string name;

    std::cin >> name;
    std::getline(std::cin, name);
    std::cout << name << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    solve();

    return a.exec();
}
