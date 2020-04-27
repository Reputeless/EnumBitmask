
# include <cstdint>
# include <iostream>
# include "EnumBitmask.hpp"

namespace mynamespace
{
	enum class Flag : std::uint8_t
	{
		Mask_0 = 0,
		Mask_1 = 1,
		Mask_2 = 2,
		Mask_4 = 4,
		Mask_8 = 8,
		Mask_16 = 16,
		Mask_32 = 32,
		Mask_64 = 64,
		Mask_128 = 128,
	};
	DEFINE_BITMASK_OPERATORS(Flag)
}

int main()
{
	using mynamespace::Flag;

	constexpr Flag a = (Flag::Mask_1 | Flag::Mask_2);
	constexpr Flag b = (a & Flag::Mask_2);
	constexpr Flag c = (Flag{ 7 } ^ Flag{ 4 });
	constexpr Flag d = (~Flag::Mask_0);

	std::cout << static_cast<std::uint32_t>(a) << '\n';
	std::cout << static_cast<std::uint32_t>(b) << '\n';
	std::cout << static_cast<std::uint32_t>(c) << '\n';
	std::cout << static_cast<std::uint32_t>(d) << '\n';
	
	Flag e = Flag::Mask_1;
	e |= Flag::Mask_32;
	Flag f = Flag{ 255 };
	f &= Flag::Mask_32;
	Flag g = Flag::Mask_1;
	g ^= Flag::Mask_32;

	std::cout << static_cast<std::uint32_t>(e) << '\n';
	std::cout << static_cast<std::uint32_t>(f) << '\n';
	std::cout << static_cast<std::uint32_t>(g) << '\n';

	static_assert((Flag{ 11 } | Flag{ 22 }) == Flag{ 11 | 22 });
	static_assert((Flag{ 11 } & Flag{ 22 }) == Flag{ 11 & 22 });
	static_assert((Flag{ 11 } ^ Flag{ 22 }) == Flag{ 11 ^ 22 });
	static_assert(~Flag{ 11 } == Flag{ static_cast<std::uint8_t>(~11) });
}
