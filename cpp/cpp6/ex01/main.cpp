#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data data;

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << deserialized << std::endl;
	return 0;
}
