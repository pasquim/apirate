/**
 * ISocket.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include "IRequest.h"
#include "IResponse.h"
#include "ISocket.h"

namespace Apirate {
	/**
	* @brief A basic implementation of the client's informations needed by the
	* server
	* @details This class provides the implementor a way to define a client and
	* its informations.
	*/
	class IClient {
	public:
		virtual ~IClient() {};

		/**
		* @brief Getter for the request
		* @details This method allows the implementor to retrieve a request
		* stored in the client.
		* @return The request to process.
		*/
		virtual IRequest* getRequest() = 0;

		/**
		* @brief Add a request to the client.
		* @details This method allowd the implementor to add a request to the
		* client.
		* @param request The request to add to the client.
		* @return Itself
		*/
		virtual IClient& addRequest(IRequest* request) = 0;

		/**
		* @brief Getter for the response
		* @details This method allows the implementor to retrieve a response
		* stored in the client.
		* @return The response to send.
		*/
		virtual IResponse* getResponse() = 0;

		/**
		* @brief Add a response to the client.
		* @details This method allowd the implementor to add a response to the
		* client.
		* @param response The response to add to the client.
		* @return Itself
		*/
		virtual IClient& addResponse(IResponse* response) = 0;

		/**
		* @brief Getter for the client's socket
		* @details This method allows the implementor to retrieve the socket
		* associated to a client.
		* @return The client's socket.
		*/
		virtual const ISocket& getSocket() const = 0;
	};
}