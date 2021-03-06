<% render(instance) %>
<%= includes((0..x).size) %>

#include <boost/hana/integral.hpp>
#include <boost/hana/searchable/searchable.hpp>


int main() {
    auto go = boost::hana::elem(
        <%= list(
            (0..x).map { |i| "decltype(boost::hana::int_<#{i}>)" },
            (0..x).map { |i| "boost::hana::int_<#{i}>" }
        ) %>,
        boost::hana::int_<  <%= x / 2 %>    >
    );
}
