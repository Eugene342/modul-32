#include <iostream>
#include "enterprise.pb.h"
int main() {
    // Инициализация библиотеки Protocol Buffers
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Создание нового объекта Enterprise
    Enterprise enterprise;
    enterprise.set_year_founded(2000);
    enterprise.set_legal_address("123 Main St, City, Country");
    enterprise.set_name("My Company");
    enterprise.set_activity_type("Manufacturing");
    enterprise.set_foreign_economic_activity(true);

    // Вывод информации о предприятии
    std::cout << "Year Founded: " << enterprise.year_founded() << std::endl;
    std::cout << "Legal Address: " << enterprise.legal_address() << std::endl;
    std::cout << "Name: " << enterprise.name() << std::endl;
    std::cout << "Activity Type: " << enterprise.activity_type() << std::endl;
    std::cout << "Foreign Economic Activity: " << (enterprise.foreign_economic_activity() ? "Yes" : "No") << std::endl;

    // Освобождение ресурсов
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}


