/**
 * ILogger.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>
#include <eLog.h>

namespace Apirate {
	/**
	* @brief Interface for basic logging in the server
	* @details This class provides the implementor an easy way to log all its
	* informations from the server.
	*/
	class ILogger {
	public:
		virtual ~ILogger() {};

		/**
		* @brief Logs an information to a stream
		* @details This method allows the implementor to identify informations
		* logged by the server.
		* @param message The message to append to the stream.
		* @return Itself
		*/
		virtual ILogger& information(const std::string& message) = 0;

		/**
		* @brief Logs a warning to a stream
		* @details This method allows the implementor to identify warnings
		* logged by the server.
		* @param message The message to append to the stream.
		* @return Itself
		*/
		virtual ILogger& warning(const std::string& message) = 0;

		/**
		* @brief Logs an error to a stream
		* @details This method allows the implementor to identify errors
		* logged by the server.
		* @param message The message to append to the stream.
		* @return Itself
		*/
		virtual ILogger& error(const std::string& message) = 0;

		/**
		* @brief Specifies a specific file to save the logs in.
		* @details This method allows the implementor to log in a file specified
		* as a parameter. Nevertheless, standard output shall not be disabled.
		* @param file The file to log in.
		* @return Itself
		*/
		virtual ILogger& export(const std::string& file) = 0;

		/**
		* @brief Allows the logging messages to be colored.
		* @details This method allows the implementor to specify a color for
		* each log type to have a clearer output.
		* @param type The type of log for which the color is going to be
		* modified.
		* @param color The new displaying color.
		* @return Itself
		*/
		virtual ILogger& colorMe(eLog type, const std::string& color) = 0;
	};
}