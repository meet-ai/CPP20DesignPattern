
#include <spdlog/spdlog.h>
#include <typeinfo>


//crtp 提供静态多态功能
//静态多态给子类提供默认的方法
//1. 基类是模板类, 模板参数是子类
template<typename Derived>
struct Base {
    //interface 是通用调用接口
    void interface() {
        spdlog::info("class: {}", typeid(*this).name()); //4BaseI7DerivedE
        spdlog::info("class: {}", typeid(* static_cast<Derived *>(this)).name());  //7Derived

        //2. 尽管this指针在Derived类的作用域内，它的类型仍然是Base<Derived>*，奇奇怪怪的特性. cpp 变废为宝.
        //所以将 Base<Derived> 转换成 Derived 类型
        static_cast<Derived *>(this)->implementation();
        // this->implementation(); 调用的是 Base 的 implementation
    }

    //3. implementation 在基类提供是默认实现
    void implementation() {
        spdlog::info("base implementation");
    }
};

//7. Base<Derived> 已经固定了父类模板参数，子类将不再是模板类
struct Derived : Base<Derived> {
    //4. implementation 在子类提供具体实现
    void implementation() {
        spdlog::info("derived implementation");
    }
};
struct DerivedB : Base<DerivedB> {
    //5. implementation 使用默认实现
};
int main () {
    //6. Derived 对接口进行实现,实现了静态接口多态
    Derived d;
    d.interface();

    DerivedB b;
    b.interface();

    Base<Derived> bd;
    bd.interface();

    //6. Base<DerivedB> 和 DerivedB 是不一样的  
    Base<DerivedB> bd2;
    bd2.interface();
}