/***
 * IServer.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>
#include <vector>
#include "IExecutionProcess.h"
#include "IModule.h"
#include "ILogger.h" 

namespace Apirate {
	/**
	* @brief Basic interface for the server, providing minimalist functions for
	* it to run.
	* @details This class represents the most essential functions needed by the
	* server to ensure a clean functionning.
	*/
	class IServer {
	public:
		virtual ~IServer() {};

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
		* @brief Attach a module to the server's Execution Processes.
		* @details This method allows the implementor to attach a module to the
		* Execution Process instances which are currently in the server.
		* @param module A pointer to the module which is going to be attached.
		* @param name A unique identifier to this module.
		* @param attachTo If specified, the module is only going to be attached
		* the specified IExecutionProcess.
		* @return Itself
		*/
		virtual IServer& attachModule(IModule* module, const std::string& name, IExecutionProcess* attachTo = nullptr) = 0;

		/**
		* @brief Detach a module to the server's Execution Processes.
		* @details This method allows the implementor to detach a module to the
		* Execution Process instances which are currently via the server.
		* @param name A unique identifier to the module to remove.
		* @param attachTo If specified, the module is only going to be attached
		* the specified IExecutionProcess
		* @return A pointer to the detached module.
		*/
		virtual IModule* detachModule(const std::string& name, IExecutionProcess* attachTo = nullptr) = 0;
	};
}