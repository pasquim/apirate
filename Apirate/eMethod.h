/**
 * eMethod.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

 namespace Apirate {
 	/**
 	* @brief The eMethod enum defines which method is contained in a request.
 	* @details This enum contains all the methods defined in HTTP1.1, it shall
 	* be updated if new methods were to be defined.
 	*/
 	enum eMethod {
 		GET, POST, HEAD, OPTIONS, CONNECT, TRACE, PUT, PATCH, DELETE
 	}
 }