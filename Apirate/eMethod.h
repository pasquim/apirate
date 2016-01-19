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
 		HTTP_GET, HTTP_POST, HTTP_HEAD, HTTP_OPTIONS,
 		HTTP_CONNECT, HTTP_TRACE, HTTP_PUT, HTTP_PATCH, HTTP_DELETE
 	};
 }