#ifndef STD_EXPERIMENTAL_BITS_CAN_REQUIRE_H
#define STD_EXPERIMENTAL_BITS_CAN_REQUIRE_H

#include <type_traits>
#include <tuple>
#include <utility>

namespace std {
namespace experimental {
inline namespace executors_v1 {
namespace execution {
namespace can_require_impl {

template<class>
struct type_check
{
  typedef void type;
};

template<class Executor, class Properties, class = void>
struct eval : std::false_type {};

template<class Executor, class... Properties>
struct eval<Executor, std::tuple<Properties...>,
  typename type_check<decltype(
    ::std::experimental::executors_v1::execution::require(std::declval<Executor>(), std::declval<Properties>()...)
  )>::type> : std::true_type {};

} // namespace can_require_impl

template<class Executor, class... Properties>
struct can_require : can_require_impl::eval<Executor, std::tuple<Properties...>> {};

} // namespace execution
} // inline namespace executors_v1
} // namespace experimental
} // namespace std

#endif // STD_EXPERIMENTAL_BITS_CAN_REQUIRE_H
