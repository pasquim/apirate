/**
 * eLog.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

 namespace Apirate {
 	/**
 	* @brief The eLog enum defines the type of log used by the server.
 	* @details This enum contains all the logger's type of log, accessible to 
 	* the implementor.
 	*/
 	enum eLog {
 		INFO, WARNING, FATAL
 	};
 }