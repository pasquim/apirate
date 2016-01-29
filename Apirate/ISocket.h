/**
 * ISocket.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>

#ifndef __unix__
 #include <winsock2.h>
#else
 typedef int SOCKET;
#endif

namespace Apirate {
	/**
	* @brief A basic interface for socket implementation
	* @details This interface contains the minimum needed informations for a server
	* to identify a client at its connection.
	*/
	class ISocket {
	public:
		virtual ~ISocket() {};

		/**
		* @brief Getter for the socket object
		* @details This methods allows the implementor to access the direct object
		* in charge of the socket managment
		* @return A SOCKET object, whose type depends of the platform the server
		* is running on.
		*/
		virtual SOCKET getSocket() const = 0;

		/**
		* @brief Setter for the socket object
		* @details This method allows the implementor to set a socket directly.
		* It must be used with care.
		* @param socket The object representif the socket and its informations.
		* @return Itself
		*/
		virtual ISocket& setSocket(SOCKET socket) = 0;

		/**
		* @brief Getter for the IP adress
		* @details This method allows the implementor to retrieve the client's IP
		* adress through the socket object.
		* @return The IP adress of the client.
		*/
		virtual const std::string& getIP() const = 0;

		/**
		* @brief Getter for the hostname
		* @details This method allows the implementor to retrieve the client's
		* hostname through the socket object.
		* @return The hostname of the client.
		*/
		virtual const std::string& getHost() const = 0;

		/**
		* @brief Getter for the port
		* @details This method allows the implementor to retrieve the client's
		* port through the socket object.
		* @return The port of the client.
		*/
		virtual const unsigned short getPort() const = 0;

		/**
		* @brief An overloaded method to get what was read from the socket
		* @details This method allows the implementor to get what was read from
		* the socket.
		* @param bytesRead A reference who will contain the number of bytes readed.
		* @return What was read.
		*/
		virtual char* read(int& bytesRead) = 0;

		/**
		* @brief An overloaded method to add someting to write on the socket
		* @details This method allows the implementor to add something to write
		* on the socket.
		* @param toWrite What to write.
		* @param bytesToWrite The size to write.
		* @return Bytes to write or error.
		*/
		virtual int write(char* toWrite, unsigned int bytesToWrite) = 0;

		/**
		* @brief An overloaded method to read from the socket.
		* @details This method allows the implementor to call a read fonction from
		* the interface, if needed.
		* @return The number of bytes readed.
		*/
		virtual int read() = 0;

		/**
		* @brief An overloaded method to write on the socket.
		* @details This method allows the implementor to call a write fonction from
		* the interface, if needed.
		* @return The number of characters written.
		*/
		virtual int write() = 0;
	};
}