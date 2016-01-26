/**
 * IConfiguration.h
 *
 * Project : 	Apirate
 * Created on:  Jan 26, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>
#include <map>

namespace Apirate {
	/**
	* @brief Basic interface for the Configuration
	* @details The Configuration is used to specify parameters and options
	* to take into account during the running of the program. It runs as a
	* simple key/value map.
	*/
	class IConfiguration {
	public:
		virtual ~IConfiguration() {};

		/**
		* @brief Method to parse a file into a configuration file.
		* @details Parsing a file (Here, you either indicates a relativ or
		* absolute path) MUST first remove all existing values before applying
		* new ones.
		* @param filename The path to the file to parse.
		* @return Itself
		*/
		virtual IConfiguration& parseFile(const std::string& filename) = 0;

		/**
		* @brief Method to save the current configuration to a file.
		* @details This method allows the implementor to save its current
		* configuration in a file which could be reused later.
		* @param path The path to the file to save the configuration in. If no
		* parameters are given, the current file containing the configuration
		* will be overwritten.
		* @return Itself
		*/
		virtual IConfiguration& saveTo(const std::string& path = "") = 0;

		/**
		* @brief Getter for the map of settings.
		* @details This method allows the implementor to retrieve the map
		* containing all values from the Configuration.
		* @return Itself
		*/
		virtual const std::map<std::string, std::string>& getFields() const = 0;

		/**
		* @brief Getter for a specific field.
		* @details This method allows the implementor to retrieve the value for
		* a given key.
		* @param key The key associated to the value wanted.
		* @return A reference on the value stored.
		*/
		virtual const std::string& getField(const std::string& key) const = 0;

		/**
		* @brief Setter for a value thanks to a key.
		* @details This method allows the implementor to add a value to the map
		* of values already stored in the Configuration.
		* @param key The key to insert in the map. If already existant, the new
		* value will override the old one.
		* @param value The value associated to the key.
		* @return Itself
		*/
		virtual IConfiguration& addField(const std::string& key, const std::string& value) = 0;

		/**
		* @brief Method used to retrieve the configuration's file name.
		* @details This methos allows the implementor to know which file is
		* currently being used as the configuration file.
		* @return a reference to the path to the configuration file.
		*/
		virtual const std::string& getConfigurationFilename() const = 0;
	};
};
