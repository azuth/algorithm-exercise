list(APPEND SRC_SORTALGORITHMS
	heapsort/heapsort.h
	insertionsort/insertionsort.h
	mergesort/mergesort.h
	quicksort/quicksort.h
)

list(APPEND SRC_TESTS
	testUtils.h
	heapsort/heapsort_normal_tests.cpp
	insertionsort/insertionsort_normal_tests.cpp
	insertionsort/insertionsort_withGuard_tests.cpp
	insertionsort/insertionsort_withGuardAndEarlyDecrement_tests.cpp
	insertionsort/insertionsort_sortBound_tests.cpp
	mergesort/mergesort_bottomUp_tests.cpp
	mergesort/mergesort_natural_tests.cpp
	quicksort/quicksort_normal_tests.cpp
	quicksort/quicksort_withShiftoperator_tests.cpp
	quicksort/quicksort_threeWayPartitioning_tests.cpp
	quicksort/quicksort_hybrid_tests.cpp
)

list(APPEND SRC_BENCHMARK
	main.cpp
	benchmark/benchmark.h
)

list(APPEND SRC_DATASET
	dataset/dataset.h
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME}_benchmark ${SRC_SORTALGORITHMS} ${SRC_DATASET} ${SRC_BENCHMARK})


add_executable(${PROJECT_NAME}_tests ${SRC_SORTALGORITHMS} ${SRC_DATASET} ${SRC_TESTS})
target_link_libraries (${PROJECT_NAME}_tests gtest gtest_main)
