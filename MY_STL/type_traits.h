#ifndef MY_type_traits_H_ //ȷ��ͷ�ļ�ֻ������һ��
#define MY_type_traits_H_ 1

// ���ͷ�ļ�������ȡ������Ϣ

#include <type_traits> //���ÿ⺯���������жϣ�����ʱ�ڵĺ�����
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
    
    //ģ���ػ�(������)
    template<bool b>
        using m_bool_constant =m_integral_constant<bool,b>;

    //���������ͣ�����̳�
    using m_true_type  = m_bool_constant<true>;
    using m_false_type = m_bool_constant<false>;
    
    
    
    //�����type traits��ʵ��
    template <class T1, class T2>
    struct pair;

    template <class T>
    struct is_pair : mystl::m_false_type {};

    template <class T1, class T2>
    struct is_pair<mystl::pair<T1,T2>> : mystl::m_true_type {};

    //��д
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