### 📦 My C++ Header

this header is adding additional types while also added some custom class template and other stuff that sometime looks hacky, but since all the implementation are in the header file this may cause slow compilation time in larger c++ project, but this thing designed for smaller project so it should be fine and the header file is pretty modular because it's only rely on c++ standard library (iostream and cstdint library).

### 🚀 Usage

just put include directive on the header file you want to include, but if you want all of it just include the `UnknownRori.hpp`

```cpp
#include "./include/UnknownRori/UnknownRori.hpp" // this thing will include entire header file
// OR
#include "./include/UnknownRori/Types.hpp" // this thing will only include the type definition

int main()
{
    i32 myNewDataType = 40;
    return 0;
}
```
