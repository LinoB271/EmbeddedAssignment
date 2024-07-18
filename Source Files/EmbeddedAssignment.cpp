#include <iostream>

#include "CANTypeA.h"
#include "Utilities.h"

int main()
{
	// Declare needed parametes for testing.
	std::unique_ptr<ICAN> canTypeAPointer = std::make_unique<CANTypeA>();
	uint8_t testSendMessage[] = {1, 2, 3, 4};
	uint8_t testFetchMessage[15];

	try
	{
		// Call interface specifc methods:
		canTypeAPointer->Initialize();
		std::future<std::tuple<bool, uint8_t>> fetchData = canTypeAPointer->FetchData(testFetchMessage, sizeof(testFetchMessage));
		bool sendResult = canTypeAPointer->SendData(testSendMessage, sizeof(testSendMessage));
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Get raw pointer from smart pointer to point to the same object.
	CANTypeA* specificCANTypeAPointer = static_cast<CANTypeA*>(canTypeAPointer.get());

	try
	{
		// Call CAN type specifc methods:
		specificCANTypeAPointer->SetActive();
		specificCANTypeAPointer->SetPassive();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

}
