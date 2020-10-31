cmake_minimum_required(VERSION 3.0)
project(Project1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Project1)

include_directories(inc)

add_executable(Project1 
	src/main.cpp 
	inc/Uncopyable.h 
	inc/Credit.h 
	inc/Tranzactie.h 
	inc/ContBancar.h 
	inc/ContBancarLei.h 
	inc/ContBancarEuro.h 
	inc/Banca.h 
	inc/Client.h 
	inc/SumaTotala.h 
	src/Banca.cpp 
	src/Client.cpp 
	src/ContBancar.cpp 
	src/ContBancarEuro.cpp 
	src/ContBancarLei.cpp 
	src/Credit.cpp 
	src/Tranzactie.cpp 
	src/Uncopyable.cpp)
