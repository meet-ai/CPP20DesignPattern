
#include <spdlog/spdlog.h>

template<typename Derived>
struct Base {
    //interface 是通用调用接口
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }

    //implementation 在基类提供是默认实现
    void implementation() {
        spdlog::info("base implementation");
    }
};

struct Derived : Base<Derived> {
    //implementation 在子类提供具体实现
    void implementation() {
        spdlog::info("derived implementation");
    }
};
struct DerivedB : Base<Derived> {
};
int main () {
    Derived d;
    //d.implementation();
    d.interface();

    DerivedB b;
    b.interface();
    
}