#pragma once

#include <cstdint>
#include <future>

#include "eBaudRate.h"

/// <summary>
/// Interface for the different CAN types.
/// </summary>
class ICAN
{
public:

	/// <summary>
	/// Default destructor.
	/// </summary>
	virtual ~ICAN() = default;

	/// <summary>
	/// Initializes the derived CAN type.
	/// </summary>
	/// <returns>True if the CAN type was initialized successfully, otherwise false.</returns>
	virtual bool Initialize() = 0;

	/// <summary>
	/// Sends data to the derived CAN type.
	/// </summary>
	/// <param name="data">The sent data.</param>
	/// <param name="dataLength">The length of the data.</param>
	/// <returns>Tue if the data was send successfully, otherwise false.</returns>
	virtual bool SendData(const uint8_t* const data, const uint8_t dataLength) const = 0;

	/// <summary>
	/// Fetches data from a derived CAN type asynchonously.
	/// </summary>
	/// <param name="dataBuffer">Container for the fetched data.</param>
	/// <param name="bufferSize">Container size for the fetched data.</param>
	/// <returns>
	/// If the data fetching was successful, true and the fetched data is returned.
	/// If the data fetching was unsuccessful, false and 0 (as fetched data) is returned.
	/// </returns>
	virtual std::future<std::tuple<bool, uint8_t>> FetchData(uint8_t* const dataBuffer, const uint8_t bufferSize) const = 0;

	/// <summary>
	/// Sets the baud rate of the derived CAN type.
	/// </summary>
	/// <param name="baudRate">The desired baud rate as enum.</param>
	/// <returns>Calls the protected 'SetBaudRate' method.</returns>
	virtual bool SetBaudRate(const eBaudRate baudRate)
	{
		return SetBaudRate(static_cast<uint32_t>(baudRate));
	}

protected:

	/// <summary>
	/// Sets the baud rate of the derived CAN type.
	/// </summary>
	/// <param name="baudrate">The desired baud rate.</param>
	/// <returns>True if the baud rate was set successfully, otherwise false.</returns>
	virtual bool SetBaudRate(const uint32_t baudRate) = 0;
};
