/**
 * IModule.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

#include <eModule.h>
#include <ILogger.h>
#include <IQuery.h>

namespace Apirate {
	class IExecutionProcess;
}

namespace Apirate {
	/**
	* @brief Basic interface for modules
	* @details This class allows the implementor to define a basic interface for
	* its modules and what minimum informations they must have.
	*/
	class IModule {
	public:
		virtual ~IModule() {};

		/**
		* @brief Allows the module to init itself
		* @details This method allows the implementor to have a specific
		* location to build the module before it starts its execution.
		*/
		virtual int init() = 0;

		/**
		* @brief Getter for the module's name
		* @details This method allows the implementor to retrieve the name of
		* the module.
		* @return The name of the module.
		*/
		virtual const std::string& getName() const = 0;

		/**
		* @brief Getter for the module's priority
		* @details This method allows the implementor to retrieve the priority
		* of the module.
		* @return A float being the priority of the module. 
		*/
		virtual float getPriority() const = 0;

		/**
		* @brief Getter for the module's version
		* @details This method allows the implementor to retrieve the version
		* of the module.
		* @return A float being the version od the module.
		*/
		virtual float getVersion() const = 0;

		/**
		* @brief Getter for the module's type
		* @details This method allows the implementor to retrieve the module's
		* type.
		* @return The type of the module.
		*/
		virtual eModule getModuleType() const = 0;

		/**
		* @brief Getter for the module's logger
		* @details This method allows the implementor to retrieve the logger
		* stored in the module.
		* @return a reference to the logger.
		*/
		virtual ILogger& getLogger() = 0;

		/**
		* @brief Attach the module to a given execution process.
		* @details This methos allows a module to attach itself to a given
		* execution process.
		* @param executionProcess The instance to which the module is going to
		* be attached to.
		* @return itself
		*/
		virtual IModule& attachModule(IExecutionProcess& executionProcess) = 0;

		/**
		* @brief Detach the module to a given execution process.
		* @details This methos allows a module to detach itself to a given
		* execution process.
		* @param executionProcess The instance from which the module is going to
		* be detached.
		* @return itself
		*/
		virtual IModule& detachModule(IExecutionProcess& executionProcess) = 0;

		/**
		* @brief Executes the module's tasks on a query.
		* @details This method allows the implementor to exeute the module's
		* tasks on a given query.
		* @param query The query to process.
		* @return The processed query.
		*/
		virtual IQuery* exec(IQuery* query) = 0;

		/**
		* @brief Clones a module.
		* @details This method allows the implementor to clone the module
		* in order to retrieve a copy of it.
		* @return The cloned module.
		*/
		virtual IModule* clone() = 0;
	};
}