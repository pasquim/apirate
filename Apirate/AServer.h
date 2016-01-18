/***
 * AServer.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>
#include <IExecutionProcess.h>
#include <IModule.h>

namespace Apirate {
	/**
	* @brief Basic interface for the server, providing minimalist functions for
	* it to run.
	* @details This class represents the most essential functions needed by the
	* server to ensure a clean functionning.
	*/
	class AServer {
	public:
		virtual ~AServer() {};

		/**
		* @brief The main running function of the server
		* @details This function is the function which must be called to run all
		* the server-related executions.
		* @return An unsigned int being the success or error code.
		*/
		virtual unsigned int run() = 0;

		/**
		* @brief A clean way to stop the server
		* @details This function allows the implementor to perform a clean stop
		* of all running process in the server.
		* @return An unsigned int being the success or error code.
		*/
		virtual unsigned int stop() = 0;

		/**
		* @brief Getter for the Execution Process
		* @details This methos allows the implementor to access the Execution
		* Process instance of the server.
		* @return A reference on the server's Execution Process.
		*/
		virtual IExecutionProcess& getExecutionProcess() const = 0;

		/**
		* @brief Attach a module to the server's Execution Process.
		* @details This method allows the implementor to attach a module to the
		* Execution Process via the server.
		* @param module A pointer to the module which is going to be attached.
		* @param name A unique identifier to this module.
		* @return Itself
		*/
		virtual AServer& attachModule(IModule* module, const std::string& name) = 0;

		/**
		* @brief Detach a module to the server's Execution Process.
		* @details This method allows the implementor to detach a module to the
		* Execution Process via the server.
		* @param name A unique identifier to the module to remove.
		* @return A pointer to the detached module.
		*/
		virtual IModule* detachModule(const std::string& name) = 0;
	};
}