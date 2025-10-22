#ifndef MY_type_traits_H_ //确保头文件只被编译一次
#define MY_type_traits_H_ 1

// 这个头文件用于提取类型信息

#include <type_traits> //调用库函数来辅助判断（编译时期的函数）
namespace mystl
{
    template <class T,T _v>
    struct m_integral_constant
    {
        static constexpr T value=_v;
        using value_type = T;
    using type = integral_constant<T, _v>;
    // constexpr operator value_type() const noexcept { return value; }
    // constexpr value_type operator()() const noexcept { return value; }
    };
    
    //模板特化(特例化)
    template<bool b>
        using m_bool_constant =m_integral_constant<bool,b>;

    //定义新类型，方便继承
    using m_true_type  = m_bool_constant<true>;
    using m_false_type = m_bool_constant<false>;
    
    
    
    //经典的type traits的实例
    template <class T1, class T2>
    struct pair;

    template <class T>
    struct is_pair : mystl::m_false_type {};

    template <class T1, class T2>
    struct is_pair<mystl::pair<T1,T2>> : mystl::m_true_type {};

    //仿写
    template<class T1, class T2, class T3>
    struct triplet;

    template<class T>
    struct is_triplet : mystl::m_false_type {};

    template<class T1,class T2>
    struct is_triplet : mystl::m_false_type {};

    template<class T1, class T2, class T3>
    struct is_triplet<mystl::triplet<T1,T2,T3>> :m_true_type {};
    
}

#endif