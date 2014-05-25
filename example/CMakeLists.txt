#=============================================================================
# Setup examples
#=============================================================================
add_custom_target(examples COMMENT "Build all the examples.")

function(boost_hana_add_example name)
    string(REGEX REPLACE "[.]" "/" source ${name})
    add_executable(_${name} EXCLUDE_FROM_ALL ${source}.cpp)
    add_custom_target(${name} _${name} DEPENDS _${name})
    add_dependencies(examples ${name})
endfunction()

boost_hana_add_example(mpl.any)
boost_hana_add_example(mpl.fmap)

boost_hana_add_example(fusion.all)
boost_hana_add_example(fusion.any)
boost_hana_add_example(fusion.find)
boost_hana_add_example(fusion.foldl)
boost_hana_add_example(fusion.foldr)
boost_hana_add_example(fusion.none)