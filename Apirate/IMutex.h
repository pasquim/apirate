#pragma once

namespace Apirate {
	/**
	* @brief A simple implementation for mutexes.
	* @details This class allows the implementor to recreate a mutex class for
	* thread-safe interaction.
	*/
	class                   IMutex
	{
	public:
	    virtual ~IMutex() {};

	    /**
	    * @brief This function tries to lock a mutex.
	    * @details If it can't be locked, it exits immediatly.
	    * @return The values defines by the platform being a success or error
	    * code.
	    */
	    virtual int trylock() = 0;

	    /**
		* @brief This function awaits the mutex to be lockable.
		* @details This function waits until the mutex can be locked.
	    * @return The values defines by the platform being a success or error
	    * code.
	    */
	    virtual bool lock() = 0;

	    /**
	    * @brief This function frees a mutex that has been previously locked.
	    * @return The values defines by the platform being a success or error
	    * code.
	    */
	    virtual bool unlock() = 0;
	};
}