

#include <spdlog/spdlog.h>


//1. requires 支持的场景, 以及定义
// 函数调用要求, impl.size() ;
// 成员函数要求 {  impl.size() } -> std::convertible_to<size_t>;
// 操作符要求  {impla + implb}  -> std::convertible_to<size_t>;
// convertible_to<size_t> 是 C++ 20 的一个特性,编译时检查类型转换的可行性
template<typename INTERFACE>
concept IFS = requires(INTERFACE impl) {
    impl.interface_a();
    impl.interface_b();
};

//2. 模板类型 IFS 用来作为函数的参数类型, 暗示 impl 需要实现 interface_a 和 interface_b
template <typename IFS>
void test_interface_impl(IFS &impl) {
    impl.interface_a();
    impl.interface_b();
}

//3. IMPL 跟模板类没关系，只需要实现 interface_a 和 interface_b
struct IMPL {
    void interface_a(){
        spdlog::info("interface_a");
    }

    void interface_b(){
        spdlog::info("interface_b");
    }
};


int main () {
    IMPL impl;
    test_interface_impl(impl);
}