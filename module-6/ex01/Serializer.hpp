#include <cstdint>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
	public:
		struct Data
		{
			int x;
			int y;
		};

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
