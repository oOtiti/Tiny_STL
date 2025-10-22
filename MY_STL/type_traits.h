#ifndef MY_type_traits_H_ //确保头文件只被编译一次
#define MY_type_traits_H_ 1

// 这个头文件用于提取类型信息

#include <type_traits> //调用库函数来辅助判断（编译时期的函数）
namespace mystl
{
    template <typename T,T _v>
    struct m_integral_constant
    {
        static constexpr T value=_v;
    };
    
    //模板特化(特例化)
    template<bool b>
    using m_bool_constant =m_integral_constant<bool,b>;

    m_bool_constant<true>  m_true_type;
    m_bool_constant<false> m_false_type;
    
    
    
    //经典的type traits的实例
    template <typename T1, typename T2>
    struct pair;

    template <typename T>
    struct is_pair : mystl::m_false_type {};

    template <typename T1, typename T2>
    struct is_pair<mystl::pair<T1,T2>> : mystl::m_true_type{};

    //仿写
    template<typename T1, typename T2, typename T3>
    struct triplet;

    template<typename T>
    struct is_triplet : mystl::m_false_type {};

    template<typename T1,typename T2>
    struct is_triplet : mystl::m_false_type {};

    template<typename T1, typename T2, typename T3>
    struct is_triplet<mystl::triplet<T1,T2,T3>> :m_true_type {};
    
} // namespace mystl

#endif