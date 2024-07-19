#pragma once

#include "ICAN.h"

/// <summary>
/// Representation of the CAN type A.
/// </summary>
class CANTypeA : public ICAN
{
public:

	// Destructors:

	/// <summary>
	/// Default destructor.
	/// </summary>
	~CANTypeA() override = default;

	// Constructors:

	/// <summary>
	/// Default constructor.
	/// </summary>
	CANTypeA();

	// Interface methods:

	/// <summary>
	/// Initializes the derived CAN type.
	/// </summary>
	/// <returns>True if the CAN type was initialized successfully, otherwise false.</returns>
	bool Initialize() override;

	/// <summary>
	/// Sends data to the derived CAN type.
	/// </summary>
	/// <param name="data">The sent data.</param>
	/// <param name="dataLength">The length of the data.</param>
	/// <returns>Tue if the data was send successfully, otherwise false.</returns>
	bool SendData(const uint8_t* const data, const uint8_t dataLength) const override;

	/// <summary>
	/// Fetches data from a derived CAN type asynchonously.
	/// </summary>
	/// <param name="dataBuffer">Container for the fetched data.</param>
	/// <param name="bufferSize">Container size for the fetched data.</param>
	/// <returns>
	/// If the data fetching was successful, true and the fetched data is returned.
	/// If the data fetching was unsuccessful, false and 0 (as fetched data) is returned.
	/// </returns>
	std::future<std::tuple<bool, uint8_t>> FetchData(uint8_t* const dataBuffer, const uint8_t bufferSize) const override;

	// Hardware specific methods:

	/// <summary>
	/// Sets the CAN system to state 'active'.
	/// </summary>
	void SetActive();

	/// <summary>
	/// Sets the CAN system to state 'passive'.
	/// </summary>
	void SetPassive();

private:

	// Methods:

	/// <summary>
	/// Sets the baud rate of the derived CAN type.
	/// </summary>
	/// <param name="baudrate">The desired baud rate.</param>
	/// <returns>True if the baud rate was set successfully, otherwise false.</returns>
	bool SetBaudRate(const uint32_t baudRate) override;

	/// <summary>
	/// Handles incoming messages.
	/// </summary>
	/// <returns>True if the message was handled successfully, otherwise false.</returns>
	bool HandleMessage();

	// Members:

	/// <summary>
	/// The baud rate of the CAN system.
	/// </summary>
	uint32_t mBaudRate;

	/// <summary>
	/// Indicates wheather or not the CAN system is initialized.
	/// </summary>
	bool mInitialized;

	/// <summary>
	/// Indicates wheather or not the CAN system is active.
	/// </summary>
	bool mActive;

	/// <summary>
	/// Array that contains the valid baud rates for the CAN system.
	/// </summary>
	const static std::array<uint32_t, 3> mValidBaudRates;
};

