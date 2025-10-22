#ifndef MY_type_traits_H_ //ȷ��ͷ�ļ�ֻ������һ��
#define MY_type_traits_H_ 1

// ���ͷ�ļ�������ȡ������Ϣ

#include <type_traits> //���ÿ⺯���������жϣ�����ʱ�ڵĺ�����
namespace mystl
{
    template <typename T,T _v>
    struct m_integral_constant
    {
        static constexpr T value=_v;
    };
    
    //ģ���ػ�(������)
    template<bool b>
    using m_bool_constant =m_integral_constant<bool,b>;

    m_bool_constant<true>  m_true_type;
    m_bool_constant<false> m_false_type;
    
    
    
    //�����type traits��ʵ��
    template <typename T1, typename T2>
    struct pair;

    template <typename T>
    struct is_pair : mystl::m_false_type {};

    template <typename T1, typename T2>
    struct is_pair<mystl::pair<T1,T2>> : mystl::m_true_type{};

    //��д
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