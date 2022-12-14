#include <iostream>

class Wezel{
    public:
        std::weak_ptr<Wezel> next;

        ~Wezel(){
            std::cout << "Destrukcja obiektu" << std::endl;
        }
};