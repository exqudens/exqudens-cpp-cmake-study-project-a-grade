#cmake_minimum_required(VERSION 3.12)
#cmake_policy(SET CMP0076 NEW)

cmake_minimum_required(VERSION 3.17)

project(ExqudensCStudyProjectAGrade)

set(CMAKE_CXX_STANDARD 20)

# main

add_subdirectory(src/main/cpp/application)
add_subdirectory(src/main/cpp/application/model)
add_subdirectory(src/main/cpp/application/util)

add_library(StringArray INTERFACE)
add_library(IntArray INTERFACE)
add_library(DoubleArray INTERFACE)
add_library(GradedArtifact INTERFACE)
add_library(GradedArtifacts INTERFACE)
add_library(Student INTERFACE)
add_library(Students INTERFACE)
add_library(Strings src/main/cpp/application/util/Strings.cpp)
add_library(Runnable src/main/cpp/application/Runnable.cpp)

target_sources(StringArray INTERFACE src/main/cpp/application/model/StringArray.h)
target_sources(IntArray INTERFACE src/main/cpp/application/model/IntArray.h)
target_sources(DoubleArray INTERFACE src/main/cpp/application/model/DoubleArray.h)
target_sources(GradedArtifact INTERFACE src/main/cpp/application/model/GradedArtifact.h)
target_sources(GradedArtifacts INTERFACE src/main/cpp/application/model/GradedArtifacts.h)
target_sources(Student INTERFACE src/main/cpp/application/model/Student.h)
target_sources(Students INTERFACE src/main/cpp/application/model/Students.h)

target_link_libraries(GradedArtifacts INTERFACE GradedArtifact)
target_link_libraries(Students INTERFACE Student)
target_link_libraries(Strings INTERFACE StringArray)
target_link_libraries(Strings INTERFACE IntArray)
target_link_libraries(Strings INTERFACE DoubleArray)
target_link_libraries(Runnable INTERFACE GradedArtifacts)
target_link_libraries(Runnable INTERFACE Students)
target_link_libraries(Runnable PUBLIC Strings)

add_executable(${CMAKE_PROJECT_NAME} src/main/cpp/application/Main.cpp)

target_link_libraries(
        ${CMAKE_PROJECT_NAME}
        PUBLIC
        Runnable
)

# test

add_subdirectory(src/test/cpp/application)

add_library(TestData INTERFACE)

target_sources(TestData INTERFACE src/test/cpp/application/TestData.h)

add_executable(${CMAKE_PROJECT_NAME}Test src/test/cpp/application/Main.cpp)

target_link_libraries(
        ${CMAKE_PROJECT_NAME}Test
        PUBLIC
        TestData
        Runnable
        Strings
)
