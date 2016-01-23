/**
 * IExecutionProcess.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <string>
#include <IClient.h>

namespace Apirate {
	class IModule;
}

namespace Apirate {
	/**
	* @brief Basic interface for the Execution Process
	* @details The Execution Process allows the implementor to create a simple
	* queue of modules to be executed on a query given by a specified client.
	*/
	class IExecutionProcess {
	public:
		virtual ~IExecutionProcess() {};

		/**
		* @brief Main function for the Execution Process
		* @details This method allows the implementor to execute all wanted 
		* instructions by the Execution Process.
		* @return An unsigned int being the success or error code.
		*/
		virtual unsigned int run() = 0;

		/**
		* @brief A clean way to restart the Execution Process
		* @details This function allows the implementor to restart the Execution
		* Process and all its modules.
		* @return An unsigned int being the success or error code.
		*/
		virtual unsigned int restart() = 0;

		/**
		* @brief A clean way to stop the Execution Process
		* @details This function allows the implementor to perform a clean stop
		* of all running modules in the Execution Process.
		* @return An unsigned int being the success or error code.
		*/
		virtual unsigned int stop() = 0;

		/**
		* @brief Attach a module to the Execution Process
		* @details This method allows the implementor to attach a module to the
		* Execution Process.
		* @param module A pointer to the module which is going to be attached.
		* @param name A unique identifier to this module.
		* @return Itself
		*/
		virtual IExecutionProcess& attachModule(IModule* module, const std::string& name) = 0;

		/**
		* @brief Detach a module to the Execution Process
		* @details This method allows the implementor to detach a module to the
		* Execution Process.
		* @param name A unique identifier to the module to remove.
		* @return Itself
		*/
		virtual IExecutionProcess& detachModule(const std::string& name) = 0;

		/**
		* @brief Setter for the client.
		* @details This method allows the implementor to set a client in the
		* ExecutionProcess.
		* @param client A pointer to the client to refer in the ExecutionProcess.
		* @return Itself
		*/
		virtual IExecutionProcess& setClient(IClient* client) = 0;

		/**
		* @brief Getter for the client.
		* @details This method allows the implementor to retrieve a pointer to
		* the client who's getting its query executed.
		* @return A pointer to the client.
		*/
		virtual IClient* getClient() const = 0;
	};
}