/**
 * IRequest.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>
#include "IQuery.h"
#include "eMethod.h"

namespace Apirate {
	/**
	* @brief A basic implementation for the HTTP requests
	* @details This class provides the implementor a simple class to handle its
	* HTTP requests, which inherits from the IQuery class.
	*/
	class IRequest : public IQuery {
	public:
		virtual ~IRequest() {};

		/**
		* @brief Getter for the URI of the request
		* @details This method allows the implementor to retrieve the URI
		* associated to the request.
		* @return The URI of the request.
		*/
		virtual const std::string& getURI() const = 0;

		/**
		* @brief Setter for the URI of the request
		* @details This method allows the implementor to set the URI for the
		* associated request.
		* @return Itself
		*/
		virtual IRequest& setURI(const std::string& uri) = 0;

		/**
		* @brief Getter for the method of the request
		* @details This method allows the implementor to get the method of the
		* associated request.
		* @return A eMethod enum corresponding to the method type.
		*/
		virtual eMethod getMethod() const = 0;

		/**
		* @brief Setter for the method of the request
		* @details This methos allows the implementor to set the method of the
		* associated request.
		* @param method The enum corresponding to the method of the request.
		* @return Itself
		*/
		virtual IRequest& setMethod(eMethod method) = 0;
	};
}