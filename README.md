# EnumBitmask <a href="https://github.com/Reputeless/EnumBitmask/blob/master/LICENSE"><img src="https://img.shields.io/badge/license-CC0%201.0-4aaa4a"></a>
**EnumBitmask** is a library to enable bitmask operators for an enum class type.  

![](EnumBitmask.png)

## Examples

```C++
# include <iostream>
# include "EnumBimask.hpp"

enum class OpemMode
{
	Append	= 1,
	Binary	= 2,
	Input	= 4,
	Output	= 8,
};
DEFINE_BITMASK_OPERATORS(OpemMode)

int main()
{
	constexpr OpemMode openMode = OpemMode::Binary | OpemMode::Input;
	
	if (openMode & OpemMode::Binary)
	{
		std::cout << "Binary mode" << '\n';
	}
}
```