# Calculator
A calculator console program for C++.
一個C++控制臺計算器程序

stk.hpp
Customized stack data structure.
自定義棧數據結構。

cct.hpp
Mathematical calculation definition. Because of the limit of C++ lib function std::pow(__X, __Y), the notation of power(^) could use the customized power function in repository PowerFunction instead.
數學運算定義。因爲受限于C++庫函數std::pow(__X, __Y)，power運算符可以使用PowerFunction倉庫中的自定義power函數替換。

main.cpp
This is a preliminary but intact calculator program for all basic mathematical calculation, therefore the whole procedure including symbol read & process, bracket match and numeral calculation is in the function body of main. The decoupling updating is on.
這是一個初步但完整的用於基本數學運算的計算器程序，因此整個流程包括符號讀取&處理，括號匹配以及數值計算在main函數體中。解耦合升級已在日程中。
