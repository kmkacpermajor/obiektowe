#include <memory>
#include "Wezel.h"

//zad 6: Nie, w obu przypadkach obiekt jest usuwany
//zad 9: Nie, żaden obiekt nie jest usuwany

int main(){
    for(int i=0; i<10; i++){
        // std::unique_ptr<Wezel>(new Wezel());
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();
        std::weak_ptr<Wezel> weak_w1 = w1;
        std::weak_ptr<Wezel> weak_w2 = w2;
        w1->next = weak_w2;
        w2->next = weak_w1;
    }

    return 0;
}