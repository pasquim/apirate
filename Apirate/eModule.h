/**
 * eModule.h
 *
 * Project : 	Apirate
 * Created on:  Jan 2, 2016
 * Author: 	    Apirate Crew
 */

#pragma once

namespace Apirate {
	/**
	* @brief The eModule enum defines at which point a module must do its work.
	* @details This enum allows the implementor to order the modules of the
	* processing queue depending on the moment they are wupposed to act on a
	* query.
	*/
	enum eModule {
		CONNECTION, PREPROCESS, PROCESS, POSTPROCESS
	};
}