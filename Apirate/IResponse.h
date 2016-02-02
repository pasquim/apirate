/**
 * IResponse.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>
#include "IQuery.h"

namespace Apirate {
	/**
	* @brief A basic implementation for the HTTP responses
	* @details This class provides the implementor a simple class to handle its
	* HTTP responses, which inherits from the IQuery class.
	*/
	class IResponse : public virtual IQuery {
	public:
		virtual ~IResponse() {};

		/**
		* @brief Getter for the status code
		* @details This method allows the implementor to retrieve the status
		* code of the response.
		* @return the response code of the query.
		*/
		virtual unsigned int getStatusCode() const = 0;

		/**
		* @brief Setter for the status code
		* @details This method allows the implementor to set the status code of
		* the response.
		* @param code The status code to give to the associated response.
		* @return Itself
		*/
		virtual IResponse& setStatusCode(unsigned int code) = 0;

		/**
		* @brief Getter for the message
		* @details This method allows the implementor to retrieve the message
		* stored in the response.
		* @return The associated message.
		*/
		virtual const std::string& getMessage() const = 0;

		/**
		* @brief Setter for the message
		* @details This method allows the implementor to set a message in the
		* response.
		* @param message The message to set in the response.
		* @return Itself
		*/
		virtual IResponse& setMessage(const std::string& message) = 0;

		/**
		* @brief A builder function for the response
		* @details This method allows the implementor to build a response based
		* on the content of the IResponse.
		* @param size A reference on the size of the built response.
		* @return A char* containing the string form of the response.
		*/
		virtual char* buildResponse(unsigned int& size) const = 0;
	};
}