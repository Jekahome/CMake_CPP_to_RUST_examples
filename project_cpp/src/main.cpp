#include <iostream>
#include "header.h" // из папки include ,а реализация .cpp должна быть в рядом с main.cpp
#include "foo.hpp" // из папки others
#include "mul.h" // тип подключения static library. Function mul
#include "sLibrary.hpp"// тип подключения dynamic library. Struct sLibrary
#include "external_cpp_library_fake_lib.hpp" // external dynamic library cpp
#include "external_rust_library.hpp" // external dynamic library rust
#include "test_lib.h" // сборка external dynamic library rust скриптами

#include <stdio.h>
#include <stdint.h>

int main(){
    std::cout << "Hello World" << std::endl;
    std::cout << add(5,5) << std::endl;
    std::cout << mul(5,5) << std::endl;
    std::cout << other_foo(5,5) << std::endl;

    sLibrary sl;
    sl.print_info();

    Third st;
    st.print_info_third_party();

    unsigned char u8 = 255;
    unsigned char res = zoo(u8);
    printf("res=%d\n", res );

    print_hello();


    // Коснтруктор std::uint32_t
    std::uint32_t current_count = 456;
    WrapperCounter  wrap(current_count);

    wrap.wrapDecrementCounterBy(1);
    wrap.wrapIncrementCounterBy(2);
    std::uint32_t count = wrap.wrapGetCounterValue();
    printf("count: %d == %d\n", count ,current_count-1+2);

    // Коснтруктор структорой
    myArgs arg {10,3};
    WrapperCounter  wrap_2(arg);
    std::uint32_t count_2 = wrap_2.wrapGetCounterValue();
    printf("count: %d == %d\n", count_2 ,10+3);

    // Использование массива
    const std::uint64_t size=3;
    std::uint32_t bys[size] = {5, 2, 3};
    std::uint32_t current_count_3 = 456;
    WrapperCounter  wrap_3(current_count_3);
    wrap_3.wrapIncrementCounterArrayBy(bys,size);
    wrap_3.wrapDecrementCounterArrayBy(bys,1);// массив с одним элементом т.е.bys[0]== 5
    std::uint32_t count_3 = wrap_3.wrapGetCounterValue();
     printf("count: %d == %d\n", count_3 ,current_count_3+5+2+3-5);
    return 0;
}
