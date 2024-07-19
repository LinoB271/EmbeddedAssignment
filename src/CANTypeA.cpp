#include <iostream>
#include <array>
#include <algorithm>
#include <stdexcept>
#include <sstream>

#include "CANTypeA.h"
#include "Utilities.h"

// Constructors:

CANTypeA::CANTypeA() : mBaudRate{ 0 }, mInitialized{ false }, mActive{ false } {}

// Public methods:

bool CANTypeA::Initialize()
{
	if (this->mInitialized != true)
	{
		this->mInitialized = true;
		std::cout << CurrentTime() << "The CAN system was initialized successfully." << std::endl;
		return true;
	}
	else
	{
		throw std::logic_error("The CAN system is already initialized.");
	}
}

bool CANTypeA::SendData(const uint8_t* data, uint8_t const dataLength) const
{
	// Check for null pointer.
	CHECK_NULLPTR(data);

	// Simulate data sending by waiting 5 seconds.
	std::cout << CurrentTime() << "Sending data..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << CurrentTime() << "Sending completed!" << std::endl;

	return true;
}

std::future<std::tuple<bool, uint8_t>> CANTypeA::FetchData(uint8_t* const dataBuffer, const uint8_t bufferSize) const
{
	// Check for null pointer.
	CHECK_NULLPTR(dataBuffer);

	return std::async(std::launch::async, [dataBuffer, bufferSize]() -> std::tuple<bool, uint8_t>
		{
			// Simulate data fetching by waiting 3 seconds.
			std::cout << CurrentTime() << "Fetching data..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));

			// Fetch dummy data.
			uint8_t fetchedSize = bufferSize <= 15 ? bufferSize : 15;
			for (uint8_t i = 0; i < fetchedSize; ++i)
			{
				dataBuffer[i] = i;
			}

			std::cout << CurrentTime() << "Fetching completed!" << std::endl;
			return std::make_tuple(true, fetchedSize);
		});
}

void CANTypeA::SetActive()
{
	if (this->mActive != true)
	{
		this->mActive = true;
		std::cout << CurrentTime() << "CAN system was set to state 'active'." << std::endl;
	}
	else
	{
		throw std::logic_error("CAN system is aready in state 'active'.");
	}
}

void CANTypeA::SetPassive()
{
	if (this->mActive != false)
	{
		this->mActive = false;
		std::cout << CurrentTime() << "CAN system was set to state 'passive'." << std::endl;
	}
	else
	{
		throw std::logic_error("CAN system is aready in state 'passive'.");
	}
}

// Private methods:

bool CANTypeA::SetBaudRate(const uint32_t baudRate)
{
	if (std::find(mValidBaudRates.begin(), mValidBaudRates.end(), baudRate) != mValidBaudRates.end())
	{
		if (this->mBaudRate != baudRate)
		{
			this->mBaudRate = baudRate;
			std::cout << CurrentTime() << "Baud rate was successfully set to: " << baudRate << std::endl;
			return true;
		}
		else
		{
			std::ostringstream oss;
			oss << "Baud rate is already set to: " << baudRate;
			throw std::logic_error(oss.str());
		}
	}
	else
	{
		std::ostringstream oss;
		oss << "The given value is not a valid baud rate: " << baudRate;
		throw std::logic_error(oss.str());
	}
}

bool CANTypeA::HandleMessage()
{
	std::cout << CurrentTime() << "Message was handled successfully!" << std::endl;
	return true;
}

// Private members:

const std::array<uint32_t, 3> CANTypeA::mValidBaudRates = { 125000, 250000, 500000 };