/**
 * IQuery.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <map>
#include <string>
#include <eQuery.h>


namespace Apirate {
	/**
	* @brief Interface for a basic, non-typed query, containing its basic
	* informations.
	* @details This interface allows the implementor to build the minimum needed
	* informations for both Requests and Responses.
	*/
	class IQuery {
	public:
		virtual ~IQuery() {};

		/**
		* @brief Add a new header to the existing set
		* @details This method allows the implementor to add a header to a HTTP
		* query.
		* @param header The name of the header the implementor wants to add.
		* @param value The value associated to the header
		* @return Itself
		*/
		virtual IQuery&	addHeader(const std::string& header,
								  const std::string& value) = 0;

		/**
		* @brief Getter for a specific header
		* @details This method allows the implementor to get the value associated
		* to a header by its name.
		* @param header The name of the header the implementor wants to retrieve.
		* @return The value associated to the header
		*/
		virtual const std::string& getHeader(const std::string& header) = 0;

		/**
		* @brief Retrieve a header by its name.
		* @details This methos allows the implementor to get the value associated
		* to a header by its name via the [] operator
		* @param header The name of the header the implementor wants to retrieve.
		* @return The value associated to the header
		*/
		virtual const std::string& operator[](const std::string& header) = 0;

		/**
		* @brief Getter for all headers
		* @details This method allows the implementor to retrieve all the headers
		* already set in a query.
		* @return A map containing all the headers and their values.
		*/
		virtual const std::map<std::string, std::string>& getHeaders() const = 0;

		/**
		* @brief Removes a specific header
		* @details This method allows the implementor to remove a specific header
		* by its name.
		* @param header The name of the header to remove.
		* @return Itself
		*/
		virtual IQuery& removeHeader(const std::string& header) = 0;

		/**
		* @brief Getter for the data of the query
		* @details This method allows the implementor to retrieve the data
		* contained in the query.
		* @return A string containing the data of the query.
		*/
		virtual const std::string& getData() const = 0;

		/**
		* @brief Setter for the data of the query
		* @details This method allows the implementor to set the content of
		* the query allowing this operation only if the content has been
		* retrieved at least once.
		* @param data The data to set in the query.
		* @return Itself
		*/
		virtual IQuery& modifyData(const std::string &data) = 0;

		/**
		* @brief Setter for the data of the query
		* @details This method allows the implementor to set the content of
		* the query.
		* @param data The data to set in the query.
		* @return Itself
		*/
		virtual IQuery& setData(const std::string &data) = 0;

		/**
		* @brief Getter for the version
		* @details This method allows the implementor to know which HTTP protocol
		* version has been used in the query.
		* @return The HTTP protocol version of the query.
		*/
		virtual const std::string& getVersion() const = 0;

		/**
		* @brief Setter for the version
		* @details This method allows the implementor to set the HTTP protocol
		* version used to create the associated query.
		* @param version A string representing the HTTP protocol version of
		* the query.
		* @return Itself
		*/
		virtual IQuery& setVersion(const std::string& version) = 0;

		/**
		* @brief Getter for the Query type.
		* @details this method allows the implementor to know whether the query
		* is a request or a response.
		* @return The type of the query.
		*/
		virtual eQuery getType() const = 0;
	};
}