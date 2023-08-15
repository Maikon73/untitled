#include <iostream>
#include <cpr/cpr.h>

using namespace std;
/*
 * Задание 1. Пользовательские запросы

Что нужно сделать

Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису httpbin.org.

Пользователь взаимодействует с программой с помощью команд: “get”, “post”, “put”, “delete”,
 “patch”. В зависимости от команды к серверу httpbin.org осуществляется запрос того или
 иного типа. Содержимое ответа сервера выводится в стандартный вывод.

Программа завершается, когда пользователь вводит команду “exit”.

Рекомендации

Для каждого HTTP-запроса в CPR есть отдельный метод, например cpr::Get.

Что оценивается

Корректность выполнения запросов к сервису в зависимости от пользовательских команд.

 */
int main()
{
    string command;
    do
    {
        cout << "Enter command" << endl;
        cin >> command;
        if (command == "get"){

            cpr::Response g = cpr::Get(cpr::Url("http://httpbin.org/get"));
            cout << g.text << endl;

        } else if (command == "post"){

            std::string name, city;
            std::cin >> name >> city;
            cpr::Response p = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                        (cpr::Payload({{"name", name.c_str()}, {"city", city.c_str()}})));
            cout << p.text << endl;

        } else if (command == "put"){

            cpr::Response pu = cpr::Put(cpr::Url("http://httpbin.org/put"));
            cout << pu.text << endl;

        } else if (command == "delete"){

            cpr::Response d = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            cout << d.text << endl;

        } else if (command == "patch"){

            cpr::Response pat = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            std::cout << pat.text << std::endl;

        } else {
            cout << "Wrong command, Enter again" << endl;
        }
    } while (command != "exit");
}
