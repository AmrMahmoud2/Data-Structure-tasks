cmake_minimum_required(VERSION 3.5 )

### c++11 standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project( All_tasks )

include_directories( headers )

add_executable( test_dll apps/test_int_dlinkedlist.cpp )
add_executable( test_sll apps/test_int_linkedlist.cpp )
add_executable( test_qarray apps/test_int_q_array.cpp )
add_executable( test_qll apps/test_int_q_linkedlist.cpp )
add_executable( stock_span apps/a1_stock_span.cpp )
add_executable( balanced_parentheses apps/a2_balanced_parentheses.cpp )
add_executable( awesome_application apps/a3_awesome_application.cpp )
add_executable( countDNA apps/countDNA.cpp )
add_executable( analyzeDNA apps/analyzeDNA.cpp )
add_executable( analyzeECG apps/analyzeECG.cpp )
add_executable( calculator apps/calculator.cpp )
add_executable( count_words apps/count_words.cpp )
add_executable( Gamila_part apps/gamilatest.cpp )
add_executable( heron apps/heron.cpp )
add_executable( main apps/main.cpp )
add_executable( main2 apps/main2.cpp )
add_executable( test_tree apps/test_tree.cpp )
add_executable( unique_words apps/unique_words.cpp )
